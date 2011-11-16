#ifndef CLIENT_H
#define CLIENT_H

#include <QtGui/QMainWindow>
#include "ui_client.h"

class Client : public QMainWindow
{
	Q_OBJECT

private:

public:
	Client(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Client();

private:
	virtual void resizeEvent(QResizeEvent *);

private slots:
	void onFullScreen();

private:
	Ui::ClientClass ui;
};

#endif // CLIENT_H
