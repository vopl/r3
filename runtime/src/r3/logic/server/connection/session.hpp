#ifndef _R3_LOGIC_SERVER_CONNECTION_SESSION_HPP_
#define _R3_LOGIC_SERVER_CONNECTION_SESSION_HPP_

#include "r3/logic/server/connection.hpp"

namespace r3
{
	namespace logic
	{
		namespace server
		{
			class Connection::Session
				: public r3::protocol::server::Connection::Session
			{
			private:
				ContextId _sid;

			public:
				Session(ContextId sid);
				~Session();

				ContextId sid();
			};
		}
	}

	//////////////////////////////////////////////////////////////////////////
	template <> struct Logic<r3::protocol::server::Connection::Session>
	{
		typedef r3::logic::server::Connection::Session Context;
	};

}
#endif
