#include "StdAfx.h"
#include "connection.hpp"
#include <QtNetwork/QSslCipher>
#include <QMessageBox>
#include "utils/streambufOnArray.hpp"
#include "utils/serialization.hpp"

namespace r3
{
	namespace logic
	{
		//////////////////////////////////////////////////////////////////////////
		Connection::Connection(QWidget *parent)
			: QWidget(parent)
			, r3::protocol::client::Connection(0, NULL)
			, _socket(NULL)
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

			fire(Event_ping());
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

		}

		//////////////////////////////////////////////////////////////////////////
		void Connection::fireImpl(const Path &cpi, const EventBase *evt)
		{
			utils::StreambufOnArray sbuf;
			{
				std::ostream os(&sbuf);

				utils::serialization::polymorphic_binary_portable_oarchive oa(os, boost::archive::no_header|boost::archive::no_codecvt);

				oa << cpi;
				oa << evt;
			}

			_socket->write(sbuf.data().get(), sbuf.size());

		
		}


	}
}
