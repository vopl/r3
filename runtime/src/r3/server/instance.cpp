#include "stdafx.h"
#include "instance.hpp"

namespace r3
{
	namespace server
	{
		//////////////////////////////////////////////////////////////////////////
		Instance::Instance()
			: _host("localhost")
			, _port(29431)
			, _hasListener(false)
			, _netsrv(NULL)
			, _threads(0)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Instance::~Instance()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::setAddress(const std::string &host, short port)
		{
			{
				boost::mutex::scoped_lock sl(_mtx);
				_host = host;
				_port = port;
			}

			updateListener();
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onChannelClose(net::ChannelPtr channel)
		{
			_channels.erase(channel);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onChannelError(net::ChannelPtr channel)
		{
			_channels.erase(channel);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onStartInThread(net::Service *netsrv)
		{
			bool needUpdateListener = false;
			{
				boost::mutex::scoped_lock sl(_mtx);
				assert(!_netsrv || _netsrv == netsrv);
				_netsrv = netsrv;
				_threads++;
				needUpdateListener = !_hasListener;
			}

			if(needUpdateListener)
			{
				updateListener();
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onError(net::Service *netsrv, net::EStage es, const boost::system::error_code& ec)
		{
			boost::mutex::scoped_lock sl(_mtx);

			//логировать
			switch(es)
			{
			case net::esListen:
			case net::esAccept:
			case net::esAcceptHandshake:
				if(_hasListener)
				{
					std::cerr<<es<<": "<<ec.message()<<"("<<ec.value()<<")"<<std::endl;
				}
				break;
			case net::esConnect:
			case net::esConnectHandshake:
			case net::esSend:
			case net::esReceive:
				std::cerr<<es<<": "<<ec.message()<<"("<<ec.value()<<")"<<std::endl;
				break;
			}
			//assert(0);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onAccept(net::ChannelPtr channel)
		{
			_channels.insert(channel);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onConnect(net::ChannelPtr channel)
		{
			_channels.insert(channel);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onStopInThread()
		{
			{
				boost::mutex::scoped_lock sl(_mtx);
				_threads--;
				if(!_threads)
				{
					_channels.clear();
					if(_netsrv)
					{
						if(_hasListener)
						{
							_netsrv->listen(NULL, 0);
							_hasListener = false;
						}
						_netsrv = NULL;
					}
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::updateListener()
		{
			boost::mutex::scoped_lock sl(_mtx);

			if(!_netsrv)
			{
				return;
			}

			if(_host.empty())
			{
				if(_hasListener)
				{
					_netsrv->listen(NULL, 0);
					_hasListener = false;
				}
			}
			else
			{
				if(!_hasListener)
				{
					_netsrv->listen(_host.c_str(), _port);
					_hasListener = true;
				}
			}
		}

	}
}
