#ifndef _NET_SERVERSESSIONIMPL_HPP_
#define _NET_SERVERSESSIONIMPL_HPP_

#include "net/serverSession.hpp"
#include "channelImplBase.hpp"

namespace net
{
	class ServerSessionImpl;
	typedef boost::shared_ptr<ServerSessionImpl> ServerSessionImplPtr;

	class ServerSessionImpl
		: public ChannelImplBase
	{
	public:
		//ServerSessionImpl(Connector con);

		virtual void receive(
			function<void (const SPacket &)> ok,
			function<void (system::error_code)> fail);

		virtual void send(
			const SPacket &p,
			function<void ()> ok,
			function<void (system::error_code)> fail);

		virtual void close();

		TServerSid sid();

	};
}
#endif
