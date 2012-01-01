#ifndef _SERVER_SERVICESTATICS_HPP_
#define _SERVER_SERVICESTATICS_HPP_

#include "server/iservice.hpp"
#include <boost/enable_shared_from_this.hpp>
#include <boost/filesystem.hpp>

namespace server
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	class ServiceStatics
		: public IService
		, public enable_shared_from_this<ServiceStatics>
	{
		static const TEndpoint _endpoint;

		boost::filesystem::path _root;

	public:
		ServiceStatics();
		~ServiceStatics();

		virtual const TEndpoint &getEndpoint();

		virtual void onHubAdd(IServiceHubPtr hub);
		virtual void onHubDel(IServiceHubPtr hub);

		virtual void onSessionAdd(ISessionPtr session);
		virtual void onSessionDel(ISessionPtr session);

		virtual void onReceive(
			IServiceHubPtr hub,
			ISessionPtr session,
			const client::TEndpoint &endpoint,
			utils::VariantPtr data);
	};
	typedef boost::shared_ptr<ServiceStatics> ServiceStaticsPtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_INHERIT_PROVIDER(ServiceStatics, IService);
}
#endif
