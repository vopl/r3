#ifndef AUTHWIDGET_H
#define AUTHWIDGET_H

#include <QWidget>
#include "ui_authwidget.h"

class AuthWidget : public QWidget
{
	Q_OBJECT

public:
	AuthWidget(QWidget *parent = 0);
	~AuthWidget();
public Q_SLOTS:
	void onError(QString err);
	void onGo();
	void onCancel();

Q_SIGNALS:
	void doGo(QString login, QString password);

private:
	Ui::AuthWidget ui;
};

#endif // LOGINWIDGET_H
