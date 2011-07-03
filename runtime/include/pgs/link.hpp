#ifndef _PGS_LINK_HPP_
#define _PGS_LINK_HPP_

#include "pgs/Field.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class Link
	{
	public:
		Link(Field src, Field dst, const char *alias);
		~Link();
	};

}
#endif
