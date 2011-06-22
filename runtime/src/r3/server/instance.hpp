#ifndef _R3_SERVER_INSTANCE_HPP_
#define _R3_SERVER_INSTANCE_HPP_

#include "net/service.hpp"
//#include "pgc/connection.hpp"
#include "r3/data.hpp"
#include "r3/logic/server/connection.hpp"
#include "r3/server/sessionManager.hpp"

namespace r3
{
	namespace server
	{
		class Instance
			: public net::IServiceHandler
		{
			std::string _connInfo;
			r3::Data _data;

			SessionManager _sessionManager;

			//управл€лка экземпл€рами схем в базе, создание, удаление
			//DataManager _dataManager;

			//текуща€ локальна€ рабоча€ схема, ее используют все клиенты
			//SchemaInstance _localSchema;

			//глоб состо€ни€ текущего запроса
			//формируетс€ в Session, разрушаетс€ там же... или это сам Session и есть
			//используетс€ логиками контекста
			//thread_ptr<SessionData> ...



			boost::mutex _mtx;
			typedef boost::shared_ptr<r3::logic::server::Connection> Connection_ptr;
			std::set<Connection_ptr> _connections;
		public:
			Instance();
			~Instance();

			//инициализаци€ базы, создание системных таблиц, вычитка из них перечн€ схем, локальной схемы
			bool setDBInfo(const char *connInfo);

			void reset();

			SessionManager *sessionManager();
			//SchemaInstance *localSchema();
			//SessionData_ptr currentSession();
			//RequestData_ptr currentRequest();

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
