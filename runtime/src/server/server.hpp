#ifndef _SERVER_SERVER_HPP_
#define _SERVER_SERVER_HPP_

#include "server/iserver.hpp"
#include <boost/enable_shared_from_this.hpp>

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	class Server
		: public IServer
		, public boost::enable_shared_from_this<Server>
	{
		pluma::Pluma *_plugs;

	public:
		Server();
		~Server();

		virtual void run(pluma::Pluma *plugs);

	};
	PLUMA_INHERIT_PROVIDER(Server, IServer);
}
#endif
