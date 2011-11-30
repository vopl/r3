#include "pch.h"
#include "mainWindow.hpp"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	client::qt::MainWindow mw;
	mw.show();
	return a.exec();
}
