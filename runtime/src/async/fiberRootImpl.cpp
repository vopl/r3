#include "pch.h"
#include "fiberRootImpl.hpp"

namespace async
{

	//////////////////////////////////////////////////////////////////////////
	FiberRootImpl::FiberRootImpl()
		: FiberImpl(false)
	{
		ConvertThreadToFiber(NULL);
		_stack = GetCurrentFiber();
		_current = this;
		enter();
	}

	//////////////////////////////////////////////////////////////////////////
	FiberRootImpl::~FiberRootImpl()
	{
		ConvertFiberToThread();
		_stack = NULL;
		assert(_current == this);
		_current = NULL;
		leave();
	}
}
