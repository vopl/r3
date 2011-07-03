#ifndef _PGS_SELECTIMPL_HPP_
#define _PGS_SELECTIMPL_HPP_

#include "statementImpl.hpp"

namespace pgs
{
	class SelectImpl
		: public StatementImpl
	{
	public:
		SelectImpl();
		~SelectImpl();

		void setWhat(const ExprImpl_ptr &e);
		void setWhere(const ExprImpl_ptr &e);
		void setLimit(const ExprImpl_ptr &e);
		void setOffset(const ExprImpl_ptr &e);

		void setOrderBy(const ExprImpl_ptr &e);
	};
}
#endif
