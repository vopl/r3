#ifndef _SERVER_SERVICEHUB_HPP_
#define _SERVER_SERVICEHUB_HPP_

#include "server/iserviceHub.hpp"
#include <boost/enable_shared_from_this.hpp>

namespace server
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	class ServiceHub
		: public IServiceHub
		, public enable_shared_from_this<ServiceHub>
	{
		typedef std::map<TServerSid, ISessionPtr> TMSessions;
		typedef std::map<TEndpoint, IServicePtr> TMServices;

		TMServices	_services;

		IServerPtr	_server;

		mutex		_mtx;

	private:
		void onSendOk(ISessionPtr session);
		void onSendFail(ISessionPtr session, system::error_code ec);

		void onReceiveOk(ISessionPtr session, const net::SPacket &p);
		void onReceiveFail(ISessionPtr session, system::error_code ec);


	public:
		ServiceHub();
		virtual ~ServiceHub();

		virtual void setServer(IServerPtr server);
		virtual IServerPtr getServer();

		virtual void addSession(ISessionPtr session);
		virtual void delSession(ISessionPtr session);

		virtual void addService(IServicePtr service);
		virtual IServicePtr getService(const TEndpoint &endpoint);
		virtual void delService(IServicePtr service);
		virtual void delServices();

		virtual void send(
			IServicePtr service,
			ISessionPtr session,
			const client::TEndpoint &endpoint,
			utils::VariantPtr data,
			boost::function<void ()> ok,
			boost::function<void (boost::system::error_code)> fail);
	};
	typedef boost::shared_ptr<ServiceHub> ServiceHubPtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_INHERIT_PROVIDER(ServiceHub, IServiceHub);

}
#endif
