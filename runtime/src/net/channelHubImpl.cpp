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
		//��� �������������

		if(!_sendWaiters.empty() && !_channelsSendNot.empty())
		{
			//���� ����� � �������� � ��������� �����
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
		{
			mutex::scoped_lock sl(_mtxSend);
			_channelsSend.erase(channel);
			_channelsSendNot.insert(channel);
			balanceSends();
		}
		sw->_ok();

	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::onSendFail(Channel channel, SendWaiterPtr sw, system::error_code ec)
	{
		assert(!"log error?");

		//������� ����� � ��������� �� ����
		channel.close();
		mutex::scoped_lock sl(_mtxChannels);
		_channels.erase(channel);

		mutex::scoped_lock sl2(_mtxSend);
		_channelsSend.erase(channel);
		_channelsSendNot.erase(channel);

		//����� ���������� ������� � ������� (� ������, �� ��������)
		_sendWaiters.push_front(sw);

		balanceSends();
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelHubImpl::balanceRecvs(RecvCallbacks &rcs)
	{
		//��� �������������

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
		std::cout<<ec<<std::endl;
		assert(!"log error?");
		//������� ����� � ��������� �� ����
		channel.close();
		mutex::scoped_lock sl(_mtxChannels);
		_channels.erase(channel);

		mutex::scoped_lock sl2(_mtxSend);
		_channelsSend.erase(channel);
		_channelsSendNot.erase(channel);

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
		RecvCallbacks rcs;

		{
			mutex::scoped_lock sl(_mtxRecv);

			//�������� � ������� �� ��������
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

		//�������� � ������� �� ��������
		SendWaiterPtr sw(new SendWaiter(p,ok,fail));
		_sendWaiters.push_back(sw);

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
			mutex::scoped_lock sl(_mtxSend);
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