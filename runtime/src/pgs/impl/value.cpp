#include "stdafx.h"
#include "value.hpp"
#include "utils/ntoa.hpp"
#include "sdHelpers.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		Value::Value(const std::string &alias, const std::string &srcAlias)
			: _alias(alias)
			, _srcAlias(srcAlias)
		{

		}

		//////////////////////////////////////////////////////////////////////////
		const std::string &Value::srcAlias() const
		{
			return _srcAlias;
		}

		//////////////////////////////////////////////////////////////////////////
		const std::string &Value::alias() const
		{
			return _alias;
		}

		//////////////////////////////////////////////////////////////////////////
		void Value::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
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
				}
				break;
			default:
				assert(0);
			}
		}

	}
}
