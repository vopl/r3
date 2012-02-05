#ifndef _SERVER_SESSIONMANAGER_HPP_
#define _SERVER_SESSIONMANAGER_HPP_

#include "server/isessionManager.hpp"
#include "session.hpp"
#include "net/iacceptor.hpp"

namespace server
{
	using namespace boost;
	using namespace net;

	//////////////////////////////////////////////////////////////////////////
	class SessionManager;
	typedef shared_ptr<SessionManager> ServerSessionManagerPtr;

	class SessionManager
		: public ISessionManager
		, public enable_shared_from_this<SessionManager>
	{
		IAcceptorPtr	_acceptor;
		std::string		_host;
		std::string		_service;

		mutex	_mtx;

		bool							_isStarted;
		function<void (ISessionPtr)>	_sstart;
		function<void (ISessionPtr)>	_sstop;
		uuids::random_generator			_sidGen;

		typedef std::map<TServerSid, SessionPtr> TMSessions;
		TMSessions	_sessions;

		//каналы в процессе инициации
		typedef std::set<IChannelPtr> TSChannels;
		TSChannels	_channels;

	private:
		void onSeessionStop(SessionPtr session);

	private:
		void listen_f(IAcceptorPtr acceptor);
		void onChannelAccept(const error_code &ec, IChannelPtr channel);
		void initChannel_f(IChannelPtr channel);
	public:
		SessionManager();

		virtual bool start(
			IAcceptorPtr acceptor, 
			const char *host, const char *service,
			function<void (ISessionPtr)> sstart,
			function<void (ISessionPtr)> sstop);

		virtual bool stop();
	};

	PLUMA_INHERIT_PROVIDER(SessionManager, ISessionManager);
}
#endif
