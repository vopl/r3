#ifndef _NET_SERVERSESSIONMANAGERIMPL_HPP_
#define _NET_SERVERSESSIONMANAGERIMPL_HPP_

#include "net/serverSession.hpp"
#include "serverSessionImpl.hpp"
#include "net/connector.hpp"
#include <boost/enable_shared_from_this.hpp>
#include <boost/uuid/random_generator.hpp>

namespace net
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	class ServerSessionManagerImpl;
	typedef boost::shared_ptr<ServerSessionManagerImpl> ServerSessionManagerImplPtr;

	class ServerSessionManagerImpl
		: public enable_shared_from_this<ServerSessionManagerImpl>
	{
		Connector		_connector;
		std::string		_host;
		std::string		_service;

		mutex _mtx;
		bool										_isStarted;
		boost::function<void (ServerSession)>		_ready;
		boost::function<void (system::error_code)>	_fail;
		boost::uuids::random_generator				_sidGen;

		typedef std::map<TServerSid, ServerSessionImplPtr> TMSessions;
		TMSessions			_sessions;

	private:
		void onAcceptOk(Channel channel);
		void onAcceptFail(system::error_code ec);

		void onReceiveSidOk(Channel channel, const SPacket &packet);
		void onReceiveSidFail(Channel channel, system::error_code ec);

		void attach2Session(ServerSessionImplPtr session, Channel channel);
		void attach2SessionFail(Channel channel);

	public:
		ServerSessionManagerImpl(
			Connector connector,
			const char *host, const char *service);

		void start(
			boost::function<void (ServerSession)> ready,
			boost::function<void (system::error_code)> fail);

		void stop();
	};
}
#endif
