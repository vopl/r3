#ifndef _PGS_SELECT_HPP_
#define _PGS_SELECT_HPP_

#include "pgs/expr.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class SelectImpl;
	typedef boost::shared_ptr<SelectImpl> SelectImpl_ptr;

	//////////////////////////////////////////////////////////////////////////
	class Select
	{
		SelectImpl_ptr _impl;
	public:
		Select(Expr what);
		~Select();

		Select &what(Expr e);
		Select &where(Expr e);
		Select &limit(Expr e);
		Select &offset(Expr e);
		Select &orderBy(Expr e);

		void compile();
	};


}
#endif
