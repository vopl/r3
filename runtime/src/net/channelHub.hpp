#ifndef _NET_CHANNELHUB_HPP_
#define _NET_CHANNELHUB_HPP_

#include "net/ichannel.hpp"

namespace net
{
	using namespace boost;
	using namespace boost::system;
	using namespace async;


	template <class Base>
	class ChannelHub
		: public Base
		, public enable_shared_from_this<ChannelHub<Base> >
	{
		typedef std::deque<IChannelPtr> TChannels;

		volatile bool	_work;
		mutex			_mtxChannels;
		TChannels		_channels;//все


		mutex										_mtxReceives;
		std::deque<Result2<error_code, SPacket> >	_receives;
		std::deque<Result2<error_code, SPacket> >	_received;

		mutex												_mtxSends;
		size_t												_next4send;
		std::deque<std::pair<Result<error_code>, SPacket> >	_sends;

	private:
		void receiveLoop(IChannelPtr channel);
		void balanceSends();

	public:
		//////////////////////////////////////////////////////////////////////////
		ChannelHub();

		virtual Result2<error_code, SPacket> receive();
		virtual Result<error_code> send(const SPacket &p);


		//////////////////////////////////////////////////////////////////////////
		virtual void close();

		//////////////////////////////////////////////////////////////////////////
		bool attachChannel(IChannelPtr channel);

		//////////////////////////////////////////////////////////////////////////
		size_t getChannelsAmount();
	};











	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	void ChannelHub<Base>::receiveLoop(IChannelPtr channel)
	{
		for(;;)
		{
			Result2<error_code, SPacket> res = channel->receive();
			res.wait();

			if(res.data1())
			{
				mutex::scoped_lock sl(_mtxChannels);

				channel->close();
				TChannels::iterator iter = std::find(_channels.begin(), _channels.end(), channel);
				if(_channels.end() != iter)
				{
					_channels.erase(iter);
				}
				return;
			}

			mutex::scoped_lock sl(_mtxReceives);
			if(_receives.empty())
			{
				_received.push_back(res);
			}
			else
			{
				_receives[0](res.data1(), res.data2());
				_receives.erase(_receives.begin());
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	void ChannelHub<Base>::balanceSends()
	{
		for(;;)
		{
			IChannelPtr channel;
			Result<error_code> res;
			SPacket p;
			{
				mutex::scoped_lock sl(_mtxSends);

				if(_sends.empty())
				{
					//нечего слать
					return;
				}

				res = _sends[0].first;
				p = _sends[0].second;
				_sends.erase(_sends.begin());
			
				mutex::scoped_lock sl2(_mtxChannels);
				if(_channels.empty())
				{
					//нет низких каналов
					return;
				}
				else
				{
					_next4send = (++_next4send) % _channels.size();
					channel = _channels[_next4send];
				}
			}

			Result<error_code> lowRes = channel->send(p);
			lowRes.wait();
			if(lowRes.data())
			{
				mutex::scoped_lock sl(_mtxSends);

				channel->close();
				TChannels::iterator iter = std::find(_channels.begin(), _channels.end(), channel);
				if(_channels.end() != iter)
				{
					_channels.erase(iter);
				}

				_sends.push_back(std::make_pair(res, p));
			}
			else
			{
				res(lowRes.data());
			}
		}
	}



	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	ChannelHub<Base>::ChannelHub()
		: _work(true)
		, _next4send(0)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	Result2<error_code, SPacket> ChannelHub<Base>::receive()
	{
		Result2<error_code, SPacket> res;

		mutex::scoped_lock sl(_mtxReceives);

		if(_work)
		{
			if(_received.empty())
			{
				_receives.push_back(res);
			}
			else
			{
				res = _received[0];
				_received.erase(_received.begin());
			}
		}
		else
		{
			res(make_error_code(errc::operation_canceled), SPacket());
		}
		return res;
	}


	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	Result<error_code> ChannelHub<Base>::send(const SPacket &p)
	{
		Result<error_code> res;

		mutex::scoped_lock sl(_mtxSends);

		if(_work)
		{
			_sends.push_back(std::make_pair(res, p));
			if(_sends.size()<2)
			{
				spawn(bind(&ChannelHub<Base>::balanceSends, shared_from_this()));
			}
		}
		else
		{
			res(make_error_code(errc::operation_canceled));
		}
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	void ChannelHub<Base>::close()
	{
		{
			mutex::scoped_lock sl(_mtxChannels);

			_work = false;

			BOOST_FOREACH(const IChannelPtr &ch, _channels)
			{
				ch->close();
			}
			_channels.clear();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	bool ChannelHub<Base>::attachChannel(IChannelPtr channel)
	{
		mutex::scoped_lock sl(_mtxChannels);
		mutex::scoped_lock sl2(_mtxSends);

		if(!_work)
		{
			return false;
		}
		_channels.push_back(channel);

		_work = true;

		spawn(bind(&ChannelHub<Base>::receiveLoop, shared_from_this(), channel));
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	size_t ChannelHub<Base>::getChannelsAmount()
	{
		mutex::scoped_lock sl(_mtxChannels);
		return _channels.size();
	}

}
#endif
