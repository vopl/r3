#include "stdafx.h"
#include "pgs/select.hpp"
#include "impl/select.hpp"
#include "impl/access.hpp"
#include "impl/statement.hpp"


namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Select::Select()
		: _impl(new impl::Select)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::whats(Expression e)
	{
		_impl->whats(impl::Access<Expression>(e));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::from(Category c)
	{
		_impl->from(impl::Access<Category>(c));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::links(Link l)
	{
		_impl->links(impl::Access<Link>(l));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::where(Expression e)
	{
		_impl->where(impl::Access<Expression>(e));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::limit(Expression e)
	{
		_impl->limit(impl::Access<Expression>(e));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::offset(Expression e)
	{
		_impl->offset(impl::Access<Expression>(e));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::orders(Order o)
	{
		_impl->orders(impl::Access<Order>(o));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Statement Select::compile(Cluster cluster)
	{
		return Statement(_impl->compile(impl::Access<Cluster>(cluster).impl()));
	}

}
