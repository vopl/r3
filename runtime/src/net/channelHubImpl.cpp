#include "stdafx.h"
#include "channelHubImpl.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	ChannelHubImpl::SendWaiter::SendWaiter(
		const SPacket &packet,
		function<void ()> ok,
		function<void (system::error_code)>	fail)
		: _packet(packet)
		, _ok(ok)
		, _fail(fail)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelHubImpl::RecvWaiter::RecvWaiter(
		function<void (const SPacket &)> ok,
		function<void (system::error_code)>	fail)
		: _ok(ok)
		, _fail(fail)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelHubImpl::RecvPacket::RecvPacket(
		const SPacket &packet, 
		Channel	channel)
		: _packet(packet) 
		, _channel(channel)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelHubImpl::RecvCallback::RecvCallback(
		const SPacket &packet,
		function<void (const SPacket &)> ok)
		: _packet(packet)
		, _ok(ok)
	{
	}


	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::balanceSends()
	{
		//уже заблокировано

		if(!_sendWaiters.empty() && !_channelsSendNot.empty())
		{
			//есть пакет к отправке и свободный канал
			Channel channel = *_channelsSendNot.begin();
			_channelsSendNot.erase(_channelsSendNot.begin());

			SendWaiterPtr sw = _sendWaiters.front();
			_sendWaiters.pop_front();
			
			channel.send(
				sw->_packet, 
				bind(&ChannelHubImpl::onSendOk, shared_from_this(), channel, sw),
				bind(&ChannelHubImpl::onSendFail, shared_from_this(), channel, sw, _1));
			_channelsSend.insert(channel);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::onSendOk(Channel channel, SendWaiterPtr sw)
	{
		bool isWork = false;
		{
			mutex::scoped_lock sl(_mtxSend);
			TChannels::iterator iter = _channelsSend.find(channel);
			if(_channelsSend.end() != iter)
			{
				_channelsSend.erase(iter);
				_channelsSendNot.insert(channel);
				isWork = true;
				balanceSends();
			}
			else
			{
				//хаб закрыт?
			}
		}

		if(isWork)
		{
			sw->_ok();
		}
		else
		{
			sw->_fail(system::errc::make_error_code(system::errc::operation_canceled));
		}

	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::onSendFail(Channel channel, SendWaiterPtr sw, system::error_code ec)
	{
		//закрыть канал и избавится от него
		channel.close();

		bool isWork = false;
		{
			mutex::scoped_lock sl(_mtxChannels);
			TChannels::iterator iter = _channels.find(channel);
			if(_channels.end() != iter)
			{
				assert(!"log error?");

				_channels.erase(iter);

				mutex::scoped_lock sl2(_mtxSend);
				_channelsSend.erase(channel);
				_channelsSendNot.erase(channel);

				//пакет переложить обратно в очередь (в начало, он обиженый)
				_sendWaiters.push_front(sw);

				balanceSends();
				isWork = true;
			}
			else
			{
				//хаб закрыт?
			}
		}

		if(!isWork)
		{
			sw->_fail(system::errc::make_error_code(system::errc::operation_canceled));
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::balanceRecvs(RecvCallbacks &rcs)
	{
		//уже заблокировано

		while(!_recvPackets.empty() && !_recvWaiters.empty())
		{
			RecvPacketPtr rp = _recvPackets.front();
			_recvPackets.pop_front();
			RecvWaiterPtr rw = _recvWaiters.front();
			_recvWaiters.pop_front();

			RecvCallbackPtr rc(new RecvCallback(rp->_packet, rw->_ok));
			rcs.push_back(rc);

			rp->_channel.receive(
				bind(&ChannelHubImpl::onRecvOk, shared_from_this(), rp->_channel, _1),
				bind(&ChannelHubImpl::onRecvFail, shared_from_this(), rp->_channel, _1));
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::onRecvOk(Channel channel, const SPacket &p)
	{
		RecvCallbacks rcs;
		{
			mutex::scoped_lock sl(_mtxRecv);

			RecvPacketPtr rp(new RecvPacket(p, channel));
			_recvPackets.push_back(rp);
			balanceRecvs(rcs);
		}

		BOOST_FOREACH(RecvCallbackPtr &rc, rcs)
		{
			rc->_ok(rc->_packet);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::onRecvFail(Channel channel, system::error_code ec)
	{
		//закрыть канал и избавится от него
		channel.close();

		bool isWork = false;
		mutex::scoped_lock sl(_mtxChannels);
		TChannels::iterator iter = _channels.find(channel);
		if(_channels.end() != iter)
		{
			assert(!"log error?");

			_channels.erase(iter);

			mutex::scoped_lock sl2(_mtxSend);
			_channelsSend.erase(channel);
			_channelsSendNot.erase(channel);

			balanceSends();
		}
		else
		{
			//хаб закрыт?
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelHubImplPtr ChannelHubImpl::shared_from_this()
	{
		return static_pointer_cast<ChannelHubImpl>(ChannelImpl::shared_from_this());
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
		RecvCallbacks rcs;

		{
			mutex::scoped_lock sl(_mtxRecv);

			//положить в очередь на отправку
			RecvWaiterPtr rp(new RecvWaiter(ok,fail));
			_recvWaiters.push_back(rp);

			balanceRecvs(rcs);
		}

		BOOST_FOREACH(RecvCallbackPtr &rc, rcs)
		{
			rc->_ok(rc->_packet);
		}

	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::send(
		const SPacket &p,
		function<void ()> ok,
		function<void (system::error_code)> fail)
	{
		mutex::scoped_lock sl(_mtxSend);

		//положить в очередь на отправку
		SendWaiterPtr sw(new SendWaiter(p,ok,fail));
		_sendWaiters.push_back(sw);

		balanceSends();
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::close()
	{
		RecvCallbacks rcs;
		TRecvWaiters rws;
		{
			mutex::scoped_lock sl(_mtxChannels);
			mutex::scoped_lock sl2(_mtxSend);
			mutex::scoped_lock sl3(_mtxRecv);

			BOOST_FOREACH(Channel &ch, _channels)
			{
				ch.close();
			}
			_channels.clear();

			{
				_channelsSend.clear();
				_channelsSendNot.clear();
			}

			{
				balanceRecvs(rcs);
				rws.swap(_recvWaiters);
				_recvPackets.clear();
			}
		}

		BOOST_FOREACH(RecvCallbackPtr &rc, rcs)
		{
			rc->_ok(rc->_packet);
		}
		BOOST_FOREACH(RecvWaiterPtr &rw, rws)
		{
			rw->_fail(system::errc::make_error_code(system::errc::operation_canceled));
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::attachChannel(Channel channel)
	{
		mutex::scoped_lock sl(_mtxChannels);
		_channels.insert(channel);

		{
			mutex::scoped_lock sl(_mtxSend);
			_channelsSendNot.insert(channel);
		}
		channel.receive(
			bind(&ChannelHubImpl::onRecvOk, shared_from_this(), channel, _1),
			bind(&ChannelHubImpl::onRecvFail, shared_from_this(), channel, _1));
	}

	//////////////////////////////////////////////////////////////////////////
	size_t ChannelHubImpl::getChannelsAmount()
	{
		mutex::scoped_lock sl(_mtxChannels);
		return _channels.size();
	}

}