#include "pch.h"
#include "server.hpp"
#include "async/iservice.hpp"



namespace server
{


	//////////////////////////////////////////////////////////////////////////
	void Server::onSessionStart(ISessionPtr session)
	{
		ILOG("sessin start");
		_serviceHub->addSession(session);
	}

	//////////////////////////////////////////////////////////////////////////
	void Server::onSessionStop(ISessionPtr session)
	{
		ILOG("sessin stop");
		_serviceHub->delSession(session);
	}

	//////////////////////////////////////////////////////////////////////////
	void Server::onDbConnectionMade(size_t numConnections)
	{
		ILOG("database connection made");
	}

	//////////////////////////////////////////////////////////////////////////
	void Server::onDbConnectionLost(size_t numConnections)
	{
		ILOG("database connection lost");
	}




	//////////////////////////////////////////////////////////////////////////
	Server::Server()
		: _plugs(NULL)
	{

	}
	
	//////////////////////////////////////////////////////////////////////////
	Server::~Server()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	bool Server::start(pluma::Pluma *plugs, const char *host, const char *service)
	{
		ILOG("start");

		assert(!_plugs);
		_plugs = plugs;

		//////////////////////////////////////////////////////////////////////////
		//поднять асинхронный двиг
		_async = _plugs->create<async::IServiceProvider>();
		assert(_async);
		if(!_async)
		{
			FLOG("failed to create async instance");
			return false;
		}


		//////////////////////////////////////////////////////////////////////////
		//поднять коннектор базы
		assert(!_db);
		_db = _plugs->create<pgc::IDbProvider>();
		assert(_db);
		if(!_db)
		{
			FLOG("failed to create db instance");
			return false;
		}

		_db->initialize(
			_async, 
			"host=localhost port=5432 dbname=test user=test password=test",
			4,
			bind(&Server::onDbConnectionMade, shared_from_this(), _1),
			bind(&Server::onDbConnectionLost, shared_from_this(), _1));

		//////////////////////////////////////////////////////////////////////////
		//поднять сетевой коннектор
		net::IConnectorPtr connector = _plugs->create<net::IConnectorProvider>();
		assert(connector);
		if(!connector)
		{
			FLOG("failed to create net connector");
			return false;
		}

		connector->initialize(_async);

		//////////////////////////////////////////////////////////////////////////
		//поднять менеджер сессий
		assert(!_sessionManager);
		_sessionManager = _plugs->create<ISessionManagerProvider>();
		assert(_sessionManager);
		if(!_sessionManager)
		{
			FLOG("failed to create session manager");
			return false;
		}
		_sessionManager->start(connector, host, service, 
			bind(&Server::onSessionStart, shared_from_this(), _1),
			bind(&Server::onSessionStop, shared_from_this(), _1));

		//////////////////////////////////////////////////////////////////////////
		//поднять хаб служб
		assert(!_serviceHub);
		_serviceHub = _plugs->create<IServiceHubProvider>();
		assert(_serviceHub);
		if(!_serviceHub)
		{
			FLOG("failed to create service hub");
			return false;
		}
		_serviceHub->setServer(shared_from_this());

		//////////////////////////////////////////////////////////////////////////
		//набавить службы
		std::vector<IServicePtr> services;
		_plugs->createAll<IServiceProvider>(services);
		BOOST_FOREACH(IServicePtr &s, services)
		{
			_serviceHub->addService(s);
		}


		//запускать асинхронный двиг
		_async->start(boost::thread::hardware_concurrency()*2);

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	void Server::stop()
	{
		ILOG("stop");
		assert(_serviceHub);
		_serviceHub->delServices();

		assert(_sessionManager);
		_sessionManager->stop();


		assert(_db);
		_db->deinitialize();

		_async->stop();


		_serviceHub.reset();
		_sessionManager.reset();
		_db.reset();
		_async.reset();
		
		_plugs = NULL;
	}

	//////////////////////////////////////////////////////////////////////////
	pluma::Pluma *Server::getPlugs()
	{
		return _plugs;
	}

	//////////////////////////////////////////////////////////////////////////
	async::IServicePtr Server::getAsync()
	{
		return _async;
	}

	//////////////////////////////////////////////////////////////////////////
	pgc::IDbPtr Server::getDb()
	{
		return _db;
	}


}
