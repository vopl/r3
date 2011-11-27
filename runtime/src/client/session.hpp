#ifndef _CLIENT_SESSION_HPP_
#define _CLIENT_SESSION_HPP_

#include "client/isession.hpp"
#include "../net/channelHub.hpp"

namespace client
{
	using namespace boost;
	using namespace net;

	class Session;
	typedef boost::shared_ptr<Session> SessionPtr;

	class Session
		: public ChannelHub<ISession>
	{
		IConnectorPtr	_connector;
		std::string		_host;
		std::string		_service;

		mutex				_mtx;
		bool				_isStarted;
		TClientSid			_sid;
		TClientSid			_needSid;
		size_t				_needNumChannels;

		size_t					_waitConnections;
		std::set<IChannelPtr>	_waitConnectionsChannels;

		boost::function<void (size_t)>						_ready;
		boost::function<void (size_t, system::error_code)>	_fail;

	private:
		void checkbalance();
		void onConnectOk(IChannelPtr channel);
		void onConnectError(system::error_code ec);

		void onSendSidOk(IChannelPtr channel);
		void onSendSidFail(IChannelPtr channel, system::error_code ec);

		void onReceiveSidOk(IChannelPtr channel, const SPacket &packet);
		void onReceiveSidFail(IChannelPtr channel, system::error_code ec);


	public:
		SessionPtr shared_from_this();

	public:
		Session();

		virtual void start(
			IConnectorPtr connector,
			const char *host, const char *service,
			TClientSid sid, 
			size_t numChannels,
			boost::function<void (size_t)> ready,
			boost::function<void (size_t, system::error_code)> fail);

		virtual void stop();
		virtual void close();

		virtual void balance(size_t numChannels);

		virtual TClientSid sid();

	};
	PLUMA_INHERIT_PROVIDER(Session, ISession);
}
#endif
