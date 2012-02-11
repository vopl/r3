#include "pch.hpp"
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
			if(!_channelHub || !_client)
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
			Future2<error_code, ISessionPtr> res =
				_client->connectSession(shared_from_this(), _host, _service);

			error_code ec = res.data1();
			if(ec)
			{
				if(ec == errc::owner_dead)
				{
					if(_onStateChanged)
					{
						spawn(bind(_onStateChanged, ec, _channelHub->getChannelsAmount()));
					}
					return;
				}

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
		//spawn(bind(&Session::balanceChannels, shared_from_this()));
	}

	//////////////////////////////////////////////////////////////////////////
	void Session::onStateChanged(const error_code &ec, size_t numChannels)
	{
		spawn(bind(&Session::balanceChannels, shared_from_this()));

		mutex::scoped_lock sl(_mtx);
		if(_onStateChanged)
		{
			spawn(bind(_onStateChanged, ec, numChannels));
		}
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
		assert(!_channelHub);
		assert(!_client);
		assert(!_needNumChannels);
		assert(!_connectInProgress);

	}

	//////////////////////////////////////////////////////////////////////////
	void Session::watchState(const function<void(error_code, size_t)> &onStateChanged)
	{
		mutex::scoped_lock sl(_mtx);

		_onStateChanged = onStateChanged;
		spawn(bind(onStateChanged, error_code(), _channelHub->getChannelsAmount()));
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
			if(_channelHub)
			{
				_channelHub->close();
				_channelHub.reset();
			}
			agents.swap(_agents);
			_needNumChannels = 0;

			boost::function<void(boost::system::error_code, size_t)>().swap(_onStateChanged);

			_connectInProgress = false;
			_client.reset();
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
		if(!_client)
		{
			channel->close();
			return false;
		}

		if(!_channelHub)
		{
			_channelHub.reset(new ChannelHub<IChannel>);
			_channelHub->listen(bind(&Session::onReceive, shared_from_this(), _1, _2));
			_channelHub->watchState(bind(&Session::onStateChanged, shared_from_this(), _1, _2));
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
	Future<error_code> Session::send(net::SPacket p)
	{
		return _channelHub->send(p);
	}


}
