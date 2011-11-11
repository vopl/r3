#ifndef _PGS_SELECT_HPP_
#define _PGS_SELECT_HPP_

#include "pgs/category.hpp"
#include "pgs/expression.hpp"
#include "pgs/field.hpp"
#include "pgs/link.hpp"
#include "pgs/order.hpp"
#include "pgs/value.hpp"
#include "pgs/cluster.hpp"
#include "pgs/statement.hpp"

namespace pgs
{

	class SelectImpl;
	typedef boost::shared_ptr<SelectImpl> SelectImpl_ptr;

	//////////////////////////////////////////////////////////////////////////
	class Select
	{
		typedef SelectImpl_ptr Impl_ptr;
		Impl_ptr	_impl;

	public:
		Select();

		Select &whats(Expression);

		Select &from(Category);
		Select &links(Link);
		Select &where(Expression);

		Select &limit(Expression);
		Select &offset(Expression);
		Select &orders(Order);

	public:
		Statement compile(Cluster cluster);
	};
}

#endif
