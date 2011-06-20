#include "stdafx.h"
#include "client.h"

Client::Client(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
	, _connection(NULL)
{
	ui.setupUi(this);

	_connection = new r3::logic::client::Connection(this);
	setCentralWidget(_connection);
}

Client::~Client()
{
	_connection->deleteLater();
	_connection = 0;
}

void Client::resizeEvent(QResizeEvent *)
{
	//setMinimumSize(centralWidget()->minimumSize());
}
