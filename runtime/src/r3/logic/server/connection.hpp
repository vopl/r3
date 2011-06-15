#ifndef _R3_LOGIC_SERVER_CONNECTION_HPP_
#define _R3_LOGIC_SERVER_CONNECTION_HPP_

#include "r3/logic.hpp"
#include "r3/protocol/server/Connection.hpp"

namespace r3
{
	template <> struct Logic<r3::protocol::server::Connection>
	{
		class Context
			: public r3::protocol::server::Connection
		{
		public:
			Context()
				: r3::protocol::server::Connection(435,NULL)
			{

			}

		public:// генераторы исходящих сообщений
			void fireImpl(const Path &cpi, const EventBase *evt)
			{
				std::cout<<"connection fireImpl"<<std::endl;
				int k=220;
				
			}
		};
	};
}

#endif
