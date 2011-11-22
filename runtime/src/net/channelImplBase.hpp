#ifndef _NET_CHANNELIMPLBASE_HPP_
#define _NET_CHANNELIMPLBASE_HPP_
#include "net/channel.hpp"

namespace net
{
	using namespace boost;
	using namespace boost::asio;

	//////////////////////////////////////////////////////////////////////////
	class ChannelImplBase;
	typedef boost::shared_ptr<ChannelImplBase> ChannelImplBasePtr;

	class ChannelImplBase
		: public enable_shared_from_this<ChannelImplBase>
	{
	public:
		virtual ~ChannelImplBase(){};
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
