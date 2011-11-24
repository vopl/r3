#include "stdafx.h"
#include "instance.hpp"
#include <boost/bind.hpp>

namespace r3
{
	namespace server
	{
		//////////////////////////////////////////////////////////////////////////
		void Instance::onListenOk(net::Channel channel)
		{
			//
		}

		void Instance::onListenFail(system::error_code ec)
		{
			mutex::scoped_lock sl(_mtx);
			if(!_host.empty())
			{
				_connector.listen(
					_host.c_str(), _service.c_str(), 
					bind(&Instance::onListenOk, this, _1), 
					bind(&Instance::onListenFail, this, _1));
			}
		}

		//////////////////////////////////////////////////////////////////////////
		Instance::Instance(net::AsyncService &asrv)
			: _host("localhost")
			, _service("29431")
			, _connector(asrv)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Instance::~Instance()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::setAddress(const std::string &host, const std::string &service)
		{
			{
				boost::mutex::scoped_lock sl(_mtx);

				if(!_host.empty())
				{
					_connector.unlisten(_host.c_str(), _service.c_str());
				}

				_host = host;
				_service = service;

				if(!_host.empty())
				{
					_connector.listen(
						_host.c_str(), _service.c_str(), 
						bind(&Instance::onListenOk, this, _1), 
						bind(&Instance::onListenFail, this, _1));
				}

			}
		}


	}
}
