#include "stdafx.h"
#include "dbWorker/select.hpp"
#include "dbMeta/cluster.hpp"

namespace dbWorker
{
	//////////////////////////////////////////////////////////////////////////
	Select::CategoryOrField::CategoryOrField(Category c)
		: _isCategory(true)
		, _category(c)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Select::CategoryOrField::CategoryOrField(Field f)
		: _isCategory(false)
		, _field(f)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Select::Select()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::what(Category c)
	{
		_what.push_back(c);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::what(Field f)
	{
		_what.push_back(f);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::link(Link l)
	{
		//проверить что исходная категория присутствует во what
		bool present = false;
		BOOST_FOREACH(CategoryOrField cof, _what)
		{
			if(cof._isCategory)
			{
				if(l.meta()->_category == cof._category.meta())
				{
					present = true;
					break;
				}
			}
			else
			{
				if(l.meta()->_category == cof._field.meta()->_category)
				{
					present = true;
					break;
				}
			}
		}

		//_what.push_back(Category(l.meta()->_anotherEnd->_category));

		if(!present)
		{
			assert(!"link source category absent in 'what'");
			throw "link source category absent in 'what'";
			return *this;
		}

		_links.push_back(l);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::where(Expression e)
	{
		//перебрать дерево выражения, проверить наличие всех полей, собрать все переменные
		_where = e;
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::limit(Variable v)
	{
		_limit = v;
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::offset(Variable v)
	{
		_offset = v;
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Select &Select::order(Order o)
	{
		_orders.push_back(o);
		return *this;
	}
}
