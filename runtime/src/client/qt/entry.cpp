#include "pch.h"
#include "mainWindow.hpp"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	int res;
	{
		client::qt::MainWindow mw;
		mw.show();
		res = a.exec();
	}
	return res;
}
