#ifndef _CLIENT_QT_DHOST_HPP_
#define _CLIENT_QT_DHOST_HPP_

#include <QtDeclarative/QDeclarativeItem>

namespace client
{
	namespace qt
	{
		class DHost
			: public QDeclarativeItem
		{
			Q_OBJECT

			//Q_PROPERTY(Agent *agent READ agent)
			//Q_PROPERTY(Env *env READ env)

			bool qmlAttachedProperties;

		public:
			DHost(QDeclarativeItem *parent = 0);
			~DHost();

		};
	}
}
//QML_DECLARE_TYPEINFO(DeclarativeHost, QML_HAS_ATTACHED_PROPERTIES)
#endif
