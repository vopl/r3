#ifndef _NET_CLIENTSESSION_HPP_
#define _NET_CLIENTSESSION_HPP_

#include "net/connector.hpp"

namespace net
{
	typedef int TSid;
	class ClientSessionImpl;
	class ClientSession
		: public Channel
	{
	protected:
		typedef boost::shared_ptr<ClientSessionImpl> ImplPtr;

	public:
		ClientSession(Connector con);

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
