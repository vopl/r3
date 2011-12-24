#ifndef _NET_ACCEPTOR_HPP_
#define _NET_ACCEPTOR_HPP_

#include "net/iacceptor.hpp"
#include "async/service.hpp"

namespace net
{
	using namespace async;

	//////////////////////////////////////////////////////////////////////////
	class Acceptor;
	typedef shared_ptr<Acceptor> AcceptorPtr;

	class Acceptor
		: public IAcceptor
		, public enable_shared_from_this<Acceptor>
	{
		mutex			_mtx;
		bool			_inProcess;

		typedef ip::tcp::acceptor TAcceptor;
		typedef boost::shared_ptr<ip::tcp::acceptor> TAcceptorPtr;
		typedef ssl::context TSslContext;
		typedef shared_ptr<TSslContext> TSslContextPtr;

		TAcceptorPtr	_acceptor;
		TSslContextPtr	_sslContext;

	private:
		std::string onSslPassword();

	private:
		void listen_f(Result<error_code> res,
			const std::string &host, const std::string &service, bool useSsl);

		void accept_f(Result2<error_code, IChannelPtr> res);

	public:
		Acceptor();
		virtual ~Acceptor();

		virtual Result<error_code> listen(const char *host, const char *service, bool useSsl);
		virtual Result2<error_code, IChannelPtr> accept();
		virtual void unlisten();

	};

	PLUMA_INHERIT_PROVIDER(Acceptor, IAcceptor);
}
#endif
