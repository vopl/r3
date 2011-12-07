#include "pch.h"
#include "connectionRunner.hpp"
#include "result.hpp"
#include "bindData.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	ConnectionRunnerPtr ConnectionRunner::shared_from_this()
	{
		return static_pointer_cast<ConnectionRunner>(ConnectionLow::shared_from_this());
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionRunner::processStart()
	{
		assert(_inProcess);
		assert(pgcon());

		if(PQflush(pgcon()))
		{
			waitSend(bind(&ConnectionRunner::onProcessCanSend, shared_from_this(), _1));
			return;
		}

		waitRecv(bind(&ConnectionRunner::onProcessCanRecv, shared_from_this(), _1));
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionRunner::onProcessCanSend(const system::error_code &ec)
	{
		assert(_inProcess);
		if(ec)
		{
			processStop();
			return;
		}

		assert(pgcon());
		if(PQflush(pgcon()))
		{
			waitSend(bind(&ConnectionRunner::onProcessCanSend, shared_from_this(), _1));
			return;
		}

		waitRecv(bind(&ConnectionRunner::onProcessCanRecv, shared_from_this(), _1));
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionRunner::onProcessCanRecv(const system::error_code &ec)
	{
		assert(_inProcess);
		if(ec)
		{
			processStop();
			return;
		}

		assert(pgcon());
		if(!PQconsumeInput(pgcon()))
		{
			std::cerr<<__FUNCTION__<<": "<<PQerrorMessage(pgcon())<<std::endl;
		}

		PGresult *pgr = PQgetResult(pgcon());
		while(pgr)
		{
			_results.push_back(pgr);

			if(!PQconsumeInput(pgcon()))
			{
				std::cerr<<__FUNCTION__<<": "<<PQerrorMessage(pgcon())<<std::endl;
			}
			if(PQisBusy(pgcon()))
			{
				waitRecv(
					bind(&ConnectionRunner::onProcessCanRecv, shared_from_this(), _1));

				return;
			}

			pgr = PQgetResult(pgcon());
		}

		processStop();
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionRunner::processStop()
	{
		assert(_inProcess);

		if(_done)
		{
			_inProcess = false;

			std::deque<PGresult *> results;
			results.swap(_results);

			boost::function<void (IResultPtr)> done;
			done.swap(_done);

			BOOST_FOREACH(PGresult *pgr, results)
			{
				assert(!"перепеши конструктор результа");
				//done(IResultPtr(new Result(pgr, shared_from_this())));
			}
		}
		else
		{
			BOOST_FOREACH(PGresult *pgr, _results)
			{
				PQclear(pgr);
			}
			_results.clear();
			assert(_inProcess);
			_inProcess = false;
		}

		runNextRequest(false);
	}











	//////////////////////////////////////////////////////////////////////////
	void ConnectionRunner::runNextRequest(bool isLocked)
	{
		SRequestPtr r;
		if(isLocked)
		{
			mutex::scoped_lock sl(_requestsMtx);
			if(!_requests.empty())
			{
				r = _requests.front();
				_requests.pop_front();
			}
		}
		else
		{
			if(!_requests.empty())
			{
				r = _requests.front();
				_requests.pop_front();
			}
		}

		if(!r)
		{
			return;
		}

		assert(!_inProcess);
		assert(!_done);
		assert(_results.empty());

		_inProcess = true;
		_done.swap(r->_done);

		int sendStatus = false;
		switch(r->_ert)
		{
		case ertQuery:
			{
				SQuery * q = static_cast<SQuery *>(r.get());
				sendStatus = PQsendQuery(pgcon(), q->_sql.c_str());
			}
			break;
		case ertPrepare:
			{
				SPrepare * q = static_cast<SPrepare *>(r.get());
				int nParams = q->_data?q->_data->typ.size():0;
				const Oid *paramTypes = nParams?&q->_data->typ[0]:NULL;
				sendStatus = PQsendPrepare(
					pgcon(), 
					q->_prid.c_str(), 
					q->_sql.c_str(),
					nParams,
					paramTypes);
			}
			break;
		case ertQueryPrepared:
			{
				SQueryPrepared * q = static_cast<SQueryPrepared *>(r.get());
				int nParams = q->_data?q->_data->typ.size():0;
				const Oid *paramTypes = nParams?&q->_data->typ[0]:NULL;
				const char * const *paramValues = nParams?&q->_data->val[0]:NULL;
				const int *paramLengths = nParams?&q->_data->len[0]:NULL;
				const int *paramFormats = nParams?&q->_data->fmt[0]:NULL;

				sendStatus = PQsendQueryPrepared(
					pgcon(), 
					q->_prid.c_str(),
					nParams,
					paramValues,
					paramLengths,
					paramFormats,
					1);
			}
			break;
		default:
			assert(!"unknown request type");
			return;
		}

		if(!sendStatus)
		{
			std::cerr<<__FUNCTION__<<": "<<PQerrorMessage(pgcon())<<std::endl;
			processStop();
			return;
		}

		processStart();
	}








	//////////////////////////////////////////////////////////////////////////
	ConnectionRunner::ConnectionRunner(PGconn *pgcon, asio::io_service &io_service)
		: ConnectionLow(pgcon, io_service)
		, _inProcess(false)
		, _done()
		, _results()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionRunner::~ConnectionRunner()
	{
		assert(!_inProcess);
	}










	//////////////////////////////////////////////////////////////////////////
	void ConnectionRunner::runQuery(const char *sql, boost::function<void (IResultPtr)> done)
	{
		mutex::scoped_lock sl(_requestsMtx);
		_requests.push_back(SRequestPtr(new SQuery(done, sql)));
		runNextRequest(true);
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionRunner::runPrepare(const char *prid, std::string sql, BindDataPtr data, boost::function<void (IResultPtr)> done)
	{
		mutex::scoped_lock sl(_requestsMtx);
		_requests.push_back(SRequestPtr(new SPrepare(done, prid, sql, data)));
		runNextRequest(true);
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionRunner::runQueryPrepared(const char *prid, BindDataPtr data, boost::function<void (IResultPtr)> done)
	{
		mutex::scoped_lock sl(_requestsMtx);
		_requests.push_back(SRequestPtr(new SQueryPrepared(done, prid, data)));
		runNextRequest(true);
	}
}
