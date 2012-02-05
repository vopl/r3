#ifndef _ASYNC_MUTEXIMPL_HPP_
#define _ASYNC_MUTEXIMPL_HPP_

#include "async/mutex.hpp"
#include <vector>
#include "fiberImpl.hpp"

namespace async
{
	class MutexImpl
	{
		mutex						_mtx;
		std::vector<FiberImplPtr>	_owners;
	public:
		MutexImpl();
		~MutexImpl();

		bool tryLock();
		void lock();
		bool isLocked();
		void unlock();
	};
	typedef shared_ptr<MutexImpl> MutexImplPtr;
}
#endif
