#ifndef _PGS_FIELD_HPP_
#define _PGS_FIELD_HPP_

#include "pgs/expression.hpp"
#include "meta/common.hpp"

namespace pgs
{
	namespace impl
	{
		class Field;
		typedef boost::shared_ptr<Field> Field_ptr;
	}

	//////////////////////////////////////////////////////////////////////////
	class Field
		: public Expression
	{
		typedef impl::Field_ptr Impl_ptr;

	public:
		Field();
		Field(pgs::meta::FieldCPtr fld);

		pgs::meta::FieldCPtr meta() const;
	};
}

#endif
