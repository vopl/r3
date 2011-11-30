#ifndef _CLIENT_QT_DECLARATIVEHOST_HPP_
#define _CLIENT_QT_DECLARATIVEHOST_HPP_

#include <QtDeclarative/QDeclarativeComponent>

namespace client
{
	namespace qt
	{
		class DeclarativeHost
			: public QDeclarativeComponent
		{
			Q_OBJECT

		public:
			DeclarativeHost(QObject *parent = 0);
			~DeclarativeHost();

		};
	}
}
#endif
