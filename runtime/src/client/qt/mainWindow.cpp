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
		void MainWindow::onSessionState(boost::system::error_code ec, size_t numChannels)
		{
			if(_nd)
			{
				if(ec)
				{
					QString s;
					s.sprintf(" (%d)", ec.value());
					s = s.fromLocal8Bit(ec.message().c_str()) + s;

					_nd->logLowError(s);
				}
				_nd->setNumChannels((quint32)numChannels);
			}

			_labelConnected->setNum((int)numChannels);
			_numChannels = (quint32)numChannels;
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::onSessionStart(boost::system::error_code ec, ISessionPtr session)
		{
			if(ec)
			{
				assert(!session);

				if(_nd)
				{
					QString s;
					s.sprintf(" (%d)", ec.value());
					s = s.fromLocal8Bit(ec.message().c_str()) + s;

					_nd->logLowError(s);
				}
				return;
			}
			
			if(session)
			{
				closeSession();

				_session = session;

				_session->watchState(bind(&MainWindow::onSessionState_proxyCallback, this, _1, _2));
				_session->balance(2);

				Agent::_staticSession = _session;

				assert(!_networkAccessManagerFactory);
				_networkAccessManagerFactory = new NetworkAccessManagerFactory(session, _asrv);

				assert(!_view);
				_view = new QDeclarativeView(this);
				setCentralWidget(_view);
				_view->engine()->addImportPath(QString("../QmlModules/"));

				_view->engine()->setNetworkAccessManagerFactory(_networkAccessManagerFactory);
				_view->engine()->setBaseUrl(QUrl("client://statics/"));

				_view->setSource(QUrl("/clientqt/index.qml"));
				_view->show();
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::onAddrChanged(QString host, QString service)
		{
			_nd->setNumChannels(0);
			_labelConnected->setNum(0);

			closeSession();

			if(_asrv)
			{
				_asrv->spawn(boost::bind(&MainWindow::startSession_f, this, host, service));
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::onSessionState_proxyCallback(const boost::system::error_code &ec, size_t numChannels)
		{
			emit onSessionState_proxySig(ec, numChannels);
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::closeEvent(QCloseEvent *evt)
		{
			closeSession();

			delete _nd;
			_nd = NULL;

			_asrv.reset();

			bool res = _client->stop();
			(void)res;

			_client.reset();

			QMainWindow::closeEvent(evt);
		}

		//////////////////////////////////////////////////////////////////////////
		void MainWindow::closeSession()
		{
			if(_view)
			{
				setCentralWidget(NULL);
				delete _view;
				_view = NULL;
			}
			if(_networkAccessManagerFactory)
			{
				delete _networkAccessManagerFactory;
				_networkAccessManagerFactory = NULL;
			}

			if(_session)
			{
				_asrv->spawn(bind(&ISession::close, _session));
				_session.reset();
			}
			Agent::_staticSession.reset();
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
			, _networkAccessManagerFactory(NULL)
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

			connect(
				this, SIGNAL(onSessionState_proxySig(boost::system::error_code, size_t)), 
				this, SLOT(onSessionState(boost::system::error_code, size_t)));

			//////////////////////////////////////////////////////////////////////////
			_plugins.loadFromFolder("../plug");

			_client = _plugins.create<client::IClientProvider>();
			assert(_client);

			if(!_client->start(&_plugins))
			{
				//QMessageBox()
			}
			_asrv = _client->getAsync();
			bool b = _asrv->setAsGlobal(false);
			assert(b);

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