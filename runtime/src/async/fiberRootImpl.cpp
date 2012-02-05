#include "pch.h"
#include "fiberRootImpl.hpp"

namespace async
{

	//////////////////////////////////////////////////////////////////////////
	FiberRootImpl::FiberRootImpl()
		: FiberImpl()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	FiberRootImpl::~FiberRootImpl()
	{
#if defined(HAVE_WINFIBER)
		ConvertFiberToThread();
		_context = NULL;
#elif defined(HAVE_UCONTEXT_H)
		//
#else
#   error Unknown context type for fibers
#endif

		assert(_current == this);
		_current = NULL;
		
// 		leave();
	}

	//////////////////////////////////////////////////////////////////////////
	bool FiberRootImpl::initialize()
	{
#if defined(HAVE_WINFIBER)
		ConvertThreadToFiber(NULL);
		_context = GetCurrentFiber();
		assert(_context);
#elif defined(HAVE_UCONTEXT_H)
		assert(!_context.uc_stack.ss_sp);
		if(getcontext(&_context))
		{
			FLOG(__FUNCTION__<<", getcontext failed");
			//throw exception("getcontext failed");
			return false;
		}
#else
#   error Unknown context type for fibers
#endif
		_current = this;
		
// 		bool b = enter();
// 		assert(b);

		return true;
	}
}
