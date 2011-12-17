#ifndef _ASYNC_FIBERROOT_HPP_
#define _ASYNC_FIBERROOT_HPP_

#include "fiber.hpp"

namespace async
{
	class FiberRoot
		: public Fiber
	{
	public:
		FiberRoot(ServiceWorker *worker);
		~FiberRoot();
	};
}

#endif
