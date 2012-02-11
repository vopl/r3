#include "pch.hpp"
#include "networkAccessManagerFactory.hpp"
#include "networkAccessManager.hpp"

namespace client
{
	namespace qt
	{
		//////////////////////////////////////////////////////////////////////////
		NetworkAccessManagerFactory::NetworkAccessManagerFactory(ISessionPtr session, async::Service asrv)
			: _session(session)
			, _asrv(asrv)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		QNetworkAccessManager *NetworkAccessManagerFactory::create(QObject *parent)
		{
			return new NetworkAccessManager(parent, _session);
		}

	}
}
