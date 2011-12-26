#include "pch.h"
#include "mainWindow.hpp"
#include <QtGui/QApplication>
#include <QtDeclarative/qdeclarative.h>
#include "client/isession.hpp"
#include "dAgent.hpp"

Q_DECLARE_METATYPE(boost::system::error_code);
Q_DECLARE_METATYPE(server::TEndpoint);
Q_DECLARE_METATYPE(utils::VariantPtr);
Q_DECLARE_METATYPE(client::ISessionPtr);


int main(int argc, char *argv[])
{
	qRegisterMetaType<boost::system::error_code>("boost::system::error_code");
	qRegisterMetaType<server::TEndpoint>("server::TEndpoint");
	qRegisterMetaType<utils::VariantPtr>("utils::VariantPtr");
	qRegisterMetaType<client::ISessionPtr>("ISessionPtr");

	qmlRegisterType<client::qt::DAgent>("Client", 1,0, "Agent");

	QApplication a(argc, argv);
	int res;
	{
		client::qt::MainWindow mw;
		mw.show();
		res = a.exec();
	}
	return res;
}
