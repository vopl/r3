#ifndef _NET_CHANNELHUB_HPP_
#define _NET_CHANNELHUB_HPP_

#include "net/ichannel.hpp"
#include "async/service.hpp"

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
		typedef std::set<IChannelPtr> TChannels;

		volatile bool	_work;
		mutex			_mtxChannels;
		TChannels		_channels;//все

		boost::function<void(boost::system::error_code, size_t)> _onStateChanged;



		mutex			_mtxSend;
		typedef std::pair<Future<error_code>, SPacket> TSend;
		typedef std::deque<TSend> TSends;
		TSends			_sends;
		TChannels		_channelsNotSend;


		mutex			_mtxReceive;
		typedef boost::function<void(const boost::system::error_code &ec, const SPacket &p)> TOnReceove;
		typedef std::pair<
			boost::function<void(const boost::system::error_code &ec, const SPacket &p)>,
			size_t> TReceive;
		typedef std::deque<TReceive> TReceives;
		TReceives		_receives;

	private:
		void onReceive(const boost::system::error_code &ec, const net::SPacket &p, IChannelPtr channel);
		void balanceSends();

	public:
		//////////////////////////////////////////////////////////////////////////
		ChannelHub();
		virtual ~ChannelHub();

		virtual void listen(
			const boost::function<void(const boost::system::error_code &ec, const SPacket &p)> &onReceive,
			size_t amount = (size_t)-1);
		virtual Future<error_code> send(const SPacket &p);


		//////////////////////////////////////////////////////////////////////////
		virtual void close();

		//////////////////////////////////////////////////////////////////////////
		bool attachChannel(IChannelPtr channel);

		//////////////////////////////////////////////////////////////////////////
		size_t getChannelsAmount();

		//////////////////////////////////////////////////////////////////////////
		void watchState(const boost::function<void(boost::system::error_code, size_t)> &onStateChanged);
	};











	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	void ChannelHub<Base>::onReceive(const boost::system::error_code &ec, const net::SPacket &p, IChannelPtr channel)
	{

		if(ec)
		{
			mutex::scoped_lock sl(_mtxChannels);
			channel->close();
			if(!_work)
			{
				return;
			}

			TChannels::iterator iter = std::find(_channels.begin(), _channels.end(), channel);
			if(_channels.end() != iter)
			{
				_channels.erase(iter);
			}
			if(_onStateChanged)
			{
				spawn(bind(_onStateChanged, ec, _channels.size()));
			}
			return;
		}

		TOnReceove onReceive;
		{
			mutex::scoped_lock sl(_mtxReceive);
			if(_receives.empty())
			{
				//остановлен
				return;
			}

			while(!_receives.front().second)
			{
				_receives.erase(_receives.begin());
			}
			onReceive = _receives.front().first;
			_receives.front().second--;
			while(!_receives.front().second)
			{
				_receives.erase(_receives.begin());
			}
		}

		assert(onReceive);
		onReceive(ec, p);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	void ChannelHub<Base>::balanceSends()
	{
		for(;;)
		{
			IChannelPtr channel;
			Future<error_code> res;
			SPacket p;
			{
				mutex::scoped_lock sl(_mtxSend);

				if(_sends.empty())
				{
					//нечего слать
					return;
				}

				if(_channelsNotSend.empty())
				{
					//нечем делать
					return;
				}

				res = _sends.begin()->first;
				p = _sends.begin()->second;
				_sends.erase(_sends.begin());

				channel = *_channelsNotSend.begin();
				_channelsNotSend.erase(_channelsNotSend.begin());
			}

			Future<error_code> lowRes = channel->send(p);
			lowRes.wait();
			if(lowRes.data())
			{
				channel->close();
				if(!_work)
				{
					return;
				}
				{
					mutex::scoped_lock sl(_mtxChannels);
					_channels.erase(channel);
					if(_onStateChanged)
					{
						spawn(bind(_onStateChanged, lowRes.data(), _channels.size()));
					}
				}

				{
					mutex::scoped_lock sl(_mtxSend);
					_sends.push_back(std::make_pair(res, p));
				}
			}
			else
			{
				mutex::scoped_lock sl(_mtxSend);
				{
					_channelsNotSend.insert(channel);
				}
				res(lowRes.data());
			}
		}
	}



	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	ChannelHub<Base>::ChannelHub()
		: _work(true)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	ChannelHub<Base>::~ChannelHub()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	void ChannelHub<Base>::listen(
		const boost::function<void(const boost::system::error_code &ec, const SPacket &p)> &onReceive,
		size_t amount)
	{
		mutex::scoped_lock sl(_mtxReceive);
		_receives.push_back(std::make_pair(onReceive, amount));
	}


	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	Future<error_code> ChannelHub<Base>::send(const SPacket &p)
	{
		Future<error_code> res;

		mutex::scoped_lock sl(_mtxSend);

		if(_work)
		{
			_sends.push_back(std::make_pair(res, p));
			spawn(bind(&ChannelHub<Base>::balanceSends, ChannelHub<Base>::shared_from_this()));
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

			if(_onStateChanged)
			{
				spawn(bind(_onStateChanged, boost::system::error_code(), 0));
				boost::function<void(boost::system::error_code, size_t)>().swap(_onStateChanged);
			}


			BOOST_FOREACH(const IChannelPtr &ch, _channels)
			{
				ch->close();
			}
			_channels.clear();

			mutex::scoped_lock sl2(_mtxReceive);
			BOOST_FOREACH(TReceive &r, _receives)
			{
				spawn(bind(r.first, make_error_code(errc::operation_canceled), SPacket()));
			}
			_receives.clear();

			mutex::scoped_lock sl3(_mtxSend);
			typedef std::pair<Future<error_code>, SPacket> PR;
			BOOST_FOREACH(PR &pr, _sends)
			{
				spawn(bind(pr.first, make_error_code(errc::operation_canceled)));
			}
			_sends.clear();
			_channelsNotSend.clear();

		}
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	bool ChannelHub<Base>::attachChannel(IChannelPtr channel)
	{
		mutex::scoped_lock sl(_mtxChannels);
		mutex::scoped_lock sl2(_mtxSend);

		if(!_work)
		{
			return false;
		}
		_channels.insert(channel);
		_channelsNotSend.insert(channel);

		_work = true;

		channel->listen(bind(&ChannelHub<Base>::onReceive, ChannelHub<Base>::shared_from_this(), _1, _2, channel), (size_t)-1);

		if(_onStateChanged)
		{
			spawn(bind(_onStateChanged, boost::system::error_code(), _channels.size()));
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	size_t ChannelHub<Base>::getChannelsAmount()
	{
		mutex::scoped_lock sl(_mtxChannels);
		return _channels.size();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	void ChannelHub<Base>::watchState(const boost::function<void(boost::system::error_code, size_t)> &onStateChanged)
	{
		mutex::scoped_lock sl(_mtxChannels);
		_onStateChanged = onStateChanged;
	}

}
#endif
