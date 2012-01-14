#ifndef _NET_ICHANNEL_HPP_
#define _NET_ICHANNEL_HPP_

#include <boost/cstdint.hpp>
#include <boost/shared_array.hpp>
#include <boost/function.hpp>
#include <boost/system/error_code.hpp>
#include "async/future.hpp"
#include "utils/variant.hpp"

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

		SPacket(const utils::Variant &v)
			: _size(0)
		{
			_data = v.serialize(_size);
		}

		operator utils::Variant() const
		{
			utils::Variant res;
			res.deserialize(_data, _size);
			return res;
		}
	};

	//////////////////////////////////////////////////////////////////////////
	struct IChannel
	{
		virtual ~IChannel(){}

		virtual void listen(
			const boost::function<void(const boost::system::error_code &ec, const SPacket &p)> &onReceive,
			size_t amount=(size_t)-1) =0;
		virtual async::Future<boost::system::error_code> send(const SPacket &p) =0;

		virtual void close() =0;
	};
	typedef boost::shared_ptr<IChannel> IChannelPtr;

}
#endif
