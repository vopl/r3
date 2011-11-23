#ifndef _NET_CHANNELHUBIMPL_HPP_
#define _NET_CHANNELHUBIMPL_HPP_

#include "channelImplBase.hpp"
#include <set>

namespace net
{
	class ChannelHubImpl;
	typedef boost::shared_ptr<ChannelHubImpl> ChannelHubImplPtr;

	class ChannelHubImpl
		: public ChannelImplBase
	{
		typedef std::set<Channel> TChannels;
		TChannels _channels;
		mutex _mtxChannels;

		//////////////////////////////////////////////////////////////////////////
		struct SendWaiter
		{
			SPacket								_packet;
			function<void ()>					_ok;
			function<void (system::error_code)>	_fail;
			SendWaiter(
				const SPacket &packet,
				function<void ()> ok,
				function<void (system::error_code)>	fail);
		};
		typedef boost::shared_ptr<SendWaiter> SendWaiterPtr;

		typedef std::deque<SendWaiterPtr> TSendWaiters;
		TSendWaiters _sendWaiters;

		TChannels	_channelsSend;
		TChannels	_channelsSendNot;

		mutex _mtxSend;

		//////////////////////////////////////////////////////////////////////////
		struct RecvWaiter
		{
			function<void (const SPacket &)>	_ok;
			function<void (system::error_code)>	_fail;
			RecvWaiter(
				function<void (const SPacket &)> ok,
				function<void (system::error_code)>	fail);
		};
		typedef boost::shared_ptr<RecvWaiter> RecvWaiterPtr;

		typedef std::deque<RecvWaiterPtr> TRecvWaiters;
		TRecvWaiters _recvWaiters;

		struct RecvPacket
		{
			SPacket	_packet;
			Channel	_channel;

			RecvPacket(
				const SPacket &packet, 
				Channel	channel);
		};
		typedef boost::shared_ptr<RecvPacket> RecvPacketPtr;
		
		typedef std::deque<RecvPacketPtr> TRecvPackets;
		TRecvPackets _recvPackets;
		
		mutex _mtxRecv;

		//////////////////////////////////////////////////////////////////////////
		struct RecvCallback
		{
			SPacket								_packet;
			function<void (const SPacket &)>	_ok;

			RecvCallback(
				const SPacket &packet,
				function<void (const SPacket &)> ok);
		};
		typedef boost::shared_ptr<RecvCallback> RecvCallbackPtr;
		typedef std::deque<RecvCallbackPtr> RecvCallbacks;

	private:
		void balanceSends();
		void onSendOk(Channel channel, SendWaiterPtr sp);
		void onSendFail(Channel channel, SendWaiterPtr sp, system::error_code ec);

		void balanceRecvs(RecvCallbacks &rcs);
		void onRecvOk(Channel channel, const SPacket &p);
		void onRecvFail(Channel channel, system::error_code ec);

	public:
		ChannelHubImplPtr shared_from_this();

	public:
		ChannelHubImpl();

		virtual void receive(
			function<void (const SPacket &)> ok,
			function<void (system::error_code)> fail);

		virtual void send(
			const SPacket &p,
			function<void ()> ok,
			function<void (system::error_code)> fail);

		virtual void close();

		void attachChannel(Channel channel);
		size_t getChannelsAmount();
	};
}
#endif
