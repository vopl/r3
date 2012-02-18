#ifndef _ASYNC_FIBERIMPL_HPP_
#define _ASYNC_FIBERIMPL_HPP_

#include "threadLocalStorage.hpp"
#include <boost/enable_shared_from_this.hpp>

#include "config.h"
//#define HAVE_UCONTEXT_H 1
//#define HAVE_WINFIBER 1

#if defined(HAVE_WINFIBER)
#	include <windows.h>
#elif defined(HAVE_UCONTEXT_H)
#	include <ucontext.h>
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
		FiberImpl(size_t stacksize = 1024*64);
		virtual ~FiberImpl();

		bool initialize();
		static FiberImpl *current();

		bool execute(const function<void()> &code);
		bool activate(bool alreadyLocked = false);

	private:
#if defined(HAVE_WINFIBER)
	static VOID WINAPI s_fiberProc(LPVOID param);
#elif defined(HAVE_UCONTEXT_H)
#	if PVOID_SIZE == INT_SIZE
        static void s_fiberProc(int param);
#	elif PVOID_SIZE == INT_SIZE*2
        static void s_fiberProc(int param1, int param2);
#	else
#		error PVOID_SIZE not equal INT_SIZE or INT_SIZE*2
#	endif
#else
#	error Unknown context type for fibers
#endif
		void fiberProc();

	protected:
		virtual bool enter();
		virtual void leave();

	protected:

		size_t _stacksize;
#if defined(HAVE_WINFIBER)
		LPVOID	_context;
#elif defined(HAVE_UCONTEXT_H)
		ucontext_t	_context;
#	if defined(HAVE_VALGRIND_H)
		int _valgrindStackId;
#	endif
#else
#   error Unknown context type for fibers
#endif


		function<void()>	_code;
		boost::mutex		_mtx;
		bool				_isLocked;

		static ThreadLocalStorage<FiberImpl *>
							_current;
	};
}

#endif
