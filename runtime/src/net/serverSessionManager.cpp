#include "pch.h"
#include "serverSessionManager.hpp"
#include <boost/bind.hpp>
#include "utils/variant.hpp"

//#define LF 		std::cerr<<__FUNCTION__ "\n";std::cerr.flush();
#define LF

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManager::onAcceptOk(IChannelPtr channel)
	{
		LF;

		mutex::scoped_lock sl(_mtx);
		if(!_isStarted)
		{
			channel->close();
			return;
		}

		channel->receive(
			bind(&ServerSessionManager::onReceiveSidOk, shared_from_this(), channel, _1),
			bind(&ServerSessionManager::onReceiveSidFail, shared_from_this(), channel, _1));
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManager::onAcceptFail(system::error_code ec)
	{
		LF;
		{
			mutex::scoped_lock sl(_mtx);
			if(!_isStarted)
			{
				return;
			}
		}

		assert(!"log error?");

		_connector->listen(
			_host.c_str(), _service.c_str(), 
			bind(&ServerSessionManager::onAcceptOk, shared_from_this(), _1),
			bind(&ServerSessionManager::onAcceptFail, shared_from_this(), _1));
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManager::onReceiveSidOk(IChannelPtr channel, const SPacket &packet)
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
			return;
		}
		v = utils::Variant(v.as<utils::Variant::MapStringVariant>()["sid"]);
		if(	!v.is<TServerSid>())
		{
			//bad packet
			assert(!"log error?");
			channel->close();
			return;
		}
		TServerSid sid = v.as<TServerSid>();

		if(nullServerSid != sid)
		{
			TMSessions::iterator iter = _sessions.find(sid);
			if(_sessions.end() == iter)
			{
				//запрошенная сессия НЕ существует
				v.as<utils::Variant::MapStringVariant>(true)["badSid"] = true;

				SPacket packet;
				packet._data = v.save(packet._size);
				channel->send(packet, 
					bind(&ServerSessionManager::onAcceptOk, shared_from_this(), channel),
					bind(&ServerSessionManager::onAcceptFail, shared_from_this(), _1));
			}
			else
			{
				//запрошенная сессия существует, привязать к ней
				v.as<utils::Variant::MapStringVariant>(true)["sid"] = sid;

				SPacket packet;
				packet._data = v.save(packet._size);
				channel->send(packet, 
					bind(&ServerSessionManager::attach2Session, shared_from_this(), iter->second, channel),
					bind(&ServerSessionManager::attach2SessionFail, shared_from_this(), channel));
			}
		}
		else
		{
			//сид был нулевой, создать новую сессию
			TServerSid newSid = _sidGen();
			while(_sessions.end() != _sessions.find(newSid))
			{
				newSid = _sidGen();
			}
			ServerSessionPtr session(new ServerSession(newSid));
			_sessions[newSid] = session;

			v.as<utils::Variant::MapStringVariant>(true)["sid"] = newSid;

			SPacket packet;
			packet._data = v.save(packet._size);
			channel->send(packet, 
				bind(&ServerSessionManager::attach2Session, shared_from_this(), session, channel),
				bind(&ServerSessionManager::attach2SessionFail, shared_from_this(), channel));
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManager::onReceiveSidFail(IChannelPtr channel, system::error_code ec)
	{
		LF;
		channel->close();

		assert(!"log error?");

		{
			mutex::scoped_lock sl(_mtx);
			if(!_isStarted)
			{
				return;
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManager::attach2Session(ServerSessionPtr session, IChannelPtr channel)
	{
		LF;
		{
			mutex::scoped_lock sl(_mtx);
			session->attachChannel(channel);
		}
		_ready(session);
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManager::attach2SessionFail(IChannelPtr channel)
	{
		LF;
		channel->close();
	}


	//////////////////////////////////////////////////////////////////////////
	ServerSessionManager::ServerSessionManager()
		: _connector()
		, _host()
		, _service()
		, _isStarted(false)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManager::start(
		IConnectorPtr connector,
		const char *host, const char *service,
		boost::function<void (IServerSessionPtr)> ready,
		boost::function<void (system::error_code)> fail)
	{
		assert(!_connector && _host.empty() && _service.empty());
		_connector = connector;
		_host = host;
		_service = service;

		mutex::scoped_lock sl(_mtx);
		if(_isStarted)
		{
			stop();
		}

		assert(!_ready);
		_ready = ready;

		assert(!_fail);
		_fail = fail;

		_isStarted = true;

		_connector->listen(
			_host.c_str(), _service.c_str(), 
			bind(&ServerSessionManager::onAcceptOk, shared_from_this(), _1),
			bind(&ServerSessionManager::onAcceptFail, shared_from_this(), _1));
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManager::stop()
	{
		mutex::scoped_lock sl(_mtx);
		if(!_isStarted)
		{
			return;
		}
		_connector->unlisten(_host.c_str(), _service.c_str());

		BOOST_FOREACH(TMSessions::value_type &p, _sessions)
		{
			p.second->close();
			p.second.reset();
		}
		_sessions.clear();

		_isStarted = false;
		
		boost::function<void (IServerSessionPtr)> nullReady;
		_ready.swap(nullReady);
		
		boost::function<void (system::error_code)> nullFail;
		_fail.swap(nullFail);

	}
}
