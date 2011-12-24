#ifndef _NET_CHANNELSOCKET_HPP_
#define _NET_CHANNELSOCKET_HPP_
#include "net/ichannel.hpp"

namespace net
{
	using namespace async;

	typedef ip::tcp::socket TSocket;
	typedef shared_ptr<TSocket> TSocketPtr;

	typedef ssl::stream<ip::tcp::socket> TSocketSsl;
	typedef shared_ptr<TSocketSsl> TSocketSslPtr;

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

			Sock(TSocketPtr socket);
			Sock(TSocketSslPtr socketSsl);

			template <class Buffer, class Handler>
			void read(Buffer b, Handler h);

			template <class Buffer, class Handler>
			void write(Buffer b, Handler h);

			void close();
		} _sock;
		io_service::strand	_strand;

		//////////////////////////////////////////////////////////////////////////
		struct STransferState
		{
			SPacket									_packet;
			boost::uint32_t							_header[1];
			size_t									_transferedSize;
		};

		//////////////////////////////////////////////////////////////////////////
		struct STransferStateSend
			: STransferState
		{
			Result<error_code>	_res;
			STransferStateSend(
				const SPacket &packet, 
				Result<error_code> res);
		};
		typedef shared_ptr<STransferStateSend> STransferStateSendPtr;

		//////////////////////////////////////////////////////////////////////////
		struct STransferStateReceive
			: STransferState
		{
			Result2<error_code, SPacket>	_res;
			STransferStateReceive(Result2<error_code, SPacket> res);
		};
		typedef shared_ptr<STransferStateReceive> STransferStateReceivePtr;

	private:
		void onReceive(STransferStateReceivePtr ts, system::error_code ec, size_t size);
		void onSend(STransferStateSendPtr ts, system::error_code ec, size_t size);

	public:
		ChannelSocket(TSocketSslPtr socket);
		ChannelSocket(TSocketPtr socket);
		~ChannelSocket();

		virtual Result2<error_code, SPacket> receive();
		virtual Result<error_code> send(const SPacket &p);

		void close();
	};
}

#endif
