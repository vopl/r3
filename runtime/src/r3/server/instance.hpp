#ifndef _R3_SERVER_INSTANCE_HPP_
#define _R3_SERVER_INSTANCE_HPP_

#include "net/service.hpp"
#include "r3/server/channel.hpp"
#include "r3/server/session.hpp"

namespace r3
{


	//////////////////////////////////////////////////////////////////////////
	namespace server
	{
		class Instance
			: public net::IServiceHandler
		{
			boost::mutex _mtx;
			std::set<ChannelPtr> _channels;
		public:
			Instance();
			~Instance();

		private:
			void onChannelClose(ChannelPtr ch);
			void onChannelError(ChannelPtr ch);


		private:
			virtual void onStartInThread(net::Service *);
			virtual void onError(net::Service *);
			virtual void onAccept(net::ChannelPtr channel);
			virtual void onConnect(net::ChannelPtr channel);
			virtual void onStopInThread();
		};
	}
}
#endif
