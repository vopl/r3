#ifndef _NET_CHANNELIMPL_HPP_
#define _NET_CHANNELIMPL_HPP_
#include "net/channel.hpp"

namespace net
{
	using namespace boost;
	using namespace boost::asio;

	typedef ssl::stream<ip::tcp::socket> TSocket;
	typedef shared_ptr<TSocket> TSocketPtr;

	//////////////////////////////////////////////////////////////////////////
	class ChannelImpl;
	typedef boost::shared_ptr<ChannelImpl> ChannelImplPtr;

	class ChannelImpl
		: public enable_shared_from_this<ChannelImpl>
	{
		TSocketPtr _socket;

		//////////////////////////////////////////////////////////////////////////
		struct STransferState
		{
			SPacket									_packet;
			boost::uint32_t							_header[1];
			ChannelImplPtr							_ch;
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
				ChannelImplPtr ch, 
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
				ChannelImplPtr ch, 
				function<void (const SPacket &)> ok,
				function<void (system::error_code)> fail);
		};
		typedef shared_ptr<STransferStateReceive> STransferStateReceivePtr;

	private:
		static void onReceive(STransferStateReceivePtr ts, system::error_code ec, size_t size);
		static void onSend(STransferStateSendPtr ts, system::error_code ec, size_t size);

	public:
		ChannelImpl(TSocketPtr socket);
		~ChannelImpl();
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
