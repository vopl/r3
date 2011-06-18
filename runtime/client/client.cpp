#include "stdafx.h"
#include "client.h"

Client::Client(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
	, _connection(NULL)
{
	ui.setupUi(this);

	connect(
		ui.pushButton_show, SIGNAL(clicked()),
		this, SLOT(show_c()));
	connect(
		ui.pushButton_hide, SIGNAL(clicked()),
		this, SLOT(hide_c()));

	_connection = new r3::logic::Connection(parent);
}

Client::~Client()
{
	_connection->deleteLater();
	_connection = 0;
}
