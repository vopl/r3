#include "pch.h"
#include "mainWindow.hpp"
#include <boost/bind.hpp>
#include <QtDeclarative/qdeclarative.h>
#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeEngine>

namespace client
{
	namespace qt
	{
		//////////////////////////////////////////////////////////////////////////
		void MainWindow::onChannelChange(int numChannels, boost::system::error_code ec)
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
			_numChannels = numChannels;
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::onSessionStart(ISessionPtr session)
		{
			assert(0);
			//Agent::_mainWindow = this;

			assert(!_view);
			_view = new QDeclarativeView(this);
			setCentralWidget(_view);
			_view->engine()->addImportPath(QString("../QmlModules/"));

			_view->engine()->setNetworkAccessManagerFactory(&_networkAccessManagerFactory);
			_view->engine()->setBaseUrl(QUrl("client://statics/"));

			_view->setSource(QUrl("/clientqt/index.qml"));
			_view->show();
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::onSessionStop(ISessionPtr session)
		{
			if(_view)
			{
				setCentralWidget(NULL);
				delete _view;
				_view = NULL;
			}

			assert(0);
// 			if(Agent::_mainWindow)
// 			{
// 				Agent::_mainWindow = NULL;
// 			}
		}


		//////////////////////////////////////////////////////////////////////////
		void MainWindow::onAddrChanged(QString host, QString service)
		{
			_nd->setNumChannels(0);
			_labelConnected->setNum(0);
			assert(0);
			//_client->connect(host.toUtf8(), service.toUtf8());
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::closeEvent(QCloseEvent *evt)
		{
			_client->stop();

			onSessionStop(ISessionPtr());

			delete _nd;
			_nd = NULL;
			QMainWindow::closeEvent(evt);
		}


		//////////////////////////////////////////////////////////////////////////
		MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
			: QMainWindow(parent, flags)
			, _nd(false)
			, _view(NULL)
			, _numChannels(0)
		{

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

			assert(0);
// 			_client->start(
// 				&_plugins, 
// 				boost::bind(&MainWindow::onSessionStart_, this, _1),
// 				boost::bind(&MainWindow::onSessionStop_, this, _1),
// 				boost::bind(&MainWindow::onChannelChange_, this, _1, _2));

			onAddrChanged(_nd->getHost(), _nd->getService());
		}

		MainWindow::~MainWindow()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::showNetworkDialog()
		{
			_nd->show();
		}

	}
}