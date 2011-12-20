#include "pch.h"
#include "fiberImpl.hpp"
#include "fiberRootImpl.hpp"
#include "workerImpl.hpp"
#include <windows.h>
#include "async/exception.hpp"

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	FiberImpl::FiberImpl(bool createStack)
		: _stack(NULL)
		, _evt(NULL)
	{
		if(createStack)
		{
			_stack = CreateFiber(0, &FiberImpl::s_fiberProc, this);
			assert(_stack);
			if(!_stack)
			{
				FLOG(__FUNCTION__<<", CreateFiber failed, "<<GetLastError());
				throw exception("CreateFiber failed");
			}

			_evt = CreateEvent(NULL, FALSE, TRUE, NULL);
			assert(_evt);
			if(!_evt)
			{
				FLOG(__FUNCTION__<<", CreateEvent failed, "<<GetLastError());
				throw exception("CreateEvent failed");
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	FiberImpl::~FiberImpl()
	{
		assert(_current != this);
		if(_stack)
		{
			DeleteFiber(_stack);
		}
		if(_evt)
		{
			if(!CloseHandle(_evt))
			{
				WLOG(__FUNCTION__<<", CloseHandle failed, "<<GetLastError());
			}
		}
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
		assert(_current != this);

		assert(!_code);
		assert(code);
		_code = code;

		activate();
	}

	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::activate()
	{
		FiberImpl *prev = _current.get();
		assert(prev != this);
		if(prev != this)
		{
			enter();
			_current = this;
			SwitchToFiber(_stack);
			leave();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::enter()
	{
		if(_evt)
		{
			DWORD res = WaitForSingleObject(_evt, INFINITE);
			assert(WAIT_OBJECT_0 == res);
			if(WAIT_OBJECT_0 != res)
			{
				FLOG(__FUNCTION__<<", WaitForSingleObject failed, "<<GetLastError());
				throw exception("WaitForSingleObject failed");
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::leave()
	{
		if(_evt)
		{
			BOOL res = SetEvent(_evt);
			assert(res);
			if(!res)
			{
				FLOG(__FUNCTION__<<", SetEvent failed, "<<GetLastError());
				throw exception("SetEvent failed");
			}
		}
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
			assert(_code);

			try
			{
				_code();
			}
			catch(...)
			{
				ELOG(__FUNCTION__<<", exception catched: "<<boost::current_exception_diagnostic_information());
			}
			assert(_code);
			_code.swap(function<void()>());

			WorkerImpl::current()->fiberExecuted(this);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ThreadLocalStorage<FiberImpl *> FiberImpl::_current;

}

