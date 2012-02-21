#ifndef _AGENT_HPP_
#define _AGENT_HPP_

#include "session.hpp"
#include <QtCore/QObject>
#include <QtCore/QVariant>
#include "utils/variant.hpp"
#include "server/endpoint.hpp"
#include "client/iagent.hpp"
#include "errorCode.hpp"

//////////////////////////////////////////////////////////////////////////
class Agent
	: public QObject

{
	Q_OBJECT

	QPointer<Session>	_session;
	client::IAgentPtr	_agent;
	QString				_service;

private:
	static void variantCnvt(utils::Variant &dst, const QVariant &src);
	static void variantCnvt(QVariant &dst, const utils::Variant &src);

private:
	void onReceiveInternal(QPointer<Agent> selfKeeper, const server::TEndpoint &endpoint, utils::VariantPtr data);
	void send_f(QPointer<Agent> selfKeeper, QVariant data, QString service);

private:
	Session *getSession();
	QString getService();
	void setService(QString service);

public:
	Agent(QPointer<Session> session, client::IAgentPtr agent);
	~Agent();

public:
	Q_PROPERTY(Session * session READ getSession);
	Q_PROPERTY(QString service READ getService WRITE setService);
	Q_INVOKABLE void send(QVariant data);
	Q_INVOKABLE void send(QVariant data, QString service);

signals:
	void onSendComplete(ErrorCode *ec, QVariant data, QString service);
	void onReceive(QVariant data, QString service);
};

Q_DECLARE_METATYPE(Agent *)

#endif
