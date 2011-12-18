#ifndef _ASYNC_RESULT_HPP_
#define _ASYNC_RESULT_HPP_

#include "async/event.hpp"

//////////////////////////////////////////////////////////////////////////
namespace async
{
	//////////////////////////////////////////////////////////////////////////
	template <class Data>
	class Result
		: public Event
	{
	public:
		boost::shared_ptr<Data> _data;
	public:
		Result()
			: _data(new Data)
		{
		}
		Data &data()
		{
			return *_data;
		}
	};
}

#endif
