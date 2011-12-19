#include "pch.h"
#include "fiberImpl.hpp"
#include "fiberRootImpl.hpp"
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
	boost::mutex g_emMtx2;
	std::map<FiberImpl *, size_t> g_em2;
	void FiberImpl::activate()
	{
		assert(_current != this);
		if(_current != this)
		{

			//assert(_code);

			{
				boost::mutex::scoped_lock sl(g_emMtx2);
				std::map<FiberImpl *, size_t> &e_em2 = g_em2;

				FiberImpl *cur = _current.get();
				if(dynamic_cast<FiberRootImpl *>(cur))
				{
					cur = 0;
				}
				FiberImpl *thi = this;
				if(dynamic_cast<FiberRootImpl *>(thi))
				{
					thi = 0;
				}
				g_em2[cur];
				g_em2[cur]--;
				g_em2[thi]++;
				assert(g_em2[thi]<2 || !thi);
			}



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

	//////////////////////////////////////////////////////////////////////////
	void FiberImpl::fiberProc()
	{
		for(;;)
		{
			{

				assert(_code);
				_code();
				assert(_code);
				_code.swap(boost::function<void()>());
			}
			WorkerImpl::current()->fiberExecuted(shared_from_this());
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ThreadLocalStorage<FiberImpl *> FiberImpl::_current;

}

