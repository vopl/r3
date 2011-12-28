#include "pch.h"
#include "session.hpp"
#include "client.hpp"

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
		{
			mutex::scoped_lock sl(_mtx);
			TMAgents::iterator iter = _agents.find(endpoint);
			if(_agents.end() != iter)
			{
				iter->second->onReceive(v["server::endpoint"], v["data"]);
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void Session::balanceChannels()
	{
		bool doAdd;
		{
			mutex::scoped_lock sl(_mtx);
			if(_connectInProgress)
			{
				return;
			}
			if(_channelHub->getChannelsAmount() == _needNumChannels)
			{
				return;
			}

			doAdd = _channelHub->getChannelsAmount() < _needNumChannels;

			_connectInProgress = true;
		}

		if(doAdd)
		{
			Result2<error_code, ISessionPtr> res =
				_client->connectSession(shared_from_this(), _host, _service);

			if(res.data1())
			{
				mutex::scoped_lock sl(_mtx);
				_connectInProgress = false;
				spawn(bind(&Session::balanceChannels, shared_from_this()));
				return;
			}
		}


		{
			mutex::scoped_lock sl(_mtx);
			_connectInProgress = false;
		}
		spawn(bind(&Session::balanceChannels, shared_from_this()));
	}


	//////////////////////////////////////////////////////////////////////////
	Session::Session(
		const TClientSid sid, 
		ClientPtr client, 
		const std::string &host, 
		const std::string &service)
		: _sid(sid)
		, _needNumChannels(1)
		, _client(client)
		, _host(host)
		, _service(service)
		, _connectInProgress(false)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Session::~Session()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void Session::watchState(const function<void(error_code, size_t)> &onStateChanged)
	{
		assert(_channelHub);
		spawn(bind(onStateChanged, error_code(), _channelHub->getChannelsAmount()));
		return _channelHub->watchState(onStateChanged);
	}

	//////////////////////////////////////////////////////////////////////////
	void Session::balance(size_t numChannels)
	{
		{
			mutex::scoped_lock sl(_mtx);
			_needNumChannels = numChannels;
		}

		spawn(bind(&Session::balanceChannels, shared_from_this()));
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Session::getNumChannels()
	{
		mutex::scoped_lock sl(_mtx);
		return _channelHub->getChannelsAmount();
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
			_needNumChannels = 0;
		}

		BOOST_FOREACH(TMAgents::value_type &el, agents)
		{
			el.second->close();
		}
		_client.reset();
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
