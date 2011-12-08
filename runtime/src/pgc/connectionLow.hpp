#ifndef _PGC_CONNECTIONLOW_HPP_
#define _PGC_CONNECTIONLOW_HPP_

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <libpq-fe.h>
#include "pgc/iresult.hpp"
#include "pgc/iconnection.hpp"

namespace pgc
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	/*
		���������� ��� PGconn *

		1. ��������� ��������� ����� ������ (��������� ��������� ��������, integerDatetime, ...)
		2. �������������� ������� ����������� (�������, �������, ...), ������������ ����� ��� ���������������
		3. �� ���� ������������� ������ ���������� ����������� �������� ����������� ������ � ������ � ��������
	*/

	//////////////////////////////////////////////////////////////////////////
	class ConnectionLow
		: public enable_shared_from_this<ConnectionLow>
	{
	private:
		//��� ��������� ������������� ������ ��� asio
		struct PGSockProtocol
		{
			int _family; int _type; int _protocol;
			PGSockProtocol(int f, int t, int p) : _family(f), _type(t), _protocol(p) {}

			int family() const		{return _family;}
			int type() const		{return _type;}
			int protocol() const	{return _protocol;}

			struct endpoint
			{
				PGSockProtocol protocol(){ return PGSockProtocol(0,0,0);}
			};
		};

	private:
		//////////////////////////////////////////////////////////////////////////
		PGconn									*_pgcon;
		asio::basic_raw_socket<PGSockProtocol>	_sock;
		asio::io_service::strand				_strand;
		bool									_integerDatetimes;

	private:
		//��������� ��� ������������� ������������� ������ � asio
		static int sockFamily(int sock);
		static int sockType(int sock);

	public:
		void waitSend(function<void(const system::error_code &)> ready);
		void waitRecv(function<void(const system::error_code &)> ready);

	public:
		ConnectionLow(PGconn *pgcon, asio::io_service &io_service);
		virtual ~ConnectionLow();

		PGconn *pgcon();

		void onOpen();
		EConnectionStatus status();
		void close();

		bool integerDatetimes();

		void dispatch(function<void()> action);
	};
	typedef shared_ptr<ConnectionLow> ConnectionLowPtr;
}
#endif
