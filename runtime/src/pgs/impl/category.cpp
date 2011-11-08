#include "stdafx.h"
#include "category.hpp"
#include "pgs/meta/category.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		Category::Category()
			: _metaCategory()
			, _alias()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Category::Category(pgs::meta::CategoryCPtr cat, const std::string &alias)
			: _metaCategory(cat)
			, _alias(alias.empty()?cat->_name:alias)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		pgs::meta::CategoryCPtr Category::meta() const
		{
			return _metaCategory;
		}

		//////////////////////////////////////////////////////////////////////////
		const std::string &Category::alias() const
		{
			return _alias;
		}

		//////////////////////////////////////////////////////////////////////////
		void Category::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
		{
			switch(ecm)
			{
			case ecmSelectWhat:
				{
					//проверить наличие alias во from или links
					state.checkAliasExistence(_alias, true);

					std::string categoryAlias = state._cluster->escapeName(_alias);

					std::string sql;
					//tableoid
					sql += categoryAlias;
					sql += ".tableoid";
					// TRATATA тут фиксировать информацию для феча

					//перебрать все поля
					BOOST_FOREACH(meta::FieldCPtr mf, _metaCategory->_fields)
					{
						sql += ", ";
						sql += categoryAlias;
						sql += ".";
						sql += state._cluster->escapeName(mf->_name);
						// TRATATA тут фиксировать информацию для феча
					}

					res.push_back(sql);

				}
				break;
			default:
				assert(0);
			}
		}

	}
}

