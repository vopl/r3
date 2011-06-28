#ifndef _PGS_ATOM_HPP_
#define _PGS_ATOM_HPP_

#include "pgs/where.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/static_assert.hpp>
#include "pgc/cppDataType.hpp"

namespace pgs
{
	template <class CppType> class AtomImpl;
	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	class Atom
	{
		BOOST_STATIC_ASSERT_MSG(pgc::CppDataType<CppType>::known, "CppType must be known for pgc::CppDataType");
		boost::shared_ptr<AtomImpl<CppType> > _impl;
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
