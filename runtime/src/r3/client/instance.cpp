#include "stdafx.h"
#include "instance.hpp"

namespace r3
{
	namespace client
	{

		//////////////////////////////////////////////////////////////////////////
		Instance::Instance()
			: _host("localhost")
			, _port(29431)
			, _netsrv(this)
			, _favorNumChannels(0)
			, _connectNumChannels(0)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Instance::~Instance()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		bool Instance::send(boost::shared_array<char> data, size_t size)
		{
			net::ChannelPtr channel;
			{
				boost::mutex::scoped_lock sl(_mtx);
				if(_channels.size())
				{
					channel = *_channels.begin();
				}
			}

			if(channel)
			{
				net::SPacket pack;
				pack._data = data;
				pack._size = size;
				channel->send(pack);
				return true;
			}

			return false;
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::tconnected(size_t channels)
		{
			//return;
			emit connected(channels);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::tsendComplete(boost::shared_array<char> data, size_t size)
		{
			emit sendComplete(data, size);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::tsendComplete(utils::VariantPtr v)
		{
			emit sendComplete(v);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::treceive(boost::shared_array<char> data, size_t size)
		{
			emit receive(data, size);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::treceive(utils::VariantPtr v)
		{
			emit receive(v);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::setAddress(const std::string &host, short port)
		{
			{
				boost::mutex::scoped_lock sl(_mtx);
				_host = host;
				_port = port;
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::balance(size_t numChannels)
		{
			{
				boost::mutex::scoped_lock sl(_mtx);
				_favorNumChannels = numChannels;
			}

			if(numChannels)
			{
				_netsrv.balance(1);
			}

			balance();

			if(!numChannels)
			{
				_netsrv.balance(0);
			}
		}


		//////////////////////////////////////////////////////////////////////////
		void Instance::onStartInThread(net::Service *netsrv)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onError(net::Service *netsrv, net::EStage es, const boost::system::error_code& ec)
		{
			//логировать
			switch(es)
			{
			case net::esConnect:
			case net::esConnectHandshake:
				{
					boost::mutex::scoped_lock sl(_mtx);
					_connectNumChannels--;
				}
				break;
			case net::esListen:
			case net::esAccept:
			case net::esAcceptHandshake:
				std::cerr<<es<<": "<<ec.message()<<"("<<ec.value()<<")"<<std::endl;
				break;
			}
			//assert(0);

			balance();
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onAccept(net::ChannelPtr channel)
		{
			channel->setHandler(this);

			size_t channels;
			{
				boost::mutex::scoped_lock sl(_mtx);
				_channels.insert(channel);
				channels = _channels.size();
			}

			balance();
			tconnected(channels);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onConnect(net::ChannelPtr channel)
		{
			channel->setHandler(this);
			size_t channels;
			{
				boost::mutex::scoped_lock sl(_mtx);
				assert(_connectNumChannels);
				_connectNumChannels--;
				_channels.insert(channel);
				channels = _channels.size();
			}

			balance();
			tconnected(channels);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onStopInThread()
		{
// 			size_t channels;
// 			{
// 				boost::mutex::scoped_lock sl(_mtx);
// 				if(!_threads)
// 				{
// 					_channels.clear();
// 				}
// 				channels = _channels.size();
// 			}
// 
// 			tconnected(channels);
		}


		//////////////////////////////////////////////////////////////////////////
		void Instance::onSendComplete(const net::ChannelPtr &channel, const net::SPacket &p)
		{
			tsendComplete(p._data, p._size);
		}
		
		//////////////////////////////////////////////////////////////////////////
		void Instance::onReceive(const net::ChannelPtr &channel, const net::SPacket &p)
		{
			treceive(p._data, p._size);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onSendFailed(const net::ChannelPtr &channel, const net::SPacket &p)
		{
			//tsendFailed(p._data, p._size);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onClose(const net::ChannelPtr &channel)
		{
			size_t channels;

			{
				boost::mutex::scoped_lock sl(_mtx);
				_channels.erase(channel);
				channels = _channels.size();
			}

			balance();
			tconnected(channels);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::balance()
		{
			{
				boost::mutex::scoped_lock sl(_mtx);
				if(_favorNumChannels)
				{
					if(_favorNumChannels > _channels.size() && !_connectNumChannels)
					{
						_netsrv.connect(_host.c_str(), _port);
						_connectNumChannels++;
					}
					else if(_favorNumChannels < _channels.size())
					{
						(*_channels.begin())->close();
					}
				}
				else
				{
					if(_channels.size())
					{
						(*_channels.begin())->close();
					}
				}
			}
		}
	}
}
