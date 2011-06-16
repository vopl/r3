#include "stdafx.h"
#include "client.h"

Client::Client(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
}

Client::~Client()
{

}
