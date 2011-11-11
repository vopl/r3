#ifndef _PGS_FIELD_HPP_
#define _PGS_FIELD_HPP_

#include "pgs/expression.hpp"
#include "meta/common.hpp"

namespace pgs
{
	class FieldImpl;
	typedef boost::shared_ptr<FieldImpl> FieldImpl_ptr;

	//////////////////////////////////////////////////////////////////////////
	class Field
		: public Expression
	{
		typedef FieldImpl_ptr Impl_ptr;

	public:
		Field(pgs::meta::FieldCPtr fld, const std::string &alias="");
		Field(const std::string &srcAlias, pgs::meta::FieldCPtr fld, const std::string &alias="");

		pgs::meta::FieldCPtr meta() const;
		const std::string &srcAlias() const; 
		const std::string &alias() const; 
	};
}

#endif
