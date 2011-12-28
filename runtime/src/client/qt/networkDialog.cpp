#include "pch.h"
#include "networkDialog.hpp"
#include <QtCore/QDateTime.h>


namespace client
{
	namespace qt
	{
		//////////////////////////////////////////////////////////////////////////
		NetworkDialog::NetworkDialog(QWidget *parent, Qt::WFlags flags)
			: QDialog(parent, flags)
			, _host("localhost")
			, _service("29431")
			, _numChannels(0)
		{
			ui.setupUi(this);
			ui._logErrors->setLineWrapMode(QPlainTextEdit::NoWrap);
			ui._logErrors->setMaximumBlockCount(500);

			ui._host->setText(_host);
			ui._service->setText(_service);


			connect(
				ui.pushButton_ok, SIGNAL(clicked()),
				this, SLOT(onOk()));
			connect(
				ui.pushButton_apply, SIGNAL(clicked()),
				this, SLOT(onApply()));
			connect(
				ui.pushButton_cancel, SIGNAL(clicked()),
				this, SLOT(onCancel()));
		}

		//////////////////////////////////////////////////////////////////////////
		NetworkDialog::~NetworkDialog()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		QString	NetworkDialog::getHost()
		{
			return _host;
		}

		//////////////////////////////////////////////////////////////////////////
		QString	NetworkDialog::getService()
		{
			return _service;
		}


		//////////////////////////////////////////////////////////////////////////
		void NetworkDialog::logLowError(const QString &s)
		{
			if(_lastLowError != s)
			{
				_lastLowError = s;
				ui._logErrors->appendPlainText(QDateTime::currentDateTime().toString() + ": " + s);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void NetworkDialog::setNumChannels(quint32 numChannels)
		{
			if(_numChannels < numChannels)
			{
				logLowError(QString("connection established"));
			}
			_numChannels = numChannels;

			ui._numChannels->setNum((int)numChannels);
		}

		//////////////////////////////////////////////////////////////////////////
		void NetworkDialog::onOk()
		{
			onApply();
			hide();
		}
		
		//////////////////////////////////////////////////////////////////////////
		void NetworkDialog::onApply()
		{
			QString host = ui._host->text();
			QString service = ui._service->text();

			if(host != _host || service != _service)
			{
				_host = host;
				_service = service;
				emit addrChanged(_host, _service);
			}
		}
		
		//////////////////////////////////////////////////////////////////////////
		void NetworkDialog::onCancel()
		{
			hide();
		}

		//////////////////////////////////////////////////////////////////////////
		void NetworkDialog::showEvent(QShowEvent * event)
		{
			ui._host->setText(_host);
			ui._service->setText(_service);
		}

	}
}