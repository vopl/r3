#include "pch.h"
#include "db.hpp"
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <boost/thread.hpp>

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	Db::Db()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Db::~Db()
	{
	}



	//////////////////////////////////////////////////////////////////////////
	void Db::balanceConnections()
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

					ConnectionImplPtr ci = *_readyConnections.begin();
					IConnectionPtr c(new ConnectionHolder(shared_from_this(), ci));
					_waiters.front()(c);

					_workConnections.insert(ci);
					_readyConnections.erase(_readyConnections.begin());

					_waiters.pop_front();
					continue;
				}

				if(!_maxConnections)
				{
					//больше выделять нельзя, освободить всех ожидающих нулями

					BOOST_FOREACH(async::Result<IConnectionPtr> &res, _waiters)
					{
						WLOG("force null result on allocConnection");
						res(IConnectionPtr());
					}
					_waiters.clear();
					continue;
				}

				if(	_startConnections.empty() && 
					_readyConnections.size() + _workConnections.size() < _maxConnections)
				{
					//готовых нет, стартующих нет, можно подключать новое
					async::spawn(bind(&Db::makeConnection, shared_from_this()));
				}
				break;
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void Db::makeConnection()
	{
		ConnectionImplPtr pcw;
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
				pcw.reset(new ConnectionImpl(pgcon));
				_startConnections.insert(pcw);
			}
			else
			{
				if(!_timeout)
				{
					ILOG("wait 1 second for rebalance connections");
					_timeout.reset(new Timeout(async::io(), boost::posix_time::seconds(1)));
					_timeout->async_wait(
						bind(&Db::onRebalanceTimer, shared_from_this()));
				}
			}
		}

		if(pcw)
		{
			makeConnection_poll(pcw);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void Db::makeConnection_poll(ConnectionImplPtr pcw)
	{
		enum EStatus
		{
			esContinue,
			esOk,
			esBad,
		} es(esContinue);

		while(esContinue == es)
		{
			switch(PQconnectPoll(pcw->pgcon()))
			{
			case PGRES_POLLING_FAILED:
				ELOG("poll result FAILED: "<<PQerrorMessage(pcw->pgcon()));
				es = esBad;
				break;
			case PGRES_POLLING_READING:
				{
					async::Result<system::error_code> r = pcw->recv0();
					if(r.data())
					{
						ILOG("poll with bad ec: "<<r.data()<<")");
						es = esBad;
					}
				}
				break;
			case PGRES_POLLING_WRITING:
				{
					async::Result<system::error_code> r = pcw->send0();
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
					pcw->onOpen();
					size_t numConnections=0;
					{
						mutex::scoped_lock sl(_mtx);
						assert(_startConnections.end() != _startConnections.find(pcw));
						_startConnections.erase(pcw);
						_readyConnections.insert(pcw);
						async::spawn(bind(_onConnectionMade, _readyConnections.size() + _workConnections.size()));
					}
					async::spawn(bind(&Db::balanceConnections, shared_from_this()));
				}
				break;
			case esBad:
				{
					mutex::scoped_lock sl(_mtx);
					assert(_startConnections.end() != _startConnections.find(pcw));
					_startConnections.erase(pcw);

					if(!_maxConnections)
					{
						ILOG("connection mading abadoned");
						async::spawn(bind(&Db::balanceConnections, shared_from_this()));
						return;
					}
					if(!_timeout)
					{
						ILOG("wait 1 second for reconnect");
						_timeout.reset(new Timeout(async::io(), boost::posix_time::seconds(1)));
						_timeout->async_wait(
							bind(&Db::onRebalanceTimer, shared_from_this()));
						return;
					}
				}
				break;
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void Db::onRebalanceTimer()
	{
		ILOG("rebalance timer now");
		{
			mutex::scoped_lock sl(_mtx);
			_timeout.reset();
		}

		balanceConnections();
	}

	//////////////////////////////////////////////////////////////////////////
	void Db::unwork(ConnectionImplPtr pcw)
	{
		if(ecsOk == pcw->status())
		{
			{
				mutex::scoped_lock sl(_mtx);

				assert(_workConnections.end() != _workConnections.find(pcw));
				_workConnections.erase(pcw);
				_readyConnections.insert(pcw);
			}
		}
		else
		{
			ELOG("bad connection detected");
			{
				mutex::scoped_lock sl(_mtx);
				assert(_workConnections.end() != _workConnections.find(pcw));
				_workConnections.erase(pcw);
				async::spawn(bind(_onConnectionLost, _readyConnections.size() + _workConnections.size()));
			}
		}

		balanceConnections();
	}

	//////////////////////////////////////////////////////////////////////////
	void Db::initialize(
		const char *conninfo,
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
	async::Result<IConnectionPtr> Db::allocConnection()
	{
		mutex::scoped_lock sl(_mtx);

		async::Result<IConnectionPtr> res;

		//небольшая оптимизация - если есть готовые то отдать сразу, без балансировки
		if(!_readyConnections.empty())
		{
			ConnectionImplPtr ci = *_readyConnections.begin();
			if(ecsOk == ci->status())
			{
				IConnectionPtr c(new ConnectionHolder(shared_from_this(), ci));
				res(c);

				_workConnections.insert(ci);
				_readyConnections.erase(_readyConnections.begin());
				return res;
			}
		}

		//не повезло, делать балансировку
		_waiters.push_back(res);
		async::spawn(bind(&Db::balanceConnections, shared_from_this()));

		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	void Db::deinitialize()
	{
		ILOG("deinitialize");
		std::deque<async::Result<IConnectionPtr> > waiters;
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
		BOOST_FOREACH(async::Result<IConnectionPtr> &w, waiters)
		{
			w(IConnectionPtr());
		}

		bool doWait = true;
		while(doWait)
		{
			{
				mutex::scoped_lock sl(_mtx);
				doWait = !(_startConnections.empty() && _readyConnections.empty() && _workConnections.empty());
			}
			if(doWait)
			{
				balanceConnections();

				boost::xtime xt;
				boost::xtime_get(&xt, boost::TIME_UTC);
				xt.nsec += 100000000;
				boost::thread::sleep(xt);
			}
		}

		_onConnectionMade.swap(function<void (size_t)>());
		_onConnectionLost.swap(function<void (size_t)>());
	}
}
