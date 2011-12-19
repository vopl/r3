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
		std::deque<FiberImplPtr> waiters;

		{
			boost::mutex::scoped_lock sl(_mtx);

			assert(!_ready);
			_ready = true;

			waiters.swap(_waiters);

			if(waiters.size()>1)
			{
				int k=220;
			}
			BOOST_FOREACH(FiberImplPtr &f, waiters)
			{
				f->ready();
			}
		}

	}

	//////////////////////////////////////////////////////////////////////////
	bool EventImpl::isReady()
	{
		return _ready;
	}

	//////////////////////////////////////////////////////////////////////////
	void EventImpl::wait()
	{
		if(_ready)
		{
			return;
		}

		{
			boost::mutex::scoped_lock sl(_mtx);
			FiberImplPtr f = FiberImpl::current();
			assert(f);
			_waiters.push_back(f);
		}

		do
		{
			FiberImpl::yield();
		}
		while(!_ready);
	}

}
