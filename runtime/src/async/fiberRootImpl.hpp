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

		bool initialize();

		virtual bool enter(){return true;}
		virtual void leave(){}
	};
	typedef shared_ptr<FiberRootImpl> FiberRootImplPtr;
}

#endif
