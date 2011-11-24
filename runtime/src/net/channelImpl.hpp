#ifndef _NET_CHANNELIMPL_HPP_
#define _NET_CHANNELIMPL_HPP_
#include "net/channel.hpp"

namespace net
{
	using namespace boost;
	using namespace boost::asio;

	//////////////////////////////////////////////////////////////////////////
	class ChannelImpl;
	typedef boost::shared_ptr<ChannelImpl> ChannelImplPtr;

	class ChannelImpl
		: public enable_shared_from_this<ChannelImpl>
	{
	public:
		virtual ~ChannelImpl(){};
		virtual void receive(
			function<void (const SPacket &)> ok,
			function<void (system::error_code)> fail) =0;

		virtual void send(
			const SPacket &p,
			function<void ()> ok,
			function<void (system::error_code)> fail) =0;

		virtual void close() =0;
	};
}

#endif
