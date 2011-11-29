#include "pch.h"
#include "client.hpp"



namespace client
{
	//////////////////////////////////////////////////////////////////////////
	void Client::onSOk(size_t numChannels)
	{
		std::cout<<__FUNCTION__<<": "<<numChannels<<std::endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void Client::onSFail(size_t numChannels, system::error_code ec)
	{
		std::cout<<__FUNCTION__<<": "<<numChannels<<", "<<ec.message()<<std::endl;
	}

	//////////////////////////////////////////////////////////////////////////
	Client::Client()
		: _plugs(NULL)
	{

	}
	
	//////////////////////////////////////////////////////////////////////////
	Client::~Client()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void Client::run(pluma::Pluma *plugs, const char *host, const char *service)
	{
		assert(!_plugs);
		_plugs = plugs;

		//////////////////////////////////////////////////////////////////////////
		//подн€ть асинхронный двиг
		_async = _plugs->create<async::IServiceProvider>();
		assert(_async);
		_async->balance(4);

		//////////////////////////////////////////////////////////////////////////
		//подн€ть коннектор
		net::IConnectorPtr connector = _plugs->create<net::IConnectorProvider>();
		assert(connector);
		connector->initialize(_async);

		//////////////////////////////////////////////////////////////////////////
		//подн€ть сессию
		ISessionPtr s = _plugs->create<ISessionProvider>();
		assert(s);
		s->start(
			connector, host, service, 
			nullClientSid, 100000,
			bind(&Client::onSOk, shared_from_this(), _1),
			bind(&Client::onSFail, shared_from_this(), _1, _2));

		//запускать асинхронный двиг
		_async->balance(4);
	}

	//////////////////////////////////////////////////////////////////////////
	pluma::Pluma *Client::getPlugs()
	{
		return _plugs;
	}

	//////////////////////////////////////////////////////////////////////////
	async::IServicePtr Client::getAsync()
	{
		return _async;
	}

	//////////////////////////////////////////////////////////////////////////
	void Client::stop()
	{
		_async->stop();
		_async.reset();
		_plugs = NULL;
	}


}
