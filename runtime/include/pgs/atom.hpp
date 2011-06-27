#ifndef _PGS_ATOM_HPP_
#define _PGS_ATOM_HPP_

#include "pgs/where.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	class Atom
	{
	public:
		Where eq(const Atom &v) const
		{
			return Where();
		}
		Where ne(const Atom &v) const
		{
			return Where();
		}
		Where gt(const Atom &v) const
		{
			return Where();
		}
		Where lt(const Atom &v) const
		{
			return Where();
		}
	};

}
#endif
