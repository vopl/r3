#ifndef _ASYNC_FIBERPOOL_HPP_
#define _ASYNC_FIBERPOOL_HPP_

#include "fiberImpl.hpp"
#include <set>

namespace async
{
	class FiberPool
	{
	public:
		//фибкры без задачи
		std::set<FiberImplPtr> _fibersIdle;

		//рабочие фиберы с задачей и готовые к исполнению
		std::set<FiberImplPtr> _fibersReady;
		//boost::mutex	_fibersReadyMtx;
	public:
	};
	typedef boost::shared_ptr<FiberPool> FiberPoolPtr;
}
#endif
