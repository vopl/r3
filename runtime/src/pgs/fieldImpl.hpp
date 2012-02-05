#ifndef _PGS_FIELDIMPL_HPP_
#define _PGS_FIELDIMPL_HPP_

#include "expressionImpl.hpp"
#include "pgs/meta/field.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class FieldImpl
		: public ExpressionImpl
	{
		pgs::meta::FieldCPtr	_metaField;
		std::string				_srcAlias;
		std::string				_alias;
	public:
		FieldImpl(pgs::meta::FieldCPtr fld, const std::string &alias);
		FieldImpl(const std::string &srcAlias, pgs::meta::FieldCPtr fld, const std::string &alias);

		pgs::meta::FieldCPtr meta() const;
		const std::string &srcAlias() const;
		const std::string &alias() const;

		virtual void compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm);
	};
	typedef boost::shared_ptr<FieldImpl> FieldImplPtr;
}

#endif
