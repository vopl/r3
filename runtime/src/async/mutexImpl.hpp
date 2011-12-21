#ifndef _ASYNC_MUTEXIMPL_HPP_
#define _ASYNC_MUTEXIMPL_HPP_

#include "async/mutex.hpp"
#include <deque>
#include "fiberImpl.hpp"

namespace async
{
	class MutexImpl
	{
		mutex						_mtx;
		std::deque<FiberImplPtr>	_owners;
	public:
		MutexImpl();
		~MutexImpl();

		bool tryLock();
		void lock();
		bool isLocked();
		void unlock();
		void unlockAny();
	};
	typedef shared_ptr<MutexImpl> MutexImplPtr;
}
#endif
