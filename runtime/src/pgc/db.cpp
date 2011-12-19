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
		struct SWorkPair
		{
			ConnectionImplPtr _con;
			async::Result<IConnectionPtr>	_waiter;
		};
		std::deque<SWorkPair> readyWaiters;
		ConnectionImplPtr pcwStarted;

		{
			mutex::scoped_lock sl(_mtx);

			//закрытие лишних
			while(	!_readyConnections.empty() &&
				_readyConnections.size() + _workConnections.size() + _startConnections.size() > _maxConnections)
			{
				ILOG("close connection");
				(*_readyConnections.begin())->close();
				_readyConnections.erase(_readyConnections.begin());
				_asrv->get_io_service().post(bind(_onConnectionLost, _readyConnections.size() + _workConnections.size()));
			}

			//распределение и открытие
			while(!_waiters.empty())
			{
				if(!_readyConnections.empty())
				{
					//есть готовые соединения
					SWorkPair swp = {*_readyConnections.begin(), _waiters.front()};
					_readyConnections.erase(_readyConnections.begin());
					_waiters.erase(_waiters.begin());

					readyWaiters.push_back(swp);
					_workConnections.insert(swp._con);

					continue;
				}

				if(!_maxConnections)
				{
					//больше выделять нельзя, освободить всех ожидающих нулями
					SWorkPair swp = {ConnectionImplPtr(), _waiters.front()};
					_waiters.erase(_waiters.begin());

					readyWaiters.push_back(swp);
					continue;
				}

				if(	_startConnections.empty() && 
					_readyConnections.size() + _workConnections.size() < _maxConnections)
				{
					//готовых нет, стартующих нет, можно подключать новое

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
						pcwStarted.reset(new ConnectionImpl(pgcon, _asrv));
						_startConnections.insert(pcwStarted);
					}
					else
					{
						if(!_timeout)
						{
							ILOG("wait 1 second for reconnect");
							_timeout.reset(new Timeout(_asrv->get_io_service(), boost::posix_time::seconds(1)));
							_timeout->async_wait(
								bind(&Db::onReconnectTimer, shared_from_this()));
						}
					}
				}
				break;
			}
		}

		if(pcwStarted)
		{
			makeConnection_poll(pcwStarted);
		}

		BOOST_FOREACH(SWorkPair &wp, readyWaiters)
		{
			IConnectionPtr c;
			if(wp._con)
			{
				c.reset(new ConnectionHolder(shared_from_this(), wp._con));
			}
			wp._waiter(c);
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
						_asrv->get_io_service().post(bind(_onConnectionMade, _readyConnections.size() + _workConnections.size()));
					}
					_asrv->get_io_service().post(bind(&Db::balanceConnections, shared_from_this()));
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
						_asrv->get_io_service().post(bind(&Db::balanceConnections, shared_from_this()));
						return;
					}
					if(!_timeout)
					{
						ILOG("wait 1 second for reconnect");
						_timeout.reset(new Timeout(_asrv->get_io_service(), boost::posix_time::seconds(1)));
						_timeout->async_wait(
							bind(&Db::onReconnectTimer, shared_from_this()));
						return;
					}
				}
				break;
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void Db::onReconnectTimer()
	{
		ILOG("reconnect timer now");
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
				_asrv->get_io_service().post(bind(_onConnectionLost, _readyConnections.size() + _workConnections.size()));
			}
		}

		balanceConnections();
	}

	//////////////////////////////////////////////////////////////////////////
	void Db::initialize(
		async::IServicePtr asrv,
		const char *conninfo,
		size_t maxConnections,
		function<void (size_t)> connectionMade,
		function<void (size_t)> connectionLost)
	{
		ILOG("initialize");
		mutex::scoped_lock sl(_mtx);
		assert(!_asrv);
		_asrv = asrv;
		assert(_asrv);

		_conninfo = conninfo;
		_maxConnections = maxConnections;
		_onConnectionMade = connectionMade;
		_onConnectionLost = connectionLost;
	}

	//////////////////////////////////////////////////////////////////////////
	void Db::allocConnection_f(async::Result<IConnectionPtr> res)
	{
		ConnectionImplPtr pcw;

		bool unableAlloc = false;
		{
			mutex::scoped_lock sl(_mtx);
			while(_readyConnections.size())
			{
				ConnectionImplPtr pcw = *_readyConnections.begin();

				if(ecsOk != pcw->status())
				{
					ELOG("bad connection detected");
					{
						assert(_workConnections.end() != _workConnections.find(pcw));
						_workConnections.erase(pcw);
						_asrv->get_io_service().post(bind(_onConnectionLost, _readyConnections.size() + _workConnections.size()));
					}
					continue;
				}

				EConnectionStatus status = pcw->status();
				assert(ecsOk == status);
				_workConnections.insert(pcw);
				_readyConnections.erase(_readyConnections.begin());

				IConnectionPtr c(new ConnectionHolder(shared_from_this(), pcw));
				res(c);
				return;
			}

			//не удалось выделить из готовых
			{
				if(_maxConnections)
				{
					_waiters.push_back(res);
				}
				else
				{
					if(_startConnections.size() + _workConnections.size())
					{
						_waiters.push_back(res);
					}
					else
					{
						ELOG("alloc connection force NULL result");
						res(IConnectionPtr());
						return;
					}
				}
			}
		}

		balanceConnections();
	}
	//////////////////////////////////////////////////////////////////////////
	async::Result<IConnectionPtr> Db::allocConnection()
	{
		async::Result<IConnectionPtr> res;
		_asrv->get_io_service().post(bind(&Db::allocConnection_f, shared_from_this(), res));
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

		_asrv.reset();
	}
}
