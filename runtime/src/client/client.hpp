#ifndef _CLIENT_CLIENT_HPP_
#define _CLIENT_CLIENT_HPP_

#include "client/iclient.hpp"
#include "client/isession.hpp"
#include "async/service.hpp"

namespace client
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	class Client
		: public IClient
		, public boost::enable_shared_from_this<Client>
	{
		pluma::Pluma		*_plugs;
		async::ServicePtr	_async;
		bool				_asyncOwn;
		ISessionPtr			_session;

		bool	_onSessionStartCalled;
		boost::function<void (ISessionPtr)> _onSessionStart;
		boost::function<void (ISessionPtr)> _onSessionStop;
		boost::function<void (size_t numChannels, boost::system::error_code ec)> _onChannelChange;

	protected:
		void onSOk(size_t numChannels);
		void onSFail(size_t numChannels, system::error_code ec);

	public:
		Client();
		~Client();

		virtual void start(
			pluma::Pluma *plugs,
			boost::function<void (ISessionPtr)> onSessionStart,
			boost::function<void (ISessionPtr)> onSessionStop,
			boost::function<void (size_t numChannels, boost::system::error_code ec)> onChannelChange);

		virtual void connect(const char *host, const char *service);
		virtual pluma::Pluma * getPlugs();
		virtual void stop();
	};
	PLUMA_INHERIT_PROVIDER(Client, IClient);
}
#endif
