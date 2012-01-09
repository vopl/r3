#ifndef _CLIENT_CLIENT_HPP_
#define _CLIENT_CLIENT_HPP_

#include "client/iclient.hpp"
#include "client/isession.hpp"
#include "async/service.hpp"
#include "net/iconnector.hpp"
#include "session.hpp"

namespace client
{
	using namespace boost;
	using namespace boost::system;
	using namespace net;

	//////////////////////////////////////////////////////////////////////////
	class Client
		: public IClient
		, public boost::enable_shared_from_this<Client>
	{
		mutex				_mtx;
		pluma::Pluma *		_plugs;
		async::Service		_asrv;
		IConnectorPtr		_connector;

	private:
		void connectSession_f(
			Result2<error_code, ISessionPtr> res, 
			const std::string &host, const std::string &service,
			SessionPtr session);

	public:
		Client();
		~Client();

		virtual bool start(pluma::Pluma *plugs);
		virtual Result2<error_code, ISessionPtr> 
			createSession(const char *host, const char *service);
		virtual pluma::Pluma * getPlugs();
		virtual Service getAsrv();
		virtual bool stop();

	public:
		Result2<error_code, ISessionPtr> 
			connectSession(SessionPtr session, const std::string &host, const std::string &service);
	};
	PLUMA_INHERIT_PROVIDER(Client, IClient);
}
#endif
