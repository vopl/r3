#include "pch.h"
#include "server.hpp"
#include "async/iservice.hpp"



namespace server
{


	//////////////////////////////////////////////////////////////////////////
	void Server::onSsmOk(ISessionPtr session)
	{
		_serviceHub->addSession(session);
	}

	//////////////////////////////////////////////////////////////////////////
	void Server::onSsmFail(system::error_code ec)
	{
		assert(0);
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
	void Server::start(pluma::Pluma *plugs, const char *host, const char *service)
	{
		assert(!_plugs);
		_plugs = plugs;

		//////////////////////////////////////////////////////////////////////////
		//поднять асинхронный двиг
		_async = _plugs->create<async::IServiceProvider>();
		assert(_async);
		_async->balance(4);

		//////////////////////////////////////////////////////////////////////////
		//поднять коннектор
		net::IConnectorPtr connector = _plugs->create<net::IConnectorProvider>();
		assert(connector);
		connector->initialize(_async);

		//////////////////////////////////////////////////////////////////////////
		//поднять менеджер сессий
		assert(!_sessionManager);
		_sessionManager = _plugs->create<ISessionManagerProvider>();
		assert(_sessionManager);
		_sessionManager->start(connector, host, service, 
			bind(&Server::onSsmOk, shared_from_this(), _1),
			bind(&Server::onSsmFail, shared_from_this(), _1));

		//////////////////////////////////////////////////////////////////////////
		//поднять хаб служб
		assert(!_serviceHub);
		_serviceHub = _plugs->create<IServiceHubProvider>();
		assert(_serviceHub);

		//////////////////////////////////////////////////////////////////////////
		//набавить службы
		std::vector<IServicePtr> services;
		_plugs->createAll<IServiceProvider>(services);
		BOOST_FOREACH(IServicePtr &s, services)
		{
			_serviceHub->addService(s);
		}

		//запускать асинхронный двиг
		_async->balance(4);
	}

	//////////////////////////////////////////////////////////////////////////
	void Server::stop()
	{
		assert(_sessionManager);
		_sessionManager->stop();
		_sessionManager.reset();
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
	async::IServicePtr Server::getAsync()
	{
		return _async;
	}

}
