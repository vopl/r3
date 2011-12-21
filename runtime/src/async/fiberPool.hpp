#ifndef _ASYNC_FIBERPOOL_HPP_
#define _ASYNC_FIBERPOOL_HPP_

#include "fiberImpl.hpp"
#include <set>

namespace async
{
	class FiberPool
	{
	public:
		//������ ��� ������
		std::set<FiberImplPtr>			_fibersIdle;

		//������� ������ � ������� � ������� � ����������
		std::set<FiberImplPtr>			_fibersReady;

		//������� ����� �� ������� �� ������� �������
		std::deque<function<void()> >	_tasks;

		mutex							_mtx;
	public:
	};
	typedef shared_ptr<FiberPool> FiberPoolPtr;
}
#endif
