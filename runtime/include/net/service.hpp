#ifndef _NET_SERVICE_HPP_
#define _NET_SERVICE_HPP_

#include "net/channel.hpp"
#include <boost/shared_ptr.hpp>

namespace net
{
	enum EStage
	{
		esListen,
		esAccept,
		esAcceptHandshake,
		esConnect,
		esConnectHandshake,
	};

	class Service;

	//////////////////////////////////////////////////////////////////////////
	struct IServiceHandler
	{
		virtual void onStartInThread(Service *) =0;

		virtual void onError(Service *srv, EStage es, const boost::system::error_code& ec) =0;

		virtual void onAccept(ChannelPtr channel) =0;
		virtual void onConnect(ChannelPtr channel) =0;

		virtual void onStopInThread() =0;
	};

	//////////////////////////////////////////////////////////////////////////
	class ServiceImpl;
	class Service
	{
		boost::shared_ptr<ServiceImpl> _impl;
	public:
		Service(IServiceHandler *);
		~Service();

		void balance(size_t numThreads);

		bool listen(const char *host, short port);
		bool connect(const char *host, short port);
	};
}
#endif
