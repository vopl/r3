#ifndef _NET_ICLIENTSESSION_HPP_
#define _NET_ICLIENTSESSION_HPP_

#include "net/iconnector.hpp"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/nil_generator.hpp>

namespace net
{
	typedef boost::uuids::uuid TClientSid;
	static const TClientSid nullClientSid = boost::uuids::nil_uuid();

	//////////////////////////////////////////////////////////////////////////
	struct IClientSession
		: public IChannel
	{
		virtual void start(
			IConnectorPtr connector,
			const char *host, const char *service,
			TClientSid sid, 
			size_t numChannels,
			boost::function<void (size_t)> ready,
			boost::function<void (size_t, boost::system::error_code)> fail) =0;

		virtual void stop() =0;
		virtual void balance(size_t numChannels) =0;

		virtual TClientSid sid() =0;
	};
	typedef boost::shared_ptr<IClientSession> IClientSessionPtr;


	PLUMA_PROVIDER_HEADER(IClientSession, 1, 1);
}
#endif
