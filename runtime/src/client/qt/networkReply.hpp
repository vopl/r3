#ifndef _CLIENT_QT_NETWORKREPLY_HPP_
#define _CLIENT_QT_NETWORKREPLY_HPP_

#include <QtNetwork/QNetworkReply>
#include "agent.hpp"

namespace client
{
	namespace qt
	{

		class NetworkReply
			: public QNetworkReply
			, Agent
		{
			Q_OBJECT

		private:
			utils::VariantPtr	_data;
			size_t				_readPos;

		private:
			void abort();
			qint64 bytesAvailable() const;
			bool isSequential() const;
			qint64 readData(char *data, qint64 maxSize);

		protected:
			virtual void onReceive(
				IAgentHubPtr hub,
				const server::TEndpoint &endpoint,
				utils::VariantPtr data);

		public:
			NetworkReply(QObject *parent, QUrl url);
			~NetworkReply();

		};

	}
}

#endif
