#include "pchqt.h"
#include "mainWindow.hpp"

namespace client
{
	namespace qt
	{
		MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
			: QMainWindow(parent, flags)
		{
			//ui.setupUi(this);

// 			_connection = new r3::logic::client::Connection(this);
// 			setCentralWidget(_connection);
		}

		MainWindow::~MainWindow()
		{
// 			_connection->deleteLater();
// 			_connection = 0;
		}
	}
}