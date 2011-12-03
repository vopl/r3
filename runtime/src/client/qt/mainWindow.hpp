#ifndef _CLIENT_QT_MAINWINDOW_HPP_
#define _CLIENT_QT_MAINWINDOW_HPP_

#include <QtGui/QMainWindow>
#include <QtDeclarative/QDeclarativeView>
#include "ui_mainWindow.h"
#include "pluma/pluma.hpp"
#include "client/iclient.hpp"
#include "networkDialog.hpp"

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
			NetworkDialog		*_nd;
			QLabel				*_labelConnected;

			int					_numChannels;

			QDeclarativeView	*_view;

		private:
			void onChannelChange_(size_t numChannels, boost::system::error_code ec);
			void onSessionStart_(ISessionPtr session);
			void onSessionStop_(ISessionPtr session);

		signals:
			void onChannelChange_sig(int numChannels, boost::system::error_code ec);
			void onSessionStart_sig(ISessionPtr session);
			void onSessionStop_sig(ISessionPtr session);
		private slots:
			void onChannelChange_slot(int numChannels, boost::system::error_code ec);
			void onSessionStart_slot(ISessionPtr session);
			void onSessionStop_slot(ISessionPtr session);
			void onAddrChanged(QString host, QString service);

		signals:
			void onChannelChange(int numChannels);
		public:
			int getNumChannels();

		private:
			virtual void closeEvent(QCloseEvent *);

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
