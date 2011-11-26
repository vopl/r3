#ifndef _NET_SERVERSESSIONMANAGER_HPP_
#define _NET_SERVERSESSIONMANAGER_HPP_

#include "net/iserverSessionManager.hpp"
#include "serverSession.hpp"
#include <boost/enable_shared_from_this.hpp>
#include <boost/uuid/random_generator.hpp>

namespace net
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	class ServerSessionManager;
	typedef boost::shared_ptr<ServerSessionManager> ServerSessionManagerPtr;

	class ServerSessionManager
		: IServerSessionManager
		, public enable_shared_from_this<ServerSessionManager>
	{
		IConnectorPtr	_connector;
		std::string		_host;
		std::string		_service;

		mutex _mtx;
		bool										_isStarted;
		boost::function<void (IServerSessionPtr)>	_ready;
		boost::function<void (system::error_code)>	_fail;
		boost::uuids::random_generator				_sidGen;

		typedef std::map<TServerSid, ServerSessionPtr> TMSessions;
		TMSessions			_sessions;

	private:
		void onAcceptOk(IChannelPtr channel);
		void onAcceptFail(system::error_code ec);

		void onReceiveSidOk(IChannelPtr channel, const SPacket &packet);
		void onReceiveSidFail(IChannelPtr channel, system::error_code ec);

		void attach2Session(ServerSessionPtr session, IChannelPtr channel);
		void attach2SessionFail(IChannelPtr channel);

	public:
		ServerSessionManager();

		virtual void start(
			IConnectorPtr connector,
			const char *host, const char *service,
			boost::function<void (IServerSessionPtr)> ready,
			boost::function<void (system::error_code)> fail);

		virtual void stop();
	};
}
#endif
