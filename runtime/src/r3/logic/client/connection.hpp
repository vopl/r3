#ifndef CONNECTION_H
#define CONNECTION_H

#include <QWidget>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include "ui_connection.h"

#include "r3/logic.hpp"
#include "r3/protocol/client/Connection.hpp"

namespace r3
{
	namespace logic
	{
		class Connection : public QWidget
			, public r3::protocol::client::Connection
		{
			Q_OBJECT

		public:
			Connection(QMainWindow *parent = 0);
			~Connection();

		private:
			Ui::Connection ui;

			QLabel *_labelConnected;
			QLabel *_labelSendReceive;
			QLabel *_labelPing;

			QPixmap _pixmapNull;
			QPixmap _pixmapConnected;
			QPixmap _pixmapDisconnected;
			QPixmap _pixmapSend;
			QPixmap _pixmapRerceive;
			QPixmap _pixmapSendRerceive;

			QTime _lastPingTime;

		private:
			bool _sendWas;
			bool _receiveWas;
			bool _sendNow;
			bool _receiveNow;
			void updateSendReceive();

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


		private slots:
			void socketStateChanged(QAbstractSocket::SocketState state);
			void socketEncrypted();
			void sslErrors(const QList<QSslError> &errors);
			void socketReadyRead();
			void socketBytesWritten(qint64 bytes);

		public:
			void fireImpl(const Path &cpi, const EventBase *evt);
		};
	}

	template <> struct Logic<r3::protocol::client::Connection>
	{
		typedef logic::Connection Context;
	};
}

#endif // CONNECTION_H
