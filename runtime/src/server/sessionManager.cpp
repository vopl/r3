#include "pch.h"
#include "sessionManager.hpp"
#include "utils/variant.hpp"


namespace server
{
	//////////////////////////////////////////////////////////////////////////
	void SessionManager::onSeessionStop(SessionPtr session)
	{
		function<void (ISessionPtr)> sstop;
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
	void SessionManager::listen_f(IAcceptorPtr acceptor)
	{
		//поставить акцептор на прослушивание
		Future<error_code> res;
		{
			mutex::scoped_lock sl(_mtx);
			if(!_isStarted)
			{
				return;
			}
			res = acceptor->listen(
				bind(&SessionManager::onChannelAccept, shared_from_this(), _1, _2),
				_host.c_str(), _service.c_str());
		}
		error_code ec = res;

		if(ec)
		{
			//прослушивание не удалось
			if(ec == errc::operation_canceled)
			{
				//отменено, менеджер остановлен
				return;
			}

			//залогировать ошибку и по новой
			ELOG(__FUNCTION__<<", "<<ec.message()<<"("<<ec.value()<<")");
			acceptor->unlisten();
			spawn(bind(&SessionManager::listen_f, shared_from_this(), acceptor));
			return;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void SessionManager::onChannelAccept(const error_code &ec, IChannelPtr channel)
	{
		if(ec)
		{
			if(ec == errc::operation_canceled)
			{
				//отменено, менеджер остановлен
				return;
			}

			//залогировать ошибку и по новой
			WLOG(__FUNCTION__<<", "<<ec.message()<<"("<<ec.value()<<")");
			return;
		}

		assert(channel);
		{
			mutex::scoped_lock sl(_mtx);
			_channels.insert(channel);
		}

		//инициировать канал на сессию
		initChannel_f(channel);
	}

	//////////////////////////////////////////////////////////////////////////
	void SessionManager::initChannel_f(IChannelPtr channel)
	{
		//теперь протокол, читать запрашиваемый sid
		Future2<error_code, SPacket> res2;
		channel->listen(res2, 1);
		error_code ec = res2.data1();
		if(ec)
		{
			//бросить канал
			if(errc::operation_canceled != ec)
			{
				WLOG(__FUNCTION__<<", "<<ec.message()<<"("<<ec.value()<<")");
			}

			mutex::scoped_lock sl(_mtx);
			_channels.erase(channel);
			channel->close();
			return;
		}

		SPacket packet = res2.data2();

		//парсить вариант
		utils::Variant v;
		if(	!v.deserialize(packet._data, packet._size) ||
			!v.isMap())
		{
			WLOG(__FUNCTION__<<", bad packet");
			mutex::scoped_lock sl(_mtx);
			_channels.erase(channel);
			channel->close();
			return;
		}

		v = v["sid"];
		if(	!v.is<TServerSid>())
		{
			ELOG(__FUNCTION__<<", bad packet");
			mutex::scoped_lock sl(_mtx);
			_channels.erase(channel);
			channel->close();
			return;
		}
		TServerSid sid = v.as<TServerSid>();

		SessionPtr session;
		if(nullServerSid != sid)
		{
			{
				mutex::scoped_lock sl(_mtx);
				if(!_isStarted)
				{
					mutex::scoped_lock sl(_mtx);
					_channels.erase(channel);
					channel->close();
					return;
				}
				TMSessions::iterator iter = _sessions.find(sid);
				if(_sessions.end() != iter)
				{
					session = iter->second;
				}
			}


			if(!session)
			{
				//запрошенная сессия НЕ существует
				v.as<utils::Variant::MapStringVariant>(true)["badSid"] = true;

				SPacket packet;
				packet._data = v.serialize(packet._size);
				Future<error_code> res = channel->send(packet);

				if(res.data())
				{
					mutex::scoped_lock sl(_mtx);
					_channels.erase(channel);
					channel->close();
					return;
				}
				else
				{
					spawn(bind(&SessionManager::initChannel_f, shared_from_this(), channel));
					return;
				}
			}
			else
			{
				//запрошенная сессия существует, привязать к ней
				v.as<utils::Variant::MapStringVariant>(true)["sid"] = session->sid();

				SPacket packet;
				packet._data = v.serialize(packet._size);
				Future<error_code> res = channel->send(packet);

				if(res.data())
				{
					mutex::scoped_lock sl(_mtx);
					_channels.erase(channel);
					channel->close();
					return;
				}
				else
				{
					mutex::scoped_lock sl(_mtx);
					if(!_isStarted)
					{
						mutex::scoped_lock sl(_mtx);
						_channels.erase(channel);
						channel->close();
						return;
					}
					_sessions[session->sid()] = session;
				}
			}
		}
		else
		{
			//сид был нулевой, создать новую сессию
			{
				mutex::scoped_lock sl(_mtx);
				if(!_isStarted)
				{
					mutex::scoped_lock sl(_mtx);
					_channels.erase(channel);
					channel->close();
					return;
				}
				TServerSid newSid = _sidGen();
				while(_sessions.end() != _sessions.find(newSid))
				{
					newSid = _sidGen();
				}
				session.reset(new Session(newSid));
				_sessions[newSid] = session;
			}


			v.as<utils::Variant::MapStringVariant>(true)["sid"] = session->sid();

			SPacket packet;
			packet._data = v.serialize(packet._size);
			Future<error_code> res = channel->send(packet);

			if(res.data())
			{
				if(errc::operation_canceled != ec)
				{
					WLOG(__FUNCTION__<<", "<<ec.message()<<"("<<ec.value()<<")");
				}
				mutex::scoped_lock sl(_mtx);
				_channels.erase(channel);
				channel->close();
				return;
			}
			else
			{
				mutex::scoped_lock sl(_mtx);
				if(!_isStarted)
				{
					mutex::scoped_lock sl(_mtx);
					_channels.erase(channel);
					channel->close();
					return;
				}
				session->attachChannel(channel);
				_sessions[session->sid()] = session;
				_channels.erase(channel);
			}

			spawn(bind(_sstart, session));
			session->listenStop(bind(&SessionManager::onSeessionStop, shared_from_this(), session));
		}
	}




	//////////////////////////////////////////////////////////////////////////
	SessionManager::SessionManager()
		: _acceptor()
		, _host()
		, _service()
		, _isStarted(false)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	bool SessionManager::start(
		IAcceptorPtr acceptor,
		const char *host, const char *service,
		function<void (ISessionPtr)> sstart,
		function<void (ISessionPtr)> sstop)
	{
		mutex::scoped_lock sl(_mtx);
		if(_isStarted)
		{
			return false;
		}

		assert(!_acceptor && _host.empty() && _service.empty());
		_acceptor = acceptor;
		_host = host;
		_service = service;

		assert(!_sstart);
		_sstart = sstart;

		assert(!_sstop);
		_sstop = sstop;

		_isStarted = true;

		spawn(bind(&SessionManager::listen_f, shared_from_this(), _acceptor));
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool SessionManager::stop()
	{
		TMSessions sessions;
		{
			mutex::scoped_lock sl(_mtx);
			if(!_isStarted)
			{
				return false;
			}
			_acceptor->unlisten();

			_sessions.swap(sessions);

			_isStarted = false;

			BOOST_FOREACH(const IChannelPtr &ch, _channels)
			{
				ch->close();
			}
			_channels.clear();
		}

		BOOST_FOREACH(TMSessions::value_type &p, sessions)
		{
			p.second->close();
			p.second.reset();
		}

		{
			mutex::scoped_lock sl(_mtx);

			function<void (ISessionPtr)> nullSStart;
			_sstart.swap(nullSStart);

			function<void (ISessionPtr)> nullSStop;
			_sstop.swap(nullSStop);
		}

		return true;

	}
}
