#ifndef CONNECTION_H
#define CONNECTION_H

#include <QWidget>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include "ui_connection.h"

#include "r3/logic.hpp"
#include "r3/protocol/client/Connection.hpp"
#include "r3/logic/client/connection/authwidget.h"

namespace r3
{
	namespace logic
	{
		namespace client
		{
			class Connection 
				: public QWidget
				, public r3::protocol::client::Connection
			{
				Q_OBJECT

			public:
				Connection(QMainWindow *parent = 0);
				~Connection();

			private:
				Ui::Connection ui;

				AuthWidget *_authWidget;
				QString _login;
				QString _password;

			public:
				class Session;
				boost::shared_ptr<Session> _session;

			private:
				virtual void resizeEvent(QResizeEvent *);

				QLabel *_labelConnected;
				QLabel *_labelSendReceive;
				QLabel *_labelPing;

				QPixmap _pixmapNull;
				QPixmap _pixmapConnected;
				QPixmap _pixmapDisconnected;
				QPixmap _pixmapSend;
				QPixmap _pixmapReceive;
				QPixmap _pixmapSendReceive;

				QTime _lastPingTime;

			private:
				bool _connectedWas;
				void updateConnected();

				bool _sendWas;
				bool _receiveWas;
				bool _sendNow;
				bool _receiveNow;
				void updateSendReceive();

				void updateWidget();


			private:
				int _reconnectTimerId;
				int _pingTimerId;
				void timerEvent(QTimerEvent *);

				QSslSocket *_socket;
				boost::uint32_t _incomingReaded;
				boost::uint32_t _incomingSize;

				boost::uint32_t _outcomingSize;

				void open();
				void close();

			public:
				template <class Event>
				void handle(const Event &evt)
				{
					//
				}
				void handle(const Event_pong &evt);
				void handle(const Event_badLogin &evt);
				void handle(const Event_startup &evt);


				bool makeNewChild(boost::shared_ptr<r3::protocol::client::Connection::Session> &child, ContextId id);
				

				private slots:
					void socketStateChanged(QAbstractSocket::SocketState state);
					void socketEncrypted();
					void sslErrors(const QList<QSslError> &errors);
					void socketReadyRead();
					void socketBytesWritten(qint64 bytes);

			public:
				void fireImpl(const Path &cpi, const EventBase *evt);

			private:
			public Q_SLOTS:
				void onLoginGo(QString login, QString password);
				void onSessionShutdown();

			};
		}
	}

	//////////////////////////////////////////////////////////////////////////
	template <> struct Logic<r3::protocol::client::Connection>
	{
		typedef r3::logic::client::Connection Context;
	};
}

#include "r3/logic/client/connection/session.hpp"

#endif // CONNECTION_H
