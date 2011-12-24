#include "pch.h"
#include "fiberImpl.hpp"
#include "fiberRootImpl.hpp"
#include "workerImpl.hpp"
#include <windows.h>
#include "async/exception.hpp"

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	FiberImpl::FiberImpl()
		: _stack(NULL)
		, _evt(NULL)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	FiberImpl::~FiberImpl()
	{
		assert(_current != this);
		if(_stack)
		{
			DeleteFiber(_stack);
			_stack = NULL;
		}
		if(_evt)
		{
			if(!CloseHandle(_evt))
			{
				WLOG(__FUNCTION__<<", CloseHandle failed, "<<GetLastError());
			}
			_evt = NULL;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	bool FiberImpl::initialize()
	{
		if(!_stack)
		{
			_stack = CreateFiberEx(1024*4, 1024*8, 0, &FiberImpl::s_fiberProc, this);
			if(!_stack)
			{
				FLOG(__FUNCTION__<<", CreateFiber failed, "<<GetLastError());
				//throw exception("CreateFiber failed");
				return false;
			}
		}

		if(!_evt)
		{
			_evt = CreateEvent(NULL, FALSE, TRUE, NULL);
			if(!_evt)
			{
				FLOG(__FUNCTION__<<", CreateEvent failed, "<<GetLastError());

				DeleteFiber(_stack);
				_stack = NULL;

				//throw exception("CreateEvent failed");
				return false;
			}
		}

// 		static int cnt(0);
// 		TLOG(__FUNCTION__<<", "<<cnt++);
		return true;
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

