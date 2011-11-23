#include "stdafx.h"
#include "channelHubImpl.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	ChannelHubImpl::ChannelHubImpl()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::receive(
		function<void (const SPacket &)> ok,
		function<void (system::error_code)> fail)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::send(
		const SPacket &p,
		function<void ()> ok,
		function<void (system::error_code)> fail)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::close()
	{
		//mutex::scoped_lock sl(_mtx);

		BOOST_FOREACH(Channel &ch, _channels)
		{
			ch.close();
		}
		_channels.clear();
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::attachChannel(Channel channel)
	{
		//mutex::scoped_lock sl(_mtx);
		_channels.push_back(channel);
	}

	//////////////////////////////////////////////////////////////////////////
	size_t ChannelHubImpl::getChannelsAmount()
	{
		//mutex::scoped_lock sl(_mtx);
		return _channels.size();
	}

}