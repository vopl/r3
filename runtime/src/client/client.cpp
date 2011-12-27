#include "pch.h"
#include "client.hpp"


namespace client
{
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

		assert(0);
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

		_asrv = service();
		if(_asrv)
		{
			ILOG("use existing async service");
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
