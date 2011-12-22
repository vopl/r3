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
		ResultWaiter(const ResultWaiter &);
		ResultWaiter(const EventWaiter<Result<Data> > &);
		ResultWaiter(const Result<Data> &);

		ResultWaiter &operator=(const ResultWaiter &);
		ResultWaiter &operator=(const EventWaiter<Result<Data> > &);
		ResultWaiter &operator=(const Result<Data> &);
	};


	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	ResultWaiter<Data>::ResultWaiter()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	ResultWaiter<Data>::ResultWaiter(const ResultWaiter<Data> &waiter)
		: Base(waiter)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	ResultWaiter<Data>::ResultWaiter(const EventWaiter<Result<Data> > &waiter)
		: Base(waiter)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	ResultWaiter<Data>::ResultWaiter(const Result<Data> &result)
		: Base(result)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	ResultWaiter<Data> &ResultWaiter<Data>::operator=(const ResultWaiter<Data> &waiter)
	{
		Base::operator=(waiter);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	ResultWaiter<Data> &ResultWaiter<Data>::operator=(const EventWaiter<Result<Data> > &waiter)
	{
		Base::operator=(waiter);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	ResultWaiter<Data> &ResultWaiter<Data>::operator=(const Result<Data> &result)
	{
		Base::operator=(result);
		return *this;
	}

}

#endif
