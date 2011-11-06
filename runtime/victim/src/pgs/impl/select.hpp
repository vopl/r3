#ifndef _PGS_IMPL_SELECT_HPP_
#define _PGS_IMPL_SELECT_HPP_

#include "category.hpp"
#include "expression.hpp"
#include "field.hpp"
#include "link.hpp"
#include "order.hpp"
#include "value.hpp"

namespace pgs
{
	namespace impl
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
}

#endif
