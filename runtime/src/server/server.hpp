#ifndef _SERVER_SERVER_HPP_
#define _SERVER_SERVER_HPP_

#include "server/iserver.hpp"
#include "server/isessionManager.hpp"
#include "server/iserviceHub.hpp"

namespace server
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	class Server
		: public IServer
		, public boost::enable_shared_from_this<Server>
	{
		pluma::Pluma *_plugs;
		async::IServicePtr	_async;
		ISessionManagerPtr	_sessionManager;
		IServiceHubPtr		_serviceHub;

	private:
		void onSessionStart(ISessionPtr session);
		void onSessionStop(ISessionPtr session);

	public:
		Server();
		~Server();

		virtual void start(pluma::Pluma *plugs, const char *host, const char *service);
		virtual void stop();
		virtual pluma::Pluma * getPlugs();
		virtual async::IServicePtr getAsync();
	};
	PLUMA_INHERIT_PROVIDER(Server, IServer);
}
#endif
