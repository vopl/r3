#ifndef _NET_CHANNEL_HPP_
#define _NET_CHANNEL_HPP_

namespace net
{
	struct Channel;
	typedef boost::shared_ptr<Channel> Channel_ptr;

	struct IChannelHandler
	{
		virtual void onReceive(Channel_ptr channel, boost::shared_array<char> data, size_t size) =0;
		virtual void onError(Channel_ptr channel) =0;
		virtual void onClose(Channel_ptr channel) =0;
	};

	struct Channel
	{
		virtual void setHandler(IChannelHandler *) =0;
		virtual void send(boost::shared_array<char> data, size_t size) =0;
		virtual void close() =0;
	};
}
#endif
