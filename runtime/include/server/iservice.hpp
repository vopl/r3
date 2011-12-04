#ifndef _SERVER_ISERVICE_HPP_
#define _SERVER_ISERVICE_HPP_

#include "pluma/pluma.hpp"
#include "utils/variant.hpp"
#include "server/isession.hpp"
#include "server/endpoint.hpp"
#include "client/endpoint.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	struct IServiceHub;
	typedef boost::shared_ptr<IServiceHub> IServiceHubPtr;

	//////////////////////////////////////////////////////////////////////////
	struct IService
	{
		virtual ~IService(){}

		virtual const TEndpoint &getEndpoint() =0;

		virtual void onHubAdd(IServiceHubPtr hub) =0;
		virtual void onHubDel(IServiceHubPtr hub) =0;

		virtual void onSessionAdd(ISessionPtr session) =0;
		virtual void onSessionDel(ISessionPtr session) =0;

		virtual void onReceive(
			IServiceHubPtr hub,
			ISessionPtr session,
			const client::TEndpoint &endpoint,
			utils::VariantPtr data) =0;
	};
	typedef boost::shared_ptr<IService> IServicePtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_PROVIDER_HEADER(IService, 1, 1);
}
#endif
