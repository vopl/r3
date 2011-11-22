#include "stdafx.h"
#include "serverSessionImpl.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	void ServerSessionImpl::receive(
		function<void (const SPacket &)> ok,
		function<void (system::error_code)> fail)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionImpl::send(
		const SPacket &p,
		function<void ()> ok,
		function<void (system::error_code)> fail)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionImpl::close()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	TServerSid ServerSessionImpl::sid()
	{
		assert(0);
		return nullServerSid;
	}
}
