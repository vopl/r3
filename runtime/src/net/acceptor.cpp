#include "pch.h"
#include "acceptor.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	Acceptor::Acceptor()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	Acceptor::~Acceptor()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	Result<system::error_code> Acceptor::listen(const char *host, const char *service)
	{
		assert(0);
		Result<system::error_code> res;

		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	Result2<system::error_code, IChannelPtr> Acceptor::accept()
	{
		assert(0);
		Result2<system::error_code, IChannelPtr> res;

		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	void Acceptor::unlisten()
	{
		assert(0);
	}

}