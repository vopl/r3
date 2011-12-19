#include "pch.h"
#include "eventImpl.hpp"

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	EventImpl::EventImpl()
		: _ready(false)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	EventImpl::~EventImpl()
	{
#ifdef _DEBUG
		boost::mutex::scoped_lock sl(_mtx);
		assert(_ready);
		assert(_waiters.empty());
#endif
	}

	//////////////////////////////////////////////////////////////////////////
	void EventImpl::ready()
	{
		boost::mutex::scoped_lock sl(_mtx);

		if(!_ready)
		{
			BOOST_FOREACH(FiberImplPtr &f, _waiters)
			{
				assert(f != FiberImpl::current());
				f->ready();
			}
			_waiters.clear();
			_ready = true;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	bool EventImpl::isReady()
	{
		boost::mutex::scoped_lock sl(_mtx);
		return _ready;
	}

	//////////////////////////////////////////////////////////////////////////
	void EventImpl::wait()
	{
		{
			boost::mutex::scoped_lock sl(_mtx);

			if(_ready)
			{
				return;
			}

			FiberImplPtr f = FiberImpl::current();
			assert(f);
			_waiters.push_back(f);
		}

		FiberImpl::yield();
	}

}
