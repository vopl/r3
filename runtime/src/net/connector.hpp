#ifndef _NET_CONNECTOR_HPP_
#define _NET_CONNECTOR_HPP_

#include "net/iconnector.hpp"
#include "async/service.hpp"
#include "channelSocket.hpp"

namespace net
{
	using namespace async;
	using namespace boost;
	using namespace boost::asio;
	using namespace boost::system;

	//////////////////////////////////////////////////////////////////////////
	class Connector;
	typedef shared_ptr<Connector> ConnectorPtr;

	class Connector
		: public IConnector
		, public enable_shared_from_this<Connector>
	{
		mutex			_mtx;
		TSslContextPtr	_sslContext;

		std::string onSslPassword();

		void connect_f(Result2<error_code, IChannelPtr> res, const std::string &host, const std::string &service, bool useSsl);

	public:
		Connector();
		virtual ~Connector();

		virtual Result2<error_code, IChannelPtr> connect(const char *host, const char *service, bool useSsl);
	};

	PLUMA_INHERIT_PROVIDER(Connector, IConnector);
}
#endif
