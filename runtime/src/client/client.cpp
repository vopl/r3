#include "pch.hpp"
#include "client.hpp"
#include "utils/variant.hpp"

namespace client
{
	using namespace utils;

	//////////////////////////////////////////////////////////////////////////
	void Client::connectSession_f(
		Future2<error_code, ISessionPtr> res, 
		const std::string &host, const std::string &service,
		SessionPtr session)
	{
		Future2<error_code, IChannelPtr> cres =
			_connector->connect(host.c_str(), service.c_str());

		cres.wait();

		if(cres.data1())
		{
			res(cres.data1(), session);
			return;
		}

		IChannelPtr channel = cres.data2();
		assert(channel);

		Variant v;
		v.as<Variant::MapStringVariant>(true)["sid"] = session?session->sid():nullClientSid;
		Future<error_code> sres = channel->send(v);

		if(sres.data())
		{
			res(sres.data(), session);
			return;
		}
		
		Future2<error_code, SPacket> rres;
		channel->listen(rres, 1);

		if(rres.data1())
		{
			res(rres.data1(), session);
			return;
		}

		v = rres.data2();
		if(!v["badSid"].isNull())
		{
			//СЃРµСЃСЃРёСЏ СѓСЃС‚Р°СЂРµР»Р°
			res(make_error_code(errc::owner_dead), session);
			return;
		}

		if(!v["sid"].is<TClientSid>())
		{
			res(make_error_code(errc::protocol_error), session);
			return;
		}

		TClientSid sid = v["sid"];

		if(!session)
		{
			session.reset(new Session(sid, shared_from_this(), host, service));
		}
		else
		{
			if(sid != session->sid())
			{
				res(make_error_code(errc::protocol_error), session);
				return;
			}
		}
		session->attachChannel(channel);
		res(error_code(), session);
	}


	//////////////////////////////////////////////////////////////////////////
	Client::Client()
		: _plugs(NULL)
	{
		ILOG("constuct");
	}

	//////////////////////////////////////////////////////////////////////////
	Client::~Client()
	{
		ILOG("destuct");

		Service asrv;

		{
			mutex::scoped_lock sl(_mtx);
			assert(!_plugs);
			assert(!_asrv);
			assert(!_connector);

			asrv = _asrv;
		}

		if(asrv)
		{
			asrv.stop();
		}


	}

	//////////////////////////////////////////////////////////////////////////
	bool Client::start(pluma::Pluma *plugs)
	{
		mutex::scoped_lock sl(_mtx);
		ILOG("start");

		if(_plugs)
		{
			WLOG("already started");
			return false;
		}
		_plugs = plugs;

		if(serviceExists())
		{
			ILOG("use existing async service");
			_asrv = service();
		}
		else
		{
			_asrv = async::Service(false);
			if(!_asrv)
			{
				FLOG("async service creation failed");
				_plugs = NULL;
				return false;
			}
			ILOG("create new async service");
		}
		_asrv.start(1);

		_connector = _plugs->create<IConnectorProvider>();
		if(!_connector)
		{
			FLOG("network connector creation failed");
			_plugs = NULL;
			_asrv.reset();
			return false;
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	Future2<error_code, ISessionPtr> 
		Client::createSession(const char *host, const char *service)
	{
		Future2<error_code, ISessionPtr> res;
		_asrv.spawn(bind(&Client::connectSession_f, shared_from_this(), res, std::string(host), std::string(service), SessionPtr()));
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	pluma::Pluma *Client::getPlugs()
	{
		mutex::scoped_lock sl(_mtx);
		return _plugs;
	}

	//////////////////////////////////////////////////////////////////////////
	Service Client::getAsrv()
	{
		mutex::scoped_lock sl(_mtx);
		return _asrv;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Client::stop()
	{
		ILOG("stop");

		Service asrv;
		{
			mutex::scoped_lock sl(_mtx);

			_connector.reset();
			asrv = _asrv;
			_asrv.reset();
			_plugs = NULL;
		}

		if(asrv)
		{
			asrv.stop();
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	Future2<error_code, ISessionPtr> 
		Client::connectSession(SessionPtr session, const std::string &host, const std::string &service)
	{
		Future2<error_code, ISessionPtr> res;
		_asrv.spawn(bind(&Client::connectSession_f, shared_from_this(), res, host, service, session));
		return res;
	}

}
