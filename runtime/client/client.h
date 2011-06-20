#ifndef CLIENT_H
#define CLIENT_H

#include <QtGui/QMainWindow>
#include "ui_client.h"
#include "connection.hpp"

class Client : public QMainWindow
{
	Q_OBJECT

private:

	r3::logic::client::Connection *_connection;

public:
	Client(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Client();

private:
	virtual void resizeEvent(QResizeEvent *);

private:
	Ui::ClientClass ui;
};

#endif // CLIENT_H
