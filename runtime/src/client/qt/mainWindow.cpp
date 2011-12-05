#include "pch.h"
#include "mainWindow.hpp"
#include <boost/bind.hpp>
#include <QtDeclarative/qdeclarative.h>
#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeEngine>
#include "agent.hpp"

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
		void MainWindow::onSessionStart_(ISessionPtr session)
		{
			emit onSessionStart_sig(session);
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::onSessionStop_(ISessionPtr session)
		{
			emit onSessionStop_sig(session);
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

			if(numChannels != _numChannels)
			{
				_numChannels = numChannels;
				emit onChannelChange(numChannels);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::onSessionStart_slot(ISessionPtr session)
		{
			Agent::_mainWindow = this;
			Agent::_lowAgentHub = _plugins.create<IAgentHubProvider>();
			assert(Agent::_lowAgentHub);
			Agent::_lowAgentHub->initialize(session);

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
		void MainWindow::onSessionStop_slot(ISessionPtr session)
		{
			if(_view)
			{
				setCentralWidget(NULL);
				delete _view;
				_view = NULL;
			}

			if(Agent::_lowAgentHub)
			{
				Agent::_lowAgentHub->deinitialize();
				Agent::_lowAgentHub.reset();
			}

			if(Agent::_mainWindow)
			{
				Agent::_mainWindow = NULL;
			}

		}


		//////////////////////////////////////////////////////////////////////////
		void MainWindow::onAddrChanged(QString host, QString service)
		{
			_nd->setNumChannels(0);
			_labelConnected->setNum(0);
			_client->connect(host.toUtf8(), service.toUtf8());
		}

		//////////////////////////////////////////////////////////////////////////
		int MainWindow::getNumChannels()
		{
			return _numChannels;
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::closeEvent(QCloseEvent *evt)
		{
			_client->stop();

			onSessionStop_slot(ISessionPtr());

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
			connect(
				this, SIGNAL(onChannelChange_sig(int, boost::system::error_code)), 
				this, SLOT(onChannelChange_slot(int, boost::system::error_code)), 
				Qt::QueuedConnection);
			connect(
				this, SIGNAL(onSessionStart_sig(ISessionPtr)), 
				this, SLOT(onSessionStart_slot(ISessionPtr)), 
				Qt::QueuedConnection);
			connect(
				this, SIGNAL(onSessionStop_sig(ISessionPtr)), 
				this, SLOT(onSessionStop_slot(ISessionPtr)), 
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
				boost::bind(&MainWindow::onSessionStart_, this, _1),
				boost::bind(&MainWindow::onSessionStop_, this, _1),
				boost::bind(&MainWindow::onChannelChange_, this, _1, _2));

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