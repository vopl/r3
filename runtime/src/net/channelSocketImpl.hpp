#ifndef _NET_CHANNELSOCKETIMPL_HPP_
#define _NET_CHANNELSOCKETIMPL_HPP_
#include "net/channel.hpp"
#include "channelImpl.hpp"

namespace net
{
	using namespace boost;
	using namespace boost::asio;

	typedef ssl::stream<ip::tcp::socket> TSocket;
	typedef shared_ptr<TSocket> TSocketPtr;

	//////////////////////////////////////////////////////////////////////////
	class ChannelSocketImpl;
	typedef boost::shared_ptr<ChannelSocketImpl> ChannelSocketImplPtr;

	class ChannelSocketImpl
		: public ChannelImpl
	{
		TSocketPtr _socket;
		io_service::strand _strand;

		//////////////////////////////////////////////////////////////////////////
		struct STransferState
		{
			SPacket									_packet;
			boost::uint32_t							_header[1];
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
				function<void (const SPacket &)> ok,
				function<void (system::error_code)> fail);
		};
		typedef shared_ptr<STransferStateReceive> STransferStateReceivePtr;

	private:
		void onReceive(STransferStateReceivePtr ts, system::error_code ec, size_t size);
		void onSend(STransferStateSendPtr ts, system::error_code ec, size_t size);

	public:
		ChannelSocketImplPtr shared_from_this();

	public:
		ChannelSocketImpl(TSocketPtr socket);
		~ChannelSocketImpl();
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
