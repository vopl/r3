#include "pch.h"
#include "client.hpp"
#include "utils/variant.hpp"
#include "session.hpp"

namespace client
{
	using namespace utils;

	//////////////////////////////////////////////////////////////////////////
	void Client::createSession_f(Result2<error_code, ISessionPtr> res, const std::string &host, const std::string &service)
	{
		Result2<error_code, IChannelPtr> cres =
			_connector->connect(host.c_str(), service.c_str());

		cres.wait();

		if(cres.data1())
		{
			res(cres.data1(), ISessionPtr());
			return;
		}

		IChannelPtr channel = cres.data2();
		assert(channel);

		Variant v;
		v.as<Variant::MapStringVariant>(true)["sid"] = nullClientSid;
		Result<error_code> sres = channel->send(v);

		if(sres.data())
		{
			res(sres.data(), ISessionPtr());
			return;
		}
		
		Result2<error_code, SPacket> rres;
		channel->listen(rres, 1);

		if(rres.data1())
		{
			res(rres.data1(), ISessionPtr());
			return;
		}

		v = rres.data2();
		TClientSid sid = v["sid"];
		if(sid.is_nil())
		{
			res(make_error_code(errc::protocol_error), ISessionPtr());
			return;
		}

		SessionPtr session(new Session(sid));
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

		ServicePtr asrv;

		{
			mutex::scoped_lock sl(_mtx);
			assert(!_plugs);
			assert(!_asrv);
			assert(!_connector);

			asrv = _asrv;
		}

		if(asrv)
		{
			asrv->stop();
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
			_asrv = createService();
			if(!_asrv)
			{
				FLOG("async service creation failed");
				_plugs = NULL;
				return false;
			}
			ILOG("create new async service");
		}
		_asrv->start(1);

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
	Result2<error_code, ISessionPtr> 
		Client::createSession(const char *host, const char *service)
	{
		Result2<error_code, ISessionPtr> res;
		_asrv->spawn(bind(&Client::createSession_f, shared_from_this(), res, std::string(host), std::string(service)));
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	pluma::Pluma *Client::getPlugs()
	{
		mutex::scoped_lock sl(_mtx);
		return _plugs;
	}

	//////////////////////////////////////////////////////////////////////////
	ServicePtr Client::getAsync()
	{
		mutex::scoped_lock sl(_mtx);
		return _asrv;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Client::stop()
	{
		ILOG("stop");

		ServicePtr asrv;
		{
			mutex::scoped_lock sl(_mtx);

			_connector.reset();
			asrv = _asrv;
			_asrv.reset();
			_plugs = NULL;
		}

		if(asrv)
		{
			asrv->stop();
		}

		return true;
	}
}
