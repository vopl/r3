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
			std::string				_alias;
		public:
			Field(pgs::meta::FieldCPtr fld, const std::string alias);
			Field(const std::string srcAlias, pgs::meta::FieldCPtr fld, const std::string alias);

			pgs::meta::FieldCPtr meta() const;
			const std::string &srcAlias() const;
			const std::string &alias() const;

			virtual void compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm);
		};
		typedef boost::shared_ptr<Field> Field_ptr;
	}
}

#endif
