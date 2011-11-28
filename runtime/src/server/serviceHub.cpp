#include "pch.h"
#include "serviceHub.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::onReceiveOk(ISessionPtr session, const net::SPacket &p)
	{
		//найти сессию, если нет то нештатная ситуация
		mutex::scoped_lock sl(_mtx);
		if(_sessions.end() == _sessions.find(session->sid()))
		{
			assert(!"пришел пакет на удаленную сессию, че делать?");
			return;
		}
		//распарсить пакет, найти службу и передать ей

		assert(0);

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

		//??? универсальное решение - повесить перезапрос на таймер через время
		assert(0);
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
		mutex::scoped_lock sl(_mtx);
		if(_sessions.end() == _sessions.find(session->sid()))
		{
			_sessions[session->sid()] = session;
			session->receive(
				bind(&ServiceHub::onReceiveOk, shared_from_this(), session, _1),
				bind(&ServiceHub::onReceiveFail, shared_from_this(), session, _1));

			//оповестить службы
			BOOST_FOREACH(TMServicesFwd::value_type &pair, _servicesFwd)
			{
				pair.second->onSessionAdd(session);
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::delSession(ISessionPtr session)
	{
		mutex::scoped_lock sl(_mtx);

		TMSessions::iterator iter = _sessions.find(session->sid());
		if(_sessions.end() != iter)
		{
			//оповестить службы
			BOOST_FOREACH(TMServicesFwd::value_type &pair, _servicesFwd)
			{
				pair.second->onSessionDel(session);
			}

			_sessions.erase(session->sid());
			//надо отменить прослушивание, а как?
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::addService(IServicePtr service)
	{
		mutex::scoped_lock sl(_mtx);
		TEndpoint id = _endpointGenerator();
		while(_servicesFwd.end() != _servicesFwd.find(id))
		{
			id = _endpointGenerator();
		}
		_servicesFwd[id] = service;
		_servicesBwd[service] = id;
		service->onHubAdd(shared_from_this());
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::delService(IServicePtr service)
	{
		mutex::scoped_lock sl(_mtx);
		TMServicesBwd::iterator iter = _servicesBwd.find(service);
		if(_servicesBwd.end() != iter)
		{
			service->onHubDel(shared_from_this());
			_servicesFwd.erase(iter->second);
			_servicesBwd.erase(iter);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::send(
		IServicePtr service,
		ISessionPtr session,
		TEndpoint endpoint,
		utils::VariantPtr data,
		boost::function<void ()> ok,
		boost::function<void (boost::system::error_code)> fail)
	{
		//проверить наличие службы и сессии
		//запаковать данные
		//отослать
		assert(0);
	}
}
