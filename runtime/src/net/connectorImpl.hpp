#ifndef _NET_CONNECTORIMPL_HPP_
#define _NET_CONNECTORIMPL_HPP_

#include "net/connector.hpp"
#include <boost/enable_shared_from_this.hpp>
#include "channelSocketImpl.hpp"
#include <set>
#include <map>

namespace net
{
	using namespace boost;
	using namespace boost::asio;

	class AsyncServiceImpl;
	typedef shared_ptr<AsyncServiceImpl> AsyncServiceImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class ConnectorImpl;
	typedef shared_ptr<ConnectorImpl> ConnectorImplPtr;

	class ConnectorImpl
		: public enable_shared_from_this<ConnectorImpl>
	{
		AsyncServiceImplPtr _asrv;

	private:
		typedef shared_ptr<ip::tcp::resolver> TResolverPtr;
		typedef shared_ptr<ip::tcp::acceptor> TAcceptorPtr;
		typedef ssl::context TSslContext;

		TSslContext	_sslContext;

	private:
		typedef std::pair<std::string, std::string> TAddr;
		struct SListenState
		{
			ConnectorImplPtr						_self;
			TAddr									_addr;
			TResolverPtr							_resolver;
			TAcceptorPtr							_acceptor;
			function<void (Channel)>				_ok;
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
			ConnectorImplPtr						_self;
			TResolverPtr							_resolver;
			function<void (Channel)>				_ok;
			function<void (system::error_code)>		_fail;
		};
		typedef shared_ptr<SConnectState> SConnectStatePtr;

	private:
		static std::string onSslPassword();
		static void onListenResolve(
			SListenStatePtr ls, 
			const system::error_code& ec,
			ip::tcp::resolver::iterator iterator);

		static void onListenAccept(
			SListenStatePtr ls, 
			const system::error_code& ec,
			TSocketPtr socket);

		static void onListenHandshake(
			SListenStatePtr ls, 
			const system::error_code& ec,
			TSocketPtr socket);

		static void onConnectResolve(
			SConnectStatePtr cs, 
			const system::error_code& ec,
			ip::tcp::resolver::iterator iterator);

		static void onConnect(
			SConnectStatePtr cs, 
			const system::error_code& ec,
			TSocketPtr socket);

		static void onConnectHandshake(
			SConnectStatePtr cs, 
			const system::error_code& ec,
			TSocketPtr socket);

	private:
		bool unlisten(const TAddr &addr, SListenStatePtr ls);


	public:
		ConnectorImpl(const AsyncServiceImplPtr &asrv);
		~ConnectorImpl();

		void listen(
			const char *host, const char *service,
			function<void (Channel)> ok,
			function<void (system::error_code)> fail);

		bool unlisten(const char *host, const char *service);

		void connect(
			const char *host, const char *service,
			function<void (Channel)> ok,
			function<void (system::error_code)> fail);
	};
}
#endif
