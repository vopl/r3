#ifndef _ASYNC_RESULTWAITER_HPP_
#define _ASYNC_RESULTWAITER_HPP_

#include "async/result.hpp"
#include "async/eventWaiter.hpp"

//////////////////////////////////////////////////////////////////////////
namespace async
{
	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	class ResultWaiter
		: public EventWaiter<Result<Data> >
	{
		typedef EventWaiter<Result<Data> > Base;
	public:
		ResultWaiter();
		ResultWaiter(const Result<Data> &);

		operator Data &();

	};

	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	ResultWaiter<Data>::ResultWaiter()
		: Base()
	{
	}


	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	ResultWaiter<Data>::ResultWaiter(const Result<Data> &event)
		: Base(event)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	ResultWaiter<Data>::operator Data &()
	{
		return current().data();
	}

}

#endif
