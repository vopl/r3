#include "pch.h"
#include "serviceHub.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::onReceiveOk(ISessionPtr session, const net::SPacket &p)
	{
		mutex::scoped_lock sl(_mtx);

		//распарсить пакет, найти службу и передать ей
		assert(0);

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
		const TEndpoint &endpoint,
		utils::VariantPtr data,
		boost::function<void ()> ok,
		boost::function<void (boost::system::error_code)> fail)
	{
		//запаковать данные
		//отослать
		assert(0);
	}
}
