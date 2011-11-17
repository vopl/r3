#ifndef _NET_CHANNEL_HPP_
#define _NET_CHANNEL_HPP_

#include "utils/variant.hpp"
#include "boost/system/error_code.hpp"

namespace net
{
	enum EStage
	{
		esListen,
		esAccept,
		esAcceptHandshake,
		esConnect,
		esConnectHandshake,
		esSend,
		esReceive,
	};

	struct Channel;
	typedef boost::shared_ptr<Channel> ChannelPtr;

	struct IChannelHandler
	{
		virtual void onSendComplete(const ChannelPtr &channel, boost::shared_array<char> data, size_t size) =0;
		virtual void onSendComplete(const ChannelPtr &channel, utils::VariantPtr v) =0;
		virtual void onReceive(const ChannelPtr &channel, boost::shared_array<char> data, size_t size) =0;
		virtual void onReceive(const ChannelPtr &channel, utils::VariantPtr v) =0;
		virtual void onError(const ChannelPtr &channel, EStage es, const boost::system::error_code& ec) =0;
		virtual void onClose(const ChannelPtr &channel) =0;
	};

	struct Channel
	{
		virtual void setHandler(IChannelHandler *) =0;
		virtual void send(boost::shared_array<char> data, size_t size) =0;
		virtual void send(utils::VariantPtr v) =0;
		virtual void close() =0;
	};
}
#endif
