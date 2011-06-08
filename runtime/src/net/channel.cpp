#include "net/channel.hpp"

namespace net
{

	class Channel
		: IChannel
	{
		virtual void setHandler(IChannelHandler *);
		virtual void send(const char *data, size_t size);
		virtual void close();
	};


	//////////////////////////////////////////////////////////////////////////

}
