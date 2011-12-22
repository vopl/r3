#include "pch.h"
#include "eventImpl.hpp"
#include "workerImpl.hpp"
#include "async/exception.hpp"

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
			if(!_autoReset)
			{
				_isSet = true;

				BOOST_FOREACH(MultiNotifierPtr &pmn, _pmnWaiters)
				{
					pmn->notifyReady(this);
				}
				_pmnWaiters.clear();

				BOOST_FOREACH(FiberImplPtr &f, _waiters)
				{
					assert(f.get() != FiberImpl::current());
					WorkerImpl::current()->fiberReady(f);
				}
				_waiters.clear();
				return;
			}

			if(!_pmnWaiters.empty())
			{
				for(std::deque<MultiNotifierPtr>::iterator ipmn(_pmnWaiters.begin()); ipmn!=_pmnWaiters.end(); ipmn++)
				{
					if((*ipmn)->notifyReady(this))
					{
						_pmnWaiters.erase(_pmnWaiters.begin(), ipmn+1);
						return;
					}
				}
				_pmnWaiters.clear();
			}

			if(!_waiters.empty())
			{
				_isSet = true;
				return;
			}

			FiberImplPtr f;
			f.swap(_waiters.front());
			_waiters.pop_front();
			WorkerImpl::current()->fiberReady(f);
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
				if(_autoReset)
				{
					_isSet = false;
				}
				return;
			}

			FiberImpl *f = FiberImpl::current();
			assert(f);
			_waiters.push_back(f->shared_from_this());
		}

		WorkerImpl::current()->fiberYield();
	}

	//////////////////////////////////////////////////////////////////////////
	bool EventImpl::MultiNotifier::notifyReady(EventImpl *who)
	{
		mutex::scoped_lock sl(_mtx);
		if(_ready)
		{
			return false;
		}

		_ready = who;
		WorkerImpl::current()->fiberReady(_initiator);

		return true;
	}


	//////////////////////////////////////////////////////////////////////////
	Event *EventImpl::waitAny(Event *begin, Event *end)
	{
		MultiNotifierPtr pmn(new MultiNotifier);
		pmn->_ready = NULL;

		//старт
		Event *iter = begin;
		{
			mutex::scoped_lock sl(pmn->_mtx);

			size_t idx(0);
			for(; iter!=end; iter++)
			{
				if(!iter->_impl->mnWait(pmn))
				{
					//готов, откатить установленные
					for(Event *iterBack = begin; iterBack!=iter; iterBack++)
					{
						iterBack->_impl->mnCancel(pmn);
					}

					return iter;
				}
			}

			pmn->_initiator = FiberImpl::current()->shared_from_this();
		}

		//никто не сработал при старте, ждать
		WorkerImpl::current()->fiberYield();

		//один сработал, отменить остальные
		assert(pmn->_ready);
		{
			//mutex::scoped_lock sl(pmn->_mtx);

			for(Event *iterBack = begin; iterBack!=end; iterBack++)
			{
				if(iterBack->_impl.get() == pmn->_ready)
				{
					continue;
				}
				iterBack->_impl->mnCancel(pmn);
			}
		}

		//переделать на хранение ключа
		for(iter = begin; iter!=end; iter++)
		{
			if(iter->_impl.get() == pmn->_ready)
			return iter;
		}

		assert(0);
		return NULL;
	}

	//////////////////////////////////////////////////////////////////////////
	bool EventImpl::mnWait(MultiNotifierPtr pmn)
	{
		{
			mutex::scoped_lock sl(_mtx);

			if(_isSet)
			{
				if(_autoReset)
				{
					_isSet = false;
				}
				return false;
			}

			_pmnWaiters.push_back(pmn);
			return true;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void EventImpl::mnCancel(MultiNotifierPtr pmn)
	{
		{
			mutex::scoped_lock sl(_mtx);

			std::deque<MultiNotifierPtr >::iterator iter =
				std::find(_pmnWaiters.begin(), _pmnWaiters.end(), pmn);
			if(_pmnWaiters.end() != iter)
			{
				_pmnWaiters.erase(iter);
			}
		}
	}

}
