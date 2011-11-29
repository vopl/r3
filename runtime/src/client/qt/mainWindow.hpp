#ifndef _CLIENT_QT_MAINWINDOW_HPP_
#define _CLIENT_QT_MAINWINDOW_HPP_

#include <QtGui/QMainWindow>
#include "ui_mainWindow.h"
#include "pluma/pluma.hpp"
#include "client/iclient.hpp"

namespace client
{
	namespace qt
	{
		class MainWindow
			: public QMainWindow
		{
			Q_OBJECT
		private:
			pluma::Pluma		_plugins;
			client::IClientPtr	_client;

		public:
			MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
			~MainWindow();

		private:
			Ui::MainWindow ui;

		};
	}
}
#endif
