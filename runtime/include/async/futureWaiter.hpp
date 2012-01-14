#ifndef _ASYNC_FUTUREWAITER_HPP_
#define _ASYNC_FUTUREWAITER_HPP_

#include "async/future.hpp"
#include "async/eventWaiter.hpp"

//////////////////////////////////////////////////////////////////////////
namespace async
{
	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	class FutureWaiter
		: public EventWaiter<Future<Data> >
	{
		typedef EventWaiter<Future<Data> > Base;
	public:
		FutureWaiter();
		FutureWaiter(const Future<Data> &);

		operator Data &();

	};

	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	FutureWaiter<Data>::FutureWaiter()
		: Base()
	{
	}


	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	FutureWaiter<Data>::FutureWaiter(const Future<Data> &event)
		: Base(event)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	FutureWaiter<Data>::operator Data &()
	{
		return current().data();
	}

}

#endif
