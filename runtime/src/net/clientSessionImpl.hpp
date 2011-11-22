#ifndef _NET_CLIENTSESSION_HPP_
#define _NET_CLIENTSESSION_HPP_

#include "net/connector.hpp"

namespace net
{
	class ClientSessionImpl
		: public ChannelImpl
	{
	public:
		ClientSessionImpl(ConnectorImplPtr con);

		void start(
			TSid sid, 
			size_t numChannels,
			const char *host, const char *service,
			boost::function<void ()> ready,
			boost::function<void (system::error_code)> fail);

		TSid sid();

		void stop();
	};
}
#endif
