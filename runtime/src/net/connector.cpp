#include "pch.h"
#include "connector.hpp"

namespace net
{

	//////////////////////////////////////////////////////////////////////////
	Connector::Connector()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	Connector::~Connector()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	Result2<system::error_code, IChannelPtr> Connector::connect(const char *host, const char *service)
	{
		assert(0);
		async::Result2<boost::system::error_code, IChannelPtr> res;
		return res;
	}

}