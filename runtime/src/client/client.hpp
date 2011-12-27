#ifndef _CLIENT_CLIENT_HPP_
#define _CLIENT_CLIENT_HPP_

#include "client/iclient.hpp"
#include "client/isession.hpp"
#include "async/service.hpp"
#include "net/iconnector.hpp"

namespace client
{
	using namespace boost;
	using namespace boost::system;
	using namespace async;
	using namespace net;

	//////////////////////////////////////////////////////////////////////////
	class Client
		: public IClient
		, public boost::enable_shared_from_this<Client>
	{
		mutex				_mtx;
		pluma::Pluma *		_plugs;
		ServicePtr			_asrv;
		IConnectorPtr		_connector;

	private:
		void createSession_f(Result2<error_code, ISessionPtr> res, const std::string &host, const std::string &service);

	public:
		Client();
		~Client();

		virtual bool start(pluma::Pluma *plugs);
		virtual Result2<error_code, ISessionPtr> 
			createSession(const char *host, const char *service);
		virtual pluma::Pluma * getPlugs();
		virtual ServicePtr getAsync();
		virtual bool stop();
	};
	PLUMA_INHERIT_PROVIDER(Client, IClient);
}
#endif
