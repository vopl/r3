#ifndef _AGENT_HPP_
#define _AGENT_HPP_

#include <QtCore/QObject>
#include <QtCore/QVariant>
#include "utils/variant.hpp"
#include "server/endpoint.hpp"
#include "client/iagent.hpp"

class Session;

//////////////////////////////////////////////////////////////////////////
class Agent
	: public QObject

{
	Q_OBJECT
// 
// 	client::IAgentPtr	_agent;
// 	Session *			_session;
// 
// private:
// 	static void variantCnvt(utils::Variant &dst, const QVariant &src);
// 	static void variantCnvt(QVariant &dst, const utils::Variant &src);
// 
// private:
// 	void onReceive(const server::TEndpoint &endpoint, utils::VariantPtr data);
// 
// private:
// 	Q_DISABLE_COPY(Agent)

// 	QString	_service;
// 	QString getService();
// 	void setService(QString service);
// 
// 	Session *getSession();
// 
// public:
// 	Agent(Session *session);
// 	~Agent();
// 
// public:
// 	Q_PROPERTY(Session * session READ getSession);
// 	Q_PROPERTY(QString service READ getService WRITE setService);
// 	Q_INVOKABLE void send(QVariant data, QString service=QString(""));
// 
// signals:
// 	void receive(QVariant data, QString service);
};

Q_DECLARE_METATYPE(Agent *)

#endif
