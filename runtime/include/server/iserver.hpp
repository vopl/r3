#ifndef _SERVER_ISERVER_HPP_
#define _SERVER_ISERVER_HPP_

#include "pluma/pluma.hpp"
#include <boost/shared_ptr.hpp>
// #include <boost/function.hpp>
// #include <boost/asio/io_service.hpp>

namespace server
{
	struct IServer
	{
		virtual void run(pluma::Pluma *plugs) =0;
	};
	typedef boost::shared_ptr<IServer> IServerPtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_PROVIDER_HEADER(IServer, 1, 1);

}
#endif
