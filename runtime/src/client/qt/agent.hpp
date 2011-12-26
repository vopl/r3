#ifndef _CLIENT_QT_AGENT_HPP_
#define _CLIENT_QT_AGENT_HPP_

#include <QtCore/QObject>
#include <QtCore/QVariant>
#include "utils/variant.hpp"
#include "server/endpoint.hpp"
#include "client/iagent.hpp"

namespace client
{
	namespace qt
	{
		class Agent
			: public QObject

		{
			Q_OBJECT

			IAgentPtr	_agent;

		private:
			static void variantCnvt(utils::Variant &dst, const QVariant &src);
			static void variantCnvt(QVariant &dst, const utils::Variant &src);

		private:
			QString	_service;
			QString getService();
			void setService(QString service);

		public:
			Agent(QObject *parent = 0);
			~Agent();

		public:
			Q_PROPERTY(QString service READ getService WRITE setService);
			Q_INVOKABLE void send(QVariant data, QString service=QString(""));

		signals:
			void receive(QVariant data, QString service);
		};
	}
}
#endif
