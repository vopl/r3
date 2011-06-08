#ifndef _NET_SERVICEIMPL_HPP_
#define _NET_SERVICEIMPL_HPP_

#include "net/service.hpp"

namespace net
{
	class ServiceImpl
	{
		//������
		//������ ��������� ������
		//�����������
	public:
		ServiceImpl(IServiceHandler *);

		void balance(size_t numThreads);

		void listen(const char *host, short port);
		void connect(const char *host, short port);
	};
}
#endif
