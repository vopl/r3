#ifndef _CLIENT_CLIENT_HPP_
#define _CLIENT_CLIENT_HPP_

#include "client/iclient.hpp"
#include "client/isession.hpp"

namespace client
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	class Client
		: public IClient
		, public boost::enable_shared_from_this<Client>
	{
		pluma::Pluma *_plugs;
		async::IServicePtr	_async;

	protected:
		void onSOk(size_t numChannels);
		void onSFail(size_t numChannels, system::error_code ec);

	public:
		Client();
		~Client();

		virtual void run(pluma::Pluma *plugs, const char *host, const char *service);
		virtual pluma::Pluma * getPlugs();
		virtual async::IServicePtr getAsync();
		virtual void stop();
	};
	PLUMA_INHERIT_PROVIDER(Client, IClient);
}
#endif
