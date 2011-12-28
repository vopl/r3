#include "pch.h"
#include "session.hpp"

namespace client
{
	//////////////////////////////////////////////////////////////////////////
	void Session::onReceive(const boost::system::error_code &ec, const SPacket &p)
	{
		if(ec)
		{
			mutex::scoped_lock sl(_mtx);
			if(!_channelHub)
			{
				return;
			}
			WLOG("receive failed: "<<ec.message()<<"("<<ec.value()<<")");
			return;
		}

		utils::Variant v = p;
		if(!v["error"].isNull())
		{
			ELOG("error from service: "<<v["error"]);
			return;
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

	//////////////////////////////////////////////////////////////////////////
	Session::Session(const TClientSid sid)
		: _sid(sid)
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

		if(!_channelHub)
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
			_channelHub->close();
			_channelHub.reset();
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
		mutex::scoped_lock sl(_mtx);
		if(!_channelHub)
		{
			_channelHub.reset(new ChannelHub<IChannel>);
			_channelHub->listen(bind(&Session::onReceive, shared_from_this(), _1, _2));
		}

		bool res = _channelHub->attachChannel(channel);
		if(!res)
		{
			return res;
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

	//////////////////////////////////////////////////////////////////////////
	Result<error_code> Session::send(net::SPacket p)
	{
		return _channelHub->send(p);
	}


}
