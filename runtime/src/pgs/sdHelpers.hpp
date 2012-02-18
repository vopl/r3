#ifndef _PGS_SDHELPERS_HPP_
#define _PGS_SDHELPERS_HPP_


namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	std::string &operator += (std::string &s, const std::deque<std::string> &d);
	std::deque<std::string> &operator += (std::deque<std::string> &d, const std::string &s);
}

#endif
