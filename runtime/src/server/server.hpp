#ifndef _SERVER_SERVER_HPP_
#define _SERVER_SERVER_HPP_

#include "server/iserver.hpp"
#include "server/isessionManager.hpp"
#include "server/iserviceHub.hpp"

#include "pgc/db.hpp"

namespace server
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	class Server
		: public IServer
		, public boost::enable_shared_from_this<Server>
	{
		pluma::Pluma *_plugs;
		async::Service		_asrv;
		ISessionManagerPtr	_sessionManager;
		IServiceHubPtr		_serviceHub;

		pgc::Db				_db;

		size_t				_numThreads;
		boost::mutex		_mtx;


		enum EState
		{
			esStop,
			esStart,
			esError,
		}					_state;
		condition_variable	_isStartedCvar;

	private:
		void startup(const char *host, const char *service);
		void shutdown();

		void onSessionStart(ISessionPtr session);
		void onSessionStop(ISessionPtr session);

		void onDbConnectionMade(size_t numConnections);
		void onDbConnectionLost(size_t numConnections);

	public:
		Server();
		~Server();

		virtual bool start(pluma::Pluma *plugs, const char *host, const char *service);
		virtual void stop();
		virtual pluma::Pluma * getPlugs();
		virtual pgc::Db getDb();
	};
	PLUMA_INHERIT_PROVIDER(Server, IServer);
}
#endif
