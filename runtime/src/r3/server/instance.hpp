#ifndef _R3_SERVER_INSTANCE_HPP_
#define _R3_SERVER_INSTANCE_HPP_

#include "net/service.hpp"
//#include "pgc/connection.hpp"
#include "r3/data.hpp"
#include "r3/logic/server/connection.hpp"

namespace r3
{
	namespace server
	{
		class Instance
			: public net::IServiceHandler
		{
			boost::mutex _mtx;
			r3::Data _data;

			typedef boost::shared_ptr<r3::logic::server::Connection> Connection_ptr;
			std::set<Connection_ptr> _connections;
		public:
			Instance();
			~Instance();

			void reset();

		private:
			friend class r3::logic::server::Connection;
			void onConnectionClose(Connection_ptr con);
			void onConnectionError(Connection_ptr con);


		private:
			virtual void onStartInThread(net::Service *);
			virtual void onError(net::Service *);
			virtual void onAccept(net::Channel_ptr channel);
			virtual void onConnect(net::Channel_ptr channel);
			virtual void onStopInThread();
		};

		Instance *instance();
	}
}
#endif