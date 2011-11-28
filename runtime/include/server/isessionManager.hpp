#ifndef _SERVER_ISESSIONMANAGER_HPP_
#define _SERVER_ISESSIONMANAGER_HPP_

#include "server/isession.hpp"
#include "net/iconnector.hpp"

namespace server
{
	struct ISessionManager
	{
		virtual ~ISessionManager(){}

		virtual void start(
			net::IConnectorPtr connector, 
			const char *host, const char *service,
			boost::function<void (ISessionPtr)> ready,
			boost::function<void (boost::system::error_code)> fail) =0;

		virtual void stop() =0;
	};
	typedef boost::shared_ptr<ISessionManager> ISessionManagerPtr;

	PLUMA_PROVIDER_HEADER(ISessionManager, 1, 1);
}
#endif
