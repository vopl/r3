#ifndef _NET_CONNECTOR_HPP_
#define _NET_CONNECTOR_HPP_

#include "net/iconnector.hpp"
#include "async/iservice.hpp"
#include "channelSocket.hpp"

namespace net
{
	using namespace boost;
	using namespace boost::asio;

	//////////////////////////////////////////////////////////////////////////
	class Connector;
	typedef shared_ptr<Connector> ConnectorPtr;

	class Connector
		: public IConnector
		, public enable_shared_from_this<Connector>
	{
		async::IServicePtr _asrv;

	private:
		typedef shared_ptr<ip::tcp::resolver> TResolverPtr;
		typedef shared_ptr<ip::tcp::acceptor> TAcceptorPtr;
		typedef ssl::context TSslContext;
		typedef shared_ptr<TSslContext> TSslContextPtr;

		TSslContextPtr	_sslContext;

	private:
		typedef std::pair<std::string, std::string> TAddr;
		struct SListenState
		{
			TAddr									_addr;
			TResolverPtr							_resolver;
			TAcceptorPtr							_acceptor;
			function<void (IChannelPtr)>			_ok;
			function<void (system::error_code)>		_fail;
		};
		typedef shared_ptr<SListenState> SListenStatePtr;

	private:
		typedef std::set<SListenStatePtr> TSListens;
		typedef std::map<TAddr, TSListens> TMAddrListens;
		TMAddrListens _listens;
		mutex _mtx;


	private:

		struct SConnectState
		{
			TResolverPtr							_resolver;
			function<void (IChannelPtr)>			_ok;
			function<void (system::error_code)>		_fail;
		};
		typedef shared_ptr<SConnectState> SConnectStatePtr;

	private:
		static std::string onSslPassword();
		void onListenResolve(
			SListenStatePtr ls, 
			const system::error_code& ec,
			ip::tcp::resolver::iterator iterator);

		void onListenAccept(
			SListenStatePtr ls, 
			const system::error_code& ec,
			TSocketPtr socket);

		void onListenHandshake(
			SListenStatePtr ls, 
			const system::error_code& ec,
			TSocketPtr socket);

		void onConnectResolve(
			SConnectStatePtr cs, 
			const system::error_code& ec,
			ip::tcp::resolver::iterator iterator);

		void onConnect(
			SConnectStatePtr cs, 
			const system::error_code& ec,
			TSocketPtr socket);

		void onConnectHandshake(
			SConnectStatePtr cs, 
			const system::error_code& ec,
			TSocketPtr socket);

	private:
		bool unlisten(const TAddr &addr, SListenStatePtr ls);


	public:
		Connector();
		~Connector();

		virtual void initialize(async::IServicePtr asrv);

		void listen(
			const char *host, const char *service,
			function<void (IChannelPtr)> ok,
			function<void (system::error_code)> fail);

		bool unlisten(const char *host, const char *service);

		void connect(
			const char *host, const char *service,
			function<void (IChannelPtr)> ok,
			function<void (system::error_code)> fail);
	};

	PLUMA_INHERIT_PROVIDER(Connector, IConnector);
}
#endif
