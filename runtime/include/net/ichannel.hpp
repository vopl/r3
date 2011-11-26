#ifndef _NET_ICHANNEL_HPP_
#define _NET_ICHANNEL_HPP_

#include <boost/cstdint.hpp>
#include <boost/shared_array.hpp>
#include <boost/function.hpp>
#include <boost/system/error_code.hpp>

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	struct SPacket
	{
		boost::shared_array<char> _data;
		boost::uint32_t _size;

		SPacket()
			: _size(0)
		{
		}

		SPacket(boost::shared_array<char> data, boost::uint32_t size)
			: _data(data)
			, _size(size)
		{
		}
	};

	//////////////////////////////////////////////////////////////////////////
	struct IChannel
	{
		virtual void receive(
			boost::function<void (const SPacket &)> ok,
			boost::function<void (boost::system::error_code)> fail = boost::function<void (boost::system::error_code)>()) =0;

		virtual void send(
			const SPacket &p,
			boost::function<void ()> ok,
			boost::function<void (boost::system::error_code)> fail = boost::function<void (boost::system::error_code)>()) =0;

		virtual void close() =0;
	};
	typedef boost::shared_ptr<IChannel> IChannelPtr;

}
#endif
