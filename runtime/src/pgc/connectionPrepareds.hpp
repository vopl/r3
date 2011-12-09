#ifndef _PGC_CONNECTIONPREPAREDS_HPP_
#define _PGC_CONNECTIONPREPAREDS_HPP_

#include "connectionProcessor.hpp"

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>

namespace pgc
{
	using namespace boost::multi_index;

	//////////////////////////////////////////////////////////////////////////
	class ConnectionPrepareds;
	typedef shared_ptr<ConnectionPrepareds> ConnectionPreparedsPtr;
	class ConnectionPrepareds
		: public ConnectionProcessor
	{
	private:
		//состояние подготовленного запроса
		struct StatementPrepareState
		{
			//идентификатор
			std::string					_prid;
			//экземпляр, у него уникальный адрес, sql
			IStatementWtr				_stm;
			//время последнего доступа
			boost::posix_time::ptime	_accessTime;
		};

		//контейнер, индексирован по таймауту и адресу запроса
		typedef multi_index_container<
			StatementPrepareState,
			indexed_by<
				ordered_unique<
					member<
						StatementPrepareState, 
						IStatementWtr,
						&StatementPrepareState::_stm
					>
				>,
				ordered_non_unique<
					member<
						StatementPrepareState, 
						boost::posix_time::ptime,
						&StatementPrepareState::_accessTime
					>
				>
			> 
		> TPrepareds;

	private:
		//ограничение на количество одновременно хранимых запросов
		static const size_t	_max = 10000000;
		//таймаут удаления по бездействию
		static const size_t	_timeout = 1000*60*10;//millisec
		//время на момент начала работы
		posix_time::ptime	_now;
		//контейнер с запросами
		TPrepareds			_prepareds;

	private:
		bool hasPrepared(IStatementWtr p);
		std::string getPrid(IStatementWtr p);
		void genPrid(IStatementWtr p);
		void delPrepared(IStatementWtr p);

		void cleanPrepareds(posix_time::ptime boundATime, TDone done, IResultPtr result);

	private:
		ConnectionPreparedsPtr shared_from_this();

	private:
		void onPrepare(IStatementPtr s,
			BindDataPtr data,
			boost::function<void (IResultPtr)> done,
			IResultPtr result,
			bool inTrans);

		void onSavepoint(IStatementPtr s,
			BindDataPtr data,
			boost::function<void (IResultPtr)> done,
			IResultPtr result);

		void onRollbackSavepoint(IStatementPtr s,
			BindDataPtr data,
			boost::function<void (IResultPtr)> done,
			IResultPtr result);

		void onReleaseSavepoint(IStatementPtr s,
			BindDataPtr data,
			boost::function<void (IResultPtr)> done,
			IResultPtr result);


		void onQueryPrepared(IStatementPtr s,
			BindDataPtr data,
			boost::function<void (IResultPtr)> done,
			IResultPtr result);

	private:
		//очередь
		enum ERequestType
		{
			ertQueryWithPrepare,
			ertCleanPrepareds,
		};
		struct SRequest
		{
			ERequestType	_ert;
			TDone			_done;
			SRequest(ERequestType ert, TDone done)
				: _ert(ert), _done(done)
			{}
		};
		typedef shared_ptr<SRequest> SRequestPtr;

		struct SQueryWithPrepare
			: SRequest
		{
			IStatementPtr	_s;
			BindDataPtr		_data;
			SQueryWithPrepare(IStatementPtr s, BindDataPtr data, TDone done)
				: SRequest(ertQueryWithPrepare, done), _s(s), _data(data)
			{}
		};

		struct SCleanPrepareds
			: SRequest
		{
			SCleanPrepareds(TDone done)
				: SRequest(ertCleanPrepareds, done)
			{}
		};

		typedef std::deque<SRequestPtr> TRequests;
		TRequests	_requests;
		bool		_inProcess;

		virtual void queueEmpty();
		void runNextRequest();
		void requestTerminator(TDone done, IResultPtr result);

	public:
		ConnectionPrepareds(PGconn *pgcon, asio::io_service &io_service);
		~ConnectionPrepareds();

		void beginWork();
		void endWork(boost::function<void (IResultPtr)> done);

		void runQueryWithPrepare(IStatementPtr s,
			BindDataPtr data,
			boost::function<void (IResultPtr)> done);

		void close();
	};
}
#endif
