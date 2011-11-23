#ifndef _NET_CLIENTSESSIONIMPL_HPP_
#define _NET_CLIENTSESSIONIMPL_HPP_

#include "net/clientSession.hpp"
#include "channelHubImpl.hpp"

namespace net
{
	class ClientSessionImpl;
	typedef boost::shared_ptr<ClientSessionImpl> ClientSessionImplPtr;

	class ClientSessionImpl
		: public ChannelHubImpl
	{
		Connector		_connector;
		std::string		_host;
		std::string		_service;

		mutex				_mtx;
		bool				_isStarted;
		TClientSid			_sid;
		TClientSid			_needSid;
		size_t				_needNumChannels;

		size_t				_waitConnections;
		std::set<Channel>	_waitConnectionsChannels;

		boost::function<void (size_t)>						_ready;
		boost::function<void (size_t, system::error_code)>	_fail;

	private:
		void checkbalance();
		void onConnectOk(Channel channel);
		void onConnectError(system::error_code ec);

		void onSendSidOk(Channel channel);
		void onSendSidFail(Channel channel, system::error_code ec);

		void onReceiveSidOk(Channel channel, const SPacket &packet);
		void onReceiveSidFail(Channel channel, system::error_code ec);


	public:
		ClientSessionImplPtr shared_from_this();

		ClientSessionImpl(
			Connector connector,
			const char *host, const char *service);

		void start(
			TClientSid sid, 
			size_t numChannels,
			boost::function<void (size_t)> ready,
			boost::function<void (size_t, system::error_code)> fail);

		void stop();
		void close();

		void balance(size_t numChannels);

		TClientSid sid();

	};
}
#endif
