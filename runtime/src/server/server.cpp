#include "pch.h"
#include "server.hpp"
#include "async/iservice.hpp"



namespace server
{


	//////////////////////////////////////////////////////////////////////////
	void Server::onSessionStart(ISessionPtr session)
	{
		_serviceHub->addSession(session);
	}

	//////////////////////////////////////////////////////////////////////////
	void Server::onSessionStop(ISessionPtr session)
	{
		_serviceHub->delSession(session);
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
		//������� ����������� ����
		_async = _plugs->create<async::IServiceProvider>();
		assert(_async);
		_async->balance(4);

		//////////////////////////////////////////////////////////////////////////
		//������� ���������
		net::IConnectorPtr connector = _plugs->create<net::IConnectorProvider>();
		assert(connector);
		connector->initialize(_async);

		//////////////////////////////////////////////////////////////////////////
		//������� �������� ������
		assert(!_sessionManager);
		_sessionManager = _plugs->create<ISessionManagerProvider>();
		assert(_sessionManager);
		_sessionManager->start(connector, host, service, 
			bind(&Server::onSessionStart, shared_from_this(), _1),
			bind(&Server::onSessionStop, shared_from_this(), _1));

		//////////////////////////////////////////////////////////////////////////
		//������� ��� �����
		assert(!_serviceHub);
		_serviceHub = _plugs->create<IServiceHubProvider>();
		assert(_serviceHub);

		//////////////////////////////////////////////////////////////////////////
		//�������� ������
		std::vector<IServicePtr> services;
		_plugs->createAll<IServiceProvider>(services);
		BOOST_FOREACH(IServicePtr &s, services)
		{
			_serviceHub->addService(s);
		}

		//��������� ����������� ����
		_async->balance(4);
	}

	//////////////////////////////////////////////////////////////////////////
	void Server::stop()
	{
		assert(_serviceHub);
		_serviceHub->delServices();

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
