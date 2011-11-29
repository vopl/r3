#include "pchqt.h"
#include "pluma/pluma.hpp"
#include "client/iclient.hpp"
#include "qt/mainWindow.hpp"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	pluma::Pluma plugins;
	plugins.loadFromFolder("../plug");

	client::IClientPtr cl(plugins.create<client::IClientProvider>());
	assert(cl);

	cl->run(&plugins, "localhost", "29431");

	QApplication a(argc, argv);
	int res;
	{
		client::qt::MainWindow mw;
 		mw.show();
		res = a.exec();
	}
	cl->stop();
	return res;
}
