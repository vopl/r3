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
				s.sprintf(" (%d)", ec.value());
				s = s.fromLocal8Bit(ec.message().c_str()) + s;

				_nd->logLowError(s);
			}

			_nd->setNumChannels(numChannels);
			_labelConnected->setNum(numChannels);
			_numChannels = numChannels;
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::onSessionStart(boost::system::error_code ec, ISessionPtr session)
		{
			if(ec)
			{
				QString s;
				s.sprintf(" (%d)", ec.value());
				s = s.fromLocal8Bit(ec.message().c_str()) + s;

				_nd->logLowError(s);
				return;
			}
			
			if(session)
			{
				if(_session)
				{
					_session->close();
					_session.reset();
				}

				_session = session;

				assert(!_view);
				_view = new QDeclarativeView(this);
				setCentralWidget(_view);
				_view->engine()->addImportPath(QString("../QmlModules/"));

				_view->engine()->setNetworkAccessManagerFactory(&_networkAccessManagerFactory);
				_view->engine()->setBaseUrl(QUrl("client://statics/"));

				_view->setSource(QUrl("/clientqt/index.qml"));
				_view->show();
			}
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

			if(_session)
			{
				_session->close();
				_session.reset();
			}

			if(_asrv)
			{
				_asrv->spawn(boost::bind(&MainWindow::startSession_f, this, host, service));
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::closeEvent(QCloseEvent *evt)
		{
			bool res = _client->stop();
			(void)res;

			onSessionStop(ISessionPtr());

			delete _nd;
			_nd = NULL;
			QMainWindow::closeEvent(evt);
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::startSession_f(QString host, QString service)
		{
			async::Result2<boost::system::error_code, ISessionPtr> res =
				_client->createSession(host.toUtf8(), service.toUtf8());

			res.wait();
			emit onSessionStart_proxySig(res.data1(), res.data2());
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
			connect(
				this, SIGNAL(onSessionStart_proxySig(boost::system::error_code, ISessionPtr)), 
				this, SLOT(onSessionStart(boost::system::error_code, ISessionPtr)));


			//////////////////////////////////////////////////////////////////////////
			_plugins.loadFromFolder("../plug");

			_client = _plugins.create<client::IClientProvider>();
			assert(_client);

			if(!_client->start(&_plugins))
			{
				//QMessageBox()
			}
			_asrv = _client->getAsync();

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