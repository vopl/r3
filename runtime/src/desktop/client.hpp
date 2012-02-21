#ifndef _CLIENT_HPP_
#define _CLIENT_HPP_

#include "session.hpp"
#include "errorCode.hpp"
#include "client/iclient.hpp"
#include <QPointer>
#include <QScriptable>
#include <pluma/pluma.hpp>

//////////////////////////////////////////////////////////////////////////
class Client
	: public QObject
	, private QScriptable
{
	Q_OBJECT

	pluma::Pluma		*_plugins;
	client::IClientPtr	_client;

private:
	void createSession_f(QPointer<Client> thisKeeper, QString host, QString service);

public:
	Client(pluma::Pluma *plugins);
	~Client();

	client::IClientPtr	getRawClient();

public:
	static QScriptValue qtscript_ctor(QScriptContext *context, QScriptEngine *engine);

public:
	Q_INVOKABLE QString toString();
	Q_INVOKABLE void sessionStart(QString host, QString service);

signals:
	void onSession(Session *s, ErrorCode *ec);

};

Q_DECLARE_METATYPE(Client *)

#endif
