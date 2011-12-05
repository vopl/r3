#include "pch.h"
#include "db.hpp"
#include "connection.hpp"
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
			PGconnWrapperPtr _con;
			function<void (IConnectionPtr)>	_waiter;
		};
		std::deque<SWorkPair> readyWaiters;

		PGconnWrapperPtr pcw;
		{
			mutex::scoped_lock sl(_mtx);

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
						pcw.reset(new PGconnWrapper(PQconnectStart(_conninfo.c_str()), _asrv->get_io_service()));

						if(CONNECTION_BAD == PQstatus(*pcw))
						{
							pcw.reset();
							std::cerr<<__FUNCTION__<<": CONNECTION_BAD, goto sleep"<<std::endl;
							assert(0);
						}
						else
						{
							_startConnections.insert(pcw);
						}
					}
					break;
				}
			}
		}

		if(pcw)
		{
			makeConnection_poll(pcw);
		}

		BOOST_FOREACH(SWorkPair &wp, readyWaiters)
		{
			IConnectionPtr c(new Connection(shared_from_this(), wp._con));
			wp._waiter(c);
		}

	}

	//////////////////////////////////////////////////////////////////////////
	void Db::makeConnection_poll(PGconnWrapperPtr pcw)
	{
		switch(PQstatus(*pcw))
		{
		case CONNECTION_STARTED:
			std::cerr<<"Waiting for connection to be made."<<std::endl;
			break;
		case CONNECTION_MADE:
			std::cerr<<"Connection OK; waiting to send."<<std::endl;
			break;
		case CONNECTION_AWAITING_RESPONSE:
			std::cerr<<"Waiting for a response from the postmaster."<<std::endl;
			break;
		case CONNECTION_AUTH_OK:
			std::cerr<<"Received authentication; waiting for backend startup."<<std::endl;
			break;
		case CONNECTION_SETENV:
			std::cerr<<"Negotiating environment."<<std::endl;
			break;
		case CONNECTION_SSL_STARTUP:
			std::cerr<<"Negotiating SSL."<<std::endl;
			break;
		case CONNECTION_NEEDED:
			std::cerr<<"Internal state: connect() needed"<<std::endl;
			break;
		}

		switch(PQconnectPoll(*pcw))
		{
		case PGRES_POLLING_FAILED:
			std::cerr<<__FUNCTION__<<": PGRES_POLLING_FAILED, goto sleep ("<<PQerrorMessage(*pcw)<<")"<<std::endl;
			{
				mutex::scoped_lock sl(_mtx);
				_startConnections.erase(pcw);
			}
			assert(0);
			return;
		case PGRES_POLLING_READING:
			//std::cerr<<__FUNCTION__<<": PGRES_POLLING_READING"<<std::endl;
			pcw->waitRead(bind(&Db::makeConnection_poll, shared_from_this(), pcw));
			break;
		case PGRES_POLLING_WRITING:
			//std::cerr<<__FUNCTION__<<": PGRES_POLLING_WRITING"<<std::endl;
			pcw->waitWrite(bind(&Db::makeConnection_poll, shared_from_this(), pcw));
			break;
		case PGRES_POLLING_OK:
			std::cerr<<__FUNCTION__<<": PGRES_POLLING_OK"<<std::endl;
			{
				mutex::scoped_lock sl(_mtx);
				_readyConnections.insert(pcw);
			}
			balanceConnections();
			return;
		default:
			break;
		}
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
		IConnectionPtr c;

		bool needBalanceConnections = false;
		{
			mutex::scoped_lock sl(_mtx);
			if(_readyConnections.size())
			{
				c.reset(new Connection(shared_from_this(), *_readyConnections.begin()));
				_workConnections.insert(*_readyConnections.begin());
				_readyConnections.erase(_readyConnections.begin());
			}
			else
			{
				_waiters.push_back(ready);

				needBalanceConnections = _startConnections.size() + _readyConnections.size() + _workConnections.size() < _maxConnections;
			}
		}

		if(c)
		{
			ready(c);
		}
		
		if(needBalanceConnections)
		{
			balanceConnections();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void Db::deinitialize()
	{
		mutex::scoped_lock sl(_mtx);
		assert(0);
	}


}
