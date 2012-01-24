#include "pch.h"
#include "fiberImpl.hpp"
#include "fiberRootImpl.hpp"
#include "workerImpl.hpp"
#include "async/exception.hpp"


namespace async
{
	//////////////////////////////////////////////////////////////////////////
	FiberImpl::FiberImpl(size_t stacksize)
		: _stacksize(stacksize)
#if defined(HAVE_WINFIBER)
		, _context(NULL)
#elif defined(HAVE_UCONTEXT_H)
#else
#   error Unknown context type for fibers
#endif
		, _evt(NULL)
	{
#if defined(HAVE_WINFIBER)
#elif defined(HAVE_UCONTEXT_H)
		memset(&_context, 0, sizeof(ucontext_t));
#else
#   error Unknown context type for fibers
#endif
	}

	//////////////////////////////////////////////////////////////////////////
	FiberImpl::~FiberImpl()
	{
		assert(_current != this);
#if defined(HAVE_WINFIBER)
		if(_context)
		{
			DeleteFiber(_context);
			_context = NULL;
		}
#elif defined(HAVE_UCONTEXT_H)
		if(_context.uc_stack.ss_sp)
		{
			free(_context.uc_stack.ss_sp);
		}
#else
#   error Unknown context type for fibers
#endif
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
#if defined(HAVE_WINFIBER)
		assert(!_context);
		if(!_context)
		{
			_context = CreateFiberEx(_stacksize, _stacksize, 0, &FiberImpl::s_fiberProc, this);
			if(!_context)
			{
				FLOG(__FUNCTION__<<", CreateFiberEx failed, "<<GetLastError());
				//throw exception("CreateFiber failed");
				return false;
			}
		}
#elif defined(HAVE_UCONTEXT_H)
		assert(!_context.uc_stack.ss_sp);
		if(getcontext(&_context))
		{
			FLOG(__FUNCTION__<<", getcontext failed");
			//throw exception("getcontext failed");
			return false;
		}
		_context.uc_link = NULL;
		_context.uc_stack.ss_sp = malloc(_stacksize);
		_context.uc_stack.ss_size = _stacksize;

		if(makecontext(&_context, (void (*)(void))&FiberImpl::s_fiberProc, 1, (int)this))
		{
			FLOG(__FUNCTION__<<", makecontext failed");

			free(_context.uc_stack.ss_sp);
			memset(&_context, 0, sizeof(ucontext_t));

			//throw exception("makecontext failed");
			return false;
		}
#else
#   error Unknown context type for fibers
#endif

		if(!_evt)
		{
			_evt = CreateEvent(NULL, FALSE, TRUE, NULL);
			if(!_evt)
			{
				FLOG(__FUNCTION__<<", CreateEvent failed, "<<GetLastError());

#if defined(HAVE_WINFIBER)
				DeleteFiber(_context);
				_context = NULL;
#elif defined(HAVE_UCONTEXT_H)
				free(_context.uc_stack.ss_sp);
				memset(&_context, 0, sizeof(ucontext_t));
#else
#   error Unknown context type for fibers
#endif

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
		assert(prev);
		assert(prev != this);
		if(prev != this)
		{
			enter();
			_current = this;
#if defined(HAVE_WINFIBER)
			SwitchToFiber(_context);
#elif defined(HAVE_UCONTEXT_H)
// 			if(setcontext(&_context))
// 			{
// 				FLOG(__FUNCTION__<<", setcontext failed");
// 				throw exception("setcontext failed");
// 			}
			if(swapcontext(&prev->_context, &_context))
			{
				FLOG(__FUNCTION__<<", swapcontext failed");
				throw exception("swapcontext failed");
			}
#else
#   error Unknown context type for fibers
#endif
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
#if defined(HAVE_WINFIBER)
	VOID WINAPI FiberImpl::s_fiberProc(LPVOID param)
#elif defined(HAVE_UCONTEXT_H)
	void FiberImpl::s_fiberProc(int param)
#else
#   error Unknown context type for fibers
#endif
	{
		((FiberImpl*)param)->fiberProc();
	}

	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::fiberProc()
	{
		for(;;)
		{
			assert(_code);
			assert(FiberImpl::current() == this);

			try
			{
				_code();
			}
			catch(...)
			{
				ELOG(__FUNCTION__<<", exception catched: "<<boost::current_exception_diagnostic_information());
			}
			assert(_code);
			assert(FiberImpl::current() == this);

			function<void()>().swap(_code);

			WorkerImpl::current()->fiberExecuted(this);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ThreadLocalStorage<FiberImpl *> FiberImpl::_current;

}

