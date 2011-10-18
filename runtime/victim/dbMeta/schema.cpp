#include "stdafx.h"
#include "dbMeta/schema.hpp"
#include "dbMeta/category.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	void Schema::init(const Manager *man)
	{
		init();

		BOOST_FOREACH(const CategoryPtr &cat, getCategories())
		{
			if(_mcategories.end() != _mcategories.find(cat->getName()))
			{
				throw std::logic_error("category "+cat->getName()+" already exists");
				return;
			}
			_mcategories[cat->getName()] = cat;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	const CategoryPtr Schema::getCategory(const std::string &name) const
	{
		TMCategories::const_iterator iter = _mcategories.find(name);
		if(_mcategories.end() == iter)
		{
			throw std::domain_error("category "+name+" absent");
			return NULL;
		}

		return iter->second;
	}
}
