#include "pch.hpp"
#include "client.hpp"
#include <boost/bind.hpp>

//////////////////////////////////////////////////////////////////////////
void Client::createSession_f(QPointer<Client> thisKeeper, QString host, QString service)
{
	if(!thisKeeper)
	{
		//object already deleted
		WLOG("Client::createSession_f on destroyed object");
		return;
	}

	async::Future2<boost::system::error_code, client::ISessionPtr> res = 
		_client->createSession(host.toUtf8().data(), service.toUtf8().data());
	
	res.wait();

	emit onSession(
		res.data1()?NULL:new Session(thisKeeper, res.data2()), 
		new ErrorCode(res.data1()));
}


//////////////////////////////////////////////////////////////////////////
Client::Client()
	: QObject()
	, _client()
{
	_plugins.loadFromFolder("../plug");
	_client = _plugins.create<client::IClientProvider>();

	//assert(_client);
	if(!_client)
	{
		return;
	}

	if(!_client->start(&_plugins))
	{
		_client.reset();
		return;
	}

	_client->getAsrv().setAsGlobal(false);
}

//////////////////////////////////////////////////////////////////////////
Client::~Client()
{
	if(_client)
	{
		_client->stop();
		_client.reset();
	}
}

//////////////////////////////////////////////////////////////////////////
QScriptValue Client::qtscript_ctor(QScriptContext *context, QScriptEngine *engine)
{
	if (context->thisObject().strictlyEquals(context->engine()->globalObject()))
	{
		return context->throwError(QString::fromLatin1("Client(): Did you forget to construct with 'new'?"));
	}

	Client* cpp = new Client();
	QScriptValue qs = context->engine()->newQObject(
		context->thisObject(), 
		cpp, 
		QScriptEngine::AutoOwnership);

	return qs;
}

//////////////////////////////////////////////////////////////////////////
QString Client::toString()
{
	return "Client";
}

//////////////////////////////////////////////////////////////////////////
void Client::sessionStart(QString host, QString service)
{
	if(!_client)
	{
		context()->throwError(QString("client is not created correctly"));
		return;
	}

	_client->getAsrv().spawn(boost::bind(
		&Client::createSession_f,
		this,
		QPointer<Client>(this),
		host,
		service));
}
