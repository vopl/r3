#ifndef _CLIENT_QT_MAINWINDOW_HPP_
#define _CLIENT_QT_MAINWINDOW_HPP_

#include <QtGui/QMainWindow>
#include <QtDeclarative/QDeclarativeView>
#include "ui_mainWindow.h"
#include "pluma/pluma.hpp"
#include "client/iclient.hpp"
#include "networkDialog.hpp"
#include "networkAccessManagerFactory.hpp"

namespace client
{
	namespace qt
	{
		class MainWindow
			: public QMainWindow
		{
			Q_OBJECT
		private:
			pluma::Pluma		_plugins;
			client::IClientPtr	_client;
			async::ServicePtr	_asrv;
			client::ISessionPtr	_session;
			NetworkDialog		*_nd;
			QLabel				*_labelConnected;

			int					_numChannels;

			NetworkAccessManagerFactory _networkAccessManagerFactory;
			QDeclarativeView	*_view;

		private slots:
			void onChannelChange(int numChannels, boost::system::error_code ec);
			void onSessionStart(boost::system::error_code ec, ISessionPtr session);
			void onSessionStop(ISessionPtr session);
			void onAddrChanged(QString host, QString service);

		signals:
			void onSessionStart_proxySig(boost::system::error_code ec, ISessionPtr session);
		private:
			virtual void closeEvent(QCloseEvent *);

		private:
			void startSession_f(QString host, QString service);

		public:
			MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
			~MainWindow();

		public slots:
			void showNetworkDialog();
		private:
			Ui::MainWindow ui;

		};
	}
}
#endif
