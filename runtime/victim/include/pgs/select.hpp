#ifndef _PGS_SELECT_HPP_
#define _PGS_SELECT_HPP_

#include "pgs/category.hpp"
#include "pgs/expression.hpp"
#include "pgs/field.hpp"
#include "pgs/link.hpp"
#include "pgs/order.hpp"
#include "pgs/value.hpp"

namespace pgs
{

	//////////////////////////////////////////////////////////////////////////
	class Select
	{
		std::deque<Expression>	_what;

		Category				_from;
		std::deque<Link>		_links;

		Expression				_where;
		Expression				_limit;
		Expression				_offset;

		std::deque<Order>		_orders;

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
		bool compile(std::string &sql);
	};
}

#endif
