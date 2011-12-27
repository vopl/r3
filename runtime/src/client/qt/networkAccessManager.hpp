#ifndef _CLIENT_QT_NETWORKACCESSMANAGER_HPP_
#define _CLIENT_QT_NETWORKACCESSMANAGER_HPP_

#include <QtNetwork/QNetworkAccessManager>
#include "client/isession.hpp"

namespace client
{
	namespace qt
	{

		class NetworkAccessManager
			: public QNetworkAccessManager
		{
			Q_OBJECT

			ISessionPtr _session;
		private:
			virtual QNetworkReply *createRequest(
				Operation op, 
				const QNetworkRequest &request,
				QIODevice *outgoingData);
		public:
			NetworkAccessManager(QObject *parent, client::ISessionPtr session);
			~NetworkAccessManager();

		};

	}
}

#endif
