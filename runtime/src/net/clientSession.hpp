#ifndef _NET_CLIENTSESSION_HPP_
#define _NET_CLIENTSESSION_HPP_

#include "net/iclientSession.hpp"
#include "channelHub.hpp"

namespace net
{
	class ClientSession;
	typedef boost::shared_ptr<ClientSession> ClientSessionPtr;

	class ClientSession
		: public ChannelHub<IClientSession>
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
		ClientSessionPtr shared_from_this();

	public:
		ClientSession();

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
}
#endif
