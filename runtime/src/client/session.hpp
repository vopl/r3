#ifndef _CLIENT_SESSION_HPP_
#define _CLIENT_SESSION_HPP_

#include "client/isession.hpp"
#include "net/channelHub.hpp"
#include "net/iconnector.hpp"
#include "client/endpoint.hpp"
#include "agent.hpp"

namespace client
{
	using namespace boost;
	using namespace boost::system;
	using namespace net;
	using namespace async;

	//////////////////////////////////////////////////////////////////////////
	class Session;
	typedef shared_ptr<Session> SessionPtr;

	//////////////////////////////////////////////////////////////////////////
	class Client;
	typedef shared_ptr<Client> ClientPtr;

	//////////////////////////////////////////////////////////////////////////
	class Session
		: public ISession
		, public enable_shared_from_this<Session>
	{
		typedef ChannelHub<ISession> Base;
		TClientSid _sid;

		typedef std::map<TEndpoint, Agent *> TMAgents;

		TMAgents	_agents;

		uuids::random_generator _endpointGenerator;
		mutex	_mtx;

		typedef shared_ptr<ChannelHub<IChannel> > ChannelHubPtr;
		ChannelHubPtr	_channelHub;

		ClientPtr	_client;
		std::string	_host;
		std::string	_service;
		size_t		_needNumChannels;
		bool		_connectInProgress;

		boost::function<void(boost::system::error_code, size_t)> _onStateChanged;


	private:
		void onReceive(const error_code &ec, const SPacket &p);

		void balanceChannels();

		void onStateChanged(const error_code &ec, size_t numChannels);

	public:
		Session(
			const TClientSid sid, 
			ClientPtr client, 
			const std::string &host, 
			const std::string &service);
		~Session();

		virtual void watchState(const function<void(error_code, size_t)> &onStateChanged);
		virtual void balance(size_t numChannels);
		virtual size_t getNumChannels();
		virtual TClientSid sid();
		virtual IAgentPtr allocAgent();
		virtual void close();

	public:
		bool attachChannel(IChannelPtr channel);

		void freeAgent(const TEndpoint &endpoint);
		Result<error_code> send(net::SPacket p);

	};
}
#endif
