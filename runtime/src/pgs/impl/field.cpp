#include "stdafx.h"
#include "field.hpp"
#include "pgs/meta/category.hpp"
#include "sdHelpers.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		Field::Field(pgs::meta::FieldCPtr fld, const std::string alias)
			: _srcAlias(fld->_category->_name)
			, _metaField(fld)
			, _alias(alias)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Field::Field(const std::string srcAlias, pgs::meta::FieldCPtr fld, const std::string alias)
			: _srcAlias(srcAlias.empty()?fld->_category->_name:srcAlias)
			, _metaField(fld)
			, _alias(alias.empty()?fld->_name:alias)
		{

		}

		//////////////////////////////////////////////////////////////////////////
		pgs::meta::FieldCPtr Field::meta() const
		{
			return _metaField;
		}

		//////////////////////////////////////////////////////////////////////////
		const std::string &Field::srcAlias() const
		{
			return _srcAlias;
		}

		//////////////////////////////////////////////////////////////////////////
		const std::string &Field::alias() const
		{
			return _alias;
		}

		//////////////////////////////////////////////////////////////////////////
		void Field::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
		{
			switch(ecm)
			{
			case ecmSelectWhat:
			case ecmSelectWhere:
				{
					state.checkAliasExistence(_srcAlias, true);

					res += state._cluster->escapeName(_srcAlias);
					res += ".";
					res += state._cluster->escapeName(_metaField->_name);

					if(ecmSelectWhat == ecm && !_alias.empty() && _alias != _metaField->_name)
					{
						res += " AS ";
						res += state._cluster->escapeName(_alias);
					}
				}
				break;
			default:
				assert(0);
			}
		}

	}
}
