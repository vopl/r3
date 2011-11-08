#ifndef _PGS_IMPL_FIELD_HPP_
#define _PGS_IMPL_FIELD_HPP_

#include "expression.hpp"
#include "pgs/meta/field.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		class Field
			: public Expression
		{
			pgs::meta::FieldCPtr	_metaField;
			std::string				_srcAlias;
		public:
			Field();
			Field(pgs::meta::FieldCPtr fld);
			Field(const std::string srcAlias, pgs::meta::FieldCPtr fld);

			pgs::meta::FieldCPtr meta() const;
			const std::string &srcAlias() const;
		};
		typedef boost::shared_ptr<Field> Field_ptr;
	}
}

#endif
