#ifndef _CLIENT_QT_NETWORKACCESSMANAGERFACTORY_HPP_
#define _CLIENT_QT_NETWORKACCESSMANAGERFACTORY_HPP_

#include <QDeclarativeNetworkAccessManagerFactory>
#include "client/isession.hpp"
#include "async/service.hpp"

namespace client
{
	namespace qt
	{
		class NetworkAccessManagerFactory
			: public QDeclarativeNetworkAccessManagerFactory
		{
			client::ISessionPtr	_session;
			async::Service		_asrv;
		public:
			NetworkAccessManagerFactory(client::ISessionPtr session, async::Service asrv);
			virtual QNetworkAccessManager *create(QObject *parent);
		};
	}
}

#endif
