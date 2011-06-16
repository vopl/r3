#include "stdafx.h"
#include "connection.hpp"
#include "r3/server/instance.hpp"

namespace r3
{
	namespace logic
	{
		namespace server
		{
			//////////////////////////////////////////////////////////////////////////
			Connection::Connection(net::Channel_ptr channel)
				: r3::protocol::server::Connection(0,NULL)
				, _channel(channel)
			{
				_channel->setHandler(this);
			}
			
			//////////////////////////////////////////////////////////////////////////
			Connection::~Connection()
			{
				r3::server::instance()->onConnectionDelete(shared_from_this());
			}
			
			//////////////////////////////////////////////////////////////////////////
			void Connection::onReceive(net::Channel_ptr channel, boost::shared_array<char> data, size_t size)
			{
				//deserialize & dispatch
			}
			
			//////////////////////////////////////////////////////////////////////////
			void Connection::onError(net::Channel_ptr channel)
			{
				r3::server::instance()->onConnectionError(shared_from_this());
			}
			
			//////////////////////////////////////////////////////////////////////////
			void Connection::onClose(net::Channel_ptr channel)
			{
				r3::server::instance()->onConnectionClose(shared_from_this());
			}
			
			//////////////////////////////////////////////////////////////////////////
			void Connection::fireImpl(const Path &cpi, const EventBase *evt)
			{
				//serialize & send
				//_channel->send()
				std::cout<<"connection fireImpl"<<std::endl;
				int k=220;

			}

		}
	}
}
