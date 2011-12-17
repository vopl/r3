#ifndef _ASYNC_FIBER_HPP_
#define _ASYNC_FIBER_HPP_

#include "threadLocalStorage.hpp"
#include <boost/enable_shared_from_this.hpp>
#include <windows.h>


//////////////////////////////////////////////////////////////////////////
namespace async
{
	class ServiceWorker;

	class Fiber
		: public boost::enable_shared_from_this<Fiber>
	{
	protected:
		Fiber();

	public:
		Fiber(ServiceWorker *worker);
		~Fiber();

		static Fiber *current();

		void execute(boost::function<void()> _code);
		void activate();
		void ready();
		void yield();

	private:
		static VOID WINAPI s_fiberProc(LPVOID lpFiberParameter);
		void fiberProc();
	protected:
		ServiceWorker *_worker;
		void *_stack;
		boost::function<void()> _code;

		static ThreadLocalStorage<Fiber *> _current;
	};
	typedef boost::shared_ptr<Fiber> FiberPtr;
}

#endif
