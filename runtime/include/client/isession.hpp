#ifndef _CLIENT_ISESSION_HPP_
#define _CLIENT_ISESSION_HPP_

#include "net/iconnector.hpp"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/nil_generator.hpp>

namespace client
{
	typedef boost::uuids::uuid TClientSid;
	static const TClientSid nullClientSid = boost::uuids::nil_uuid();

	//////////////////////////////////////////////////////////////////////////
	struct ISession
		: public net::IChannel
	{
		virtual void start(
			net::IConnectorPtr connector,
			const char *host, const char *service,
			TClientSid sid, 
			size_t numChannels,
			boost::function<void (size_t)> ready,
			boost::function<void (size_t, boost::system::error_code)> fail) =0;

		virtual void stop() =0;
		virtual void balance(size_t numChannels) =0;

		virtual TClientSid sid() =0;
	};
	typedef boost::shared_ptr<ISession> ISessionPtr;


	PLUMA_PROVIDER_HEADER(ISession, 1, 1);
}
#endif
