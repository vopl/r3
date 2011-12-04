#ifndef _CLIENT_QT_AGENT_HPP_
#define _CLIENT_QT_AGENT_HPP_

#include <boost/enable_shared_from_this.hpp>
#include "client/iagent.hpp"
#include "client/iagentHub.hpp"

namespace client
{
	namespace qt
	{
		class Agent
		{
		protected:
			friend class MainWindow;
			static IAgentHubPtr	_lowAgentHub;
			static MainWindow	*_mainWindow;


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

		protected:
			IAgentPtr		_lowAgent;
			
			virtual void onReceive(
				IAgentHubPtr hub,
				const server::TEndpoint &endpoint,
				utils::VariantPtr data) =0;

		public:
			Agent();
			~Agent();

			int getNumChannels();
		};
	}
}
#endif
