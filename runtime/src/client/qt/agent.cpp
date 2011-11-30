#include "pch.h"
#include "agent.hpp"
#include <QtDeclarative/qdeclarative.h>

namespace client
{
	namespace qt
	{
		//////////////////////////////////////////////////////////////////////////
		void Agent::LowAgent::onReceive(
			IAgentHubPtr hub,
			const server::TEndpoint &endpoint,
			utils::VariantPtr data)
		{
			_agent->onReceive_sig(hub, endpoint, data);
		}

		//////////////////////////////////////////////////////////////////////////
		Agent::LowAgent::LowAgent(Agent *agent)
			: _agent(agent)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		void Agent::onReceive_slot(
			IAgentHubPtr hub,
			const server::TEndpoint &endpoint,
			utils::VariantPtr data)
		{
			emit receive(QString("srv"), QVariant(220));
		}


		//////////////////////////////////////////////////////////////////////////
		Agent::Agent()
			: _lowAgentHub()
		{
			connect(
				this, SIGNAL(onReceive_sig(IAgentHubPtr, const server::TEndpoint &, utils::VariantPtr)),
				this, SLOT(onReceive_slot(IAgentHubPtr, const server::TEndpoint &, utils::VariantPtr)),
				Qt::QueuedConnection);

			_lowAgent.reset(new LowAgent(this));
		}

		//////////////////////////////////////////////////////////////////////////
		Agent::Agent(IAgentHubPtr lowAgentHub)
			: _lowAgentHub(lowAgentHub)
		{
			qmlRegisterType<Agent>("r3.clientqt", 1, 0, "Agent");

			qRegisterMetaType<client::IAgentHubPtr>("client::IAgentHubPtr");
			qRegisterMetaType<server::TEndpoint>("server::TEndpoint");
			qRegisterMetaType<utils::VariantPtr>("utils::VariantPtr");

			connect(
				this, SIGNAL(onReceive_sig(IAgentHubPtr, const server::TEndpoint &, utils::VariantPtr)),
				this, SLOT(onReceive_slot(IAgentHubPtr, const server::TEndpoint &, utils::VariantPtr)),
				Qt::QueuedConnection);

			_lowAgent.reset(new LowAgent(this));
			_lowAgentHub->addAgent(_lowAgent);
		}
		
		//////////////////////////////////////////////////////////////////////////
		Agent::~Agent()
		{
			_lowAgentHub->delAgent(_lowAgent);
		}

		//////////////////////////////////////////////////////////////////////////
		void Agent::send(QString service, QVariant data)
		{
			assert(0);
			//endpoint
			//_lowAgentHub->send(_lowAgent, endpoint, data, ok, fail);

		}

	}
}
