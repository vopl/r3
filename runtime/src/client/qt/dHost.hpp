#ifndef _CLIENT_QT_DHOST_HPP_
#define _CLIENT_QT_DHOST_HPP_

#include <QtDeclarative/QDeclarativeItem>

namespace client
{
	namespace qt
	{
		class DHost
			: public QObject
		{
			Q_OBJECT

			//Q_PROPERTY(Agent *agent READ agent)
			//Q_PROPERTY(Env *env READ env)

		public:
			static QObject *qmlAttachedProperties(QObject *);

		public:
			DHost(QObject *parent = 0);
			~DHost();

		};
	}
}
QML_DECLARE_TYPEINFO(client::qt::DHost, QML_HAS_ATTACHED_PROPERTIES)
#endif
