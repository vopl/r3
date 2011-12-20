#include "pch.h"
#include "fiberImpl.hpp"
#include "fiberRootImpl.hpp"
#include "workerImpl.hpp"
#include <windows.h>

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	FiberImpl::FiberImpl(bool createStack)
		: _stack(NULL)
	{
		if(createStack)
		{
			_stack = CreateFiber(0, &FiberImpl::s_fiberProc, this);
			assert(_stack);
		}
		_evt = CreateEvent(NULL, FALSE, TRUE, NULL);
		assert(_evt);
	}

	//////////////////////////////////////////////////////////////////////////
	FiberImpl::~FiberImpl()
	{
		assert(_current != this);
		if(_stack)
		{
			DeleteFiber(_stack);
		}
		CloseHandle(_evt);
	}

	//////////////////////////////////////////////////////////////////////////
	FiberImpl *FiberImpl::current()
	{
		FiberImpl *fiber = _current;
		return fiber;
	}

	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::execute(function<void()> code)
	{
		{
			assert(_current != this);

			assert(!_code);
			assert(code);
			_code = code;
		}
		activate();
	}

	//////////////////////////////////////////////////////////////////////////
	mutex g_emMtx2;
	std::map<FiberImpl *, size_t> g_em2;
	void FiberImpl::activate()
	{
		FiberImpl *prev = _current.get();
		assert(prev != this);
		if(prev != this)
		{

			//assert(_code);

			enter();
			_current = this;
			SwitchToFiber(_stack);
			leave();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::ready()
	{
		assert(_current != this);
		WorkerImpl::current()->fiberReady(this);
	}
	
	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::yield()
	{
		WorkerImpl::current()->fiberYield();
	}

	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::enter()
	{
		DWORD res = WaitForSingleObject(_evt, INFINITE);
		assert(WAIT_OBJECT_0 == res);
	}

	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::leave()
	{
		BOOL res = SetEvent(_evt);
		assert(res);
	}


	//////////////////////////////////////////////////////////////////////////
	VOID WINAPI FiberImpl::s_fiberProc(LPVOID lpFiberImplParameter)
	{
		((FiberImpl*)lpFiberImplParameter)->fiberProc();
	}

	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::fiberProc()
	{
		for(;;)
		{
			{

				assert(_code);
				_code();
				assert(_code);
				_code.swap(function<void()>());
			}
			WorkerImpl::current()->fiberExecuted(this);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ThreadLocalStorage<FiberImpl *> FiberImpl::_current;

}

