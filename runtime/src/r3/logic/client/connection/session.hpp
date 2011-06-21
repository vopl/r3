#ifndef SESSION_HPP
#define SESSION_HPP

#include <QWidget>
#include "ui_session.h"

#include "r3/logic/client/connection.hpp"

namespace r3
{
	namespace logic
	{
		namespace client
		{
			class Connection::Session
				: public QWidget
				, public r3::protocol::client::Connection::Session
			{
				Q_OBJECT

			public:
				Session(QWidget *parent);
				~Session();

				template <class Event>
				void handle(const Event &evt)
				{
					r3::protocol::client::Connection::Session::handle(evt);
				}

				void handle(const Event_shutdown &evt);
				void handle(const Event_logout &evt);
			private:
				Ui::Session ui;

			public slots:
				void onBlock();
				void onLogout();

			signals:
				void doShutdown();
			};
		}
	}

	//////////////////////////////////////////////////////////////////////////
	template <> struct Logic<r3::protocol::client::Connection::Session>
	{
		typedef r3::logic::client::Connection::Session Context;
	};

}
#endif // SESSION_HPP
