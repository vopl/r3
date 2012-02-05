#include "pch.h"
#include "valueImpl.hpp"
#include "utils/ntoa.hpp"
#include "sdHelpers.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	ValueImpl::ValueImpl(const std::string &alias)
		: _alias(alias)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &ValueImpl::alias() const
	{
		return _alias;
	}

	//////////////////////////////////////////////////////////////////////////
	void ValueImpl::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
	{
		switch(ecm)
		{
		case ecmSelectWhat:
		case ecmSelectWhere:
		case ecmSelectLimit:
		case ecmSelectOffset:
			{
				std::map<void *, size_t>::iterator iter = state._valueNumbers.find(this);
				if(state._valueNumbers.end() == iter)
				{
					iter = state._valueNumbers.insert(std::make_pair(this, state._valueNumbers.size()+1)).first;
				}

				res += "$";
				char tmp[64];
				res += utils::_ntoa(iter->second, tmp);

				state._bindName2idx[_alias] = iter->second;
			}
			break;
		default:
			assert(0);
		}
	}
}
