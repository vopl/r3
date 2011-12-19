#ifndef _PGC_CONNECTIONIMPL_HPP_
#define _PGC_CONNECTIONIMPL_HPP_

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <libpq-fe.h>
#include "pgc/iresult.hpp"
#include "pgc/iconnection.hpp"
#include "async/iservice.hpp"
#include "async/result.hpp"

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>


namespace pgc
{
	using namespace boost;
	using namespace multi_index;

	//////////////////////////////////////////////////////////////////////////
	class BindData;
	typedef shared_ptr<BindData> BindDataPtr;


	//////////////////////////////////////////////////////////////////////////
	class ConnectionImpl
		: public enable_shared_from_this<ConnectionImpl>
	{
	private:
		//тип протокола постгресового сокета для asio
		struct PGSockProtocol
		{
			int _family; int _type; int _protocol;
			PGSockProtocol(int f, int t, int p) : _family(f), _type(t), _protocol(p) {}

			int family() const		{return _family;}
			int type() const		{return _type;}
			int protocol() const	{return _protocol;}

			struct endpoint
			{
				PGSockProtocol protocol(){ return PGSockProtocol(0,0,0);}
			};
		};

		//состояние подготовленного запроса
		struct StatementPrepareState
		{
			//идентификатор
			std::string					_prid;
			//экземпляр, у него уникальный адрес, sql
			IStatementWtr				_stm;
			//время последнего доступа
			posix_time::ptime			_accessTime;
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
						posix_time::ptime,
						&StatementPrepareState::_accessTime
					>
				>
			> 
		> TPrepareds;

		typedef asio::basic_stream_socket<PGSockProtocol> PGSock;
	private:
		//////////////////////////////////////////////////////////////////////////
		PGconn						*_pgcon;
		PGSock						_sock;
		asio::io_service::strand	_strand;
		bool						_integerDatetimes;

		async::IServicePtr			_asrv;

	private:
		//ограничение на количество одновременно хранимых запросов
		static const size_t	_max = 100;
		//таймаут удаления по бездействию
		static const size_t	_timeout = 1000*60*5;//millisec
		//время на момент начала работы
		posix_time::ptime	_now;
		//контейнер с запросами
		TPrepareds			_prepareds;

	private:
		bool hasPrepared(IStatementWtr p);
		std::string getPrid(IStatementWtr p);
		void genPrid(IStatementWtr p);
		void delPrepared(IStatementWtr p);

	private:
		//помогалки для инициализации постгресового сокета в asio
		static int sockFamily(int sock);
		static int sockType(int sock);

	private:
		void processSingle(async::Result<IResultPtrs> res);
		void processQueryWithPrepare(async::Result<IResultPtrs> res, IStatementPtr s, BindDataPtr data);

	public:
		async::Result<system::error_code> send0();
		async::Result<system::error_code> recv0();

	public:
		ConnectionImpl(PGconn *pgcon, async::IServicePtr asrv);
		virtual ~ConnectionImpl();

		PGconn *pgcon();

		void onOpen();
		EConnectionStatus status();
		void close();

		bool integerDatetimes();

		void dispatch(function<void()> action);

	public:
		void runQuery(async::Result<IResultPtrs> res, const std::string &sql);

		void runPrepare(
			async::Result<IResultPtrs> res, 
			const std::string &prid, 
			const std::string &sql, 
			BindDataPtr data);

		void runQueryPrepared(
			async::Result<IResultPtrs> res, 
			const std::string &prid, 
			BindDataPtr data);

		//а так же всякие describe
		//void runDescribePrepared...
		//void runDescribePortal...

	public:
		void runQueryWithPrepare(async::Result<IResultPtrs> res, IStatementPtr s, BindDataPtr data);

	public:
		void beginWork();
		void endWork();


	};
	typedef shared_ptr<ConnectionImpl> ConnectionImplPtr;
}
#endif
