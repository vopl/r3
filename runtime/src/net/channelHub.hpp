#ifndef _NET_CHANNELHUB_HPP_
#define _NET_CHANNELHUB_HPP_

#include "net/ichannel.hpp"
#include <set>

namespace net
{
	using namespace boost;


	template <class Base>
	class ChannelHub
		: public Base
		, public enable_shared_from_this<ChannelHub<Base> >
	{
		typedef std::set<IChannelPtr> TChannels;
		TChannels _channels;
		mutex _mtxChannels;

		//////////////////////////////////////////////////////////////////////////
		struct SendWaiter
		{
			SPacket								_packet;
			function<void ()>					_ok;
			function<void (system::error_code)>	_fail;
			SendWaiter(
				const SPacket &packet,
				function<void ()> ok,
				function<void (system::error_code)>	fail)
				: _packet(packet)
				, _ok(ok)
				, _fail(fail)
			{
			}

		};
		typedef boost::shared_ptr<SendWaiter> SendWaiterPtr;

		typedef std::deque<SendWaiterPtr> TSendWaiters;
		TSendWaiters _sendWaiters;

		TChannels	_channelsSend;
		TChannels	_channelsSendNot;

		mutex _mtxSend;

		//////////////////////////////////////////////////////////////////////////
		struct RecvWaiter
		{
			function<void (const SPacket &)>	_ok;
			function<void (system::error_code)>	_fail;
			RecvWaiter(
				function<void (const SPacket &)> ok,
				function<void (system::error_code)>	fail)
				: _ok(ok)
				, _fail(fail)
			{
			}
		};
		typedef boost::shared_ptr<RecvWaiter> RecvWaiterPtr;

		typedef std::deque<RecvWaiterPtr> TRecvWaiters;
		TRecvWaiters _recvWaiters;

		struct RecvPacket
		{
			SPacket	_packet;
			IChannelPtr	_channel;

			RecvPacket(
				const SPacket &packet, 
				IChannelPtr	channel)
				: _packet(packet) 
				, _channel(channel)
			{
			}
		};
		typedef boost::shared_ptr<RecvPacket> RecvPacketPtr;
		
		typedef std::deque<RecvPacketPtr> TRecvPackets;
		TRecvPackets _recvPackets;

		size_t _recvChannelsAmount;
		
		mutex _mtxRecv;

		//////////////////////////////////////////////////////////////////////////
		struct RecvCallback
		{
			SPacket								_packet;
			function<void (const SPacket &)>	_ok;

			RecvCallback(
				const SPacket &packet,
				function<void (const SPacket &)> ok)
				: _packet(packet)
				, _ok(ok)
			{
			}
		};
		typedef boost::shared_ptr<RecvCallback> RecvCallbackPtr;
		typedef std::deque<RecvCallbackPtr> RecvCallbacks;

	private:
		//////////////////////////////////////////////////////////////////////////
		void balanceSends()
		{
			//уже заблокировано

			if(!_sendWaiters.empty() && !_channelsSendNot.empty())
			{
				//есть пакет к отправке и свободный канал
				IChannelPtr channel = *_channelsSendNot.begin();
				_channelsSendNot.erase(_channelsSendNot.begin());

				SendWaiterPtr sw = _sendWaiters.front();
				_sendWaiters.pop_front();

				channel->send(
					sw->_packet, 
					bind(&ChannelHub::onSendOk, ChannelHub<Base>::shared_from_this(), channel, sw),
					bind(&ChannelHub::onSendFail, ChannelHub<Base>::shared_from_this(), channel, sw, _1));
				_channelsSend.insert(channel);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void onSendOk(IChannelPtr channel, SendWaiterPtr sw)
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

			sw->_ok();
		}

		//////////////////////////////////////////////////////////////////////////
		void onSendFail(IChannelPtr channel, SendWaiterPtr sw, system::error_code ec)
		{
			//закрыть канал и избавится от него
			channel->close();

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
		void balanceRecvs(RecvCallbacks &rcs)
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

				rp->_channel->receive(
					bind(&ChannelHub::onRecvOk, ChannelHub<Base>::shared_from_this(), rp->_channel, _1),
					bind(&ChannelHub::onRecvFail, ChannelHub<Base>::shared_from_this(), rp->_channel, _1));
				_recvChannelsAmount++;
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void onRecvOk(IChannelPtr channel, const SPacket &p)
		{
			RecvCallbacks rcs;
			{
				mutex::scoped_lock sl(_mtxRecv);

				if(_recvChannelsAmount)
				{
					_recvChannelsAmount--;

					RecvPacketPtr rp(new RecvPacket(p, channel));
					_recvPackets.push_back(rp);
					balanceRecvs(rcs);
				}
				else
				{
					//хаб закрыт?
				}
			}

			BOOST_FOREACH(RecvCallbackPtr &rc, rcs)
			{
				rc->_ok(rc->_packet);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void onRecvFail(IChannelPtr channel, system::error_code ec)
		{
			//закрыть канал и избавится от него
			channel->close();

			bool isWork = false;
			mutex::scoped_lock sl(_mtxChannels);
			TChannels::iterator iter = _channels.find(channel);
			if(_channels.end() != iter)
			{
				std::cout<<ec.message()<<std::endl;
				assert(!"log error?");

				_channels.erase(iter);

				mutex::scoped_lock sl2(_mtxSend);
				mutex::scoped_lock sl3(_mtxRecv);
				_channelsSend.erase(channel);
				_channelsSendNot.erase(channel);

				balanceSends();

				assert(_recvChannelsAmount);
				_recvChannelsAmount--;

			}
			else
			{
				//хаб закрыт?
			}
		}


	public:
		//////////////////////////////////////////////////////////////////////////
		ChannelHub()
			: _recvChannelsAmount(0)
		{
		}


		//////////////////////////////////////////////////////////////////////////
		virtual void receive(
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
		virtual void send(
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
		virtual void close()
		{
			RecvCallbacks rcs;
			TRecvWaiters rws;
			{
				mutex::scoped_lock sl(_mtxChannels);
				mutex::scoped_lock sl2(_mtxSend);
				mutex::scoped_lock sl3(_mtxRecv);

				BOOST_FOREACH(const IChannelPtr &ch, _channels)
				{
					ch->close();
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
				_recvChannelsAmount = 0;
			}

			BOOST_FOREACH(const RecvCallbackPtr &rc, rcs)
			{
				rc->_ok(rc->_packet);
			}
			BOOST_FOREACH(const RecvWaiterPtr &rw, rws)
			{
				rw->_fail(system::errc::make_error_code(system::errc::operation_canceled));
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void attachChannel(IChannelPtr channel)
		{
			mutex::scoped_lock sl(_mtxChannels);
			mutex::scoped_lock sl2(_mtxSend);
			mutex::scoped_lock sl3(_mtxRecv);

			_channels.insert(channel);
			_channelsSendNot.insert(channel);

			channel->receive(
				bind(&ChannelHub::onRecvOk, ChannelHub<Base>::shared_from_this(), channel, _1),
				bind(&ChannelHub::onRecvFail, ChannelHub<Base>::shared_from_this(), channel, _1));
			_recvChannelsAmount++;
		}

		//////////////////////////////////////////////////////////////////////////
		size_t getChannelsAmount()
		{
			mutex::scoped_lock sl(_mtxChannels);
			return _channels.size();
		}

	};
}
#endif
