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
			quint32		_numChannels;

			friend class MainWindow;
			static		ISessionPtr	_staticSession;

		private:
			static void variantCnvt(utils::Variant &dst, const QVariant &src);
			static void variantCnvt(QVariant &dst, const utils::Variant &src);

		private:
			void onReceive(const server::TEndpoint &endpoint, utils::VariantPtr data);

		private:
			QString	_service;
			QString getService();
			void setService(QString service);

			quint32 getNumChannels();

		public:
			Agent(QObject *parent = 0);
			~Agent();

		public:
			Q_PROPERTY(quint32 numChannels READ getNumChannels);
			Q_PROPERTY(QString service READ getService WRITE setService);
			Q_INVOKABLE void send(QVariant data, QString service=QString(""));

		signals:
			void receive(QVariant data, QString service);
			void numChannelsChanged(quint32 numChannels);

		public slots:
			void setNumChannels(quint32 numChannels);
		};
	}
}
#endif
