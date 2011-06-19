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
		Connection::Connection(QMainWindow *parent)
			: QWidget(parent)
			, r3::protocol::client::Connection(0, NULL)
			, _reconnectTimerId(0)
			, _pingTimerId(0)
			, _socket(NULL)
			, _incomingReaded(0)
			, _incomingSize(0)
			, _outcomingSize(0)
			, _pixmapNull(":/Client/images/null.png")
			, _pixmapConnected(":/Client/images/connected.png")
			, _pixmapDisconnected(":/Client/images/disconnected.png")
			, _pixmapSend(":/Client/images/send.png")
			, _pixmapRerceive(":/Client/images/receive.png")
			, _pixmapSendRerceive(":/Client/images/sendreceive.png")
			, _sendNow(false)
			, _receiveNow(false)
			, _sendWas(false)
			, _receiveWas(false)

		{
			ui.setupUi(this);

			_labelConnected = new QLabel(parent->statusBar());
			_labelConnected->setPixmap(_pixmapNull);
			_labelSendReceive = new QLabel(parent->statusBar());
			_labelSendReceive->setPixmap(_pixmapNull);
			_labelPing = new QLabel(parent->statusBar());
			_labelPing->setText("_labelPing");

			parent->statusBar()->addPermanentWidget(_labelPing);
			parent->statusBar()->addPermanentWidget(_labelSendReceive);
			parent->statusBar()->addPermanentWidget(_labelConnected);

			open();

		}

		//////////////////////////////////////////////////////////////////////////
		Connection::~Connection()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		void Connection::updateSendReceive()
		{
			if(_sendNow != _sendWas ||
				_receiveNow != _receiveWas)
			{
				if(_sendNow && _receiveNow)
				{
					_labelSendReceive->setPixmap(_pixmapSendRerceive);
				}
				else if(_sendNow)
				{
					_labelSendReceive->setPixmap(_pixmapSend);
				}
				else if(_receiveNow)
				{
					_labelSendReceive->setPixmap(_pixmapRerceive);
				}
				else
				{
					_labelSendReceive->setPixmap(_pixmapNull);
				}

				_sendWas = _sendNow;
				_receiveWas = _receiveNow;
			}
		}


		//////////////////////////////////////////////////////////////////////////
		void Connection::timerEvent(QTimerEvent *te)
		{
			if(te->timerId() == _reconnectTimerId)
			{
				killTimer(_reconnectTimerId);
				_reconnectTimerId = 0;
				open();
			}
			else if(te->timerId() == _pingTimerId)
			{
				if(_socket)
				{
					_lastPingTime = QTime::currentTime();
					fire(Event_ping());
				}
			}
		}


		//////////////////////////////////////////////////////////////////////////
		void Connection::open()
		{
			assert(!_socket);
			_incomingReaded = 0;
			_incomingSize = 0;
			_outcomingSize = 0;
			_labelConnected->setPixmap(_pixmapDisconnected);

			_sendNow = false;
			_receiveNow = false;
			updateSendReceive();

			_labelPing->setText("inf");

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
			connect(_socket, SIGNAL(bytesWritten(qint64)),
				this, SLOT(socketBytesWritten(qint64)));

			_socket->connectToHostEncrypted("127.0.0.1", 1234);
		}

		//////////////////////////////////////////////////////////////////////////
		void Connection::close()
		{
			_labelConnected->setPixmap(_pixmapDisconnected);
			if(_socket)
			{
				_socket->close();
				_socket->deleteLater();
				_socket = 0;
			}

			_sendNow = false;
			_receiveNow = false;
			updateSendReceive();
		}

		//////////////////////////////////////////////////////////////////////////
		void Connection::handle(const Event_pong &evt)
		{
			int ms = _lastPingTime.msecsTo(QTime::currentTime());
			_labelPing->setNum(ms);
		}


		//////////////////////////////////////////////////////////////////////////
		void Connection::socketStateChanged(QAbstractSocket::SocketState state)
		{
			if(!_socket)
			{
				_labelConnected->setPixmap(_pixmapDisconnected);
				_sendNow = false;
				_receiveNow = false;
				updateSendReceive();
				_labelPing->setText("inf");

				return;
			}

			if (state == QAbstractSocket::UnconnectedState)
			{
				_socket->deleteLater();
				_socket = 0;

				if(_pingTimerId)
				{
					killTimer(_pingTimerId);
					_pingTimerId = 0;
				}
				_labelPing->setText("inf");


				assert(!_reconnectTimerId);
				_reconnectTimerId = startTimer(1000);

				_labelConnected->setPixmap(_pixmapDisconnected);
				_sendNow = false;
				_receiveNow = false;
				updateSendReceive();
			}

			if(state == QAbstractSocket::ConnectedState)
			{
				_labelConnected->setPixmap(_pixmapConnected);

				assert(!_pingTimerId);
				_pingTimerId = startTimer(1000);

				_lastPingTime = QTime::currentTime();
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
				_receiveNow = true;
				updateSendReceive();

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


			_receiveNow = false;
			updateSendReceive();

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
		void Connection::socketBytesWritten(qint64 bytes)
		{
			_outcomingSize -= bytes;

			_sendNow = _outcomingSize != 0;
			updateSendReceive();
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

			_outcomingSize += 4 + sbuf.size() + 4;

			_sendNow = _outcomingSize != 0;
			updateSendReceive();
		}


	}
}
