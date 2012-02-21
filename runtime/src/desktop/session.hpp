#ifndef _SESSION_HPP_
#define _SESSION_HPP_

#include "errorCode.hpp"
#include <client/isession.hpp>
#include <QtCore/QUuid>
#include <QPointer>

class Client;
class Agent;

//////////////////////////////////////////////////////////////////////////
class Session
	: public QObject

{
	Q_OBJECT

	QPointer<Client>	_client;
	client::ISessionPtr	_session;

private:
	void onStateChangedInternal(QPointer<Session> thisKeeper, const boost::system::error_code &ec, size_t numChannels);

private:
 	Client *getClient();
	quint32 getNumChannels();
	QUuid getSid();

public:
	Session(QPointer<Client> client, client::ISessionPtr session);
	~Session();

public:
	Q_PROPERTY(Client * client READ getClient);
	Q_PROPERTY(quint32 numChannels READ getNumChannels);
	Q_PROPERTY(QUuid sid READ getSid);

	Q_INVOKABLE void balance(quint32 numChannels);
	Q_INVOKABLE void close();
	Q_INVOKABLE Agent *allocAgent();

signals:
	void onStateChanged(ErrorCode *, quint32);
};

Q_DECLARE_METATYPE(Session *)


#endif
