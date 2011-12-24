#include "pch.h"
#include "sessionManager.hpp"
#include "utils/variant.hpp"

//#define LF 		std::cerr<<__FUNCTION__ "\n";std::cerr.flush();
#define LF

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	void SessionManager::onAcceptOk(IChannelPtr channel)
	{
		LF;

		mutex::scoped_lock sl(_mtx);
		if(!_isStarted)
		{
			channel->close();
			return;
		}

		Result2<system::error_code, net::SPacket> res = channel->receive();

		if(res.data1())
		{
			onReceiveSidFail(channel, res.data1());
		}
		else
		{
			onReceiveSidOk(channel, res.data2());
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void SessionManager::onAcceptFail(system::error_code ec)
	{
		LF;
		{
			mutex::scoped_lock sl(_mtx);
			if(!_isStarted)
			{
				return;
			}
		}

		//assert(!"log error?");
		ELOG(__FUNCTION__<<", "<<ec.message()<<"("<<ec.value()<<")");

		Result<system::error_code> res = _acceptor->listen(
			_host.c_str(), _service.c_str());

		if(res.data())
		{
			onAcceptFail(res.data());
		}
		else
		{
			Result2<system::error_code, IChannelPtr> resa = _acceptor->accept();
			if(resa.data1())
			{
				onAcceptFail(resa.data1());
			}
			else
			{
				onAcceptOk(resa.data2());
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void SessionManager::onReceiveSidOk(IChannelPtr channel, const SPacket &packet)
	{
		LF;
		mutex::scoped_lock sl(_mtx);
		if(!_isStarted)
		{
			channel->close();
			return;
		}

		utils::Variant v;
		if(	!v.deserialize(packet._data, packet._size) || 
			!v.is<utils::Variant::MapStringVariant>())
		{
			ELOG(__FUNCTION__<<", bad packet");

			channel->close();
			return;
		}
		v = utils::Variant(v.as<utils::Variant::MapStringVariant>()["sid"]);
		if(	!v.is<TServerSid>())
		{
			ELOG(__FUNCTION__<<", bad packet");

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
				packet._data = v.serialize(packet._size);
				Result<system::error_code> res = channel->send(packet);

				if(res.data())
				{
					onAcceptFail(res.data());
				}
				else
				{
					onAcceptOk(channel);
				}
			}
			else
			{
				//запрошенная сессия существует, привязать к ней
				v.as<utils::Variant::MapStringVariant>(true)["sid"] = sid;

				SPacket packet;
				packet._data = v.serialize(packet._size);
				Result<system::error_code> res = channel->send(packet);

				if(res.data())
				{
					attach2SessionFail(channel);
				}
				else
				{
					attach2Session(iter->second, channel);
				}
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
			SessionPtr session(new Session(newSid));
			_sessions[newSid] = session;


			v.as<utils::Variant::MapStringVariant>(true)["sid"] = newSid;

			SPacket packet;
			packet._data = v.serialize(packet._size);
			Result<system::error_code> res = channel->send(packet);
			
			if(res.data())
			{
				attach2SessionFail(channel);
			}
			else
			{
				attach2Session(session, channel);
			}

			_sstart(session);
			session->listenStop(bind(&SessionManager::onSeessionStop, shared_from_this(), session));
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void SessionManager::onReceiveSidFail(IChannelPtr channel, system::error_code ec)
	{
		LF;
		channel->close();

		ELOG(__FUNCTION__<<", "<<ec.message()<<"("<<ec.value()<<")");

		{
			mutex::scoped_lock sl(_mtx);
			if(!_isStarted)
			{
				return;
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void SessionManager::attach2Session(SessionPtr session, IChannelPtr channel)
	{
		LF;
		{
			mutex::scoped_lock sl(_mtx);
			if(_isStarted)
			{
				session->attachChannel(channel);
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void SessionManager::attach2SessionFail(IChannelPtr channel)
	{
		LF;
		channel->close();
	}

	//////////////////////////////////////////////////////////////////////////
	void SessionManager::onSeessionStop(SessionPtr session)
	{
		boost::function<void (ISessionPtr)> sstop;
		{
			mutex::scoped_lock sl(_mtx);
			_sessions.erase(session->sid());
			sstop = _sstop;
		}
		if(sstop)
		{
			sstop(session);
		}
	}


	//////////////////////////////////////////////////////////////////////////
	SessionManager::SessionManager()
		: _connector()
		, _host()
		, _service()
		, _isStarted(false)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void SessionManager::start(
		IConnectorPtr connector,
		net::IAcceptorPtr acceptor, 
		const char *host, const char *service,
		boost::function<void (ISessionPtr)> sstart,
		boost::function<void (ISessionPtr)> sstop)
	{
		assert(!_connector && _host.empty() && _service.empty());
		_connector = connector;
		_acceptor = acceptor;
		_host = host;
		_service = service;

		mutex::scoped_lock sl(_mtx);
		if(_isStarted)
		{
			stop();
		}

		assert(!_sstart);
		_sstart = sstart;

		assert(!_sstop);
		_sstop = sstop;

		_isStarted = true;

		Result<error_code> res = _acceptor->listen(_host.c_str(), _service.c_str());

		if(res.data())
		{
			onAcceptFail(res.data());
		}
		else
		{
			Result2<system::error_code, IChannelPtr> resa = _acceptor->accept();
			if(resa.data1())
			{
				onAcceptFail(resa.data1());
			}
			else
			{
				onAcceptOk(resa.data2());
			}
		}

	}

	//////////////////////////////////////////////////////////////////////////
	void SessionManager::stop()
	{
		TMSessions sessions;
		{
			mutex::scoped_lock sl(_mtx);
			if(!_isStarted)
			{
				return;
			}
			_acceptor->unlisten();

			_sessions.swap(sessions);

			_isStarted = false;
		}

		BOOST_FOREACH(TMSessions::value_type &p, sessions)
		{
			p.second->close();
			p.second.reset();
		}

		{
			mutex::scoped_lock sl(_mtx);

			boost::function<void (ISessionPtr)> nullSStart;
			_sstart.swap(nullSStart);

			boost::function<void (ISessionPtr)> nullSStop;
			_sstop.swap(nullSStop);
		}


	}
}
