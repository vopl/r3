#include "pch.hpp"
#include "async/mutex.hpp"
#include "mutexImpl.hpp"

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	Mutex::Mutex()
		: _impl(new MutexImpl)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	bool Mutex::tryLock()
	{
		return _impl->tryLock();
	}

	//////////////////////////////////////////////////////////////////////////
	void Mutex::lock()
	{
		return _impl->lock();
	}

	//////////////////////////////////////////////////////////////////////////
	bool Mutex::isLocked()
	{
		return _impl->isLocked();
	}

	//////////////////////////////////////////////////////////////////////////
	void Mutex::unlock()
	{
		return _impl->unlock();
	}
}
