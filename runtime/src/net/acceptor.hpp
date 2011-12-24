#ifndef _NET_ACCEPTOR_HPP_
#define _NET_ACCEPTOR_HPP_

#include "net/iacceptor.hpp"
#include "async/service.hpp"
#include "channelSocket.hpp"

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

		TAcceptorPtr	_acceptor;
		TSslContextPtr	_sslContext;

	private:
		std::string onSslPassword();

	private:
		void listen_f(Result<error_code> res,
			const boost::function<void(boost::system::error_code, IChannelPtr)> &onAccept,
			const std::string &host, const std::string &service, bool useSsl);

		void accept_f(const function<void(error_code, IChannelPtr)> &onAccept);

	public:
		Acceptor();
		virtual ~Acceptor();

		virtual Result<error_code> listen(
			const boost::function<void(boost::system::error_code, IChannelPtr)> &onAccept,
			const char *host, const char *service, bool useSsl);
		virtual void unlisten();

	};

	PLUMA_INHERIT_PROVIDER(Acceptor, IAcceptor);
}
#endif
