#include "pch.h"
#include "networkAccessManagerFactory.hpp"
#include "networkAccessManager.hpp"

namespace client
{
	namespace qt
	{
		QNetworkAccessManager *NetworkAccessManagerFactory::create(QObject *parent)
		{
			return new NetworkAccessManager(parent);
		}

	}
}
