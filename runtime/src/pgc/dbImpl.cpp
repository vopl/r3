#include "pch.hpp"
#include "dbImpl.hpp"
#include "utils/implAccess.hpp"
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <boost/thread.hpp>
#include "connectionImpl.hpp"
#include "async/futureWaiter.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	DbImpl::DbImpl(const char *conninfo,
		size_t maxConnections,
		function<void (size_t)> connectionMade,
		function<void (size_t)> connectionLost)
	{
		ILOG("initialize");
		mutex::scoped_lock sl(_mtx);

		_conninfo = conninfo;
		_maxConnections = maxConnections;
		_onConnectionMade = connectionMade;
		_onConnectionLost = connectionLost;
	}

	//////////////////////////////////////////////////////////////////////////
	DbImpl::~DbImpl()
	{
		reset();
	}



	//////////////////////////////////////////////////////////////////////////
	void DbImpl::balanceConnections()
	{

		{
			mutex::scoped_lock sl(_mtx);

			//Р·Р°РєСЂС‹С‚РёРµ Р»РёС€РЅРёС…
			while(	!_readyConnections.empty() &&
				_readyConnections.size() + _workConnections.size() + _startConnections.size() > _maxConnections)
			{
				ILOG("close connection");
				(*_readyConnections.begin())->close();
				_readyConnections.erase(_readyConnections.begin());
				if(_onConnectionLost)
				{
					async::spawn(bind(_onConnectionLost, _readyConnections.size() + _workConnections.size()));
				}
			}

			//СЂР°СЃРїСЂРµРґРµР»РµРЅРёРµ Рё РѕС‚РєСЂС‹С‚РёРµ
			while(!_waiters.empty())
			{
				if(!_readyConnections.empty())
				{
					//РµСЃС‚СЊ РіРѕС‚РѕРІС‹Рµ СЃРѕРµРґРёРЅРµРЅРёСЏ

					ConnectionHolderPtr ch = *_readyConnections.begin();
					ConnectionImplPtr ci(new ConnectionImpl(ch));
					Connection c = utils::ImplAccess<Connection>(ci);
					_waiters.front()(c);

					_workConnections.insert(ch);
					_readyConnections.erase(_readyConnections.begin());

					_waiters.pop_front();
					continue;
				}

				if(!_maxConnections)
				{
					//Р±РѕР»СЊС€Рµ РІС‹РґРµР»СЏС‚СЊ РЅРµР»СЊР·СЏ, РѕСЃРІРѕР±РѕРґРёС‚СЊ РІСЃРµС… РѕР¶РёРґР°СЋС‰РёС… РЅСѓР»СЏРјРё

					BOOST_FOREACH(async::Future<Connection> &res, _waiters)
					{
						WLOG("force null result on allocConnection");
						res(Connection());
					}
					_waiters.clear();
					continue;
				}

				if(	_startConnections.empty() &&
					_readyConnections.size() + _workConnections.size() < _maxConnections)
				{
					//РіРѕС‚РѕРІС‹С… РЅРµС‚, СЃС‚Р°СЂС‚СѓСЋС‰РёС… РЅРµС‚, РјРѕР¶РЅРѕ РїРѕРґРєР»СЋС‡Р°С‚СЊ РЅРѕРІРѕРµ
					async::spawn(bind(&DbImpl::makeConnection, shared_from_this()));
				}
				break;
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void DbImpl::makeConnection()
	{
		ConnectionHolderPtr pch;
		{
			mutex::scoped_lock sl(_mtx);

			if(!_startConnections.empty())
			{
				//СѓР¶Рµ РїСЂРѕРёСЃС…РѕРґРёС‚ РїРѕРґРєР»СЋС‡РµРЅРёРµ, РЅРёС‡РµРіРѕ РЅРµ РґРµР»Р°С‚СЊ
				return;
			}
			ILOG("start connection");
			PGconn *pgcon = PQconnectStart(_conninfo.c_str());
			bool isOk = true;
			if(pgcon)
			{
				ConnStatusType status = PQstatus(pgcon);
				if(CONNECTION_BAD == status)
				{
					ILOG("start connection failed, bad status");
					PQfinish(pgcon);
					isOk = false;
				}
			}
			else
			{
				ILOG("start connection failed, libpq has been unable to allocate a new PGconn structure");
				isOk = false;
			}

			if(isOk)
			{
				pch.reset(new ConnectionHolder(shared_from_this(), pgcon));
				_startConnections.insert(pch);
			}
			else
			{
				if(!_timeout)
				{
					ILOG("wait 1 second for rebalance connections");
					_timeout.reset(new Timeout(async::io(), boost::posix_time::seconds(1)));
					_timeout->async_wait(
						async::bridge(bind(&DbImpl::onRebalanceTimer, shared_from_this())));
				}
			}
		}

		if(pch)
		{
			makeConnection_poll(pch);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void DbImpl::makeConnection_poll(ConnectionHolderPtr pch)
	{
		enum EStatus
		{
			esContinue,
			esOk,
			esBad,
		} es(esContinue);

		while(esContinue == es)
		{
			switch(PQconnectPoll(pch->pgcon()))
			{
			case PGRES_POLLING_FAILED:
				ELOG("poll result FAILED: "<<PQerrorMessage(pch->pgcon()));
				es = esBad;
				break;
			case PGRES_POLLING_READING:
				{
					async::FutureWaiter<system::error_code> w(
						pch->send0(),
						async::timeout(2000));
					w.wait();

					if(w.currentIndex() == 1)
					{
						//СЃСЂР°Р±РѕС‚Р°Р» С‚Р°Р№РјР°СѓС‚, РєР°Рє РѕС‚РјРµРЅРёС‚СЊ send0?
						//ILOG("poll timeout");
					}
					else if(w.current().data())
					{
						ILOG("poll with bad ec: "<<w.current().data()<<")");
						es = esBad;
					}
				}
				break;
			case PGRES_POLLING_WRITING:
				{
					async::FutureWaiter<system::error_code> w(
						pch->send0(),
						async::timeout(2000));
					w.wait();

					if(w.currentIndex() == 1)
					{
						//СЃСЂР°Р±РѕС‚Р°Р» С‚Р°Р№РјР°СѓС‚, РєР°Рє РѕС‚РјРµРЅРёС‚СЊ send0?
						//ILOG("poll timeout");
					}
					else if(w.current().data())
					{
						ILOG("poll with bad ec: "<<w.current().data()<<")");
						es = esBad;
					}
				}
				break;
			case PGRES_POLLING_OK:
				{
					//ILOG("poll result OK");
					es = esOk;
				}
				break;
			default:
				ELOG("poll result UNKNOWN");
				{
					assert(0);
				}
				break;
			}

			switch(es)
			{
			case esOk:
				{
					pch->onOpen();
					{
						mutex::scoped_lock sl(_mtx);
						assert(_startConnections.end() != _startConnections.find(pch));
						_startConnections.erase(pch);
						_readyConnections.insert(pch);

						if(_onConnectionMade)
						{
							async::spawn(bind(_onConnectionMade, _readyConnections.size() + _workConnections.size()));
						}
					}
					async::spawn(bind(&DbImpl::balanceConnections, shared_from_this()));
				}
				break;
			case esBad:
				{
					mutex::scoped_lock sl(_mtx);
					assert(_startConnections.end() != _startConnections.find(pch));
					_startConnections.erase(pch);

					if(!_maxConnections)
					{
						ILOG("connection mading abadoned");
						async::spawn(bind(&DbImpl::balanceConnections, shared_from_this()));
						return;
					}
					if(!_timeout)
					{
						ILOG("wait 1 second for reconnect");
						_timeout.reset(new Timeout(async::io(), boost::posix_time::seconds(1)));
						_timeout->async_wait(
							async::bridge(bind(&DbImpl::onRebalanceTimer, shared_from_this())));
						return;
					}
				}
				break;
			default:
				break;
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void DbImpl::onRebalanceTimer()
	{
		ILOG("rebalance timer now");
		{
			mutex::scoped_lock sl(_mtx);
			_timeout.reset();
		}

		balanceConnections();
	}

	//////////////////////////////////////////////////////////////////////////
	void DbImpl::unwork(ConnectionHolderPtr pch)
	{
		if(ecsOk == pch->status())
		{
			{
				mutex::scoped_lock sl(_mtx);

				assert(_workConnections.end() != _workConnections.find(pch));
				_workConnections.erase(pch);
				_readyConnections.insert(pch);
			}
		}
		else
		{
			ELOG("bad connection detected");
			{
				mutex::scoped_lock sl(_mtx);
				assert(_workConnections.end() != _workConnections.find(pch));
				_workConnections.erase(pch);
				if(_onConnectionLost)
				{
					async::spawn(bind(_onConnectionLost, _readyConnections.size() + _workConnections.size()));
				}
			}
		}

		balanceConnections();
	}

	//////////////////////////////////////////////////////////////////////////
	async::Future<Connection> DbImpl::allocConnection()
	{
		mutex::scoped_lock sl(_mtx);

		async::Future<Connection> res;

		//РЅРµР±РѕР»СЊС€Р°СЏ РѕРїС‚РёРјРёР·Р°С†РёСЏ - РµСЃР»Рё РµСЃС‚СЊ РіРѕС‚РѕРІС‹Рµ С‚Рѕ РѕС‚РґР°С‚СЊ СЃСЂР°Р·Сѓ, Р±РµР· Р±Р°Р»Р°РЅСЃРёСЂРѕРІРєРё
		if(!_readyConnections.empty())
		{
			ConnectionHolderPtr ch = *_readyConnections.begin();
			if(ecsOk == ch->status())
			{
				ConnectionImplPtr ci(new ConnectionImpl(ch));
				Connection c = utils::ImplAccess<Connection>(ci);
				res(c);

				_workConnections.insert(ch);
				_readyConnections.erase(_readyConnections.begin());
				return res;
			}
		}

		//РЅРµ РїРѕРІРµР·Р»Рѕ, РґРµР»Р°С‚СЊ Р±Р°Р»Р°РЅСЃРёСЂРѕРІРєСѓ
		_waiters.push_back(res);
		async::spawn(bind(&DbImpl::balanceConnections, shared_from_this()));

		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	void DbImpl::reset()
	{
		ILOG("deinitialize");
		std::deque<async::Future<Connection> > waiters;
		{
			mutex::scoped_lock sl(_mtx);

			if(_timeout)
			{
				system::error_code ec;
				_timeout->cancel(ec);
			}

			_maxConnections = 0;
			_conninfo.clear();
			waiters.swap(_waiters);
		}
		BOOST_FOREACH(async::Future<Connection> &w, waiters)
		{
			w(Connection());
		}

		for(;;)
		{
			bool doWait = true;
			{
				mutex::scoped_lock sl(_mtx);
				BOOST_FOREACH(const ConnectionHolderPtr &c, _readyConnections)
				{
					ILOG("close connection");
					c->close();
				}
				_readyConnections.clear();
				doWait = !(_startConnections.empty() && _readyConnections.empty() && _workConnections.empty());
			}
			if(doWait)
			{
				async::timeout(50).wait();
			}
			else
			{
				break;
			}
		}

		function<void (size_t)>().swap(_onConnectionMade);
		function<void (size_t)>().swap(_onConnectionLost);
	}

}
