#ifndef CLIENT_H
#define CLIENT_H

#include <QtGui/QMainWindow>
#include "ui_client.h"
#include "connection.hpp"

class Client : public QMainWindow
{
	Q_OBJECT

private:

	r3::logic::Connection *_connection;

public:
	Client(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Client();

public slots:
	void show_c()
	{
		_connection->show();

	}
	void hide_c()
	{
		_connection->hide();
	}

private:
	Ui::ClientClass ui;
};

#endif // CLIENT_H
