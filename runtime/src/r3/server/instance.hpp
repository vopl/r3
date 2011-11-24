#ifndef _R3_SERVER_INSTANCE_HPP_
#define _R3_SERVER_INSTANCE_HPP_

#include "net/connector.hpp"
#include "r3/server/channel.hpp"
#include "r3/server/session.hpp"

namespace r3
{


	//////////////////////////////////////////////////////////////////////////
	namespace server
	{
		using namespace boost;

		class Instance
		{
			boost::mutex _mtx;

			std::string _host;
			std::string _service;

			net::Connector	_connector;

		private:

		private:
			void onListenOk(net::Channel channel);
			void onListenFail(system::error_code ec);

		public:
			Instance(net::AsyncService &asrv);
			~Instance();

			void setAddress(const std::string &host, const std::string &service);

		private:
// 			virtual void onStartInThread(net::Service *netsrv);
// 			virtual void onError(net::Service *netsrv, net::EStage es, const boost::system::error_code& ec);
// 			virtual void onAccept(net::ChannelPtr channel);
// 			virtual void onConnect(net::ChannelPtr channel);
// 			virtual void onStopInThread();

		private:
// 			void updateListener();
		};
	}
}
#endif
