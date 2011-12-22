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

				BOOST_FOREACH(MultiNotifierMarked &mn, _mnWaiters)
				{
					mn._pmn->notifyReady(mn._key);
				}
				_mnWaiters.clear();

				BOOST_FOREACH(FiberImplPtr &f, _waiters)
				{
					assert(f.get() != FiberImpl::current());
					WorkerImpl::current()->fiberReady(f);
				}
				_waiters.clear();
				return;
			}

			if(!_mnWaiters.empty())
			{
				for(std::vector<MultiNotifierMarked>::iterator ipmn(_mnWaiters.begin()); ipmn!=_mnWaiters.end(); ipmn++)
				{
					if(ipmn->_pmn->notifyReady(ipmn->_key))
					{
						_mnWaiters.erase(_mnWaiters.begin(), ipmn+1);
						return;
					}
				}
				_mnWaiters.clear();
			}

			if(!_waiters.empty())
			{
				_isSet = true;
				return;
			}

			FiberImplPtr f;
			f.swap(_waiters.front());
			_waiters.erase(_waiters.begin());
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
	bool EventImpl::MultiNotifier::notifyReady(void *key)
	{
		mutex::scoped_lock sl(_mtx);
		if(_readyKey)
		{
			return false;
		}

		_readyKey = key;
		WorkerImpl::current()->fiberReady(_initiator);

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	EventImpl::MultiNotifierMarked::MultiNotifierMarked(const MultiNotifierPtr &pmn, void *key)
		: _pmn(pmn)
		, _key(key)
	{
	}



	//////////////////////////////////////////////////////////////////////////
	Event *EventImpl::waitAny(Event *begin, Event *end)
	{
		MultiNotifierPtr pmn(new MultiNotifier);
		pmn->_readyKey = NULL;
		pmn->_initiator = FiberImpl::current()->shared_from_this();

		//старт
		pmn->_mtx.lock();
		Event *iter = begin;
		size_t idx(0);
		for(; iter!=end; iter++)
		{
			if(!iter->_impl->mnWait(MultiNotifierMarked(pmn, iter)))
			{
				pmn->_readyKey = iter->_impl.get();
				pmn->_mtx.unlock();
				//готов, откатить установленные
				for(Event *iterBack = begin; iterBack!=iter; iterBack++)
				{
					iterBack->_impl->mnCancel(pmn);
				}

				return iter;
			}
		}
		pmn->_mtx.unlock();

		//никто не сработал при старте, ждать
		WorkerImpl::current()->fiberYield();

		//один сработал, отменить остальные
		assert(pmn->_readyKey);
		{
			for(Event *iterBack = begin; iterBack!=end; iterBack++)
			{
				if(iterBack == pmn->_readyKey)
				{
					continue;
				}
				iterBack->_impl->mnCancel(pmn);
			}
		}

		return (Event *)pmn->_readyKey;
	}

	//////////////////////////////////////////////////////////////////////////
	bool EventImpl::mnWait(const MultiNotifierMarked &mn)
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

		_mnWaiters.push_back(mn);
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	void EventImpl::mnCancel(const MultiNotifierPtr &pmn)
	{
		mutex::scoped_lock sl(_mtx);

		std::vector<MultiNotifierMarked>::iterator iter = _mnWaiters.begin();
		std::vector<MultiNotifierMarked>::iterator end = _mnWaiters.end();
		for(; iter!=end; iter++)
		{
			if(pmn == iter->_pmn)
			{
				_mnWaiters.erase(iter);
				return;
			}
		}
	}

}
