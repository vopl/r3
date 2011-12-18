#include "pch.h"
#include "fiberRootImpl.hpp"

namespace async
{

	//////////////////////////////////////////////////////////////////////////
	FiberRootImpl::FiberRootImpl(WorkerImpl *worker)
		: FiberImpl()
	{
		_worker = worker;
		ConvertThreadToFiberEx(NULL, FIBER_FLAG_FLOAT_SWITCH);
		_stack = GetCurrentFiber();
		_current = this;
	}

	//////////////////////////////////////////////////////////////////////////
	FiberRootImpl::~FiberRootImpl()
	{
		ConvertFiberToThread();
		_stack = NULL;
		assert(_current == this);
		_current = NULL;
	}
}
