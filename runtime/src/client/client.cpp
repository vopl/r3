#include "pch.h"
#include "client.hpp"



namespace client
{
	//////////////////////////////////////////////////////////////////////////
	void Client::onSOk(size_t numChannels)
	{
		if(!_onSessionStartCalled)
		{
			_onSessionStart(_session);
			_onSessionStartCalled = true;
		}

		//std::cout<<__FUNCTION__<<": "<<numChannels<<std::endl;
		_onChannelChange(numChannels, boost::system::errc::make_error_code(boost::system::errc::success));
	}

	//////////////////////////////////////////////////////////////////////////
	void Client::onSFail(size_t numChannels, system::error_code ec)
	{
		//std::cout<<__FUNCTION__<<": "<<numChannels<<", "<<ec.message()<<std::endl;
		_onChannelChange(numChannels, ec);
	}

	//////////////////////////////////////////////////////////////////////////
	Client::Client()
		: _plugs(NULL)
		, _asyncOwn(false)
		, _onSessionStartCalled(false)
	{

	}
	
	//////////////////////////////////////////////////////////////////////////
	Client::~Client()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void Client::start(
		pluma::Pluma *plugs,
		async::IServicePtr async,
		boost::function<void (ISessionPtr)> onSessionStart,
		boost::function<void (ISessionPtr)> onSessionStop,
		boost::function<void (size_t numChannels, boost::system::error_code ec)> onChannelChange)
	{
		_onSessionStartCalled = false;
		_onSessionStart = onSessionStart;
		_onSessionStop = onSessionStop;
		_onChannelChange = onChannelChange;

		assert(!_plugs);
		_plugs = plugs;

		assert(!_async);
		_async = async;
		if(!_async)
		{
			//////////////////////////////////////////////////////////////////////////
			//подн€ть асинхронный двиг
			_async = _plugs->create<async::IServiceProvider>();
			assert(_async);

			_asyncOwn = true;

			//запускать асинхронный двиг
			_async->balance(1);
		}
		else
		{
			_asyncOwn = false;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void Client::connect(const char *host, const char *service)
	{
		if(_session)
		{
			if(_onSessionStartCalled)
			{
				_onSessionStop(_session);
			}
			_session->close();
			_session->stop();
			_session.reset();
		}

		_onSessionStartCalled = false;

		//////////////////////////////////////////////////////////////////////////
		//подн€ть коннектор
		net::IConnectorPtr connector = _plugs->create<net::IConnectorProvider>();
		assert(connector);
		connector->initialize(_async);

		//////////////////////////////////////////////////////////////////////////
		//подн€ть сессию
		assert(!_session);
		_session = _plugs->create<ISessionProvider>();
		assert(_session);
		_session->start(
			connector, host, service, 
			nullClientSid, 1,
			bind(&Client::onSOk, shared_from_this(), _1),
			bind(&Client::onSFail, shared_from_this(), _1, _2));
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
		if(_session)
		{
			if(_onSessionStartCalled)
			{
				_onSessionStop(_session);
			}
			_session->close();
			_session->stop();
			_session.reset();
		}

		if(_asyncOwn)
		{
			_async->stop();
		}
		_async.reset();
		_plugs = NULL;
		boost::function<void (size_t numChannels, boost::system::error_code ec)>().swap(_onChannelChange);
	}


}
