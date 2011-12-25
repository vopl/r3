#ifndef _CLIENT_CLIENT_HPP_
#define _CLIENT_CLIENT_HPP_

#include "client/iclient.hpp"
#include "client/isession.hpp"
#include "async/service.hpp"

namespace client
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	class Client
		: public IClient
		, public boost::enable_shared_from_this<Client>
	{
	public:
		Client();
		~Client();

		virtual void start(pluma::Pluma *plugs);
		virtual async::Result2<boost::system::error_code, ISessionPtr> 
			createSession(const char *host, const char *service);
		virtual pluma::Pluma * getPlugs();
		virtual void stop();
	};
	PLUMA_INHERIT_PROVIDER(Client, IClient);
}
#endif
