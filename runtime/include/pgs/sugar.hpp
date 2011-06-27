#ifndef _PGS_SUGAR_HPP_
#define _PGS_SUGAR_HPP_

#include "pgs/atom.hpp"
#include "pgs/data.hpp"
#include "pgs/value.hpp"
#include "pgs/field.hpp"
#include "pgs/select.hpp"

namespace pgs
{
	Where operator==(const Atom<int> &v1, const Atom<int> &v2)
	{
		return v1.eq(v2);
	}

	Where operator||(const Where &v1, const Where &v2)
	{
		return v1.or(v2);
	}
}
#endif
