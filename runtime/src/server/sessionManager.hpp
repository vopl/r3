#ifndef _SERVER_SESSIONMANAGER_HPP_
#define _SERVER_SESSIONMANAGER_HPP_

#include "server/isessionManager.hpp"
#include "session.hpp"

namespace server
{
	using namespace boost;
	using namespace net;

	//////////////////////////////////////////////////////////////////////////
	class SessionManager;
	typedef boost::shared_ptr<SessionManager> ServerSessionManagerPtr;

	class SessionManager
		: public ISessionManager
		, public enable_shared_from_this<SessionManager>
	{
		IConnectorPtr	_connector;
		std::string		_host;
		std::string		_service;

		mutex _mtx;
		bool										_isStarted;
		boost::function<void (ISessionPtr)>			_sstart;
		boost::function<void (ISessionPtr)>			_sstop;
		boost::uuids::random_generator				_sidGen;

		typedef std::map<TServerSid, SessionPtr> TMSessions;
		TMSessions			_sessions;

	private:
		void onAcceptOk(IChannelPtr channel);
		void onAcceptFail(system::error_code ec);

		void onReceiveSidOk(IChannelPtr channel, const SPacket &packet);
		void onReceiveSidFail(IChannelPtr channel, system::error_code ec);

		void attach2Session(SessionPtr session, IChannelPtr channel);
		void attach2SessionFail(IChannelPtr channel);

		void onSeessionStop(SessionPtr session);

	public:
		SessionManager();

		virtual void start(
			IConnectorPtr connector,
			const char *host, const char *service,
			boost::function<void (ISessionPtr)> sstart,
			boost::function<void (ISessionPtr)> sstop);

		virtual void stop();
	};

	PLUMA_INHERIT_PROVIDER(SessionManager, ISessionManager);
}
#endif
