#ifndef _SERVER_SERVICEHUB_HPP_
#define _SERVER_SERVICEHUB_HPP_

#include "server/iserviceHub.hpp"
#include <boost/enable_shared_from_this.hpp>

namespace server
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	struct ServiceHub
		: public IServiceHub
		, public enable_shared_from_this<ServiceHub>
	{
		typedef std::map<TServerSid, ISessionPtr> TMSessions;
		typedef std::map<TEndpoint, IServicePtr> TMServices;

		TMSessions	_sessions;
		TMServices	_services;

		mutex	_mtx;

	private:
		void onReceiveOk(ISessionPtr session, const net::SPacket &p);
		void onReceiveFail(ISessionPtr session, system::error_code ec);


	public:
		ServiceHub();
		virtual ~ServiceHub();

		virtual void addSession(ISessionPtr session);
		virtual void delSession(ISessionPtr session);

		virtual void addService(IServicePtr service);
		virtual void delService(IServicePtr service);

		virtual void send(
			IServicePtr service,
			ISessionPtr session,
			const TEndpoint &endpoint,
			utils::VariantPtr data,
			boost::function<void ()> ok,
			boost::function<void (boost::system::error_code)> fail);
	};
	typedef boost::shared_ptr<ServiceHub> ServiceHubPtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_INHERIT_PROVIDER(ServiceHub, IServiceHub);

}
#endif
