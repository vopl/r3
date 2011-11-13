#ifndef _UTILS_DATETIMEDURATION_HPP_
#define _UTILS_DATETIMEDURATION_HPP_

#include <boost/date_time/gregorian/greg_date.hpp>
#include <boost/date_time/posix_time/ptime.hpp>

namespace utils
{
	struct DateTimeDuration
	{
		boost::gregorian::date_duration		_dd;
		boost::posix_time::time_duration	_td;

		DateTimeDuration()
			: _dd()
			, _td()
		{}

		DateTimeDuration(boost::gregorian::date_duration dd, boost::posix_time::time_duration td)
			: _dd(dd)
			, _td(td)
		{}

	};
}

#endif
