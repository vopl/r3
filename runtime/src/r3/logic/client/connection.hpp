#ifndef _R3_LOGIC_CLIENT_CONNECTION_HPP_
#define _R3_LOGIC_CLIENT_CONNECTION_HPP_

#include "r3/logic.hpp"
#include "r3/protocol/client/Connection.hpp"

namespace r3
{
	template <> struct Logic<r3::protocol::client::Connection>
	{
		class Context
			: public r3::protocol::client::Connection
		{
		public:
			Context()
				: r3::protocol::client::Connection(435,NULL)
			{

			}

		};
	};
}

#endif
