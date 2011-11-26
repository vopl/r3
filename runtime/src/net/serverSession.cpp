#include "pch.h"
#include "serverSession.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	ServerSession::ServerSession(TServerSid sid)
		: _sid(sid)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	TServerSid ServerSession::sid()
	{
		assert(0);
		return nullServerSid;
	}
}
