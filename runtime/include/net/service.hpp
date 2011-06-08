#ifndef _NET_SERVICE_HPP_
#define _NET_SERVICE_HPP_

#include "net/channel.hpp"
#include <boost/shared_ptr.hpp>

namespace net
{
	class Service;

	//////////////////////////////////////////////////////////////////////////
	struct IServiceHandler
	{
		virtual void onStart(Service *) {};
		virtual void onStartInThread(Service *) {};

		virtual void onError(Service *) {};

		virtual void onAccept(IChannel *) {};
		virtual void onConnect(IChannel *) {};

		virtual void onStopInThread() {};
		virtual void onStop() {};
	};

	//////////////////////////////////////////////////////////////////////////
	class ServiceImpl;
	class Service
	{
		boost::shared_ptr<ServiceImpl> _impl;
	public:
		Service(IServiceHandler *);

		void balance(size_t numThreads);

		void listen(const char *host, short port);
		void connect(const char *host, short port);
	};
}
#endif
