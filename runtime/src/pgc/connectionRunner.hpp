#ifndef _PGC_CONNECTIONRUNNER_HPP_
#define _PGC_CONNECTIONRUNNER_HPP_

#include "connectionLow.hpp"
#include "pgc/istatement.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	class BindData;
	typedef boost::shared_ptr<BindData> BindDataPtr;

	//////////////////////////////////////////////////////////////////////////
	/*
		функционал над ConnectionLow

		1. исполнение простейших запросов (query, prepare, queryPrepared, ...)
		2. организация очереди простейших запросов (постгрес исполняет только последовательно)
	*/

	//////////////////////////////////////////////////////////////////////////
	class ConnectionRunner;
	typedef shared_ptr<ConnectionRunner> ConnectionRunnerPtr;
	class ConnectionRunner
		: public ConnectionLow
	{
	private:
		ConnectionRunnerPtr shared_from_this();

	private:
		typedef boost::function<void (IResultPtr)> TDone;

	private:
		//////////////////////////////////////////////////////////////////////////
		//поддержка исполнения простого запроса
		bool					_inProcess;
		TDone					_done;
		std::deque<PGresult *>	_results;

		void processStart();
		void onProcessCanSend(const system::error_code &ec);
		void onProcessCanRecv(const system::error_code &ec);
		void processStop();

	private:
		//////////////////////////////////////////////////////////////////////////
		//поддержка очередности
		enum ERequestType
		{
			ertQuery,
			ertPrepare,
			ertQueryPrepared,
		};
		struct SRequest
		{
			ERequestType	_ert;
			TDone			_done;
			SRequest(ERequestType ert, const TDone &done) :_ert(ert), _done(done){}
		};
		typedef shared_ptr<SRequest> SRequestPtr;

		struct SQuery : SRequest
		{
			std::string		_sql;
			SQuery(const TDone &done, const std::string &sql) :SRequest(ertQuery, done), _sql(sql){}
		};
		struct SPrepare : SRequest
		{
			std::string		_prid;
			std::string		_sql;
			BindDataPtr		_data;
			SPrepare(const TDone &done, const std::string &prid, std::string sql, BindDataPtr data) :SRequest(ertPrepare, done), _prid(prid), _sql(sql), _data(data){}
		};
		struct SQueryPrepared : SRequest
		{
			std::string		_prid;
			BindDataPtr		_data;
			SQueryPrepared(const TDone &done, const std::string &prid, BindDataPtr data) :SRequest(ertQueryPrepared, done), _prid(prid), _data(data){}
		};

		typedef std::deque<SRequestPtr> TRequests;
		TRequests	_requests;
		mutex		_requestsMtx;

	private:
		void runNextRequest(bool isLocked);

	public:
		ConnectionRunner(PGconn *pgcon, asio::io_service &io_service);
		~ConnectionRunner();

		void runQuery(
			const char *sql, 
			boost::function<void (IResultPtr)> done);

		void runPrepare(
			const char *prid, 
			std::string sql, 
			BindDataPtr data, 
			boost::function<void (IResultPtr)> done);

		void runQueryPrepared(
			const char *prid, 
			BindDataPtr data, 
			boost::function<void (IResultPtr)> done);

		//а так же всякие describe
		//void runDescribePrepared...
		//void runDescribePortal...

	};
}
#endif
