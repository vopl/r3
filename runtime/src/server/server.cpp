#include "pch.hpp"
#include "server.hpp"
#include "async/service.hpp"
#include "server/inode.hpp"


namespace server
{

	//////////////////////////////////////////////////////////////////////////
	void Server::startup(const char *host, const char *service)
	{
		mutex::scoped_lock sl(_mtx);
		assert(esStop == _state);

		//////////////////////////////////////////////////////////////////////////
		//поднять коннектор базы
		assert(!_db);
		_db = pgc::Db(
			"host=localhost port=5432 dbname=test user=test password=test",
			20,
			bind(&Server::onDbConnectionMade, shared_from_this(), _1),
			bind(&Server::onDbConnectionLost, shared_from_this(), _1));

		//////////////////////////////////////////////////////////////////////////
		//поднять сетевой акцептор
		net::IAcceptorPtr acceptor = _plugs->create<net::IAcceptorProvider>();
		assert(acceptor);
		if(!acceptor)
		{
			FLOG("failed to create net acceptor");
			_state = esError;
			return;
		}


		//////////////////////////////////////////////////////////////////////////
		//поднять менеджер сессий
		assert(!_sessionManager);
		_sessionManager = _plugs->create<ISessionManagerProvider>();
		assert(_sessionManager);
		if(!_sessionManager)
		{
			FLOG("failed to create session manager");
			_state = esError;
			return;
		}
		_sessionManager->start(acceptor, host, service, 
			bind(&Server::onSessionStart, shared_from_this(), _1),
			bind(&Server::onSessionStop, shared_from_this(), _1));

		//////////////////////////////////////////////////////////////////////////
		//поднять хаб служб
		assert(!_nodeManager);
		_nodeManager = _plugs->create<INodeManagerProvider>();
		assert(_nodeManager);
		if(!_nodeManager)
		{
			FLOG("failed to create node manager");
			_state = esError;
			return;
		}
		_nodeManager->setServer(shared_from_this());

		//////////////////////////////////////////////////////////////////////////
		//набавить службы
		std::vector<INodePtr> nodes;
		_plugs->createAll<INodeProvider>(nodes);
		BOOST_FOREACH(INodePtr &n, nodes)
		{
			if(enfService & n->getFlags())
			{
				ILOG("add service node: "<<n->getId());
				_nodeManager->addNode(n);
			}
		}

		_state = esStart;
		_isStartedCvar.notify_one();
	}

	//////////////////////////////////////////////////////////////////////////
	void Server::shutdown()
	{
		mutex::scoped_lock sl(_mtx);
		assert(esStart == _state);

		_asrv.cancelAllTimeouts();

		assert(_nodeManager);
		_nodeManager->delNodes();

		_asrv.cancelAllTimeouts();
		assert(_sessionManager);
		_sessionManager->stop();

		_asrv.cancelAllTimeouts();
		assert(_db);
		_db.reset();

		_asrv.cancelAllTimeouts();
		_nodeManager.reset();
		_sessionManager.reset();

		_asrv.cancelAllTimeouts();
		_state = esStop;
		_isStartedCvar.notify_one();
	}


	//////////////////////////////////////////////////////////////////////////
	void Server::onSessionStart(ISessionPtr session)
	{
		ILOG("session start");
		_nodeManager->addSession(session);
	}

	//////////////////////////////////////////////////////////////////////////
	void Server::onSessionStop(ISessionPtr session)
	{
		ILOG("session stop");
		_nodeManager->delSession(session);
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
		//поднять асинхронный двиг
		_asrv = async::Service(false);
		assert(_asrv);
		if(!_asrv)
		{
			FLOG("failed to create async instance");
			return false;
		}

		//запускать асинхронный двиг
		_asrv.start(
			//1);
			boost::thread::hardware_concurrency());

		//родить запускалку в асинхронной среде
		_asrv.spawn(bind(&Server::startup, shared_from_this(), host, service));

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
		ILOG("start done");

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	void Server::stop()
	{
		mutex::scoped_lock sl(_mtx);
		assert(esStart == _state || esStop == _state);
		if(esStop == _state)
		{
			ILOG("stop when already stopped, ok");
			return;
		}

		ILOG("stop");

		_asrv.spawn(bind(&Server::shutdown, shared_from_this()));

		while(esStop != _state)
		{
			_isStartedCvar.wait(sl);
		}
		assert(esStop == _state);

		_asrv.stop();
		_asrv.reset();
		_plugs = NULL;

		ILOG("stop done");
	}

	//////////////////////////////////////////////////////////////////////////
	pluma::Pluma *Server::getPlugs()
	{
		return _plugs;
	}

	//////////////////////////////////////////////////////////////////////////
	pgc::Db Server::getDb()
	{
		return _db;
	}


}
