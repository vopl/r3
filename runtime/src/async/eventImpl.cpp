#include "pch.h"
#include "eventImpl.hpp"

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
#ifdef _DEBUG
		boost::mutex::scoped_lock sl(_mtx);
		assert(_waiters.empty());
#endif
	}

	//////////////////////////////////////////////////////////////////////////
	void EventImpl::set()
	{
		if(!_isSet)
		{
			boost::mutex::scoped_lock sl(_mtx);

			BOOST_FOREACH(FiberImplPtr &f, _waiters)
			{
				assert(f.get() != FiberImpl::current());
				if(f.get() != FiberImpl::current())
				{
					f->ready();
				}
			}
			_waiters.clear();
			_isSet = true;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void EventImpl::reset()
	{
		if(_isSet)
		{
			boost::mutex::scoped_lock sl(_mtx);
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
		if(_isSet)
		{
			return;
		}
		{
			boost::mutex::scoped_lock sl(_mtx);

			FiberImpl *f = FiberImpl::current();
			assert(f);
			_waiters.push_back(f->shared_from_this());
		}

		FiberImpl::yield();
	}

}
