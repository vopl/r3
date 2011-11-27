#ifndef _SERVER_SERVER_HPP_
#define _SERVER_SERVER_HPP_

#include "server/iserver.hpp"
#include "server/isession.hpp"

namespace server
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	class Server
		: public IServer
		, public boost::enable_shared_from_this<Server>
	{
		pluma::Pluma *_plugs;
		async::IServicePtr	_async;

	private:
		void onSsmOk(ISessionPtr session);
		void onSsmFail(system::error_code ec);

	public:
		Server();
		~Server();

		virtual void run(pluma::Pluma *plugs, const char *host, const char *service);
		virtual pluma::Pluma * getPlugs();
		virtual async::IServicePtr getAsync();
	};
	PLUMA_INHERIT_PROVIDER(Server, IServer);
}
#endif
