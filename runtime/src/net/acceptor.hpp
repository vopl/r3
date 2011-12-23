#ifndef _NET_ACCEPTOR_HPP_
#define _NET_ACCEPTOR_HPP_

#include "net/iacceptor.hpp"
#include "async/service.hpp"

namespace net
{
	using namespace async;
	using namespace boost;
	using namespace boost::asio;

	//////////////////////////////////////////////////////////////////////////
	class Acceptor;
	typedef shared_ptr<Acceptor> AcceptorPtr;

	class Acceptor
		: public IAcceptor
		, public enable_shared_from_this<Acceptor>
	{
	public:
		Acceptor();
		virtual ~Acceptor();

		virtual async::Result<boost::system::error_code> listen(const char *host, const char *service);
		virtual async::Result2<boost::system::error_code, IChannelPtr> accept();
		virtual void unlisten();

	};

	PLUMA_INHERIT_PROVIDER(Acceptor, IAcceptor);
}
#endif
