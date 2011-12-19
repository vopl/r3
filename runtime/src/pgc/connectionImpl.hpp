#ifndef _PGC_CONNECTIONIMPL_HPP_
#define _PGC_CONNECTIONIMPL_HPP_

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <libpq-fe.h>
#include "pgc/iresult.hpp"
#include "pgc/iconnection.hpp"
#include "async/iservice.hpp"
#include "async/result.hpp"

namespace pgc
{
	using namespace boost;

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

		typedef asio::basic_stream_socket<PGSockProtocol> PGSock;
	private:
		//////////////////////////////////////////////////////////////////////////
		PGconn						*_pgcon;
		PGSock						_sock;
		asio::io_service::strand	_strand;
		bool						_integerDatetimes;

		async::IServicePtr			_asrv;

	private:
		//помогалки для инициализации постгресового сокета в asio
		static int sockFamily(int sock);
		static int sockType(int sock);

	private:
		void processTransmission(async::Result<IResultPtrs> res);

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
		async::Result<IResultPtrs> runQuery(const std::string &sql);

		async::Result<IResultPtrs> runPrepare(
			const std::string &prid, 
			const std::string &sql, 
			BindDataPtr data);

		async::Result<IResultPtrs> runQueryPrepared(
			const std::string &prid, 
			BindDataPtr data);

		//а так же всякие describe
		//void runDescribePrepared...
		//void runDescribePortal...

	};
	typedef shared_ptr<ConnectionImpl> ConnectionImplPtr;
}
#endif
