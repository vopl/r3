#ifndef _NET_CLIENTSESSION_HPP_
#define _NET_CLIENTSESSION_HPP_

#include "net/connector.hpp"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/nil_generator.hpp>

namespace net
{
	typedef boost::uuids::uuid TClientSid;
	static const TClientSid nullClientSid = boost::uuids::nil_uuid();

	//////////////////////////////////////////////////////////////////////////
	class ClientSessionImpl;
	class ClientSession
		: public Channel
	{
	protected:
		typedef boost::shared_ptr<ClientSessionImpl> ImplPtr;

	public:
		ClientSession(
			Connector connector,
			const char *host, const char *service);

		void start(
			TClientSid sid, 
			size_t numChannels,
			boost::function<void (size_t)> ready,
			boost::function<void (size_t, boost::system::error_code)> fail);

		void balance(size_t numChannels);

		TClientSid sid();
	};
}
#endif
