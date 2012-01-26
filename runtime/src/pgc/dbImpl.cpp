#include "pch.h"
#include "dbImpl.hpp"
#include "utils/implAccess.hpp"
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <boost/thread.hpp>
#include "connectionImpl.hpp"

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

			//закрытие лишних
			while(	!_readyConnections.empty() &&
				_readyConnections.size() + _workConnections.size() + _startConnections.size() > _maxConnections)
			{
				ILOG("close connection");
				(*_readyConnections.begin())->close();
				_readyConnections.erase(_readyConnections.begin());
				async::spawn(bind(_onConnectionLost, _readyConnections.size() + _workConnections.size()));
			}

			//распределение и открытие
			while(!_waiters.empty())
			{
				if(!_readyConnections.empty())
				{
					//есть готовые соединения

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
					//больше выделять нельзя, освободить всех ожидающих нулями

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
					//готовых нет, стартующих нет, можно подключать новое
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
				//уже происходит подключение, ничего не делать
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
					async::Future<system::error_code> r = pch->recv0();
					if(r.data())
					{
						ILOG("poll with bad ec: "<<r.data()<<")");
						es = esBad;
					}
				}
				break;
			case PGRES_POLLING_WRITING:
				{
					async::Future<system::error_code> r = pch->send0();
					if(r.data())
					{
						ILOG("poll with bad ec: "<<r.data()<<")");
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
					int k=220;
				}
				break;
			}

			switch(es)
			{
			case esOk:
				{
					pch->onOpen();
					size_t numConnections=0;
					{
						mutex::scoped_lock sl(_mtx);
						assert(_startConnections.end() != _startConnections.find(pch));
						_startConnections.erase(pch);
						_readyConnections.insert(pch);
						async::spawn(bind(_onConnectionMade, _readyConnections.size() + _workConnections.size()));
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
				async::spawn(bind(_onConnectionLost, _readyConnections.size() + _workConnections.size()));
			}
		}

		balanceConnections();
	}

	//////////////////////////////////////////////////////////////////////////
	async::Future<Connection> DbImpl::allocConnection()
	{
		mutex::scoped_lock sl(_mtx);

		async::Future<Connection> res;

		//небольшая оптимизация - если есть готовые то отдать сразу, без балансировки
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

		//не повезло, делать балансировку
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
				doWait = !(_startConnections.empty() && _readyConnections.empty() && _workConnections.empty());
			}
			if(doWait)
			{
				async::yield();
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
