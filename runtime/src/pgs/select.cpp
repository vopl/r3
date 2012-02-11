#include "pch.hpp"
#include "pgs/select.hpp"
#include "selectImpl.hpp"
#include "utils/implAccess.hpp"
#include "statementImpl.hpp"
#include "categoryImpl.hpp"


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
		_impl->whats(utils::ImplAccess<Expression>(e));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::from(Category c)
	{
		_impl->from(utils::ImplAccess<Category>(c));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::links(Link l)
	{
		_impl->links(utils::ImplAccess<Link>(l));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::where(Expression e)
	{
		_impl->where(utils::ImplAccess<Expression>(e));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::limit(Expression e)
	{
		_impl->limit(utils::ImplAccess<Expression>(e));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::offset(Expression e)
	{
		_impl->offset(utils::ImplAccess<Expression>(e));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::orders(Order o)
	{
		_impl->orders(utils::ImplAccess<Order>(o));
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Statement Select::compile(Cluster cluster)
	{
		return Statement(_impl->compile(utils::ImplAccess<Cluster>(cluster).impl()));
	}

}
