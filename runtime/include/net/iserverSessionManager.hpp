#ifndef _NET_ISERVERSESSIONMANAGER_HPP_
#define _NET_ISERVERSESSIONMANAGER_HPP_

#include "net/iserverSession.hpp"
#include "net/iconnector.hpp"

namespace net
{
	struct IServerSessionManager
	{
		virtual void start(
			IConnectorPtr connector, 
			const char *host, const char *service,
			boost::function<void (IServerSessionPtr)> ready,
			boost::function<void (boost::system::error_code)> fail) =0;

		virtual void stop() =0;
	};
	typedef boost::shared_ptr<IServerSessionManager> IServerSessionManagerPtr;

	PLUMA_PROVIDER_HEADER(IServerSessionManager, 1, 1);
}
#endif
