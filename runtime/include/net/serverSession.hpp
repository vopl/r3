#ifndef _NET_SERVERSESSION_HPP_
#define _NET_SERVERSESSION_HPP_

#include "net/channel.hpp"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/nil_generator.hpp>

namespace net
{
	typedef boost::uuids::uuid TServerSid;
	static const TServerSid nullServerSid = boost::uuids::nil_uuid();
	
	//////////////////////////////////////////////////////////////////////////
	class ServerSessionImpl;
	class ServerSession
		: public Channel
	{
	protected:
		typedef boost::shared_ptr<ServerSessionImpl> ImplPtr;

	public:
		ServerSession(ImplPtr impl);

		TServerSid sid();
	};
}
#endif
