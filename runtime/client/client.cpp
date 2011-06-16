#include "stdafx.h"
#include "client.h"

Client::Client(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
	, _connection(parent)
{
	ui.setupUi(this);

	connect(
		ui.pushButton_show, SIGNAL(clicked()),
		this, SLOT(show_c()));
	connect(
		ui.pushButton_hide, SIGNAL(clicked()),
		this, SLOT(hide_c()));
}

Client::~Client()
{

}
