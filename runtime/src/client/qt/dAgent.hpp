#ifndef _CLIENT_QT_DAGENT_HPP_
#define _CLIENT_QT_DAGENT_HPP_

#include <QtCore/QObject>
#include <QtCore/QVariant>
#include "agent.hpp"

namespace client
{
	namespace qt
	{
		class DAgent
			: public QObject
			, public Agent

		{
			Q_OBJECT

		private:
			virtual void onReceive(
				IAgentHubPtr hub,
				const server::TEndpoint &endpoint,
				utils::VariantPtr data);

		signals:
			void onReceive_sig(
				IAgentHubPtr hub,
				const server::TEndpoint &endpoint,
				utils::VariantPtr data);
		private slots:
			void onReceive_slot(
				IAgentHubPtr hub,
				const server::TEndpoint &endpoint,
				utils::VariantPtr data);
			void onChannelChange_slot(int numChannels);

		private:
			static void variantCnvt(utils::Variant &dst, const QVariant &src);
			static void variantCnvt(QVariant &dst, const utils::Variant &src);

		private:
			QString	_service;
			QString getService();
			void setService(QString service);

		public:
			DAgent(QObject *parent = 0);
			~DAgent();

		public:
			Q_PROPERTY(int numChannels READ getNumChannels);
			Q_PROPERTY(QString service READ getService WRITE setService);
			Q_INVOKABLE void send(QVariant data, QString service=QString(""));

		signals:
			void receive(QVariant data, QString service);
			void numChannelsChanged();
		};
	}
}
#endif
