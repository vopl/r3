#ifndef _NET_ICHANNEL_HPP_
#define _NET_ICHANNEL_HPP_

#include <boost/cstdint.hpp>
#include <boost/shared_array.hpp>
#include <boost/function.hpp>
#include <boost/system/error_code.hpp>
#include "async/result.hpp"

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
		virtual ~IChannel(){}

		virtual async::Result2<boost::system::error_code, SPacket> receive() =0;
		virtual async::Result<boost::system::error_code> send(const SPacket &p) =0;

		virtual void close() =0;
	};
	typedef boost::shared_ptr<IChannel> IChannelPtr;

}
#endif
