#include "pch.h"
#include "fiberRoot.hpp"

namespace async
{

	//////////////////////////////////////////////////////////////////////////
	FiberRoot::FiberRoot(ServiceWorker *worker)
		: Fiber()
	{
		_worker = worker;
		ConvertThreadToFiberEx(NULL, FIBER_FLAG_FLOAT_SWITCH);
		_stack = GetCurrentFiber();
	}

	//////////////////////////////////////////////////////////////////////////
	FiberRoot::~FiberRoot()
	{
		ConvertFiberToThread();
		_stack = NULL;
	}
}
