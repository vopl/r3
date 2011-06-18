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
			Connection(QWidget *parent = 0);
			~Connection();

		private:
			Ui::Connection ui;

		private:
			QSslSocket *_socket;

			void open();
			void close();

		private slots:
			void socketStateChanged(QAbstractSocket::SocketState state);
			void socketEncrypted();
			void sslErrors(const QList<QSslError> &errors);
			void socketReadyRead();

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
