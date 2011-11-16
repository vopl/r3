#ifndef _NET_CHANNEL_HPP_
#define _NET_CHANNEL_HPP_

#include "utils/variant.hpp"

namespace net
{
	struct Channel;
	typedef boost::shared_ptr<Channel> ChannelPtr;

	struct IChannelHandler
	{
		virtual void onReceive(ChannelPtr channel, boost::shared_array<char> data, size_t size) =0;
		virtual void onReceive(ChannelPtr channel, const utils::VariantPtr vptr) =0;
		virtual void onError(ChannelPtr channel) =0;
		virtual void onClose(ChannelPtr channel) =0;
	};

	struct Channel
	{
		virtual void setHandler(IChannelHandler *) =0;
		virtual void send(boost::shared_array<char> data, size_t size) =0;
		virtual void send(const utils::Variant &v) =0;
		virtual void close() =0;
	};
}
#endif
