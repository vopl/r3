#ifndef _PGS_FIELD_HPP_
#define _PGS_FIELD_HPP_

#include "pgs/expression.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class Field
		: public Expression
	{
		pgs::meta::FieldCPtr _metaField;
	public:
		Field();
		Field(pgs::meta::FieldCPtr fld);

		pgs::meta::FieldCPtr meta() const;
	};
}

#endif
