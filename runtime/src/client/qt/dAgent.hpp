#ifndef _CLIENT_QT_AGENT_HPP_
#define _CLIENT_QT_AGENT_HPP_

#include <QtCore/QObject>
#include <QtCore/QVariant>
#include <boost/enable_shared_from_this.hpp>
#include "client/iagent.hpp"
#include "client/iagentHub.hpp"

namespace client
{
	namespace qt
	{
		class DAgent
			: public QObject

		{
			Q_OBJECT

		private:
			friend class MainWindow;
			static IAgentHubPtr	_lowAgentHub;
			static MainWindow	*_mainWindow;


		private:
			class LowAgent
				: public IAgent
				, public boost::enable_shared_from_this<LowAgent>
			{
				DAgent *_agent;
				virtual void onReceive(
					IAgentHubPtr hub,
					const server::TEndpoint &endpoint,
					utils::VariantPtr data);
			public:
				LowAgent(DAgent *agent);
			};

			IAgentPtr		_lowAgent;
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

			int getNumChannels();

		public:
			DAgent(QObject *parent = 0);
			~DAgent();

		public:
			Q_PROPERTY(int numChannels READ getNumChannels);
			Q_INVOKABLE void send(QVariant data, QString service=QString(""));

		signals:
			void receive(QVariant data, QString service);
			void numChannelsChanged();
		};
	}
}
#endif
