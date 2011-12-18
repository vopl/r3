#include "pch.h"
#include "fiberImpl.hpp"
#include "workerImpl.hpp"
#include <windows.h>

namespace async
{

	//////////////////////////////////////////////////////////////////////////
	FiberImpl::FiberImpl()
		: _worker(NULL)
		, _stack(NULL)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	FiberImpl::FiberImpl(WorkerImpl *worker)
		: _worker(worker)
	{
		_stack = CreateFiberEx(0, 0, FIBER_FLAG_FLOAT_SWITCH, &FiberImpl::s_fiberProc, this);
		assert(_stack);
	}

	//////////////////////////////////////////////////////////////////////////
	FiberImpl::~FiberImpl()
	{
		if(_stack)
		{
			DeleteFiber(_stack);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	FiberImplPtr FiberImpl::current()
	{
		return _current->shared_from_this();
	}

	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::execute(boost::function<void()> code)
	{
		assert(_current != this);

		assert(!_code);
		assert(code);
		_code = code;
		activate();
	}

	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::activate()
	{
		assert(_current != this);
		_current = this;
		SwitchToFiber(_stack);
	}

	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::ready()
	{
		_worker->fiberReady(shared_from_this());
	}
	
	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::yield()
	{
		_worker->fiberYield(shared_from_this());
	}

	//////////////////////////////////////////////////////////////////////////
	VOID WINAPI FiberImpl::s_fiberProc(LPVOID lpFiberImplParameter)
	{
		((FiberImpl*)lpFiberImplParameter)->fiberProc();
	}

	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::fiberProc()
	{
		//for(;;)
		{
			assert(_code);
			_code();
			_code.swap(boost::function<void()>());
			_worker->fiberExecuted(shared_from_this());
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ThreadLocalStorage<FiberImpl *> FiberImpl::_current;

}

