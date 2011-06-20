#include "StdAfx.h"
#include "loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton_go, SIGNAL(clicked()), 
		this, SLOT(onOk()));
	connect(ui.pushButton_cancel, SIGNAL(clicked()), 
		this, SLOT(onCancel()));

}

LoginWidget::~LoginWidget()
{

}

void LoginWidget::onError(QString err)
{
	ui.label_error->setText(err);
}

void LoginWidget::onOk()
{
	doOk(ui.lineEdit_login->text(), ui.lineEdit_password->text());
}
void LoginWidget::onCancel()
{
	ui.lineEdit_login->clear();
	ui.lineEdit_password->clear();
	ui.label_error->clear();
}

