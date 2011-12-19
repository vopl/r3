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

		assert(!_ready);
		_ready = true;

		std::deque<FiberImplPtr> waiters;
		waiters.swap(_waiters);

		BOOST_FOREACH(FiberImplPtr &f, waiters)
		{
			f->ready();
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

		do
		{
			FiberImpl::yield();
		}
		while(!isReady());
	}

}
