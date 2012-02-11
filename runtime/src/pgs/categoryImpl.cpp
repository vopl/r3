#include "pch.hpp"
#include "categoryImpl.hpp"
#include "pgs/meta/category.hpp"
#include "sdHelpers.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	CategoryImpl::CategoryImpl(pgs::meta::CategoryCPtr cat, const std::string &alias)
		: _metaCategory(cat)
		, _alias(alias.empty()?cat->_name:alias)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	pgs::meta::CategoryCPtr CategoryImpl::meta() const
	{
		return _metaCategory;
	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &CategoryImpl::alias() const
	{
		return _alias;
	}

	//////////////////////////////////////////////////////////////////////////
	void CategoryImpl::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
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
				std::string fldName = categoryAlias + ".tableoid";
				state._fetchName2idx[fldName] = state._nextWhatColumnIndex++;

				res += fldName;

				//перебрать все поля
				BOOST_FOREACH(meta::FieldCPtr mf, _metaCategory->_fields)
				{
					fldName = categoryAlias + "." + state._cluster->escapeName(mf->_name);
					state._fetchName2idx[fldName] = state._nextWhatColumnIndex++;

					res += ", ";
					res += fldName;
				}
			}
			break;
		default:
			assert(0);
		}
	}
}

