#ifndef _NET_CHANNEL_HPP_
#define _NET_CHANNEL_HPP_

#include "utils/variant.hpp"
#include "boost/system/error_code.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	struct SPacket
	{
		boost::uint32_t	_id;
		boost::uint32_t	_kind;
		boost::uint32_t _size;
		boost::shared_array<char> _data;

		SPacket();
	};

	//////////////////////////////////////////////////////////////////////////
	struct Channel;
	typedef boost::shared_ptr<Channel> ChannelPtr;

	struct IChannelHandler
	{
		virtual void onSendFailed(const ChannelPtr &channel, const SPacket &p) =0;
		virtual void onSendComplete(const ChannelPtr &channel, const SPacket &p) =0;

		virtual void onReceive(const ChannelPtr &channel, const SPacket &p) =0;

		virtual void onClose(const ChannelPtr &channel) =0;
	};

	struct Channel
	{
		virtual void setHandler(IChannelHandler *handler) =0;
		virtual void send(const SPacket &p) =0;
		virtual void close() =0;
	};
}
#endif
