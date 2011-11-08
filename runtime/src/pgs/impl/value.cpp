#include "stdafx.h"
#include "value.hpp"
#include "utils/ntoa.hpp"

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
			assert(0);
		}

	}
}
