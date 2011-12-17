#include "pch.h"
#include "fiber.hpp"
#include "serviceWorker.hpp"

namespace async
{

	//////////////////////////////////////////////////////////////////////////
	Fiber::Fiber()
		: _worker(NULL)
		, _stack(NULL)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Fiber::Fiber(ServiceWorker *worker)
		: _worker(worker)
	{
		_stack = CreateFiberEx(0, 0, FIBER_FLAG_FLOAT_SWITCH, &Fiber::s_fiberProc, this);
		assert(_stack);
	}

	//////////////////////////////////////////////////////////////////////////
	Fiber::~Fiber()
	{
		if(_stack)
		{
			DeleteFiber(_stack);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	Fiber* Fiber::current()
	{
		return _current.get();
	}

	//////////////////////////////////////////////////////////////////////////
	void Fiber::execute(boost::function<void()> code)
	{
		assert(!_code);
		assert(code);
		_code = code;
		activate();
	}

	//////////////////////////////////////////////////////////////////////////
	void Fiber::activate()
	{
		_current.reset(this);
		SwitchToFiber(_stack);
	}

	VOID WINAPI Fiber::s_fiberProc(LPVOID lpFiberParameter)
	{
		((Fiber*)lpFiberParameter)->fiberProc();
	}

	//////////////////////////////////////////////////////////////////////////
	void Fiber::fiberProc()
	{
		for(;;)
		{
			assert(_code);
			_code();
			_code.swap(boost::function<void()>());
			_worker->fiberExecuted(this);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	boost::thread_specific_ptr<Fiber> Fiber::_current;

}

