#include "pch.h"
#include "connectionProcessor.hpp"
#include "result.hpp"
#include "bindData.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	ConnectionProcessorPtr ConnectionProcessor::shared_from_this()
	{
		return static_pointer_cast<ConnectionProcessor>(ConnectionLow::shared_from_this());
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionProcessor::processStart()
	{
		assert(_inProcess);
		assert(pgcon());

		if(PQflush(pgcon()))
		{
			waitSend(bind(&ConnectionProcessor::onProcessCanSend, shared_from_this(), _1));
			return;
		}

		waitRecv(bind(&ConnectionProcessor::onProcessCanRecv, shared_from_this(), _1));
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionProcessor::onProcessCanSend(const system::error_code &ec)
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
			waitSend(bind(&ConnectionProcessor::onProcessCanSend, shared_from_this(), _1));
			return;
		}

		waitRecv(bind(&ConnectionProcessor::onProcessCanRecv, shared_from_this(), _1));
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionProcessor::onProcessCanRecv(const system::error_code &ec)
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
					bind(&ConnectionProcessor::onProcessCanRecv, shared_from_this(), _1));

				return;
			}

			pgr = PQgetResult(pgcon());
		}

		processStop();
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionProcessor::processStop()
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
				done(IResultPtr(new Result(pgr, shared_from_this())));
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

		runNextRequest();
	}











	//////////////////////////////////////////////////////////////////////////
	void ConnectionProcessor::runNextRequest()
	{
		if(_inProcess)
		{
			return;
		}

		if(_requests.empty())
		{
			this->queueEmpty();
			return;
		}

		switch(status())
		{
		case ecsNull:
		case ecsLost:
			//соединение утеряно или закрыто
			{
				std::cerr<<__FUNCTION__<<": connection lost or closed"<<std::endl;
				IResultPtr nullResult;
				TRequests requests;
				requests.swap(_requests);
				BOOST_FOREACH(SRequestPtr &r, requests)
				{
					r->_done(nullResult);
					r.reset();
				}
			}
			return;
		}

		SRequestPtr r = _requests.front();
		_requests.pop_front();

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
			processStop();
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
	bool ConnectionProcessor::inProcess()
	{
		return _inProcess;
	}
	
	//////////////////////////////////////////////////////////////////////////
	void ConnectionProcessor::queueEmpty()
	{
		//тут ничего, производный класс должен получить уведомление
	}





	//////////////////////////////////////////////////////////////////////////
	ConnectionProcessor::ConnectionProcessor(PGconn *pgcon, asio::io_service &io_service)
		: ConnectionLow(pgcon, io_service)
		, _inProcess(false)
		, _done()
		, _results()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionProcessor::~ConnectionProcessor()
	{
		assert(!_inProcess);
		assert(_requests.empty());
	}









	//////////////////////////////////////////////////////////////////////////
	void ConnectionProcessor::runQuery(const std::string &sql, boost::function<void (IResultPtr)> done)
	{
		_requests.push_back(SRequestPtr(new SQuery(done, sql)));
		runNextRequest();
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionProcessor::runPrepare(const std::string &prid, const std::string &sql, BindDataPtr data, boost::function<void (IResultPtr)> done)
	{
		_requests.push_back(SRequestPtr(new SPrepare(done, prid, sql, data)));
		runNextRequest();
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionProcessor::runQueryPrepared(const std::string &prid, BindDataPtr data, boost::function<void (IResultPtr)> done)
	{
		_requests.push_back(SRequestPtr(new SQueryPrepared(done, prid, data)));
		runNextRequest();
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionProcessor::close()
	{
		assert(!_inProcess);
		assert(_requests.empty());

		ConnectionLow::close();
	}

}
