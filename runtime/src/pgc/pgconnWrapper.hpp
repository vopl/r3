#ifndef _PGC_PGCONNWRAPPER_HPP_
#define _PGC_PGCONNWRAPPER_HPP_

#include <boost/asio.hpp>
#include <boost/asio/local/basic_endpoint.hpp>
#include <libpq-fe.h>
#include "pgc/istatement.hpp"
#include "pgc/iresult.hpp"

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>

namespace pgc
{
	using namespace boost;
	using namespace boost::multi_index;

	//////////////////////////////////////////////////////////////////////////
	class BindData;
	typedef boost::shared_ptr<BindData> BindDataPtr;

	//////////////////////////////////////////////////////////////////////////
	class PGconnWrapper
		: public boost::enable_shared_from_this<PGconnWrapper>
	{
		struct SockProtocol
		{
			int _family;
			int _type;
			int _protocol;
			
			SockProtocol(int f, int t, int p) : _family(f), _type(t), _protocol(p) {}

			int family() const {return _family;}
			int type() const {return _type;}
			int protocol() const {return _protocol;}

			struct endpoint
			{
				SockProtocol protocol(){ return SockProtocol(0,0,0);}
			};
		};

	private:
		//////////////////////////////////////////////////////////////////////////
		PGconn									*_lowConn;
		asio::basic_raw_socket<SockProtocol>	_sock;
		asio::strand							_sockReadStrand;
		bool									_integerDatetimes;
		posix_time::ptime						_now;

	public:
		//////////////////////////////////////////////////////////////////////////
		//��������� ���������� �������� �������
		bool								_inProcess;
		boost::function<void (IResultPtr)>	_done;
		std::deque<PGresult *>				_results;

		void continueSend();
		void continueRecv();
		void execSimple(const char *sql, boost::function<void (IResultPtr)> done);
		void execPrepare(IStatementPtr s, BindDataPtr data, boost::function<void (IResultPtr)> done);
		void execPrepared(IStatementPtr s, BindDataPtr data, boost::function<void (IResultPtr)> done);


	private:
		//////////////////////////////////////////////////////////////////////////
		//�������������� �������
		static const size_t _maxPreparedStatements = 1000;
		static const size_t _timeoutPreparedStatements = 1000*60*60*12;//millisec

		struct StatementPrepareState
		{
			std::string					_prid;
			IStatementWtr				_stm;
			boost::posix_time::ptime	_timeout;
		};
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
						&StatementPrepareState::_timeout
					>
				>
			> 
		> TPrepareds;

		TPrepareds	_prepareds;

		void cleanPrepareds(function<void()> ready);

	private:
		void onWaitRead(
			function<void()> ready,
			const system::error_code& error, 
			std::size_t bytes_transferre);

		void onWaitWrite(
			function<void()> ready,
			const system::error_code& error, 
			std::size_t bytes_transferre);

	private:
		static int sockFamily(int sock);
		static int sockType(int sock);
	public:
		PGconnWrapper(PGconn *lowConn, asio::io_service &io_service);
		~PGconnWrapper();

		void onOpen();
		void close();

		void beginWork(function<void()> ready);
		void endWork(function<void()> ready);

		bool integerDatetimes();

		operator PGconn *() const;
		void waitRead(function<void()> ready);
		void waitWrite(function<void()> ready);


		void touchPrepared(IStatementWtr p);
		bool hasPrepared(IStatementWtr p);
		std::string getPrid(IStatementWtr p);
		void genPrid(IStatementWtr p);
	};
	typedef shared_ptr<PGconnWrapper> PGconnWrapperPtr;
}
#endif
