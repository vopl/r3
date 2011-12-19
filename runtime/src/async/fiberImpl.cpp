#include "pch.h"
#include "fiberImpl.hpp"
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
	}

	//////////////////////////////////////////////////////////////////////////
	FiberImpl::~FiberImpl()
	{
		assert(_current != this);
		if(_stack)
		{
			DeleteFiber(_stack);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	FiberImplPtr FiberImpl::current()
	{
		FiberImplPtr fiber = _current->shared_from_this();
		return fiber;
	}

	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::execute(boost::function<void()> code)
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
	void FiberImpl::activate()
	{
		assert(_current != this);
		if(_current != this)
		{
			_current = this;
			SwitchToFiber(_stack);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::ready()
	{
		assert(_current != this);
		WorkerImpl::current()->fiberReady(shared_from_this());
	}
	
	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::yield()
	{
		WorkerImpl::current()->fiberYield(current());
	}

	//////////////////////////////////////////////////////////////////////////
	VOID WINAPI FiberImpl::s_fiberProc(LPVOID lpFiberImplParameter)
	{
		__try
		{
			((FiberImpl*)lpFiberImplParameter)->fiberProc();
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
			std::cout<<__FUNCTION__<<", seh"<<std::endl;
		}
	}

	boost::mutex g_emMtx;
	std::map<FiberImpl *, size_t> g_em;
	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::fiberProc()
	{
		for(;;)
		{
			{
				{
					boost::mutex::scoped_lock sl(g_emMtx);
					g_em[this]++;
					assert(g_em[this]<2);
				}
				assert(_code);
				_code();
				_code.swap(boost::function<void()>());
				{
					boost::mutex::scoped_lock sl(g_emMtx);
					g_em[this]--;
					assert(g_em[this]<1);
				}
			}
			WorkerImpl::current()->fiberExecuted(shared_from_this());
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ThreadLocalStorage<FiberImpl *> FiberImpl::_current;

}

