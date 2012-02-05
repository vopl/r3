#ifndef _CLIENT_QT_NETWORKREPLY_HPP_
#define _CLIENT_QT_NETWORKREPLY_HPP_

#include <QtNetwork/QNetworkReply>
#include "utils/variant.hpp"
#include "server/endpoint.hpp"
#include "client/iagent.hpp"
#include "client/isession.hpp"

namespace client
{
	namespace qt
	{

		class NetworkReply
			: public QNetworkReply
		{
			Q_OBJECT

		private:
			client::IAgentPtr	_agent;
			utils::VariantPtr	_data;
			size_t				_readPos;

		private:
			void abort();
			qint64 bytesAvailable() const;
			bool isSequential() const;
			qint64 readData(char *data, qint64 maxSize);

		protected:
			void processSend(async::Future<boost::system::error_code> res);
			void onReceive(server::TEndpoint endpoint, utils::VariantPtr data);

		public:
			NetworkReply(QObject *parent, QUrl url, client::ISessionPtr session);
			~NetworkReply();

		};

	}
}

#endif
