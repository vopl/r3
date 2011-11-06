#ifndef _PGS_IMPL_FIELD_HPP_
#define _PGS_IMPL_FIELD_HPP_

#include "expression.hpp"

namespace pgs
{
	namespace impl
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
}

#endif
