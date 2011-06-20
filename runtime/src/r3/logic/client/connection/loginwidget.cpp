#include "StdAfx.h"
#include "loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

}

LoginWidget::~LoginWidget()
{

}


void LoginWidget::resizeEvent(QResizeEvent *evt)
{
// 	ui.horizontalLayoutWidget_2->setGeometry(QRect(QPoint(0,0), evt->size()));
// 	ui.horizontalLayoutWidget_2->setMaximumSize(evt->size());
// 	ui.horizontalLayout_root->setGeometry(QRect(QPoint(0,0), evt->size()));
}
