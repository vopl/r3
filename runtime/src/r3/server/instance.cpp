#include "stdafx.h"
#include "instance.hpp"

namespace r3
{
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
		void Instance::reset()
		{
			boost::mutex::scoped_lock l(_mtx);
			BOOST_FOREACH(Connection_ptr c, _connections)
			{
				c->close();
			}
			_connections.clear();
		}

		//////////////////////////////////////////////////////////////////////////
		SessionManager *Instance::sessionManager()
		{
			return &_sessionManager;
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
			_data.startInThread("dbname=test user=postgres password=postgres port=5432");

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
		}

		//////////////////////////////////////////////////////////////////////////
		Instance *instance()
		{
			return g_instance;
		}

	}
}
