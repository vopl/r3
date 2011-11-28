#include "pch.h"
#include "serviceHub.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::onReceiveOk(ISessionPtr session, const net::SPacket &p)
	{
		//����� ������, ���� ��� �� ��������� ��������
		mutex::scoped_lock sl(_mtx);
		if(_sessions.end() == _sessions.find(session->sid()))
		{
			assert(!"������ ����� �� ��������� ������, �� ������?");
			return;
		}
		//���������� �����, ����� ������ � �������� ��

		assert(0);

		session->receive(
			bind(&ServiceHub::onReceiveOk, shared_from_this(), session, _1),
			bind(&ServiceHub::onReceiveFail, shared_from_this(), session, _1));
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceHub::onReceiveFail(ISessionPtr session, system::error_code ec)
	{
		//��������� ��������, ��� � �������?
		//���� ������ �� �������� ������ ������� - �� ������ �� ������ ���������, ���� ������������ ��� ������
		//� ���� ������� - �� ������� ������ ��� ���� ������ delSession

		//??? ������������� ������� - �������� ���������� �� ������ ����� �����
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

			//���������� ������
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
			//���������� ������
			BOOST_FOREACH(TMServicesFwd::value_type &pair, _servicesFwd)
			{
				pair.second->onSessionDel(session);
			}

			_sessions.erase(session->sid());
			//���� �������� �������������, � ���?
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
		//��������� ������� ������ � ������
		//���������� ������
		//��������
		assert(0);
	}
}
