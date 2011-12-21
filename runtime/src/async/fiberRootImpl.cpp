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
		ConvertFiberToThread();
		_stack = NULL;
		assert(_current == this);
		_current = NULL;
		leave();
	}

	//////////////////////////////////////////////////////////////////////////
	bool FiberRootImpl::initialize()
	{
		ConvertThreadToFiber(NULL);
		_stack = GetCurrentFiber();
		assert(_stack);
		_current = this;
		enter();
		return true;
	}
}
