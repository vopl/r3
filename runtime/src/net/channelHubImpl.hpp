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

		//////////////////////////////////////////////////////////////////////////
		struct SendPacket
		{
			SPacket								_packet;
			function<void ()>					_ok;
			function<void (system::error_code)>	_fail;
			SendPacket(
				const SPacket &packet,
				function<void ()> ok,
				function<void (system::error_code)>	fail);
		};
		typedef boost::shared_ptr<SendPacket> SendPacketPtr;
		typedef std::deque<SendPacketPtr> TSendPackets;
		TSendPackets _sendPackets;
		mutex _mtxSends;


		TChannels	_channelsSend;
		TChannels	_channelsSendNot;
		mutex _mtxChannels;

	private:
		void balanceSends();

		void onSendOk(Channel channel, SendPacketPtr sp);
		void onSendFail(Channel channel, SendPacketPtr sp, system::error_code ec);

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
