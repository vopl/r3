#include "pch.h"
#include "session.hpp"

namespace client
{
	//////////////////////////////////////////////////////////////////////////
	SessionPtr Session::shared_from_this()
	{
		return static_pointer_cast<Session>(Base::shared_from_this());
	}

	//////////////////////////////////////////////////////////////////////////
	void Session::receiveLoop_f()
	{
		for(;;)
		{
			Result2<error_code, SPacket> res = Base::receive();
			res.wait();

			error_code ec = res.data1();
			if(ec)
			{
				mutex::scoped_lock sl(_mtx);
				if(_closed)
				{
					return;
				}
				WLOG("receive failed: "<<ec.message()<<"("<<ec.value()<<")");
				continue;
			}

			utils::Variant v = res.data2();
			if(!v["error"].isNull())
			{
				ELOG("error from service: "<<v["error"]);
				continue;
			}

			TEndpoint endpoint = v["client::endpoint"];
			Agent *agent = NULL;
			{
				mutex::scoped_lock sl(_mtx);
				TMAgents::iterator iter = _agents.find(endpoint);
				if(_agents.end() != iter)
				{
					agent = iter->second;
				}
			}

			agent->onReceive(v["server::endpoint"], v["data"]);


		}
	}

	//////////////////////////////////////////////////////////////////////////
	Session::Session(const TClientSid sid)
		: _sid(sid)
		, _closed(true)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Session::~Session()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	Result2<error_code, size_t> Session::watchState()
	{
		assert(0);
		Result2<error_code, size_t> res;
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	void Session::balance(size_t numChannels)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	TClientSid Session::sid()
	{
		return _sid;
	}

	//////////////////////////////////////////////////////////////////////////
	IAgentPtr Session::allocAgent()
	{
		mutex::scoped_lock sl(_mtx);

		if(_closed)
		{
			assert(0);
			return IAgentPtr();
		}

		TEndpoint endpoint = _endpointGenerator();
		while(_agents.end() != _agents.find(endpoint))
		{
			endpoint = _endpointGenerator();
		}
		AgentPtr agent(new Agent(shared_from_this(), endpoint));

		_agents[endpoint] = agent.get();

		return agent;
	}

	//////////////////////////////////////////////////////////////////////////
	void Session::close()
	{
		TMAgents agents;
		{
			mutex::scoped_lock sl(_mtx);
			_closed = true;
			Base::close();
			agents.swap(_agents);
		}

		BOOST_FOREACH(TMAgents::value_type &el, agents)
		{
			el.second->close();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	bool Session::attachChannel(IChannelPtr channel)
	{
		bool res = Base::attachChannel(channel);
		if(!res)
		{
			return res;
		}
		mutex::scoped_lock sl(_mtx);
		if(_closed)
		{
			_closed = false;
			spawn(bind(&Session::receiveLoop_f, shared_from_this()));
		}

		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	void Session::freeAgent(const TEndpoint &endpoint)
	{
		mutex::scoped_lock sl(_mtx);
		TMAgents::iterator iter = _agents.find(endpoint);
		assert(_agents.end() != iter);

		if(_agents.end() != iter)
		{
			_agents.erase(iter);
		}
	}

}
