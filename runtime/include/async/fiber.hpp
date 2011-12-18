#ifndef _ASYNC_FIBER_HPP_
#define _ASYNC_FIBER_HPP_

#include "async/api.h"
#include <boost/enable_shared_from_this.hpp>



//////////////////////////////////////////////////////////////////////////
namespace async
{
	//////////////////////////////////////////////////////////////////////////
	class Fiber;
	typedef boost::shared_ptr<Fiber> FiberPtr;

	//////////////////////////////////////////////////////////////////////////
	class ASYNC_API Fiber
	{
	protected:
		Fiber();
		Fiber(const Fiber&);

	public:
		virtual ~Fiber();

		//получить экземпл€р текущего фибера
		static FiberPtr current();

		//оповестить воркера о готовности этого фибера к исполнению
		void ready();

		//зафиксировать исполнение текущего фибера в пользу корн€
		static void yield();

	};
}

#endif
