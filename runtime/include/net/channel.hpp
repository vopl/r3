#ifndef _NET_CHANNEL_HPP_
#define _NET_CHANNEL_HPP_

namespace net
{
	struct IChannel;
	struct IChannelHandler
	{
		virtual void onReceive(IChannel *, char *data, size_t size) =0;
		virtual void onError(IChannel *) =0;
		virtual void onClose(IChannel *) =0;
	};

	struct IChannel
	{
		virtual void setHandler(IChannelHandler *) =0;
		virtual void send(const char *data, size_t size) =0;
		virtual void close() =0;
	};
}
#endif
