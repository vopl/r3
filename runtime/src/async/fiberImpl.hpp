#ifndef _ASYNC_FIBERIMPL_HPP_
#define _ASYNC_FIBERIMPL_HPP_

#include "threadLocalStorage.hpp"
#include <boost/enable_shared_from_this.hpp>

//#include "config.h"
#define HAVE_UCONTEXT_H 1
/* #define HAVE_WINFIBER 1 */

#if defined(HAVE_WINFIBER)
#	include <windows.h>
#elif defined(HAVE_UCONTEXT_H)
#	include "ucontext.h"

#	define DeleteFiber DeleteFiber_absent
#	define CreateFiberEx CreateFiberEx_absent
#	define SwitchToFiber SwitchToFiber_absent

#else
#   error Unknown context type for fibers
#endif



//////////////////////////////////////////////////////////////////////////
namespace async
{
	class WorkerImpl;
	class FiberImpl;
	typedef shared_ptr<FiberImpl> FiberImplPtr;

	class FiberImpl
		: public enable_shared_from_this<FiberImpl>
	{
	public:
		FiberImpl(size_t stacksize = 1024*32);
		virtual ~FiberImpl();

		bool initialize();
		static FiberImpl *current();

		void execute(function<void()> _code);
		void activate();

	private:
#if defined(HAVE_WINFIBER)
		static VOID WINAPI s_fiberProc(LPVOID param);
#elif defined(HAVE_UCONTEXT_H)
		static void s_fiberProc(int param);
#else
#   error Unknown context type for fibers
#endif
		void fiberProc();

	protected:
		void enter();
		void leave();

	protected:

		size_t _stacksize;
#if defined(HAVE_WINFIBER)
		LPVOID	_context;
#elif defined(HAVE_UCONTEXT_H)
		ucontext_t	_context;
#else
#   error Unknown context type for fibers
#endif

		function<void()>	_code;
		HANDLE				_evt;

		static ThreadLocalStorage<FiberImpl *>
							_current;
	};
}

#endif
