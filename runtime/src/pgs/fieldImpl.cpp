#include "stdafx.h"
#include "fieldImpl.hpp"
#include "pgs/meta/category.hpp"
#include "sdHelpers.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	FieldImpl::FieldImpl(pgs::meta::FieldCPtr fld, const std::string alias)
		: _srcAlias(fld->_category->_name)
		, _metaField(fld)
		, _alias(alias)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	FieldImpl::FieldImpl(const std::string srcAlias, pgs::meta::FieldCPtr fld, const std::string alias)
		: _srcAlias(srcAlias.empty()?fld->_category->_name:srcAlias)
		, _metaField(fld)
		, _alias(alias.empty()?fld->_name:alias)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	pgs::meta::FieldCPtr FieldImpl::meta() const
	{
		return _metaField;
	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &FieldImpl::srcAlias() const
	{
		return _srcAlias;
	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &FieldImpl::alias() const
	{
		return _alias;
	}

	//////////////////////////////////////////////////////////////////////////
	void FieldImpl::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
	{
		switch(ecm)
		{
		case ecmSelectWhere:
		case ecmSelectWhat:
			{
				state.checkAliasExistence(_srcAlias, true);

				std::string fldName;

				fldName += state._cluster->escapeName(_srcAlias);
				fldName += ".";
				fldName += state._cluster->escapeName(_metaField->_name);

				if(ecmSelectWhat == ecm && !_alias.empty() && _alias != _metaField->_name)
				{
					fldName += " AS ";
					fldName += state._cluster->escapeName(_alias);
				}
				res += fldName;

				if(ecmSelectWhat == ecm)
				{
					state._fetchName2idx[fldName] = state._nextWhatColumnIndex++;
				}
			}
			break;
		default:
			assert(0);
		}
	}
}
