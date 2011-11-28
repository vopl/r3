#include "pch.h"
#include "session.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	Session::Session(TServerSid sid)
		: _sid(sid)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	TServerSid Session::sid()
	{
		return _sid;
	}
}
