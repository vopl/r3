#include "pch.hpp"
#include "sdHelpers.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	std::string &operator += (std::string &s, const std::deque<std::string> &d)
	{
		BOOST_FOREACH(const std::string &ds, d)
		{
			s += ds;
		}
		return s;
	}

	//////////////////////////////////////////////////////////////////////////
	std::deque<std::string> &operator += (std::deque<std::string> &d, const std::string &s)
	{
		d.push_back(s);
		return d;
	}
}
