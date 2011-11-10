#include "stdafx.h"
#include "value.hpp"
#include "utils/ntoa.hpp"
#include "sdHelpers.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		void Value::reset()
		{
			if(_dataDeleter)
			{
				(this->*_dataDeleter)();
				_dataDeleter = NULL;
			}
			_data = NULL;
			_cdt = 0;
			_vdm = vdm_null;
		}

		//////////////////////////////////////////////////////////////////////////
		Value::Value()
			: _vdm(vdm_null)
			, _data(NULL)
			, _cdt(0)
			, _dataDeleter(NULL)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Value::~Value()
		{
			reset();
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
