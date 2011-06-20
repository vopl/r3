#include "StdAfx.h"
#include "loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton_go, SIGNAL(clicked()), 
		this, SLOT(onGo()));
	connect(ui.pushButton_cancel, SIGNAL(clicked()), 
		this, SLOT(onCancel()));

	//onCancel();

}

LoginWidget::~LoginWidget()
{

}

void LoginWidget::onError(QString err)
{
	ui.label_error->show();
	ui.label_error->setText(err);
}

void LoginWidget::onGo()
{
	doGo(ui.lineEdit_login->text(), ui.lineEdit_password->text());
}
void LoginWidget::onCancel()
{
	ui.lineEdit_login->clear();
	ui.lineEdit_password->clear();
	ui.label_error->clear();
	ui.label_error->hide();
}

