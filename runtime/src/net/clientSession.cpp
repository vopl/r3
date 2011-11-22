#include "stdafx.h"
#include "net/clientSession.hpp"
#include "clientSessionImpl.hpp"

namespace net
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	ClientSession::ClientSession(Connector connector, const char *host, const char *service)
		: Channel(ChannelImplBasePtr(new ClientSessionImpl(connector, host, service)))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSession::start(
		TClientSid sid, 
		size_t numChannels,
		function<void (size_t)> ready,
		function<void (size_t, system::error_code)> fail)
	{
		return static_pointer_cast<ClientSessionImpl>(_impl)
			->start(sid, numChannels, ready, fail);
	}

	//////////////////////////////////////////////////////////////////////////
	void ClientSession::balance(size_t numChannels)
	{
		return static_pointer_cast<ClientSessionImpl>(_impl)
			->balance(numChannels);
	}

	//////////////////////////////////////////////////////////////////////////
	TClientSid ClientSession::sid()
	{
		return static_pointer_cast<ClientSessionImpl>(_impl)
			->sid();
	}
}
