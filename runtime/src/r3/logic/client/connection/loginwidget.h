#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include "ui_loginwidget.h"

class LoginWidget : public QWidget
{
	Q_OBJECT

public:
	LoginWidget(QWidget *parent = 0);
	~LoginWidget();

private:
	Ui::LoginWidget ui;

private:
	virtual void resizeEvent(QResizeEvent *);

};

#endif // LOGINWIDGET_H
