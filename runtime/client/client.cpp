#include "stdafx.h"
#include "client.h"
#include "r3/client/instance.hpp"

Client::Client(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
	, _sended(0)
	, _received(0)

{
	qRegisterMetaType<boost::shared_array<char> >("boost::shared_array<char>");
	qRegisterMetaType<utils::VariantPtr>("utils::VariantPtr");
	qRegisterMetaType<size_t>("size_t");

	ui.setupUi(this);

	ui.actionFullScreen->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_F11));
	connect(ui.actionFullScreen, SIGNAL(changed()),
		this, SLOT(onFullScreen()));

	connect(ui.doPing, SIGNAL(clicked()),
		this, SLOT(onBtn()));


	connect(
		&_inst, SIGNAL(connected(size_t)),
		this, SLOT(connected(size_t)),
		Qt::QueuedConnection);

	connect(
		&_inst, SIGNAL(sendComplete(boost::shared_array<char>, size_t)),
		this, SLOT(sendComplete(boost::shared_array<char>, size_t)),
		Qt::QueuedConnection);

	connect(
		&_inst, SIGNAL(sendComplete(utils::VariantPtr)),
		this, SLOT(sendComplete(utils::VariantPtr)),
		Qt::QueuedConnection);

	connect(
		&_inst, SIGNAL(receive(boost::shared_array<char>, size_t)),
		this, SLOT(receive(boost::shared_array<char>, size_t)),
		Qt::QueuedConnection);

	connect(
		&_inst, SIGNAL(receive(utils::VariantPtr)),
		this, SLOT(receive(utils::VariantPtr)),
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
		&_inst, SIGNAL(sendComplete(boost::shared_array<char>, size_t)),
		this, SLOT(sendComplete(boost::shared_array<char>, size_t)));

	disconnect(
		&_inst, SIGNAL(sendComplete(const utils::VariantPtr &)),
		this, SLOT(sendComplete(const utils::VariantPtr &)));

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




void Client::onBtn()
{
	_inst.send(boost::shared_array<char>(new char[10]), 10);
}


void Client::connected(size_t channels)
{
	QString s;
	s.sprintf("%d", (int)channels);
	ui.connected_->setText(s);
}


void Client::sendComplete(boost::shared_array<char> data, size_t size)
{
	_sended++;
	QString s;
	s.sprintf("%d", _sended);
	ui.send_->setText(s);
}

void Client::sendComplete(utils::VariantPtr v)
{
	_sended++;
	QString s;
	s.sprintf("%d", _sended);
	ui.send_->setText(s);
}

void Client::receive(boost::shared_array<char> data, size_t size)
{
	_received++;
	QString s;
	s.sprintf("%d", _received);
	ui.receive_->setText(s);
}

void Client::receive(utils::VariantPtr v)
{
	_received++;
	QString s;
	s.sprintf("%d", _received);
	ui.receive_->setText(s);
}
