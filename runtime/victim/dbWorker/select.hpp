#ifndef _DBWORKER_SELECT_HPP_
#define _DBWORKER_SELECT_HPP_

#include "dbWorker/category.hpp"
#include "dbWorker/expression.hpp"
#include "dbWorker/field.hpp"
#include "dbWorker/link.hpp"
#include "dbWorker/order.hpp"
#include "dbWorker/variable.hpp"

namespace dbWorker
{

	//////////////////////////////////////////////////////////////////////////
	class Select
	{
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
