#ifndef _R3_LOGIC_SERVER_CONNECTION_HPP_
#define _R3_LOGIC_SERVER_CONNECTION_HPP_

#include "r3/logic.hpp"
#include "r3/protocol/server/Connection.hpp"
#include "net/service.hpp"

namespace r3
{
	namespace logic
	{
		namespace server
		{
			class Connection
				: public r3::protocol::server::Connection
				, public net::IChannelHandler
				, public boost::enable_shared_from_this<Connection>
			{
			public:
				class Session;
				typedef boost::shared_ptr<Session> Session_ptr;

			private:
				net::Channel_ptr _channel;
			public:
				Connection(net::Channel_ptr channel);
				~Connection();

				void close();

			private:
				virtual void onReceive(net::Channel_ptr channel, boost::shared_array<char> data, size_t size);
				virtual void onError(net::Channel_ptr channel);
				virtual void onClose(net::Channel_ptr channel);


			public:// генераторы исходящих сообщений
				void fireImpl(const Path &cpi, const EventBase *evt);

			public:
				template <class Event> void handle(const Event &evt)
				{
					return BaseType::handle(evt);
				}
				void handle(const Event_login &evt);

				bool makeNewChild(boost::shared_ptr<r3::protocol::server::Connection::Session> &child, ContextId id)
				{
					return false;
				}
			};

		}
	}

	//////////////////////////////////////////////////////////////////////////
	template <> struct Logic<r3::protocol::server::Connection>
	{
		typedef logic::server::Connection Context;
	};
}

#include "r3/logic/server/connection/session.hpp"

namespace r3
{
	namespace logic
	{
		namespace server
		{
		}
	}
}
#endif
