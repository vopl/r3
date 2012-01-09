#ifndef _PGS_VALUEIMPL_HPP_
#define _PGS_VALUEIMPL_HPP_

#include "expressionImpl.hpp"
#include "pgs/value.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class ValueImpl
		: public ExpressionImpl
	{
		std::string				_alias;

	public:
		ValueImpl(const std::string &alias);

		const std::string &alias() const;

		virtual void compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm);
	};
	typedef boost::shared_ptr<ValueImpl> ValueImplPtr;
}
#endif
