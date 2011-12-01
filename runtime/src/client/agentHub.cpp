#include "pch.h"
#include "agentHub.hpp"

namespace client
{
	//////////////////////////////////////////////////////////////////////////
	void AgentHub::onReceiveOk(const net::SPacket &p)
	{
		mutex::scoped_lock sl(_mtx);

		//���������� �����, ����� ������ � �������� ���
		assert(0);

		//������� ������ ������
		assert(_session);
		if(_session)
		{
			_session->receive(
				bind(&AgentHub::onReceiveOk, shared_from_this(), _1),
				bind(&AgentHub::onReceiveFail, shared_from_this(), _1));
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void AgentHub::onReceiveFail(system::error_code ec)
	{
		//��������� ��������, ��� � �������?
		//���� ������ �� �������� ������ ������� - �� ������ �� ������ ���������, ���� ������������ ��� ������
		//� ���� ������� - �� ������� ������ ��� ���� ������ delSession

		//��� ��� �������
		//session->close();
		//delSession(session);
	}

	//////////////////////////////////////////////////////////////////////////
	void AgentHub::onSendOk()
	{
		//������
		//assert(0);
	}
	
	//////////////////////////////////////////////////////////////////////////
	void AgentHub::onSendFail(system::error_code ec)
	{
		//������ �� ������ ����
		assert(0);
	}


	//////////////////////////////////////////////////////////////////////////
	AgentHub::AgentHub()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	AgentHub::~AgentHub()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void AgentHub::initialize(ISessionPtr session)
	{
		{
			mutex::scoped_lock sl(_mtx);
			_session = session;
			_session->receive(
				bind(&AgentHub::onReceiveOk, shared_from_this(), _1),
				bind(&AgentHub::onReceiveFail, shared_from_this(), _1));
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void AgentHub::deinitialize()
	{

		{
			mutex::scoped_lock sl(_mtx);
			_session.reset();

 			//���� �������� �������������, � ���?
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void AgentHub::addAgent(IAgentPtr agent)
	{
		mutex::scoped_lock sl(_mtx);

		TMAgentsBwd::iterator iter = _agentsBwd.find(agent);
		if(_agentsBwd.end() == iter)
		{
			TEndpoint endpoint = _endpointGenerator();
			while(_agentsFwd.end() != _agentsFwd.find(endpoint))
			{
				endpoint = _endpointGenerator();
			}

			_agentsFwd[endpoint] = agent;
			_agentsBwd[agent] = endpoint;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void AgentHub::delAgent(IAgentPtr agent)
	{
		mutex::scoped_lock sl(_mtx);
		TMAgentsBwd::iterator iter = _agentsBwd.find(agent);
		if(_agentsBwd.end() != iter)
		{
			_agentsFwd.erase(iter->second);
			_agentsBwd.erase(iter);
		}
	}


	//////////////////////////////////////////////////////////////////////////
	void AgentHub::send(
		IAgentPtr agent,
		const server::TEndpoint &endpoint,
		utils::VariantPtr data)
	{
		mutex::scoped_lock sl(_mtx);

		TMAgentsBwd::iterator iter = _agentsBwd.find(agent);
		if(_agentsBwd.end() != iter)
		{
			//���������� ������
			utils::Variant v;
			utils::Variant::MapStringVariant &m = v.as<utils::Variant::MapStringVariant>(true);
			m["server::endpoint"] = endpoint;
			m["client::endpoint"] = iter->second;
			m["data"] = data;

			net::SPacket p;
			p._data = v.save(p._size);

			//��������
			_session->send(p, 
				bind(&AgentHub::onSendOk, shared_from_this()),
				bind(&AgentHub::onSendFail, shared_from_this(), _1));
		}
	}
}
