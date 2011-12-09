#include "pch.h"
#include "db.hpp"
#include <boost/bind.hpp>
#include <boost/foreach.hpp>

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
			function<void (IConnectionPtr)>	_waiter;
		};
		std::deque<SWorkPair> readyWaiters;
		std::deque<size_t> lostsConnections;

		ConnectionPreparedsPtr pcw;
		{
			mutex::scoped_lock sl(_mtx);

			if(_waiters.empty())
			{
				int k=220;
			}
			while(!_waiters.empty())
			{
				if(!_readyConnections.empty())
				{
					SWorkPair swp = {*_readyConnections.begin(), _waiters.front()};
					readyWaiters.push_back(swp);

					_workConnections.insert(*_readyConnections.begin());
					_readyConnections.erase(_readyConnections.begin());
					_waiters.erase(_waiters.begin());
				}
				else
				{
					if(	_startConnections.empty() && 
						_readyConnections.size() + _workConnections.size() < _maxConnections)
					{
						pcw.reset(new ConnectionPrepareds(PQconnectStart(_conninfo.c_str()), _asrv->get_io_service()));
						_startConnections.insert(pcw);
					}
					break;
				}
			}

			while(	!_readyConnections.empty() &&
					_readyConnections.size() + _workConnections.size() + _startConnections.size() > _maxConnections)
			{
				(*_readyConnections.begin())->close();
				_readyConnections.erase(_readyConnections.begin());
				lostsConnections.push_back(_readyConnections.size() + _workConnections.size());
			}
		}

		if(pcw)
		{
			makeConnection_poll(system::errc::make_error_code(system::errc::success), pcw);
		}

		BOOST_FOREACH(SWorkPair &wp, readyWaiters)
		{
			IConnectionPtr c(new ConnectionHolder(shared_from_this(), wp._con));
			if(wp._waiter)
			{
				wp._waiter(c);
			}
		}

		BOOST_FOREACH(size_t numConnections, lostsConnections)
		{
			_onConnectionLost(numConnections);
		}

	}

	//////////////////////////////////////////////////////////////////////////
	void Db::makeConnection_poll(const system::error_code &ec, ConnectionPreparedsPtr pcw)
	{
		if(ec)
		{
			std::cerr<<__FUNCTION__<<": "<<ec.message()<<std::endl;
		}

		switch(PQstatus(pcw->pgcon()))
		{
		case CONNECTION_OK:
			std::cerr<<"CONNECTION_OK"<<std::endl;
			break;
		case CONNECTION_BAD:
			std::cerr<<"CONNECTION_BAD"<<std::endl;
			break;
		case CONNECTION_STARTED:
			//std::cerr<<"Waiting for connection to be made."<<std::endl;
			break;
		case CONNECTION_MADE:
			std::cerr<<"Connection OK; waiting to send."<<std::endl;
			break;
		case CONNECTION_AWAITING_RESPONSE:
			//std::cerr<<"Waiting for a response from the postmaster."<<std::endl;
			break;
		case CONNECTION_AUTH_OK:
			//std::cerr<<"Received authentication; waiting for backend startup."<<std::endl;
			break;
		case CONNECTION_SETENV:
			//std::cerr<<"Negotiating environment."<<std::endl;
			break;
		case CONNECTION_SSL_STARTUP:
			//std::cerr<<"Negotiating SSL."<<std::endl;
			break;
		case CONNECTION_NEEDED:
			//std::cerr<<"Internal state: connect() needed"<<std::endl;
			break;
		}

		switch(PQconnectPoll(pcw->pgcon()))
		{
		case PGRES_POLLING_FAILED:
			std::cerr<<__FUNCTION__<<": PGRES_POLLING_FAILED, wait timeout ("<<PQerrorMessage(pcw->pgcon())<<")"<<std::endl;
			{
				mutex::scoped_lock sl(_mtx);
				_startConnections.erase(pcw);

				TimeoutPtr timeout(new Timeout(_asrv->get_io_service(), boost::posix_time::seconds(1)));
				_timeouts.insert(timeout);
				std::cout<<"-----------_timeouts.insert(timeout);"<<_timeouts.size()<<std::endl;
				timeout->async_wait(
					bind(&Db::onReconnectTimer, shared_from_this(), timeout, _1));
			}
			return;
		case PGRES_POLLING_READING:
			//std::cerr<<__FUNCTION__<<": PGRES_POLLING_READING"<<std::endl;
			pcw->waitRecv(bind(&Db::makeConnection_poll, shared_from_this(), _1, pcw));
			break;
		case PGRES_POLLING_WRITING:
			//std::cerr<<__FUNCTION__<<": PGRES_POLLING_WRITING"<<std::endl;
			pcw->waitSend(bind(&Db::makeConnection_poll, shared_from_this(), _1, pcw));
			break;
		case PGRES_POLLING_OK:
			//std::cerr<<__FUNCTION__<<": PGRES_POLLING_OK"<<std::endl;
			
			{
				pcw->onOpen();
				size_t numConnections=0;
				{
					mutex::scoped_lock sl(_mtx);
					_startConnections.erase(pcw);
					_readyConnections.insert(pcw);
					numConnections = _readyConnections.size() + _workConnections.size();
				}
				_onConnectionMade(numConnections);
				balanceConnections();
			}
			return;
		default:
			{
				int k=220;
			}
			break;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void Db::onReconnectTimer(TimeoutPtr t, const boost::system::error_code& ec)
	{
		{
			mutex::scoped_lock sl(_mtx);
			_timeouts.erase(t);
			std::cout<<"-----------_timeouts.erase(t);"<<_timeouts.size()<<std::endl;
		}

		if(!ec)
		{
			balanceConnections();
		}
		else
		{
			std::cout<<ec.message()<<std::endl;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void Db::unwork(ConnectionPreparedsPtr pcw)
	{
		if(ecsOk == pcw->status())
		{
			{
				mutex::scoped_lock sl(_mtx);

				TSConnectins::iterator iter = _workConnections.find(pcw);
				if(_workConnections.end() != iter)
				{
					if(_maxConnections < _readyConnections.size() + _workConnections.size() + _startConnections.size())
					{
						_workConnections.erase(iter);
						pcw->close();
						pcw.reset();
					}
					else
					{
						_workConnections.erase(iter);
						_readyConnections.insert(pcw);
					}
				}
			}
		}
		else
		{
			size_t numConnections = 0;
			{
				mutex::scoped_lock sl(_mtx);
				assert(_workConnections.end() != _workConnections.find(pcw));
				_workConnections.erase(pcw);
				numConnections = _readyConnections.size() + _workConnections.size();
			}
			_onConnectionLost(numConnections);
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
	void Db::allocConnection(function<void (IConnectionPtr)> ready)
	{
		ConnectionPreparedsPtr pcw;

		bool unableAlloc = false;
		{
			mutex::scoped_lock sl(_mtx);
			if(_readyConnections.size())
			{
				pcw = *_readyConnections.begin();
				_workConnections.insert(pcw);
				_readyConnections.erase(_readyConnections.begin());
			}
			else
			{
				if(_maxConnections)
				{
					_waiters.push_back(ready);
				}
				else
				{
					if(_startConnections.size() + _workConnections.size())
					{
						_waiters.push_back(ready);
					}
					else
					{
						unableAlloc = true;
					}
				}
			}
		}

		if(pcw)
		{
			IConnectionPtr c(new ConnectionHolder(shared_from_this(), pcw));
			ready(c);
		}
		else if(unableAlloc)
		{
			ready(IConnectionPtr());
		}
		
		balanceConnections();
	}

	//////////////////////////////////////////////////////////////////////////
	void Db::deinitialize()
	{
		std::deque<function<void (IConnectionPtr)> > waiters;

		{
			mutex::scoped_lock sl(_mtx);

			//////////////////////////////////////////////////////////////////////////
			system::error_code ec;
			BOOST_FOREACH(TimeoutPtr &t, _timeouts)
			{
				t->cancel(ec);
			}
			_timeouts.clear();

			_maxConnections = 0;
			_conninfo.clear();
			waiters.swap(_waiters);
		}
		BOOST_FOREACH(function<void (IConnectionPtr)> &w, waiters)
		{
			w(IConnectionPtr());
		}
		balanceConnections();

		//_onConnectionMade.swap(function<void (size_t)>());
		//_onConnectionLost.swap(function<void (size_t)>());

// 		//////////////////////////////////////////////////////////////////////////
// 		BOOST_FOREACH(ConnectionPreparedsPtr &c, _startConnections)
// 		{
// 			c->close();
// 		}
// 		_startConnections.clear();
// 		BOOST_FOREACH(ConnectionPreparedsPtr &c, _readyConnections)
// 		{
// 			c->close();
// 		}
// 		_readyConnections.clear();
// 		BOOST_FOREACH(ConnectionPreparedsPtr &c, _workConnections)
// 		{
// 			c->close();
// 		}
// 		_workConnections.clear();
// 
// 		//////////////////////////////////////////////////////////////////////////
// 		_waiters.clear();
	}


}
