#include "pch.h"
#include "serviceHub.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::onReceive(const boost::system::error_code &ec, const net::SPacket &p, ISessionPtr session)
	{
		if(ec)
		{
			if(ec == errc::operation_canceled)
			{
				return;
			}

			assert(0);
			WLOG(__FUNCTION__<<", "<<ec.message()<<"("<<ec.value()<<")");
			return;
		}

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
// 			assert(!"log error?");

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

				//отослать без контроля
				session->send(p);
			}
		}
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

			//оповестить службы
			BOOST_FOREACH(TMServices::value_type &pair, _services)
			{
				pair.second->onSessionAdd(session);
			}
		}

		session->listen(bind(&ServiceHub::onReceive, shared_from_this(), _1, _2, session));
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
		}
		//надо отменить прослушивание, а как? да вот так
		session->close();
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
	async::Result<error_code> ServiceHub::send(
		IServicePtr service,
		ISessionPtr session,
		const client::TEndpoint &endpoint,
		utils::VariantPtr data)
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
		return session->send(p);
	}
}
