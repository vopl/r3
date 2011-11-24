#include "stdafx.h"
#include "clientSessionImpl.hpp"
#include <boost/bind.hpp>
#include "utils/variant.hpp"

//#define LF 		std::cerr<<__FUNCTION__ "\n";std::cerr.flush();
#define LF

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	void ClientSessionImpl::checkbalance()
	{
		LF;
		//уже заблокировано
		//mutex::scoped_lock sl(_mtx);
		assert(_isStarted);

		if(_needNumChannels > getChannelsAmount() && !_waitConnections)
		{
			_connector.connect(
				_host.c_str(), _service.c_str(), 
				bind(&ClientSessionImpl::onConnectOk, shared_from_this(), _1),
				bind(&ClientSessionImpl::onConnectError, shared_from_this(), _1));
			_waitConnections++;
		}

		if(_needNumChannels < getChannelsAmount())
		{
			//закрыть один когда не будет трафика
			assert(0);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSessionImpl::onConnectOk(Channel channel)
	{
		LF;
		mutex::scoped_lock sl(_mtx);
		if(!_isStarted)
		{
			channel.close();
			return;
		}

		utils::Variant v;
		v.as<utils::Variant::MapStringVariant>(true)["sid"] = _needSid;

		SPacket packet;
		packet._data = v.save(packet._size);

		//послать сид
		channel.send(
			packet, 
			bind(&ClientSessionImpl::onSendSidOk, shared_from_this(), channel),
			bind(&ClientSessionImpl::onSendSidFail, shared_from_this(), channel, _1));
		
		_waitConnectionsChannels.insert(channel);
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSessionImpl::onConnectError(system::error_code ec)
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
	void ClientSessionImpl::onSendSidOk(Channel channel)
	{
		LF;
		mutex::scoped_lock sl(_mtx);
		if(!_isStarted)
		{
			channel.close();
			return;
		}
		//принять сид
		channel.receive(
			bind(&ClientSessionImpl::onReceiveSidOk, shared_from_this(), channel, _1),
			bind(&ClientSessionImpl::onReceiveSidFail, shared_from_this(), channel, _1));
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSessionImpl::onSendSidFail(Channel channel, system::error_code ec)
	{
		LF;
		channel.close();

		{
			mutex::scoped_lock sl(_mtx);
			if(!_isStarted)
			{
				return;
			}

			assert(!"log error?");
			_waitConnections--;
			_waitConnectionsChannels.erase(channel);
			channel.close();
			checkbalance();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSessionImpl::onReceiveSidOk(Channel channel, const SPacket &packet)
	{
		LF;
		mutex::scoped_lock sl(_mtx);
		if(!_isStarted)
		{
			channel.close();
			return;
		}

		utils::Variant v;
		if(	!v.load(packet._data, packet._size) || 
			!v.is<utils::Variant::MapStringVariant>())
		{
			//bad packet

			assert(!"log error?");
			channel.close();

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
			channel.close();
			_waitConnections--;
			checkbalance();
			return;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSessionImpl::onReceiveSidFail(Channel channel, system::error_code ec)
	{
		LF;
		channel.close();

		{
			mutex::scoped_lock sl(_mtx);
			if(!_isStarted)
			{
				return;
			}

			//assert(!"log error?");
			_waitConnectionsChannels.erase(channel);
			channel.close();
			_waitConnections--;
			checkbalance();
		}
	}


	//////////////////////////////////////////////////////////////////////////
	ClientSessionImplPtr ClientSessionImpl::shared_from_this()
	{
		return static_pointer_cast<ClientSessionImpl>(ChannelImpl::shared_from_this());
	}


	//////////////////////////////////////////////////////////////////////////
	ClientSessionImpl::ClientSessionImpl(Connector connector, const char *host, const char *service)
		: _connector(connector)
		, _host(host)
		, _service(service)
		, _isStarted(false)
		, _sid(nullClientSid)
		, _needSid(nullClientSid)
		, _needNumChannels(0)
		, _waitConnections(0)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSessionImpl::start(
		TClientSid sid, 
		size_t numChannels,
		boost::function<void (size_t)> ready,
		boost::function<void (size_t, system::error_code)> fail)
	{
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
	void ClientSessionImpl::close()
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
		BOOST_FOREACH(Channel &c, _waitConnectionsChannels)
		{
			c.close();
		}
		_waitConnectionsChannels.clear();
		ChannelHubImpl::close();
	}
	
	//////////////////////////////////////////////////////////////////////////
	void ClientSessionImpl::stop()
	{
		return close();
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSessionImpl::balance(size_t numChannels)
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
	TClientSid ClientSessionImpl::sid()
	{
		mutex::scoped_lock sl(_mtx);
		return _sid;
	}
}
