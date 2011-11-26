#include "pch.h"
#include "clientSession.hpp"
#include <boost/bind.hpp>
#include "utils/variant.hpp"

//#define LF 		std::cerr<<__FUNCTION__ "\n";std::cerr.flush();
#define LF

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	void ClientSession::checkbalance()
	{
		LF;
		//уже заблокировано
		//mutex::scoped_lock sl(_mtx);
		assert(_isStarted);

		if(_needNumChannels > getChannelsAmount() && !_waitConnections)
		{
			_connector->connect(
				_host.c_str(), _service.c_str(), 
				bind(&ClientSession::onConnectOk, shared_from_this(), _1),
				bind(&ClientSession::onConnectError, shared_from_this(), _1));
			_waitConnections++;
		}

		if(_needNumChannels < getChannelsAmount())
		{
			//закрыть один когда не будет трафика
			assert(0);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSession::onConnectOk(IChannelPtr channel)
	{
		LF;
		mutex::scoped_lock sl(_mtx);
		if(!_isStarted)
		{
			channel->close();
			return;
		}

		utils::Variant v;
		v.as<utils::Variant::MapStringVariant>(true)["sid"] = _needSid;

		SPacket packet;
		packet._data = v.save(packet._size);

		//послать сид
		channel->send(
			packet, 
			bind(&ClientSession::onSendSidOk, shared_from_this(), channel),
			bind(&ClientSession::onSendSidFail, shared_from_this(), channel, _1));
		
		_waitConnectionsChannels.insert(channel);
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSession::onConnectError(system::error_code ec)
	{
		LF;
		mutex::scoped_lock sl(_mtx);
		if(!_isStarted)
		{
			return;
		}
		//assert(!"log error?");
		_waitConnections--;
		checkbalance();
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSession::onSendSidOk(IChannelPtr channel)
	{
		LF;
		mutex::scoped_lock sl(_mtx);
		if(!_isStarted)
		{
			channel->close();
			return;
		}
		//принять сид
		channel->receive(
			bind(&ClientSession::onReceiveSidOk, shared_from_this(), channel, _1),
			bind(&ClientSession::onReceiveSidFail, shared_from_this(), channel, _1));
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSession::onSendSidFail(IChannelPtr channel, system::error_code ec)
	{
		LF;
		channel->close();

		{
			mutex::scoped_lock sl(_mtx);
			if(!_isStarted)
			{
				return;
			}

			assert(!"log error?");
			_waitConnections--;
			_waitConnectionsChannels.erase(channel);
			channel->close();
			checkbalance();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSession::onReceiveSidOk(IChannelPtr channel, const SPacket &packet)
	{
		LF;
		mutex::scoped_lock sl(_mtx);
		if(!_isStarted)
		{
			channel->close();
			return;
		}

		utils::Variant v;
		if(	!v.load(packet._data, packet._size) || 
			!v.is<utils::Variant::MapStringVariant>())
		{
			//bad packet

			assert(!"log error?");
			channel->close();

			_waitConnections--;
			checkbalance();
			return;
		}

		utils::Variant::MapStringVariant &msv = v.as<utils::Variant::MapStringVariant>();

		if(msv.end() != msv.find("badSid"))
		{
			//сессия утеряня, поднять новую
			assert(!"sid lost!");
			_needSid = nullClientSid;
			_waitConnectionsChannels.erase(channel);
			onConnectOk(channel);
			return;
		}
		else if(msv.end() != msv.find("sid") && msv["sid"].is<TClientSid>())
		{
			size_t channels;
			{
				_sid = msv["sid"];
				_needSid = msv["sid"];

				attachChannel(channel);
				channels = getChannelsAmount();

				_waitConnectionsChannels.erase(channel);
				_waitConnections--;
				checkbalance();
			}
			_ready(channels);
		}
		else
		{
			assert(!"packet out of format");
			_waitConnectionsChannels.erase(channel);
			channel->close();
			_waitConnections--;
			checkbalance();
			return;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSession::onReceiveSidFail(IChannelPtr channel, system::error_code ec)
	{
		LF;
		channel->close();

		{
			mutex::scoped_lock sl(_mtx);
			if(!_isStarted)
			{
				return;
			}

			//assert(!"log error?");
			_waitConnectionsChannels.erase(channel);
			channel->close();
			_waitConnections--;
			checkbalance();
		}
	}


	//////////////////////////////////////////////////////////////////////////
	ClientSessionPtr ClientSession::shared_from_this()
	{
		return static_pointer_cast<ClientSession>(ChannelHub<IClientSession>::shared_from_this());
	}


	//////////////////////////////////////////////////////////////////////////
	ClientSession::ClientSession()
		: _connector()
		, _host()
		, _service()
		, _isStarted(false)
		, _sid(nullClientSid)
		, _needSid(nullClientSid)
		, _needNumChannels(0)
		, _waitConnections(0)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSession::start(
		IConnectorPtr connector,
		const char *host, const char *service,
		TClientSid sid, 
		size_t numChannels,
		boost::function<void (size_t)> ready,
		boost::function<void (size_t, system::error_code)> fail)
	{
		assert(!_connector && _host.empty() && _service.empty());
		_connector = connector;
		_host = host;
		_service = service;

		mutex::scoped_lock sl(_mtx);
		if(_isStarted)
		{
			close();
		}

		assert(!getChannelsAmount());

		assert(nullClientSid == _needSid);
		_needSid = sid;
		assert(nullClientSid == _sid);

		assert(!_needNumChannels);
		_needNumChannels = numChannels;

		assert(!_ready);
		_ready = ready;

		assert(!_fail);
		_fail = fail;

		assert(!_isStarted);
		_isStarted = true;

		assert(!_waitConnections);
		_waitConnections = 0;
		assert(_waitConnectionsChannels.empty());
		_waitConnectionsChannels.clear();

		checkbalance();
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSession::close()
	{
		mutex::scoped_lock sl(_mtx);
		if(!_isStarted)
		{
			return;
		}


		_needSid = nullClientSid;
		_sid = nullClientSid;

		_needNumChannels = 0;

		_ready = function<void (size_t)>();

		_fail = function<void (size_t, system::error_code)>();

		_isStarted = false;

		_waitConnections = 0;
		BOOST_FOREACH(IChannelPtr &c, _waitConnectionsChannels)
		{
			c->close();
		}
		_waitConnectionsChannels.clear();
		ChannelHub::close();

		_connector.reset();
		_host.clear();
		_service.clear();
	}
	
	//////////////////////////////////////////////////////////////////////////
	void ClientSession::stop()
	{
		return close();
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSession::balance(size_t numChannels)
	{
		mutex::scoped_lock sl(_mtx);
		if(!_isStarted)
		{
			return;
		}

		_needNumChannels = numChannels;
		checkbalance();
	}

	//////////////////////////////////////////////////////////////////////////
	TClientSid ClientSession::sid()
	{
		mutex::scoped_lock sl(_mtx);
		return _sid;
	}
}
