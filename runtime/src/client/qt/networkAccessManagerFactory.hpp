#ifndef _CLIENT_QT_NETWORKACCESSMANAGERFACTORY_HPP_
#define _CLIENT_QT_NETWORKACCESSMANAGERFACTORY_HPP_

#include <QDeclarativeNetworkAccessManagerFactory>
#include "client/isession.hpp"

namespace client
{
	namespace qt
	{
		class NetworkAccessManagerFactory
			: public QDeclarativeNetworkAccessManagerFactory
		{
			client::ISessionPtr _session;
		public:
			NetworkAccessManagerFactory(client::ISessionPtr session);
			virtual QNetworkAccessManager *create(QObject *parent);
		};
	}
}

#endif
