#ifndef _ASYNC_FIBERIMPL_HPP_
#define _ASYNC_FIBERIMPL_HPP_

#include "threadLocalStorage.hpp"
#include <boost/enable_shared_from_this.hpp>
#include "async/fiber.hpp"


//////////////////////////////////////////////////////////////////////////
namespace async
{
	class WorkerImpl;
	class FiberImpl;
	typedef boost::shared_ptr<FiberImpl> FiberImplPtr;

	class FiberImpl
		: public Fiber
		, public boost::enable_shared_from_this<FiberImpl>
	{
	public:
		FiberImpl(bool createStack=true);
		~FiberImpl();

		static FiberImplPtr current();

		void execute(boost::function<void()> _code);
		void activate();
		void ready();
		static void yield();

	private:
		static VOID WINAPI s_fiberProc(LPVOID lpFiberParameter);
		void fiberProc();
	protected:
		void *_stack;
		boost::function<void()> _code;

		static ThreadLocalStorage<FiberImpl *> _current;
	};
}

#endif
