#ifndef _CLIENT_QT_NETWORKACCESSMANAGER_HPP_
#define _CLIENT_QT_NETWORKACCESSMANAGER_HPP_

#include <QtNetwork/QNetworkAccessManager>
#include "client/isession.hpp"
#include "async/service.hpp"

namespace client
{
	namespace qt
	{

		class NetworkAccessManager
			: public QNetworkAccessManager
		{
			Q_OBJECT

			ISessionPtr			_session;
			async::ServicePtr	_asrv;
		private:
			virtual QNetworkReply *createRequest(
				Operation op, 
				const QNetworkRequest &request,
				QIODevice *outgoingData);
		public:
			NetworkAccessManager(
				QObject *parent, 
				ISessionPtr session,
				async::ServicePtr asrv);
			~NetworkAccessManager();

		};

	}
}

#endif
