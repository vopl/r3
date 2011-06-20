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
				Session(ContextId id, r3::logic::client::Connection *parent);
				~Session();

			private:
				Ui::Session ui;
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
