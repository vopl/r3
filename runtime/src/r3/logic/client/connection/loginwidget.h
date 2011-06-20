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
public Q_SLOTS:
	void onError(QString err);
	void onOk();
	void onCancel();

Q_SIGNALS:
	void doOk(QString login, QString password);

private:
	Ui::LoginWidget ui;
};

#endif // LOGINWIDGET_H
