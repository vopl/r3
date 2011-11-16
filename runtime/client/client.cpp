#include "stdafx.h"
#include "client.h"
#include "r3/client/instance.hpp"

Client::Client(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	qRegisterMetaType<boost::shared_array<char> >("boost::shared_array<char>");
	qRegisterMetaType<utils::VariantPtr>("utils::VariantPtr");
	qRegisterMetaType<size_t>("size_t");

	ui.setupUi(this);

	ui.actionFullScreen->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_F11));
	connect(ui.actionFullScreen, SIGNAL(changed()),
		this, SLOT(onFullScreen()));

	connect(
		&_inst, SIGNAL(connected(size_t)),
		this, SLOT(connected(size_t)),
		Qt::QueuedConnection);

	connect(
		&_inst, SIGNAL(receive(boost::shared_array<char>, size_t)),
		this, SLOT(receive(boost::shared_array<char>, size_t)),
		Qt::QueuedConnection);

	connect(
		&_inst, SIGNAL(receive(const utils::VariantPtr &)),
		this, SLOT(receive(const utils::VariantPtr &)),
		Qt::QueuedConnection);

	_inst.setAddress("localhost", 29431);
	_inst.balance(2);
}

Client::~Client()
{
	disconnect(
		&_inst, SIGNAL(connected(size_t)),
		this, SLOT(connected(size_t)));

	disconnect(
		&_inst, SIGNAL(receive(boost::shared_array<char>, size_t)),
		this, SLOT(receive(boost::shared_array<char>, size_t)));

	disconnect(
		&_inst, SIGNAL(receive(const utils::VariantPtr &)),
		this, SLOT(receive(const utils::VariantPtr &)));

	_inst.balance(0);
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






void Client::connected(size_t channels)
{
	QString s;
	s.sprintf("%d", (int)channels);
	ui.label_2->setText(s);
}

void Client::receive(boost::shared_array<char> data, size_t size)
{
	assert(0);
}

void Client::receive(const utils::VariantPtr &v)
{
	assert(0);
}
