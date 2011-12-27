#include "pch.h"
#include "networkAccessManager.hpp"
#include "networkReply.hpp"
#include <QtNetwork/QNetworkRequest>

namespace client
{
	namespace qt
	{
		//////////////////////////////////////////////////////////////////////////
		QNetworkReply *NetworkAccessManager::createRequest(
			Operation op, 
			const QNetworkRequest &request,
			QIODevice *outgoingData)
		{
			QUrl url = request.url();

			if(url.scheme() == "client")
			{
				//url.host() - служба
				return new NetworkReply(this, url, _session);
			}

			return QNetworkAccessManager::createRequest(op, request, outgoingData);
		}

		//////////////////////////////////////////////////////////////////////////
		NetworkAccessManager::NetworkAccessManager(
			QObject *parent, 
			ISessionPtr session)
			: QNetworkAccessManager(parent)
			, _session(session)
		{

		}

		//////////////////////////////////////////////////////////////////////////
		NetworkAccessManager::~NetworkAccessManager()
		{

		}

	}
}
