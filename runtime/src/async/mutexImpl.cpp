#include "pch.h"
#include "mutexImpl.hpp"
#include "workerImpl.hpp"
#include "async/exception.hpp"

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	MutexImpl::MutexImpl()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	MutexImpl::~MutexImpl()
	{
		boost::mutex::scoped_lock scopeLock(_mtx);
		assert(_owners.empty());

		BOOST_FOREACH(FiberImplPtr &fiber, _owners)
		{
			WorkerImpl::current()->fiberReady(_owners.front());
		}
	}

	//////////////////////////////////////////////////////////////////////////
	bool MutexImpl::tryLock()
	{
		boost::mutex::scoped_lock scopeLock(_mtx);

		if(_owners.empty())
		{
			FiberImplPtr current = FiberImpl::current()->shared_from_this();
			_owners.push_back(current);
			return true;
		}

		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	void MutexImpl::lock()
	{
		{
			boost::mutex::scoped_lock scopeLock(_mtx);

			FiberImplPtr current = FiberImpl::current()->shared_from_this();
			_owners.push_back(current);
			if(_owners.size() == 1)
			{
				return;
			}
		}
		WorkerImpl::current()->fiberYield();
	}

	//////////////////////////////////////////////////////////////////////////
	bool MutexImpl::isLocked()
	{
		boost::mutex::scoped_lock scopeLock(_mtx);
		return !_owners.empty();
	}

	//////////////////////////////////////////////////////////////////////////
	void MutexImpl::unlock()
	{
		boost::mutex::scoped_lock scopeLock(_mtx);
		if(_owners.empty())
		{
			ELOG("unlock mutex which is not locked");
			throw exception("unlock mutex which is not locked");
			return;
		}

		//не важно, что текущий фибер не €вл€етс€ владельцем
// 		if(_owners.front().get() != FiberImpl::current())
// 		{
// 			ELOG("unlockStrict mutex which from alien fiber");
// 			throw exception("unlockStrict mutex which from alien fiber");
// 			return;
// 		}


		_owners.erase(_owners.begin());

		if(!_owners.empty())
		{
#ifdef _DEBUG
			bool fired = WorkerImpl::current()->fiberReadyIfWait(_owners.front());
			if(!fired)
			{
				assert("unlockStrict mutex for non-wait fiber");
			}
#else
			WorkerImpl::current()->fiberReady(_owners.front());
#endif
		}
	}
}
