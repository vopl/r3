#include "StdAfx.h"
#include "connection.hpp"
#include <QtNetwork/QSslCipher>
#include <QMessageBox>
#include "utils/streambufOnArray.hpp"
#include "utils/serialization.hpp"
#include "utils/crc32.hpp"

#include "r3/data.hpp"

namespace r3
{
	namespace logic
	{
		//////////////////////////////////////////////////////////////////////////
		Connection::Connection(QWidget *parent)
			: QWidget(parent)
			, r3::protocol::client::Connection(0, NULL)
			, _socket(NULL)
			, _incomingReaded(0)
			, _incomingSize(0)

		{
			ui.setupUi(this);

			open();

		}

		//////////////////////////////////////////////////////////////////////////
		Connection::~Connection()
		{

		}

		//////////////////////////////////////////////////////////////////////////
		void Connection::open()
		{
			_incomingReaded = 0;
			_incomingSize = 0;

			if(!QSslSocket::supportsSsl())
			{
				QMessageBox::information(0, "Secure Socket Client",
					"This system does not support OpenSSL.");
				return;
			}
			_socket = new QSslSocket(this);
			_socket->setPeerVerifyMode(QSslSocket::VerifyNone);

			connect(_socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
				this, SLOT(socketStateChanged(QAbstractSocket::SocketState)));
			connect(_socket, SIGNAL(encrypted()),
				this, SLOT(socketEncrypted()));
			connect(_socket, SIGNAL(sslErrors(QList<QSslError>)),
				this, SLOT(sslErrors(QList<QSslError>)));
			connect(_socket, SIGNAL(readyRead()),
				this, SLOT(socketReadyRead()));

			_socket->connectToHostEncrypted("127.0.0.1", 1234);
		}

		//////////////////////////////////////////////////////////////////////////
		void Connection::close()
		{
			if(_socket)
			{
				_socket->close();
				_socket->deleteLater();
				_socket = 0;
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void Connection::handle(const Event_pong &evt)
		{
			fire(Event_ping());
		}


		//////////////////////////////////////////////////////////////////////////
		void Connection::socketStateChanged(QAbstractSocket::SocketState state)
		{
			if(!_socket)
			{
				return;
			}

			if (state == QAbstractSocket::UnconnectedState)
			{
				_socket->deleteLater();
				_socket = 0;
			}

			if(state == QAbstractSocket::ConnectedState)
			{
				fire(Event_ping());
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void Connection::socketEncrypted()
		{
			if (!_socket)
			{
				return;                 // might have disconnected already
			}


			QSslCipher ciph = _socket->sessionCipher();
			QString cipher = QString("%1, %2 (%3/%4)").arg(ciph.authenticationMethod())
				.arg(ciph.name()).arg(ciph.usedBits()).arg(ciph.supportedBits());;

			int k=220;
		}

		//////////////////////////////////////////////////////////////////////////
		void Connection::sslErrors(const QList<QSslError> &errors)
		{
			QString errs;

			foreach (const QSslError &error, errors)
			{
				errs += "\n\n";
				errs += error.errorString();
			}

			_socket->ignoreSslErrors();

			// did the socket state change?
			if (_socket->state() != QAbstractSocket::ConnectedState)
			{
				socketStateChanged(_socket->state());
			}

			int k=220;
		}

		//////////////////////////////////////////////////////////////////////////
		void Connection::socketReadyRead()
		{
			if(_incomingReaded < 4)
			{
				if(_socket->bytesAvailable() < 4)
				{
					return;
				}
				_incomingReaded += _socket->read((char *)&_incomingSize, 4);
				assert(4 == _incomingReaded);
				_incomingSize = utils::fixEndian(_incomingSize);
			}
			
			if(_socket->bytesAvailable() < _incomingSize+4)
			{
				return;
			}

			boost::shared_array<char> incomingData(new char[_incomingSize]);
			_incomingReaded += _socket->read(incomingData.get(), _incomingSize);
			assert(4+_incomingSize == _incomingReaded);

			boost::uint32_t incomingCrc;
			_incomingReaded += _socket->read((char *)&incomingCrc, 4);
			assert(4+_incomingSize+4 == _incomingReaded);
			incomingCrc = utils::fixEndian(incomingCrc);


			boost::uint32_t crc = utils::crc32(incomingData.get(), _incomingSize);

			if(crc != incomingCrc)
			{
				assert(0);
				_socket->close();
			}

			//////////////////////////////////////////////////////////////////////////
			Path cpi;
			EventBase *evt = NULL;

			try
			{
				utils::StreambufOnArray sbuf(incomingData, _incomingSize);
				{
					std::istream is(&sbuf);
					utils::serialization::polymorphic_binary_portable_iarchive ia(is, boost::archive::no_header|boost::archive::no_codecvt);

					ia >> BOOST_SERIALIZATION_NVP(cpi);
					ia >> BOOST_SERIALIZATION_NVP(evt);
				}

				this->dispatch(cpi, evt);
			}
			catch(...)
			{
				assert(0);
				std::cerr<<"exception in "<<__FUNCTION__<<std::endl;
			}
			delete evt;
			_incomingReaded = 0;
			_incomingSize = 0;
		}

		//////////////////////////////////////////////////////////////////////////
		void Connection::fireImpl(const Path &cpi, const EventBase *evt)
		{
			if(!_socket)
			{
				return;
			}


			utils::StreambufOnArray sbuf;
			{
				std::ostream os(&sbuf);

				utils::serialization::polymorphic_binary_portable_oarchive oa(os, boost::archive::no_header|boost::archive::no_codecvt);

				oa << BOOST_SERIALIZATION_NVP(cpi);
				oa << BOOST_SERIALIZATION_NVP(evt);
			}

			boost::uint32_t size = utils::fixEndian((boost::uint32_t)sbuf.size());
			boost::uint32_t crc = utils::fixEndian(utils::crc32(sbuf.data().get(), sbuf.size()));

			_socket->write((const char *)&size, 4);
			_socket->write(sbuf.data().get(), sbuf.size());
			_socket->write((const char *)&crc, 4);
		}


	}
}
