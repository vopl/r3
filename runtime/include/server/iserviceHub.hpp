#ifndef _SERVER_ISERVICEHUB_HPP_
#define _SERVER_ISERVICEHUB_HPP_

#include "server/iservice.hpp"
#include "server/endpoint.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	struct IServer;
	typedef boost::shared_ptr<IServer> IServerPtr;

	//////////////////////////////////////////////////////////////////////////
	struct IServiceHub
	{
		virtual ~IServiceHub(){}

		virtual void setServer(IServerPtr server) =0;
		virtual IServerPtr getServer() =0;

		virtual void addSession(ISessionPtr session) =0;
		virtual void delSession(ISessionPtr session) =0;

		virtual void addService(IServicePtr service) =0;
		virtual IServicePtr getService(const TEndpoint &endpoint) =0;
		virtual void delService(IServicePtr service) =0;
		virtual void delServices() =0;

		virtual void send(
			IServicePtr service,
			ISessionPtr session,
			const client::TEndpoint &endpoint,
			utils::VariantPtr data,
			boost::function<void ()> ok,
			boost::function<void (boost::system::error_code)> fail) =0;

	};
	typedef boost::shared_ptr<IServiceHub> IServiceHubPtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_PROVIDER_HEADER(IServiceHub, 1, 1);

}
#endif
