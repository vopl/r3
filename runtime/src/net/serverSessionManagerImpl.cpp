#include "stdafx.h"
#include "serverSessionManagerImpl.hpp"
#include <boost/bind.hpp>
#include "utils/variant.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManagerImpl::onAcceptOk(Channel channel)
	{
		{
			mutex::scoped_lock sl(_mtx);
			if(!_isStarted)
			{
				channel.close();
				return;
			}
		}

		//канал провести в сессию
// 		channel.receive(getMeASid)
// 		if(sid null)
// 		{
// 			create new session, attach channel to session, call ok
// 		}
// 		else if(sid known)
// 		{
// 			attach channel to session, call ok
// 		}
// 		else //sid unknown
// 		{
// 			send "no session"
// 		}

		channel.receive(
			bind(&ServerSessionManagerImpl::onReceiveSidOk, shared_from_this(), channel, _1),
			bind(&ServerSessionManagerImpl::onReceiveSidFail, shared_from_this(), channel, _1));
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManagerImpl::onAcceptFail(system::error_code ec)
	{
		assert(!"log error?");

		mutex::scoped_lock sl(_mtx);
		if(!_isStarted)
		{
			return;
		}

		_connector.listen(
			_host.c_str(), _service.c_str(), 
			bind(&ServerSessionManagerImpl::onAcceptOk, shared_from_this(), _1),
			bind(&ServerSessionManagerImpl::onAcceptFail, shared_from_this(), _1));
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManagerImpl::onReceiveSidOk(Channel channel, const SPacket &packet)
	{
		utils::Variant v;
		if(	!v.load(packet._data, packet._size) || 
			!v.is<utils::Variant::MapStringVariant>())
		{
			//bad packet
			assert(!"log error?");
			channel.close();
			return;
		}
		v = utils::Variant(v.as<utils::Variant::MapStringVariant>()["sid"]);
		if(	!v.is<TServerSid>())
		{
			//bad packet
			assert(!"log error?");
			channel.close();
			return;
		}
		TServerSid sid = v.as<TServerSid>();

		if(nullServerSid != sid)
		{
			mutex::scoped_lock sl(_mtx);
			TMSessions::iterator iter = _sessions.find(sid);
			if(_sessions.end() == iter)
			{
				//запрошенная сессия НЕ существует
				v.as<utils::Variant::MapStringVariant>(true)["badSid"] = true;

				SPacket packet;
				packet._data = v.save(packet._size);
				channel.send(packet, 
					bind(&ServerSessionManagerImpl::onAcceptOk, shared_from_this(), channel));
			}
			else
			{
				//запрошенная сессия существует, привязать к ней
				v.as<utils::Variant::MapStringVariant>(true)["sid"] = sid;

				SPacket packet;
				packet._data = v.save(packet._size);
				channel.send(packet, 
					bind(&ServerSessionManagerImpl::attach2Session, shared_from_this(), iter->second, channel));
			}
		}
		else
		{
			//сид был нулевой, создать новую сессию
			mutex::scoped_lock sl(_mtx);

			TServerSid newSid = _sidGen();
			while(_sessions.end() != _sessions.find(newSid))
			{
				newSid = _sidGen();
			}
			ServerSessionImplPtr session(new ServerSessionImpl(newSid));
			_sessions[newSid] = session;

			v.as<utils::Variant::MapStringVariant>(true)["sid"] = newSid;

			SPacket packet;
			packet._data = v.save(packet._size);
			channel.send(packet, 
				bind(&ServerSessionManagerImpl::attach2Session, shared_from_this(), session, channel));
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManagerImpl::onReceiveSidFail(Channel channel, system::error_code ec)
	{
		assert(!"log error?");

		{
			mutex::scoped_lock sl(_mtx);
			if(!_isStarted)
			{
				return;
			}
		}
		channel.close();
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManagerImpl::attach2Session(ServerSessionImplPtr session, Channel channel)
	{
		session->attachChannel(channel);
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManagerImpl::attach2SessionFail(Channel channel)
	{
		channel.close();
	}


	//////////////////////////////////////////////////////////////////////////
	ServerSessionManagerImpl::ServerSessionManagerImpl(
		Connector connector,
		const char *host, const char *service)
		: _connector(connector)
		, _host(host)
		, _service(service)
		, _isStarted(false)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManagerImpl::start(
		boost::function<void (ServerSession)> ready,
		boost::function<void (system::error_code)> fail)
	{
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

		_connector.listen(
			_host.c_str(), _service.c_str(), 
			bind(&ServerSessionManagerImpl::onAcceptOk, shared_from_this(), _1),
			bind(&ServerSessionManagerImpl::onAcceptFail, shared_from_this(), _1));
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManagerImpl::stop()
	{
		mutex::scoped_lock sl(_mtx);
		if(!_isStarted)
		{
			return;
		}
		_connector.unlisten(_host.c_str(), _service.c_str());

		BOOST_FOREACH(TMSessions::value_type &p, _sessions)
		{
			p.second->close();
			p.second.reset();
		}
		_sessions.clear();

		_isStarted = false;
		_ready.swap(boost::function<void (ServerSession)>());
		_fail.swap(boost::function<void (system::error_code)>());

	}
}
