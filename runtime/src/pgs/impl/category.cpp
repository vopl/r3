#include "stdafx.h"
#include "category.hpp"
#include "pgs/meta/category.hpp"
#include "sdHelpers.hpp"

namespace pgs
{
	namespace impl
	{
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
			case ecmSelectFrom:
				{
					res += state._cluster->tableName(_metaCategory);
					res += " AS ";
					res += state._cluster->escapeName(_alias);

					state._aliases.insert(_alias);
				}
				break;
			case ecmSelectWhat:
				{
					//проверить наличие alias во from или links
					state.checkAliasExistence(_alias, true);

					std::string categoryAlias = state._cluster->escapeName(_alias);

					//tableoid
					res += categoryAlias;
					res += ".tableoid";
					// TRATATA тут фиксировать информацию для феча

					//перебрать все поля
					BOOST_FOREACH(meta::FieldCPtr mf, _metaCategory->_fields)
					{
						res += ", ";
						res += categoryAlias;
						res += ".";
						res += state._cluster->escapeName(mf->_name);

						// TRATATA тут фиксировать информацию для феча
					}
				}
				break;
			default:
				assert(0);
			}
		}

	}
}

