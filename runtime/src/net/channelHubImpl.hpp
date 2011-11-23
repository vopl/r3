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
		typedef std::deque<Channel> TChannels;
		TChannels _channels;

		//mutex _mtx;

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
