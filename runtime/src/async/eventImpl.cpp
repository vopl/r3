#include "pch.h"
#include "eventImpl.hpp"
#include "workerImpl.hpp"

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	EventImpl::EventImpl(bool autoReset)
		: _isSet(false)
		, _autoReset(autoReset)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	EventImpl::~EventImpl()
	{
		mutex::scoped_lock sl(_mtx);
		assert(_waiters.empty());
		BOOST_FOREACH(FiberImplPtr &fiber, _waiters)
		{
			WorkerImpl::current()->fiberReady(_waiters.front());
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void EventImpl::set()
	{
		mutex::scoped_lock sl(_mtx);
		if(!_isSet)
		{
			BOOST_FOREACH(FiberImplPtr &f, _waiters)
			{
				assert(f.get() != FiberImpl::current());
				WorkerImpl::current()->fiberReady(f);
			}
			_waiters.clear();

			if(!_autoReset)
			{
				_isSet = true;
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void EventImpl::reset()
	{
		mutex::scoped_lock sl(_mtx);
		if(_isSet)
		{
			assert(_waiters.empty());
			_waiters.clear();
			_isSet = false;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	bool EventImpl::isSet()
	{
		return _isSet;
	}

	//////////////////////////////////////////////////////////////////////////
	void EventImpl::wait()
	{
		{
			mutex::scoped_lock sl(_mtx);

			if(_isSet)
			{
				return;
			}

			FiberImpl *f = FiberImpl::current();
			assert(f);
			_waiters.push_back(f->shared_from_this());
		}

		WorkerImpl::current()->fiberYield();
	}

}
