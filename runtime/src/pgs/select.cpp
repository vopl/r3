#include "pgs/select.hpp"
#include "selectImpl.hpp"
#include "exprAccess.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Select::Select(Expr w)
		: _impl(new SelectImpl())
	{
		what(w);
	}

	//////////////////////////////////////////////////////////////////////////
	Select::~Select()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::what(Expr e)
	{
		_impl->setWhat(ExprAccess(e));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::where(Expr e)
	{
		_impl->setWhere(ExprAccess(e));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::limit(Expr e)
	{
		_impl->setLimit(ExprAccess(e));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::offset(Expr e)
	{
		_impl->setOffset(ExprAccess(e));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::orderBy(Expr e)
	{
		_impl->setOrderBy(ExprAccess(e));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	void Select::compile()
	{
		_impl->compile();
	}

}
