#include "pch.h"
#include "serviceHub.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::onReceiveOk(ISessionPtr session, const net::SPacket &p)
	{
		mutex::scoped_lock sl(_mtx);

		//распарсить пакет, найти службу и передать ей
		bool packetOk = false;
		utils::Variant v;
		if(	v.load(p._data, p._size) &&
			v.is<utils::Variant::MapStringVariant>())
		{
			utils::Variant::MapStringVariant &m = v.as<utils::Variant::MapStringVariant>();
			utils::Variant endpoint = m["server::endpoint"];

			if(endpoint.is<TEndpoint>())
			{
				TMServices::iterator iter = _services.find(endpoint);
				if(_services.end() != iter)
				{
					utils::Variant clientEndpoint = m["client::endpoint"];
					utils::Variant data = m["data"];
					if(	clientEndpoint.is<client::TEndpoint>() &&
						data.is<utils::VariantPtr>())
					{
						packetOk = true;
						iter->second->onReceive(
							shared_from_this(),
							session,
							clientEndpoint.as<client::TEndpoint>(),
							data.as<utils::VariantPtr>());
					}
				}
			}
		}

		if(!packetOk)
		{
			//assert(!"ничего не слать");
		}

		//слушать сессию дальше
		session->receive(
			bind(&ServiceHub::onReceiveOk, shared_from_this(), session, _1),
			bind(&ServiceHub::onReceiveFail, shared_from_this(), session, _1));
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
		mutex::scoped_lock sl(_mtx);
		if(_services.end() == _services.find(service->getEndpoint()))
		{
			_services[service->getEndpoint()] = service;
			service->onHubAdd(shared_from_this());
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::delService(IServicePtr service)
	{
		mutex::scoped_lock sl(_mtx);
		TMServices::iterator iter = _services.find(service->getEndpoint());
		if(_services.end() != iter)
		{
			service->onHubDel(shared_from_this());
			_services.erase(iter);
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
		p._data = v.save(p._size);

		//отослать
		session->send(p, 
			ok,
			fail);
	}
}
