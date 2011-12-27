#include "pch.h"
#include "session.hpp"

namespace client
{
	//////////////////////////////////////////////////////////////////////////
	Session::Session(const TClientSid sid)
		: _sid(sid)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Session::~Session()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	Result2<error_code, size_t> Session::watchState()
	{
		assert(0);
		Result2<error_code, size_t> res;
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	void Session::balance(size_t numChannels)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	TClientSid Session::sid()
	{
		return _sid;
	}

	//////////////////////////////////////////////////////////////////////////
	IAgentPtr Session::allocAgent()
	{
		assert(0);
		return IAgentPtr();
	}

	//////////////////////////////////////////////////////////////////////////
	void Session::close()
	{
		assert(0);
	}

}
