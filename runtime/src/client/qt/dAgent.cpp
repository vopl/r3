#include "pch.h"
#include "dAgent.hpp"
#include <QtDeclarative/qdeclarative.h>

namespace client
{
	namespace qt
	{
		//////////////////////////////////////////////////////////////////////////
		IAgentHubPtr DAgent::_lowAgentHub;

		//////////////////////////////////////////////////////////////////////////
		void DAgent::LowAgent::onReceive(
			IAgentHubPtr hub,
			const server::TEndpoint &endpoint,
			utils::VariantPtr data)
		{
			_agent->onReceive_sig(hub, endpoint, data);
		}

		//////////////////////////////////////////////////////////////////////////
		DAgent::LowAgent::LowAgent(DAgent *agent)
			: _agent(agent)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		void DAgent::onReceive_slot(
			IAgentHubPtr hub,
			const server::TEndpoint &endpoint,
			utils::VariantPtr data)
		{
			assert(!"конвертировать данные");
			emit receive(QVariant(220), QString("srv"));
		}


		//////////////////////////////////////////////////////////////////////////
		DAgent::DAgent(QObject *parent)
		{
			connect(
				this, SIGNAL(onReceive_sig(IAgentHubPtr, const server::TEndpoint &, utils::VariantPtr)),
				this, SLOT(onReceive_slot(IAgentHubPtr, const server::TEndpoint &, utils::VariantPtr)),
				Qt::QueuedConnection);

			_lowAgent.reset(new LowAgent(this));
			_lowAgentHub->addAgent(_lowAgent);
		}

	
		//////////////////////////////////////////////////////////////////////////
		DAgent::~DAgent()
		{
			_lowAgentHub->delAgent(_lowAgent);
		}

		//////////////////////////////////////////////////////////////////////////
		void DAgent::send(QVariant data, QString service)
		{
			assert(0);
			//endpoint
			//_lowAgentHub->send(_lowAgent, endpoint, data, ok, fail);

		}

	}
}
