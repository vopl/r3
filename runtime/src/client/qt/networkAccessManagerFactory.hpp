#ifndef _CLIENT_QT_NETWORKACCESSMANAGERFACTORY_HPP_
#define _CLIENT_QT_NETWORKACCESSMANAGERFACTORY_HPP_

#include <QDeclarativeNetworkAccessManagerFactory>

namespace client
{
	namespace qt
	{
		class NetworkAccessManagerFactory
			: public QDeclarativeNetworkAccessManagerFactory
		{
		public:
			virtual QNetworkAccessManager *create(QObject *parent);
		};
	}
}

#endif
