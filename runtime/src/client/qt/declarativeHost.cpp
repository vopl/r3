#include "pch.h"
#include "declarativeHost.hpp"

namespace client
{
	namespace qt
	{
		//////////////////////////////////////////////////////////////////////////
		DeclarativeHost::DeclarativeHost(QObject *parent)
			: QDeclarativeComponent(parent)
		{

		}
		
		//////////////////////////////////////////////////////////////////////////
		DeclarativeHost::~DeclarativeHost()
		{

		}
	}
}