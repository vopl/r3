#include "stdafx.h"
#include "instance.hpp"

namespace r3
{
	boost::thread_specific_ptr<RightFiller<true> > RightFiller<true>::_instance;

	namespace server
	{
		//////////////////////////////////////////////////////////////////////////
		Instance *g_instance = NULL;

		//////////////////////////////////////////////////////////////////////////
		Instance::Instance()
		{
			assert(!g_instance);
			g_instance = this;
		}

		//////////////////////////////////////////////////////////////////////////
		Instance::~Instance()
		{
			g_instance = NULL;
		}

		//////////////////////////////////////////////////////////////////////////
		bool Instance::setDBInfo(const char *connInfo)
		{
			//подключится к базе
			_data.startInThread(connInfo);

			switch(_data.con().status())
			{
			case pgc::ecs_ok:
				break;
			default:
				std::cerr<<"unable connect to database"<<std::endl;
				return false;
			}

			bool res = true;
			//сформировать локальную схему или взять готовую
			_data.con().once("BEGIN").exec();

			try
			{
				{
					r3::data::Test_ptr s = _data.getTest("local");
					if(!s->dbExists())
					{
						s->dbCreate();
					}
				}
				{
					r3::data::V1_ptr s = _data.getV1("local");
					if(!s->dbExists())
					{
						s->dbCreate();
					}
				}
				_data.con().once("COMMIT").exec();
			}
			catch(...)
			{
				std::cerr<<"exception in local schema creation"<<std::endl;
				_data.con().once("ROLLBACK").exec();
				res = true;
			}

			//еслм что не так выкинуть false, сервер должен остановиться

			_connInfo = connInfo;
			_data.stopInThread();

			_localSchema = _data.getV1("local");
			return res;
		}


		//////////////////////////////////////////////////////////////////////////
		void Instance::reset()
		{
			boost::mutex::scoped_lock l(_mtx);
			BOOST_FOREACH(Connection_ptr c, _connections)
			{
				c->close();
			}
			_connections.clear();
			_sessionManager.reset();
		}

		//////////////////////////////////////////////////////////////////////////
		SessionManager *Instance::sessionManager()
		{
			return &_sessionManager;
		}

		//////////////////////////////////////////////////////////////////////////
		r3::data::V1_ptr Instance::localSchema()
		{
			return _localSchema;
		}

		//////////////////////////////////////////////////////////////////////////
		ThreadLocalStorage *Instance::tls()
		{
			return _tls.get();
		}




		//////////////////////////////////////////////////////////////////////////
		void Instance::onConnectionClose(Connection_ptr con)
		{
			boost::mutex::scoped_lock l(_mtx);
			_connections.erase(con);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onConnectionError(Connection_ptr con)
		{
			boost::mutex::scoped_lock l(_mtx);
			_connections.erase(con);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onStartInThread(net::Service *)
		{
			assert(!_tls.get());
			_tls.reset(new ThreadLocalStorage);

			_data.startInThread(_connInfo.c_str());
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onError(net::Service *)
		{
			//assert(0);
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onAccept(net::Channel_ptr channel)
		{
			boost::mutex::scoped_lock l(_mtx);
			_connections.insert(Connection_ptr(new r3::logic::server::Connection(channel)));
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onConnect(net::Channel_ptr channel)
		{
			assert(!"never here");
		}

		//////////////////////////////////////////////////////////////////////////
		void Instance::onStopInThread()
		{
			_data.stopInThread();
			assert(_tls.get());
			delete _tls.release();
		}

		//////////////////////////////////////////////////////////////////////////
		Instance *instance()
		{
			return g_instance;
		}

	}
}
