#ifndef _PGC_PGCONNWRAPPER_HPP_
#define _PGC_PGCONNWRAPPER_HPP_

#include <boost/asio.hpp>
#include <boost/asio/local/basic_endpoint.hpp>
#include <libpq-fe.h>

namespace pgc
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	class PGconnWrapper
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
		PGconn *_lowConn;
		asio::basic_raw_socket<SockProtocol> _sock;
		bool	_integerDatetimes;

	private:
		static void onWaitRead(
			function<void()> ready,
			const system::error_code& error, 
			std::size_t bytes_transferre);

		static void onWaitWrite(
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

		operator PGconn *() const;
		void waitRead(function<void()> ready);
		void waitWrite(function<void()> ready);
	};
	typedef shared_ptr<PGconnWrapper> PGconnWrapperPtr;
}
#endif
