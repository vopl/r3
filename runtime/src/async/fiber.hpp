#ifndef _ASYNC_FIBER_HPP_
#define _ASYNC_FIBER_HPP_

#include <boost/enable_shared_from_this.hpp>
#include <boost/thread/tss.hpp>






// OS
#ifdef _WIN32
#   define WINDOWS
#else
#   define POSIX
#endif
#ifdef __CYGWIN__
#   define WINDOWS
#   define CYGWIN
#endif

#ifdef linux
#   define LINUX
#endif

#ifdef __APPLE__
#   define OSX
#   define BSD
#endif

#ifdef __FreeBSD__
#   define FREEBSD
#   define BSD
#endif


// Architecture
#ifdef _MSC_VER
#   define MSVC
#   ifdef _M_X64
#       define X86_64
#   elif defined(_M_IX86)
#       define X86
#   endif
#endif

#ifdef __GNUC__
#   define GCC
#   ifdef __x86_64
#       define X86_64
#   elif defined(i386)
#       define X86
#   elif defined(__ppc__)
#       define PPC
#   elif defined(__arm__)
#       define ARM
#   endif
#endif

// Fiber impl selection
#ifdef X86_64
#   ifdef WINDOWS
#       define NATIVE_WINDOWS_FIBERS
#   elif defined(OSX)
#       define SETJMP_FIBERS
#   elif defined(POSIX)
#       define UCONTEXT_FIBERS
#   endif
#elif defined(X86)
#   ifdef WINDOWS
#       define NATIVE_WINDOWS_FIBERS
#   elif defined(OSX)
#       define SETJMP_FIBERS
#   elif defined(POSIX)
#       define UCONTEXT_FIBERS
#   endif
#elif defined(PPC)
#   define UCONTEXT_FIBERS
#elif defined(ARM)
#   define UCONTEXT_FIBERS
#else
#   error Platform not supported
#endif

#ifdef UCONTEXT_FIBERS
#   ifdef __APPLE__
#       include <sys/ucontext.h>
#   else
#       include <ucontext.h>
#   endif
#endif
#ifdef SETJMP_FIBERS
#	include <setjmp.h>
#endif



//////////////////////////////////////////////////////////////////////////
namespace async
{
	class ServiceWorker;

	class Fiber
	{
	protected:
		Fiber();

	public:
		Fiber(ServiceWorker *worker);
		~Fiber();

		static Fiber *current();

		void execute(boost::function<void()> _code);
		void activate();

	private:
		static VOID WINAPI s_fiberProc(LPVOID lpFiberParameter);
		void fiberProc();
	protected:
		ServiceWorker *_worker;
		void *_stack;
		boost::function<void()> _code;

		static boost::thread_specific_ptr<Fiber> _current;
	};
}

#endif
