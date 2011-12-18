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
			ConnectionPreparedsPtr _con;
			async::Result<IConnectionPtr>	_waiter;
		};
		std::deque<SWorkPair> readyWaiters;
		ConnectionPreparedsPtr pcwStarted;

		{
			mutex::scoped_lock sl(_mtx);

			//закрытие
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
				if(!_maxConnections)
				{
					//больше выделять нельзя, освободить всех ожидающих нулями
					SWorkPair swp = {ConnectionPreparedsPtr(), _waiters.front()};
					_waiters.erase(_waiters.begin());

					readyWaiters.push_back(swp);
					continue;
				}

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
// 							PostgresPollingStatusType status;
// 							status = PQconnectPoll(pgcon);
// 							status = PQconnectPoll(pgcon);
// 							status = PQconnectPoll(pgcon);

						pcwStarted.reset(new ConnectionPrepareds(pgcon, _asrv));
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
			makeConnection_poll(pcwStarted, system::errc::make_error_code(system::errc::success));
		}

		BOOST_FOREACH(SWorkPair &wp, readyWaiters)
		{
			IConnectionPtr c;
			if(wp._con)
			{
				c.reset(new ConnectionHolder(shared_from_this(), wp._con));
			}
			wp._waiter._state->_data = c;
			wp._waiter.ready();

// 			if(wp._waiter)
// 			{
// 				_asrv->get_io_service().post(bind(wp._waiter, c));
// 			}
		}

	}

	//////////////////////////////////////////////////////////////////////////
	void Db::makeConnection_poll(ConnectionPreparedsPtr pcw, system::error_code ec)
	{
		if(ec)
		{
			ILOG("poll with bad ec: "<<ec.message()<<"("<<ec.value()<<")");
		}

// 		switch(PQstatus(pcw->pgcon()))
// 		{
// 		case CONNECTION_OK:
// 			ILOG("poll status CONNECTION_OK");
// 			break;
// 		case CONNECTION_BAD:
// 			ILOG("poll status CONNECTION_OK");
// 			break;
// 		case CONNECTION_STARTED:
// 			ILOG("poll status CONNECTION_STARTED");
// 			break;
// 		case CONNECTION_MADE:
// 			ILOG("poll status CONNECTION_MADE");
// 			break;
// 		case CONNECTION_AWAITING_RESPONSE:
// 			ILOG("poll status CONNECTION_AWAITING_RESPONSE");
// 			break;
// 		case CONNECTION_AUTH_OK:
// 			ILOG("poll status CONNECTION_AUTH_OK");
// 			break;
// 		case CONNECTION_SETENV:
// 			ILOG("poll status CONNECTION_SETENV");
// 			break;
// 		case CONNECTION_SSL_STARTUP:
// 			ILOG("poll status CONNECTION_SSL_STARTUP");
// 			break;
// 		case CONNECTION_NEEDED:
// 			ILOG("poll status CONNECTION_NEEDED");
// 			break;
// 		default:
// 			ILOG("poll status UNKNOWN");
// 			break;
// 		}


		switch(PQconnectPoll(pcw->pgcon()))
		{
		case PGRES_POLLING_FAILED:
			ELOG("poll result FAILED: "<<PQerrorMessage(pcw->pgcon()));
			{
				mutex::scoped_lock sl(_mtx);
				assert(_startConnections.end() != _startConnections.find(pcw));
				_startConnections.erase(pcw);

				if(!_timeout)
				{
					ILOG("wait 1 second for reconnect");
					_timeout.reset(new Timeout(_asrv->get_io_service(), boost::posix_time::seconds(1)));
					_timeout->async_wait(
						bind(&Db::onReconnectTimer, shared_from_this()));
				}
			}
			return;
		case PGRES_POLLING_READING:
			pcw->waitRecv(bind(&Db::makeConnection_poll, shared_from_this(), pcw, _1));
			return;
		case PGRES_POLLING_WRITING:
			pcw->waitSend(bind(&Db::makeConnection_poll, shared_from_this(), pcw, _1));
			return;
		case PGRES_POLLING_OK:
			{
				//ILOG("poll result OK");
				pcw->onOpen();
				size_t numConnections=0;
				{
					mutex::scoped_lock sl(_mtx);
					assert(_startConnections.end() != _startConnections.find(pcw));
					_startConnections.erase(pcw);
					_readyConnections.insert(pcw);
					_asrv->get_io_service().post(bind(_onConnectionMade, _readyConnections.size() + _workConnections.size()));
				}
				balanceConnections();
			}
			return;
		default:
			ELOG("poll result UNKNOWN");
			{
				assert(0);
				int k=220;
			}
			break;
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
	void Db::unwork(ConnectionPreparedsPtr pcw)
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
		ConnectionPreparedsPtr pcw;

		bool unableAlloc = false;
		{
			mutex::scoped_lock sl(_mtx);
			while(_readyConnections.size())
			{
				ConnectionPreparedsPtr pcw = *_readyConnections.begin();

				if(ecsOk != pcw->status())
				{
					ELOG("bad connection detected");
					{
						mutex::scoped_lock sl(_mtx);
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
				res._state->_data = c;
				res.ready();
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
						res._state->_data = IConnectionPtr();
						res.ready();
						//_asrv->get_io_service().post(bind(ready, IConnectionPtr()));
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
			w._state->_data = IConnectionPtr();
			w.ready();
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
