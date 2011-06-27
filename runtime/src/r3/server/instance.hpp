#ifndef _R3_SERVER_INSTANCE_HPP_
#define _R3_SERVER_INSTANCE_HPP_

#include "net/service.hpp"
#include "r3/data.hpp"
#include "r3/logic/server/connection.hpp"
#include "r3/server/sessionManager.hpp"
#include "r3/server/threadLocalStorage.hpp"
#include "r3/rightFillerServer.hpp"

namespace r3
{


	//////////////////////////////////////////////////////////////////////////
	namespace server
	{
		class Instance
			: public net::IServiceHandler
		{
			std::string _connInfo;
			r3::Data _data;

			SessionManager _sessionManager;

			//���������� ������������ ���� � ����, ��������, ��������
			//DataManager _dataManager;

			//������� ��������� ������� �����, �� ���������� ��� �������
			r3::data::V1_ptr _localSchema;

			//���� ��������� �������� �������
			//����������� � Session, ����������� ��� ��... ��� ��� ��� Session � ����
			//������������ �������� ���������
			boost::thread_specific_ptr<ThreadLocalStorage> _tls;



			boost::mutex _mtx;
			typedef boost::shared_ptr<r3::logic::server::Connection> Connection_ptr;
			std::set<Connection_ptr> _connections;
		public:
			Instance();
			~Instance();

			//������������� ����, �������� ��������� ������, ������� �� ��� ������� ����, ��������� �����
			bool setDBInfo(const char *connInfo);

			void reset();

			SessionManager *sessionManager();
			r3::data::V1_ptr localSchema();
			ThreadLocalStorage *tls();
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
