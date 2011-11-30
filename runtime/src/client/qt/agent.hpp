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
		class Agent
			: public QObject
		{
			Q_OBJECT

		private:
			class LowAgent
				: public IAgent
				, public boost::enable_shared_from_this<LowAgent>
			{
				Agent *_agent;
				virtual void onReceive(
					IAgentHubPtr hub,
					const server::TEndpoint &endpoint,
					utils::VariantPtr data);
			public:
				LowAgent(Agent *agent);
			};

		private:
			IAgentPtr		_lowAgent;
			IAgentHubPtr	_lowAgentHub;

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


		public:
			Agent();
			Agent(IAgentHubPtr lowAgentHub);
			~Agent();

		public:
			Q_INVOKABLE void send(QString service, QVariant data);

		signals:
			void receive(QString service, QVariant data);
		};
	}
}
#endif
