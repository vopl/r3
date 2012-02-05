#ifndef _CLIENT_QT_NETWORKDIALOG_HPP_
#define _CLIENT_QT_NETWORKDIALOG_HPP_

#include <QtGui/QDialog>
#include "ui_networkDialog.h"

namespace client
{
	namespace qt
	{
		class NetworkDialog
			: public QDialog
		{
			Q_OBJECT

		private:
			QString	_host;
			QString	_service;
			QString	_lastLowError;
			quint32	_numChannels;


		public:
			NetworkDialog(QWidget *parent = 0, Qt::WFlags flags = 0);
			~NetworkDialog();
			QString	getHost();
			QString	getService();

		public slots:
			void logLowError(const QString &s);
			void setNumChannels(quint32 numChannels);

		private slots:
			void onOk();
			void onApply();
			void onCancel();

		signals:
			void addrChanged(QString host, QString service);

		private:
			void showEvent(QShowEvent * event);
		private:
			Ui::NetworkDialog ui;
		};
	}
}
#endif
