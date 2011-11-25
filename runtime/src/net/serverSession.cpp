#include "pch.h"
#include "net/serverSession.hpp"
#include "serverSessionImpl.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	ServerSession::ServerSession(ImplPtr impl)
		: Channel(impl)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	TServerSid ServerSession::sid()
	{
		return static_pointer_cast<ServerSessionImpl>(_impl)
			->sid();
	}
}
