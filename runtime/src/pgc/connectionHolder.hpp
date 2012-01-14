#ifndef _PGC_CONNECTIONHOLDER_HPP_
#define _PGC_CONNECTIONHOLDER_HPP_

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <libpq-fe.h>
#include "async/service.hpp"
#include "async/future.hpp"
#include "async/mutex.hpp"

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>

#include "statementImpl.hpp"
#include "pgc/result.hpp"
#include "pgc/connection.hpp"

namespace pgc
{
	using namespace boost;
	using namespace multi_index;

	//////////////////////////////////////////////////////////////////////////
	class BindData;
	typedef shared_ptr<BindData> BindDataPtr;

	//////////////////////////////////////////////////////////////////////////
	class DbImpl;
	typedef shared_ptr<DbImpl> DbImplPtr;


	//////////////////////////////////////////////////////////////////////////
	class ConnectionHolder
		: public enable_shared_from_this<ConnectionHolder>
	{
	private:
		//��� ��������� ������������� ������ ��� asio
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

		//��������� ��������������� �������
		struct StatementPrepareState
		{
			//�������������
			std::string					_prid;
			//���������, � ���� ���������� �����, sql
			StatementImplWtr			_stm;
			//����� ���������� �������
			posix_time::ptime			_accessTime;
		};

		//���������, ������������ �� �������� � ������ �������
		typedef multi_index_container<
			StatementPrepareState,
			indexed_by<
				ordered_unique<
					member<
						StatementPrepareState, 
						StatementImplWtr,
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

		//������� �������� ��������
		enum ERequestType
		{
			ertQuery,
			ertQueryWithPrepare,
			ertQueryEndWork,
		};
		struct SRequest
		{
			ERequestType				_ert;
			async::Future<Result>	_res;
			SRequest(ERequestType ert, async::Future<Result> res)
				: _ert(ert), _res(res)
			{}
		};
		typedef boost::shared_ptr<SRequest> SRequestPtr;

		struct SRequestQuery
			: SRequest
		{
			std::string	_sql;
			BindDataPtr	_bindData;
			SRequestQuery(async::Future<Result> res, std::string sql, BindDataPtr bindData)
				: SRequest(ertQuery, res), _sql(sql), _bindData(bindData)
			{}
		};
		struct SRequestQueryWithPrepare
			: SRequest
		{
			StatementImplPtr	_s;
			BindDataPtr			_bindData;
			SRequestQueryWithPrepare(async::Future<Result> res, StatementImplPtr s, BindDataPtr bindData)
				: SRequest(ertQueryWithPrepare, res), _s(s), _bindData(bindData)
			{}
		};

		struct SRequestEndWork
			: SRequest
		{
			SRequestEndWork(async::Future<Result> res)
				: SRequest(ertQueryEndWork, res)
			{}
		};

		typedef std::deque<SRequestPtr> TRequests;

		typedef asio::basic_stream_socket<PGSockProtocol> PGSock;
	private:
		//////////////////////////////////////////////////////////////////////////
		DbImplPtr					_db;
		PGconn						*_pgcon;
		PGSock						_sock;
		bool						_integerDatetimes;

	private:
		//����������� �� ���������� ������������ �������� ��������
		static const size_t	_max = 1000;
		//������� �������� �� �����������
		static const size_t	_timeout = 1000*60*5;//millisec
		//����� �� ������ ������ ������
		posix_time::ptime	_now;
		//��������� � ���������
		TPrepareds			_prepareds;

		TRequests			_requests;
		mutex				_mtx;

		async::Mutex		_mtxProcess;

	private:
		bool hasPrepared(StatementImplWtr p);
		std::string getPrid(StatementImplWtr p);
		void genPrid(StatementImplWtr p);
		void delPrepared(StatementImplWtr p);

	private:
		//��������� ��� ������������� ������������� ������ � asio
		static int sockFamily(int sock);
		static int sockType(int sock);

	private:
		void setResult(async::Future<Result> &res, bool success=false);

	private:
		void processRequest();

	private:
		void processSingle(async::Future<Result> res);
		void processQueryWithPrepare(async::Future<Result> res, StatementImplPtr s, BindDataPtr bindData);

	private:
		void runQuery_f(async::Future<Result> res, const std::string &sql, BindDataPtr bindData = BindDataPtr());

		void runPrepare_f(
			async::Future<Result> res, 
			const std::string &prid, 
			const std::string &sql, 
			BindDataPtr bindData);

		void runQueryPrepared_f(
			async::Future<Result> res, 
			const std::string &prid, 
			BindDataPtr bindData);

		//� ��� �� ������ describe
		//void runDescribePrepared...
		//void runDescribePortal...

	private:
		void runQueryWithPrepare_f(async::Future<Result> res, StatementImplPtr s, BindDataPtr bindData);

	private:
		void runEndWork_f(async::Future<Result> res);

	public:
		async::Future<system::error_code> send0();
		async::Future<system::error_code> recv0();

	public:
		ConnectionHolder(DbImplPtr db, PGconn *pgcon);
		~ConnectionHolder();

		PGconn *pgcon();

		void onOpen();
		EConnectionStatus status();
		void close();

		bool integerDatetimes();

	public:
		void runQuery(async::Future<Result> res, const std::string &sql, BindDataPtr bindData);
		void runQueryWithPrepare(async::Future<Result> res, Statement s, BindDataPtr bindData);

	public:
		void beginWork();
		void endWork();


	};
	typedef shared_ptr<ConnectionHolder> ConnectionHolderPtr;
}
#endif
