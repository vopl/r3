#ifndef _NET_CONNECTOR_HPP_
#define _NET_CONNECTOR_HPP_

#include "net/iconnector.hpp"
#include "async/service.hpp"

namespace net
{
	using namespace async;
	using namespace boost;
	using namespace boost::asio;

	//////////////////////////////////////////////////////////////////////////
	class Connector;
	typedef shared_ptr<Connector> ConnectorPtr;

	class Connector
		: public IConnector
		, public enable_shared_from_this<Connector>
	{
	public:
		Connector();
		virtual ~Connector();

		virtual Result2<system::error_code, IChannelPtr> connect(const char *host, const char *service);
	};

	PLUMA_INHERIT_PROVIDER(Connector, IConnector);
}
#endif
