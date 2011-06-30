#ifndef _PGS_STATEMENTIMPL_HPP_
#define _PGS_STATEMENTIMPL_HPP_

#include "valueImpl.hpp"
#include "fieldImpl.hpp"
#include <set>

namespace pgs
{
	class StatementImpl
	{
		std::set<ExprImpl_ptr>		_exprs;
		std::set<ValueImpl_ptr>		_values;
		std::set<FieldImpl_ptr>		_fields;

	public:
		StatementImpl();
		~StatementImpl();

		void addExpr(const ExprImpl_ptr &e);

		void compile();

		virtual void regValue(const ValueImpl_ptr &v);
		virtual void regField(const FieldImpl_ptr &f);
	};
}
#endif
