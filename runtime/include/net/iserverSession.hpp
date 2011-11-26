#ifndef _NET_ISERVERSESSION_HPP_
#define _NET_ISERVERSESSION_HPP_

#include "net/ichannel.hpp"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/nil_generator.hpp>

namespace net
{
	typedef boost::uuids::uuid TServerSid;
	static const TServerSid nullServerSid = boost::uuids::nil_uuid();
	
	//////////////////////////////////////////////////////////////////////////
	struct IServerSession
		: public IChannel
	{
		virtual TServerSid sid() =0;
	};
	typedef boost::shared_ptr<IServerSession> IServerSessionPtr;
}
#endif
