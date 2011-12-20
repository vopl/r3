#ifndef _ASYNC_FIBERIMPL_HPP_
#define _ASYNC_FIBERIMPL_HPP_

#include "threadLocalStorage.hpp"
#include <boost/enable_shared_from_this.hpp>


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
		FiberImpl(bool createStack=true);
		virtual ~FiberImpl();

		static FiberImpl *current();

		void execute(function<void()> _code);
		void activate();

	private:
		static VOID WINAPI s_fiberProc(LPVOID lpFiberParameter);
		void fiberProc();

	protected:
		void enter();
		void leave();

	protected:
		void				*_stack;
		function<void()>	_code;
		HANDLE				_evt;

		static ThreadLocalStorage<FiberImpl *>
							_current;
	};
}

#endif
