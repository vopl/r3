#ifndef _PGS_SELECT_HPP_
#define _PGS_SELECT_HPP_

#include "pgs/category.hpp"
#include "pgs/expression.hpp"
#include "pgs/field.hpp"
#include "pgs/link.hpp"
#include "pgs/order.hpp"
#include "pgs/variable.hpp"

namespace pgs
{

	//////////////////////////////////////////////////////////////////////////
	class Select
	{
		//для what либо категория либо поле
		struct CategoryOrField
		{
			bool		_isCategory;
			Category	_category;
			Field		_field;
			CategoryOrField(Category c);
			CategoryOrField(Field f);
		};

		std::deque<CategoryOrField>	_what;
		std::deque<Link>			_links;

		Expression					_where;
		Variable					_limit;
		Variable					_offset;

		std::deque<Order>			_orders;

	public:
		Select();

		Select &what(Category);
		Select &what(Field);
		Select &link(Link);
		Select &where(Expression);
		Select &limit(Variable);
		Select &offset(Variable);
		Select &order(Order);
	};
}

#endif
