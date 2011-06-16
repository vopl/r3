#ifndef CONNECTION_H
#define CONNECTION_H

#include <QWidget>
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
		};
	}

	template <> struct Logic<r3::protocol::client::Connection>
	{
		typedef logic::Connection Context;
	};
}

#endif // CONNECTION_H
