#include "pch.h"
#include "server.hpp"
#include "async/service.hpp"



namespace server
{

	//////////////////////////////////////////////////////////////////////////
	void Server::startup(const char *host, const char *service)
	{
		mutex::scoped_lock sl(_mtx);
		assert(esStop == _state);

		//////////////////////////////////////////////////////////////////////////
		//подн€ть коннектор базы
		assert(!_db);
		_db = _plugs->create<pgc::IDbProvider>();
		assert(_db);
		if(!_db)
		{
			FLOG("failed to create db instance");
			_state = esError;
			return;
		}

		_db->initialize(
			"host=localhost port=5432 dbname=test user=test password=test",
			4,
			bind(&Server::onDbConnectionMade, shared_from_this(), _1),
			bind(&Server::onDbConnectionLost, shared_from_this(), _1));

		//////////////////////////////////////////////////////////////////////////
		//подн€ть сетевой коннектор
		net::IConnectorPtr connector = _plugs->create<net::IConnectorProvider>();
		assert(connector);
		if(!connector)
		{
			FLOG("failed to create net connector");
			_state = esError;
			return;
		}

		connector->initialize();

		//////////////////////////////////////////////////////////////////////////
		//подн€ть менеджер сессий
		assert(!_sessionManager);
		_sessionManager = _plugs->create<ISessionManagerProvider>();
		assert(_sessionManager);
		if(!_sessionManager)
		{
			FLOG("failed to create session manager");
			_state = esError;
			return;
		}
		_sessionManager->start(connector, host, service, 
			bind(&Server::onSessionStart, shared_from_this(), _1),
			bind(&Server::onSessionStop, shared_from_this(), _1));

		//////////////////////////////////////////////////////////////////////////
		//подн€ть хаб служб
		assert(!_serviceHub);
		_serviceHub = _plugs->create<IServiceHubProvider>();
		assert(_serviceHub);
		if(!_serviceHub)
		{
			FLOG("failed to create service hub");
			_state = esError;
			return;
		}
		_serviceHub->setServer(shared_from_this());

		//////////////////////////////////////////////////////////////////////////
		//набавить службы
		std::vector<IServicePtr> services;
		_plugs->createAll<IServiceProvider>(services);
		BOOST_FOREACH(IServicePtr &s, services)
		{
			ILOG("add service "<<s->getEndpoint());
			_serviceHub->addService(s);
		}

		_state = esStart;
		_isStartedCvar.notify_one();
	}

	//////////////////////////////////////////////////////////////////////////
	void Server::shutdown()
	{
		mutex::scoped_lock sl(_mtx);
		_numThreads--;

		if(0 == _numThreads)
		{
			assert(_serviceHub);
			_serviceHub->delServices();
		}
	}


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
		, _numThreads(0)
		, _state(esStop)
	{
		ILOG("create");
	}
	
	//////////////////////////////////////////////////////////////////////////
	Server::~Server()
	{
		assert(esStop == _state);
		ILOG("destroy");
	}

	//////////////////////////////////////////////////////////////////////////
	bool Server::start(pluma::Pluma *plugs, const char *host, const char *service)
	{
		mutex::scoped_lock sl(_mtx);
		assert(esStart == _state || esStop == _state);
		if(esStart == _state)
		{
			ILOG("start when already started, ok");
			return true;
		}

		ILOG("start");

		assert(!_plugs);
		_plugs = plugs;

		//////////////////////////////////////////////////////////////////////////
		//подн€ть асинхронный двиг
		_async = async::createService();
		assert(_async);
		if(!_async)
		{
			FLOG("failed to create async instance");
			return false;
		}

		//запускать асинхронный двиг
		_async->start(
			boost::thread::hardware_concurrency());

		//родить запускалку в асинхронной среде
		_async->spawn(bind(&Server::startup, shared_from_this(), host, service));

		//ждать когда запускалка отработает
		while(esStop == _state)
		{
			_isStartedCvar.wait(sl);
		}
		if(esError == _state)
		{
			ELOG("start failed");
			return false;
		}
		assert(esStart == _state);
		ILOG("start ok");

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	void Server::stop()
	{
		assert(!"отработать стоп так же как старт");
		ILOG("stop");

		async::spawn(bind(&Server::shutdown, shared_from_this()));

		assert(_sessionManager);
		_sessionManager->stop();


		assert(_db);
		_db->deinitialize();


		_serviceHub.reset();
		_sessionManager.reset();
		_db.reset();

		_async->stop();
		_async.reset();
		
		_plugs = NULL;
	}

	//////////////////////////////////////////////////////////////////////////
	pluma::Pluma *Server::getPlugs()
	{
		return _plugs;
	}

	//////////////////////////////////////////////////////////////////////////
	pgc::IDbPtr Server::getDb()
	{
		return _db;
	}


}
