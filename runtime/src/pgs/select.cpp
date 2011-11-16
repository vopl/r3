#include "stdafx.h"
#include "pgs/select.hpp"
#include "selectImpl.hpp"
#include "implAccess.hpp"
#include "statementImpl.hpp"


namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Select::Select()
		: _impl(new SelectImpl)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::whats(Expression e)
	{
		_impl->whats(ImplAccess<Expression>(e));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::from(Category c)
	{
		_impl->from(ImplAccess<Category>(c));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::links(Link l)
	{
		_impl->links(ImplAccess<Link>(l));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::where(Expression e)
	{
		_impl->where(ImplAccess<Expression>(e));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::limit(Expression e)
	{
		_impl->limit(ImplAccess<Expression>(e));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::offset(Expression e)
	{
		_impl->offset(ImplAccess<Expression>(e));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::orders(Order o)
	{
		_impl->orders(ImplAccess<Order>(o));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Statement Select::compile(Cluster cluster)
	{
		return Statement(_impl->compile(ImplAccess<Cluster>(cluster).impl()));
	}

}
