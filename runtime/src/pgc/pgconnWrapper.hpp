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

			static SockProtocol v4(){return SockProtocol();}
			static SockProtocol v6(){return SockProtocol();}

			typedef asio::ip::basic_endpoint<SockProtocol> endpoint;
			int family() const {return _family;}
			int type() const {return _type;}
			int protocol() const {return _protocol;}
		};
	private:
		PGconn *_lowConn;
		asio::basic_raw_socket<SockProtocol> _sock;

	private:
		static void onWait(
			function<void()> ready,
			const system::error_code& error, 
			std::size_t bytes_transferre);

	public:
		PGconnWrapper(PGconn *lowConn, asio::io_service &io_service);
		~PGconnWrapper();

		void close();

		operator PGconn *() const;
		void waitRead(function<void()> ready);
		void waitWrite(function<void()> ready);
	};
	typedef shared_ptr<PGconnWrapper> PGconnWrapperPtr;
}
#endif
