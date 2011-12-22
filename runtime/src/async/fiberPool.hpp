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
		mutex							_mtxFibers;


		//������� ����� �� ������� �� ������� �������
		std::deque<function<void()> >	_tasks;
		mutex							_mtxTasks;

	public:
	};
	typedef shared_ptr<FiberPool> FiberPoolPtr;
}
#endif
