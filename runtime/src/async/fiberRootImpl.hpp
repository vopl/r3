#ifndef _ASYNC_FIBERROOTIMPL_HPP_
#define _ASYNC_FIBERROOTIMPL_HPP_

#include "fiberImpl.hpp"

namespace async
{
	class FiberRootImpl
		: public FiberImpl
	{
	public:
		FiberRootImpl();
		~FiberRootImpl();
	};
	typedef shared_ptr<FiberRootImpl> FiberRootImplPtr;
}

#endif
