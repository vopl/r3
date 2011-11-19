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

			std::string _host;
			short		_port;
			bool		_hasListener;
			size_t		_threads;

			std::set<net::ChannelPtr> _channels;
			net::Service *_netsrv;

		private:
			typedef std::map<std::string, SessionPtr> TMSessions;
			TMSessions _sessions;

		public:
			Instance();
			~Instance();

			void setAddress(const std::string &host, short port);

		private:
			virtual void onStartInThread(net::Service *netsrv);
			virtual void onError(net::Service *netsrv, net::EStage es, const boost::system::error_code& ec);
			virtual void onAccept(net::ChannelPtr channel);
			virtual void onConnect(net::ChannelPtr channel);
			virtual void onStopInThread();

		private:
			void updateListener();
		};
	}
}
#endif
