#ifndef _SERVER_ISESSIONMANAGER_HPP_
#define _SERVER_ISESSIONMANAGER_HPP_

#include "server/isession.hpp"
#include "net/iconnector.hpp"
#include "net/iacceptor.hpp"

namespace server
{
	struct ISessionManager
	{
		virtual ~ISessionManager(){}

		virtual void start(
			net::IConnectorPtr connector, 
			net::IAcceptorPtr acceptor, 
			const char *host, const char *service,
			boost::function<void (ISessionPtr)> sstart,
			boost::function<void (ISessionPtr)> sstop) =0;

		virtual void stop() =0;
	};
	typedef boost::shared_ptr<ISessionManager> ISessionManagerPtr;

	PLUMA_PROVIDER_HEADER(ISessionManager, 1, 1);
}
#endif
