#ifndef _NET_CHANNELIMPLSOCKET_HPP_
#define _NET_CHANNELIMPLSOCKET_HPP_
#include "net/channel.hpp"
#include "channelImplBase.hpp"

namespace net
{
	using namespace boost;
	using namespace boost::asio;

	typedef ssl::stream<ip::tcp::socket> TSocket;
	typedef shared_ptr<TSocket> TSocketPtr;

	//////////////////////////////////////////////////////////////////////////
	class ChannelImplSocket;
	typedef boost::shared_ptr<ChannelImplSocket> ChannelImplSocketPtr;

	class ChannelImplSocket
		: public ChannelImplBase
	{
		TSocketPtr _socket;
		io_service::strand _strand;

		//////////////////////////////////////////////////////////////////////////
		struct STransferState
		{
			SPacket									_packet;
			boost::uint32_t							_header[1];
			ChannelImplSocketPtr					_ch;
			size_t									_transferedSize;
			function<void (system::error_code)>		_fail;
		};

		//////////////////////////////////////////////////////////////////////////
		struct STransferStateSend
			: STransferState
		{
			function<void ()>						_ok;
			STransferStateSend(
				const SPacket &packet, 
				ChannelImplSocketPtr ch, 
				function<void ()> ok,
				function<void (system::error_code)> fail);
		};
		typedef shared_ptr<STransferStateSend> STransferStateSendPtr;

		//////////////////////////////////////////////////////////////////////////
		struct STransferStateReceive
			: STransferState
		{
			function<void (const SPacket &)>		_ok;
			STransferStateReceive(
				ChannelImplSocketPtr ch, 
				function<void (const SPacket &)> ok,
				function<void (system::error_code)> fail);
		};
		typedef shared_ptr<STransferStateReceive> STransferStateReceivePtr;

	private:
		static void onReceive(STransferStateReceivePtr ts, system::error_code ec, size_t size);
		static void onSend(STransferStateSendPtr ts, system::error_code ec, size_t size);

	public:
		ChannelImplSocket(TSocketPtr socket);
		~ChannelImplSocket();
		void receive(
			function<void (const SPacket &)> ok,
			function<void (system::error_code)> fail);

		void send(
			const SPacket &p,
			function<void ()> ok,
			function<void (system::error_code)> fail);

		void close();
	};
}

#endif
