#include "pch.h"
#include "agent.hpp"
#include "mainWindow.hpp"

namespace client
{
	namespace qt
	{
		//////////////////////////////////////////////////////////////////////////
		IAgentHubPtr Agent::_lowAgentHub;
		MainWindow *Agent::_mainWindow=NULL;

		//////////////////////////////////////////////////////////////////////////
		void Agent::LowAgent::onReceive(
			IAgentHubPtr hub,
			const server::TEndpoint &endpoint,
			utils::VariantPtr data)
		{
			_agent->onReceive(hub, endpoint, data);
		}

		//////////////////////////////////////////////////////////////////////////
		Agent::LowAgent::LowAgent(Agent *agent)
			: _agent(agent)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Agent::Agent()
		{
			_lowAgent.reset(new LowAgent(this));
			_lowAgentHub->addAgent(_lowAgent);
		}

		//////////////////////////////////////////////////////////////////////////
		Agent::~Agent()
		{
			_lowAgentHub->delAgent(_lowAgent);
			_lowAgent.reset();
		}

		//////////////////////////////////////////////////////////////////////////
		void Agent::send(
			const server::TEndpoint &endpoint,
			utils::VariantPtr data)
		{
			return _lowAgentHub->send(_lowAgent, endpoint, data);
		}

		//////////////////////////////////////////////////////////////////////////
		int Agent::getNumChannels()
		{
			return _mainWindow->getNumChannels();
		}

	}
}
