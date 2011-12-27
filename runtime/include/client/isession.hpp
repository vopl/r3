#ifndef _CLIENT_ISESSION_HPP_
#define _CLIENT_ISESSION_HPP_

#include "pluma/pluma.hpp"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/nil_generator.hpp>
#include "client/iagent.hpp"

namespace client
{
	typedef boost::uuids::uuid TClientSid;
	static const TClientSid nullClientSid = boost::uuids::nil_uuid();

	//////////////////////////////////////////////////////////////////////////
	struct ISession
	{
		virtual async::Result2<boost::system::error_code, size_t> watchState() =0;
		virtual void balance(size_t numChannels) =0;
		virtual TClientSid sid() =0;
		virtual IAgentPtr allocAgent() =0;
		virtual void close() =0;
	};
	typedef boost::shared_ptr<ISession> ISessionPtr;
}
#endif
