#ifndef _SERVER_ISESSION_HPP_
#define _SERVER_ISESSION_HPP_

#include "net/ichannel.hpp"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/nil_generator.hpp>

namespace server
{
	typedef boost::uuids::uuid TServerSid;
	static const TServerSid nullServerSid = boost::uuids::nil_uuid();
	
	//////////////////////////////////////////////////////////////////////////
	struct ISession
		: public net::IChannel
	{
		virtual TServerSid sid() =0;
	};
	typedef boost::shared_ptr<ISession> ISessionPtr;
}
#endif
