#include "pchqt.h"
#include "mainWindow.hpp"
#include <boost/bind.hpp>

namespace client
{
	namespace qt
	{
		//////////////////////////////////////////////////////////////////////////
		void MainWindow::onChannelChange_(size_t numChannels, boost::system::error_code ec)
		{
			emit onChannelChange_sig((int)numChannels, ec);
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::onChannelChange_slot(int numChannels, boost::system::error_code ec)
		{
			if(ec)
			{
				QString s;
				s.sprintf(" (0x%x)", ec.value());
				s = s.fromLocal8Bit(ec.message().c_str()) + s;

				_nd->logLowError(s);
			}
			_nd->setNumChannels(numChannels);
			_labelConnected->setNum(numChannels);
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::onAddrChanged(QString host, QString service)
		{
			_client->connect(host.toUtf8(), service.toUtf8());
		}


		//////////////////////////////////////////////////////////////////////////
		MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
			: QMainWindow(parent, flags)
			, _nd(false)
		{
			qRegisterMetaType<boost::system::error_code>("boost::system::error_code");

			connect(
				this, SIGNAL(onChannelChange_sig(int, boost::system::error_code)), 
				this, SLOT(onChannelChange_slot(int, boost::system::error_code)), 
				Qt::QueuedConnection);

			ui.setupUi(this);
			connect(
				ui.actionNetwork, SIGNAL(activated()), 
				this, SLOT(showNetworkDialog()));

			_nd = new NetworkDialog(this);
			connect(
				_nd, SIGNAL(addrChanged(QString, QString)), 
				this, SLOT(onAddrChanged(QString, QString)));

			_labelConnected = new QLabel(statusBar());
			_labelConnected->setNum(0);
			statusBar()->addPermanentWidget(_labelConnected);


			//////////////////////////////////////////////////////////////////////////
			_plugins.loadFromFolder("../plug");

			_client = _plugins.create<client::IClientProvider>();
			assert(_client);

			_client->start(
				&_plugins, 
				async::IServicePtr(), 
				boost::bind(&MainWindow::onChannelChange_, this, _1, _2));

			onAddrChanged(_nd->getHost(), _nd->getService());
		}

		MainWindow::~MainWindow()
		{
			delete _nd;
			_client->stop();
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::showNetworkDialog()
		{
			_nd->show();
		}

	}
}