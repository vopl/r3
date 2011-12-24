#ifndef _NET_CHANNELSOCKET_HPP_
#define _NET_CHANNELSOCKET_HPP_
#include "net/ichannel.hpp"
#include "async/service.hpp"

namespace net
{
	using namespace async;

	typedef ip::tcp::socket TSocket;
	typedef shared_ptr<TSocket> TSocketPtr;

	typedef ssl::stream<ip::tcp::socket> TSocketSsl;
	typedef shared_ptr<TSocketSsl> TSocketSslPtr;

	typedef ssl::context TSslContext;
	typedef shared_ptr<TSslContext> TSslContextPtr;

	//////////////////////////////////////////////////////////////////////////
	class ChannelSocket;
	typedef boost::shared_ptr<ChannelSocket> ChannelSocketPtr;

	class ChannelSocket
		: public IChannel
		, public enable_shared_from_this<ChannelSocket>
	{
		struct Sock
		{
			TSocketPtr			_socket;
			TSocketSslPtr		_socketSsl;
			TSslContextPtr		_sslContext;

			Sock(TSocketPtr socket);
			Sock(TSocketSslPtr socketSsl, TSslContextPtr sslContext);

			template <class Buffer, class Handler>
			void read(Buffer b, Handler h);

			template <class Buffer, class Handler>
			void write(Buffer b, Handler h);

			void close();
		} _sock;


	private:

		typedef std::deque<Result2<error_code, SPacket> > TReceives;
		typedef std::deque<std::pair<Result<error_code>, SPacket> > TSends;


		mutex		_mtxReceives;
		TReceives	_receives;
		void receive_f();

		mutex		_mtxSends;
		TSends		_sends;
		void send_f();


	public:
		ChannelSocket(TSocketPtr socket);
		ChannelSocket(TSocketSslPtr socket, TSslContextPtr sslContext);
		~ChannelSocket();

		virtual Result2<error_code, SPacket> receive();
		virtual Result<error_code> send(const SPacket &p);

		void close();
	};
}

#endif
