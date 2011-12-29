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
	typedef shared_ptr<ChannelSocket> ChannelSocketPtr;

	class ChannelSocket
		: public IChannel
		, public enable_shared_from_this<ChannelSocket>
	{
		struct Sock
		{
			TSocketPtr			_socket;
			TSocketSslPtr		_socketSsl;
			TSslContextPtr		_sslContext;

			typedef asio::io_service::strand TStrand;
			typedef shared_ptr<TStrand> TStrandPtr;
			TStrandPtr			_sslStrand;

			Sock(TSocketPtr socket);
			Sock(TSocketSslPtr socketSsl, TSslContextPtr sslContext);
			~Sock();

			template <class Buffer, class Handler>
			void read(const Buffer &b, const Handler &h);

			template <class Buffer, class Handler>
			void write(const Buffer &b, const Handler &h);

			void close();

		private:
			static void onSslShutdown(
				const error_code &ec, 
				TSocketSslPtr socketSsl,
				TSslContextPtr sslContextHolder);
		} _sock;


	private:

		typedef std::deque<std::pair<Result<error_code>, SPacket> > TSends;
		typedef function<void(const error_code &ec, const SPacket &p)> TOnReceive;
		typedef std::pair<TOnReceive, size_t> TReceive;
		typedef std::deque<TReceive> TReceives;


		void receiveLoop_f();
		mutex		_mtxReceive;
		TReceives	_receives;

		mutex		_mtxSends;
		TSends		_sends;
		bool		_sendInProcess;
		void send_f();


	public:
		ChannelSocket(TSocketPtr socket);
		ChannelSocket(TSocketSslPtr socket, TSslContextPtr sslContext);
		~ChannelSocket();

		virtual void listen(
			const TOnReceive &onReceive,
			size_t amount);
		virtual Result<error_code> send(const SPacket &p);

		void close();
	};
}

#endif
