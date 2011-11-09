#include "stdafx.h"
#include "link.hpp"
#include "pgs/meta/category.hpp"
#include "utils/ntoa.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		Link::Link(pgs::meta::RelationEndCPtr re, const std::string &alias)
			: _srcAlias(re->_category->_name)
			, _metaRelatioEnd(re)
			, _alias(alias.empty()?re->_name:alias)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Link::Link(const std::string &srcAlias, pgs::meta::RelationEndCPtr re, const std::string &alias)
			: _srcAlias(srcAlias.empty()?re->_category->_name:srcAlias)
			, _metaRelatioEnd(re)
			, _alias(alias.empty()?re->_name:alias)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		pgs::meta::RelationEndCPtr Link::meta() const
		{
			return _metaRelatioEnd;
		}

		//////////////////////////////////////////////////////////////////////////
		const std::string &Link::srcAlias() const
		{
			return _srcAlias;
		}

		//////////////////////////////////////////////////////////////////////////
		const std::string &Link::alias() const
		{
			return _alias;
		}

		//////////////////////////////////////////////////////////////////////////
		void Link::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
		{
			switch(ecm)
			{
			case ecmSelectLink:
				{
					//проверить наличие srcAlias во from или уже реализованых link
					state.checkAliasExistence(_srcAlias, true);

					//проверить отсутствие alias во from или уже реализованых link
					state.checkAliasExistence(_alias, false);

					std::string srcAlias = state._cluster->escapeName(_srcAlias);
					std::string alias = state._cluster->escapeName(_alias);
					std::string crossTable = state._cluster->tableName(_metaRelatioEnd->_relation);
					char tmp[64];
					std::string crossAlias = state._cluster->escapeName(std::string("___cross_")+utils::_ntoa(state._nextCrossIndex++, tmp));
					std::string foreignTable = state._cluster->tableName(_metaRelatioEnd->_anotherEnd->_category);

					std::string sql;
					sql += "LEFT OUTER JOIN ";
					sql += crossTable;
					sql += " AS ";
					sql += crossAlias;
					sql += " ON (";

					sql += srcAlias;
					sql += ".id";
					sql += "=";
					sql += crossAlias;
					sql += ".";
					sql += _metaRelatioEnd->_isInput?"output_id":"input_id";



					sql += ") LEFT OUTER JOIN ";
					sql += foreignTable;
					sql += " AS ";
					sql += alias;

					sql += " ON(";

					sql += crossAlias;
					sql += ".";
					sql += _metaRelatioEnd->_isInput?"input_id":"output_id";
					sql += "=";
					sql += alias;
					sql += ".id";


					sql += ")";


					res.push_back(sql);
					state._aliases.insert(_alias);
				}
				break;
			default:
				assert(0);
			}
		}

	}
}
