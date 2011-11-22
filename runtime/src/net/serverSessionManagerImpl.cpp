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
	void ServerSessionManagerImpl::onAcceptError(system::error_code ec)
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
			bind(&ServerSessionManagerImpl::onAcceptError, shared_from_this(), _1));

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
		assert(0);
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
			bind(&ServerSessionManagerImpl::onAcceptError, shared_from_this(), _1));
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

		BOOST_FOREACH(ServerSessionImplPtr &s, _sessions)
		{
			s->close();
			s.reset();
		}
		_sessions.clear();

		_isStarted = false;
		_ready.swap(boost::function<void (ServerSession)>());
		_fail.swap(boost::function<void (system::error_code)>());

	}
}
