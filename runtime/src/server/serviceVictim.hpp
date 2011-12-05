#ifndef _SERVER_SERVICEVICTIM_HPP_
#define _SERVER_SERVICEVICTIM_HPP_

#include "server/iservice.hpp"
#include <boost/enable_shared_from_this.hpp>

namespace server
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	class ServiceVictim
		: public IService
		, public enable_shared_from_this<ServiceVictim>
	{
		static const TEndpoint _endpoint;
		void onSendOk();
		void onSendFail(system::error_code ec);

	public:

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
	typedef boost::shared_ptr<ServiceVictim> ServiceVictimPtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_INHERIT_PROVIDER(ServiceVictim, IService);
}
#endif
