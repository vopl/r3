#include "stdafx.h"
#include "channelHubImpl.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	ChannelHubImpl::SendPacket::SendPacket(
		const SPacket &packet,
		function<void ()> ok,
		function<void (system::error_code)>	fail)
		: _packet(packet)
		, _ok(ok)
		, _fail(fail)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::balanceSends()
	{
		//уже заблокировано

		if(!_sendPackets.empty() && !_channelsSendNot.empty())
		{
			//есть пакет к отправке и свободный канал
			Channel channel = *_channelsSendNot.begin();
			_channelsSendNot.erase(_channelsSendNot.begin());

			SendPacketPtr sp = _sendPackets.front();
			_sendPackets.pop_front();
			
			channel.send(
				sp->_packet, 
				bind(&ChannelHubImpl::onSendOk, shared_from_this(), channel, sp),
				bind(&ChannelHubImpl::onSendFail, shared_from_this(), channel, sp, _1));
			_channelsSend.insert(channel);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::onSendOk(Channel channel, SendPacketPtr sp)
	{
		mutex::scoped_lock sl(_mtxSends);
		sp->_ok();
		_channelsSend.erase(channel);
		_channelsSendNot.insert(channel);
		balanceSends();
	}

	void ChannelHubImpl::onSendFail(Channel channel, SendPacketPtr sp, system::error_code ec)
	{
		//закрыть канал и избавится от него
		channel.close();
		mutex::scoped_lock sl(_mtxChannels);
		_channels.erase(channel);

		mutex::scoped_lock sl2(_mtxSends);
		assert(_channelsSend.end() != _channelsSend.find(channel));
		_channelsSend.erase(channel);
		_channelsSendNot.erase(channel);

		//пакет переложить обратно в очередь (в начало, он обиженый)
		_sendPackets.push_front(sp);

		balanceSends();
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelHubImplPtr ChannelHubImpl::shared_from_this()
	{
		return static_pointer_cast<ChannelHubImpl>(ChannelImplBase::shared_from_this());
	}

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
		mutex::scoped_lock sl(_mtxSends);

		//положить в очередь на отправку
		SendPacketPtr sp(new SendPacket(p,ok,fail));
		_sendPackets.push_back(sp);

		balanceSends();
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::close()
	{
		mutex::scoped_lock sl(_mtxChannels);

		BOOST_FOREACH(Channel &ch, _channels)
		{
			ch.close();
		}
		_channels.clear();

		{
			mutex::scoped_lock sl(_mtxSends);
			_channelsSend.clear();
			_channelsSendNot.clear();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::attachChannel(Channel channel)
	{
		mutex::scoped_lock sl(_mtxChannels);
		_channels.insert(channel);

		{
			mutex::scoped_lock sl(_mtxSends);
			_channelsSendNot.insert(channel);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	size_t ChannelHubImpl::getChannelsAmount()
	{
		mutex::scoped_lock sl(_mtxChannels);
		return _channels.size();
	}

}