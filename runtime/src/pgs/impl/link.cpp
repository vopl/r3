#include "stdafx.h"
#include "link.hpp"
#include "pgs/meta/category.hpp"

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
			default:
				assert(0);
			}
		}

	}
}
