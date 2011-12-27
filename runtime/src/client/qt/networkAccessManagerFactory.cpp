#include "pch.h"
#include "networkAccessManagerFactory.hpp"
#include "networkAccessManager.hpp"

namespace client
{
	namespace qt
	{
		//////////////////////////////////////////////////////////////////////////
		NetworkAccessManagerFactory::NetworkAccessManagerFactory(ISessionPtr session)
			: _session(session)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		QNetworkAccessManager *NetworkAccessManagerFactory::create(QObject *parent)
		{
			return new NetworkAccessManager(parent, _session);
		}

	}
}
