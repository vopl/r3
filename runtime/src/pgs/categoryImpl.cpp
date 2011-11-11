#include "stdafx.h"
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
				//��������� ������� alias �� from ��� links
				state.checkAliasExistence(_alias, true);

				std::string categoryAlias = state._cluster->escapeName(_alias);

				//tableoid
				res += categoryAlias;
				res += ".tableoid";
				// TRATATA ��� ����������� ���������� ��� ����

				//��������� ��� ����
				BOOST_FOREACH(meta::FieldCPtr mf, _metaCategory->_fields)
				{
					res += ", ";
					res += categoryAlias;
					res += ".";
					res += state._cluster->escapeName(mf->_name);

					// TRATATA ��� ����������� ���������� ��� ����
				}
			}
			break;
		default:
			assert(0);
		}
	}
}

