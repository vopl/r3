#include "pch.h"
#include "serviceHub.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::onReceiveOk(ISessionPtr session, const net::SPacket &p)
	{

		//слушать сессию дальше
		session->receive(
			bind(&ServiceHub::onReceiveOk, shared_from_this(), session, _1),
			bind(&ServiceHub::onReceiveFail, shared_from_this(), session, _1));

		//а этот пакет просунуть в сервис
		server::TEndpoint serverEndpoint_;
		client::TEndpoint clientEndpoint_;
		utils::VariantPtr data_;
		IServicePtr service_;
		bool serverEndpointExists = false;
		bool clientEndpointExists = false;
		bool dataExists = false;

		{
			//распарсить пакет, найти службу и передать ей
			utils::Variant v;
			if(	v.deserialize(p._data, p._size) &&
				v.is<utils::Variant::MapStringVariant>())
			{
				utils::Variant::MapStringVariant &m = v.as<utils::Variant::MapStringVariant>();
				utils::Variant serverEndpoint = m["server::endpoint"];

				if(serverEndpoint.is<TEndpoint>())
				{
					serverEndpoint_ = serverEndpoint.as<TEndpoint>();
					serverEndpointExists = true;
					{
						mutex::scoped_lock sl(_mtx);
						TMServices::iterator iter = _services.find(serverEndpoint_);
						if(_services.end() != iter)
						{
							service_ = iter->second;
						}
					}

					utils::Variant clientEndpoint = m["client::endpoint"];
					if(	clientEndpoint.is<client::TEndpoint>())
					{
						clientEndpoint_ = clientEndpoint.as<client::TEndpoint>();
						clientEndpointExists = true;
					}

					utils::Variant data = m["data"];
					if(data.is<utils::VariantPtr>())
					{
						data_ = data.as<utils::VariantPtr>();
						dataExists = true;
					}
				}
			}
		}


		if(service_ && dataExists && clientEndpointExists)
		{
			service_->onReceive(
				shared_from_this(),
				session,
				clientEndpoint_,
				data_);
		}
		else
		{
			//assert(!"log error?");

			if(clientEndpointExists && serverEndpointExists)
			{
				//запаковать данные
				utils::Variant v;
				utils::Variant::MapStringVariant &m = v.as<utils::Variant::MapStringVariant>(true);
				m["server::endpoint"] = serverEndpoint_;
				m["client::endpoint"] = clientEndpoint_;
				m["error"] = "badRequest";

				net::SPacket p;
				p._data = v.serialize(p._size);

				//отослать
				session->send(p, 
					bind(&ServiceHub::onSendOk, shared_from_this(), session),
					bind(&ServiceHub::onSendFail, shared_from_this(), session, _1));
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::onSendOk(ISessionPtr session)
	{
		//ok
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::onSendFail(ISessionPtr session, system::error_code ec)
	{
		//assert(!"log error?");
	}


	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::onReceiveFail(ISessionPtr session, system::error_code ec)
	{
		//нештатная ситуация, что с сессией?
		//если просто не осталось низких каналов - то ошибка не должна приходить, надо переработать хаб канала
		//а если закрыта - то сначало должен был быть вызван delSession

		//уже все закрыто
		//session->close();
		//delSession(session);
	}

	//////////////////////////////////////////////////////////////////////////
	ServiceHub::ServiceHub()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ServiceHub::~ServiceHub()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::setServer(IServerPtr server)
	{
		_server = server;
	}

	//////////////////////////////////////////////////////////////////////////
	IServerPtr ServiceHub::getServer()
	{
		return _server;
	}


	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::addSession(ISessionPtr session)
	{
		{
			mutex::scoped_lock sl(_mtx);
			session->receive(
				bind(&ServiceHub::onReceiveOk, shared_from_this(), session, _1),
				bind(&ServiceHub::onReceiveFail, shared_from_this(), session, _1));

			//оповестить службы
			BOOST_FOREACH(TMServices::value_type &pair, _services)
			{
				pair.second->onSessionAdd(session);
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::delSession(ISessionPtr session)
	{

		{
			mutex::scoped_lock sl(_mtx);

			//оповестить службы
			BOOST_FOREACH(TMServices::value_type &pair, _services)
			{
				pair.second->onSessionDel(session);
			}

 			//надо отменить прослушивание, а как?
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::addService(IServicePtr service)
	{
		bool isOk = false;
		{
			mutex::scoped_lock sl(_mtx);
			if(_services.end() == _services.find(service->getEndpoint()))
			{
				_services[service->getEndpoint()] = service;
				isOk = true;
			}
		}
		if(isOk)
		{
			service->onHubAdd(shared_from_this());
		}
	}

	IServicePtr ServiceHub::getService(const TEndpoint &endpoint)
	{
		mutex::scoped_lock sl(_mtx);
		TMServices::iterator iter = _services.find(endpoint);
		if(_services.end() != iter)
		{
			return iter->second;
		}
		return IServicePtr();
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::delService(IServicePtr service)
	{
		bool isOk = false;
		{
			mutex::scoped_lock sl(_mtx);
			TMServices::iterator iter = _services.find(service->getEndpoint());
			if(_services.end() != iter)
			{
				_services.erase(iter);
				isOk = true;
			}
		}

		if(isOk)
		{
			service->onHubDel(shared_from_this());
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::delServices()
	{
		mutex::scoped_lock sl(_mtx);
		BOOST_FOREACH(TMServices::value_type &p, _services)
		{
			p.second->onHubDel(shared_from_this());
		}
		_services.clear();
	}


	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::send(
		IServicePtr service,
		ISessionPtr session,
		const client::TEndpoint &endpoint,
		utils::VariantPtr data,
		boost::function<void ()> ok,
		boost::function<void (boost::system::error_code)> fail)
	{
		//запаковать данные
		utils::Variant v;
		utils::Variant::MapStringVariant &m = v.as<utils::Variant::MapStringVariant>(true);
		m["server::endpoint"] = service->getEndpoint();
		m["client::endpoint"] = endpoint;
		m["data"] = data;

		net::SPacket p;
		p._data = v.serialize(p._size);

		//отослать
		session->send(p, 
			ok,
			fail);
	}
}
