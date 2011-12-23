#ifndef _NET_CONNECTOR2_HPP_
#define _NET_CONNECTOR2_HPP_

#include "net/iconnector2.hpp"
#include "async/service.hpp"

namespace net
{
	using namespace async;
	using namespace boost;
	using namespace boost::asio;

	//////////////////////////////////////////////////////////////////////////
	class Connector2;
	typedef shared_ptr<Connector2> Connector2Ptr;

	class Connector2
		: public IConnector2
		, public enable_shared_from_this<Connector2>
	{
	public:
		Connector2();
		virtual ~Connector2();

		virtual Result2<system::error_code, IChannelPtr> connect(const char *host, const char *service);
	};

	PLUMA_INHERIT_PROVIDER(Connector2, IConnector2);
}
#endif
