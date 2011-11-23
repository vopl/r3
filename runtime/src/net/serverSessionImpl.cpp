#include "stdafx.h"
#include "serverSessionImpl.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	ServerSessionImpl::ServerSessionImpl(TServerSid sid)
		: _sid(sid)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	TServerSid ServerSessionImpl::sid()
	{
		assert(0);
		return nullServerSid;
	}
}
