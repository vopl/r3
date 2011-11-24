#include "stdafx.h"
#include "net/channel.hpp"
#include "channelImpl.hpp"

namespace net
{
	SPacket::SPacket()
		: _data()
		, _size(0)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	SPacket::SPacket(boost::shared_array<char> data, boost::uint32_t size)
		: _data(data)
		, _size(size)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	Channel::Channel(ImplPtr impl)
		: _impl(impl)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void Channel::receive(
		boost::function<void (const SPacket &)> ok,
		boost::function<void (boost::system::error_code)> fail)
	{
		return _impl->receive(ok, fail);
	}

	//////////////////////////////////////////////////////////////////////////
	void Channel::send(
		const SPacket &p,
		boost::function<void ()> ok,
		boost::function<void (boost::system::error_code)> fail)
	{
		return _impl->send(p, ok, fail);
	}

	//////////////////////////////////////////////////////////////////////////
	void Channel::close()
	{
		return _impl->close();
	}

	//////////////////////////////////////////////////////////////////////////
	bool Channel::operator<(const Channel &with) const
	{
		return _impl < with._impl;
	}

}
