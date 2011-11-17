#ifndef CLIENT_H
#define CLIENT_H

#include <QtGui/QMainWindow>
#include "ui_client.h"
#include "utils/variant.hpp"
#include "r3/client/instance.hpp"

class Client : public QMainWindow
{
	Q_OBJECT

private:

	r3::client::Instance _inst;

	int _sended;
	int _received;

public:
	Client(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Client();

private:
	virtual void resizeEvent(QResizeEvent *);

private slots:
	void onFullScreen();

private slots:
	void onBtn();

private slots:
	void connected(size_t channels);
	void sendComplete(boost::shared_array<char> data, size_t size);
	void sendComplete(utils::VariantPtr v);
	void receive(boost::shared_array<char> data, size_t size);
	void receive(utils::VariantPtr v);

private:
	Ui::ClientClass ui;
};

#endif // CLIENT_H
