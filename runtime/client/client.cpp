#include "stdafx.h"
#include "client.h"

Client::Client(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	ui.actionFullScreen->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_F11));
	connect(ui.actionFullScreen, SIGNAL(changed()),
		this, SLOT(onFullScreen()));
}

Client::~Client()
{
}

void Client::resizeEvent(QResizeEvent *)
{
	//setMinimumSize(centralWidget()->minimumSize());
}

void Client::onFullScreen()
{
	if(isFullScreen())
	{
		showNormal();
		ui.actionFullScreen->setChecked(false);
	}
	else
	{
		showFullScreen();
		ui.actionFullScreen->setChecked(true);
	}
}
