#include "pchqt.h"
#include "mainWindow.hpp"

namespace client
{
	namespace qt
	{
		MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
			: QMainWindow(parent, flags)
		{
			ui.setupUi(this);

			_plugins.loadFromFolder("../plug");

			_client = _plugins.create<client::IClientProvider>();
			assert(_client);

			_client->run(&_plugins, "localhost", "29431");

// 			_connection = new r3::logic::client::Connection(this);
// 			setCentralWidget(_connection);
		}

		MainWindow::~MainWindow()
		{
			_client->stop();
// 			_connection->deleteLater();
// 			_connection = 0;
		}
	}
}