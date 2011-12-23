#include "pch.h"
#include "connector2.hpp"

namespace net
{

	//////////////////////////////////////////////////////////////////////////
	Connector2::Connector2()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	Connector2::~Connector2()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result2<boost::system::error_code, IChannelPtr> Connector2::connect(const char *host, const char *service)
	{
		assert(0);
		async::Result2<boost::system::error_code, IChannelPtr> res;
		return res;
	}

}