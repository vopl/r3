#include "valueImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	void ValueImpl::reset()
	{
		if(_dataDeleter)
		{
			(this->*_dataDeleter)();
			_dataDeleter = NULL;
		}
		_data = NULL;
		_cdt = 0;
		_dataMode = 0;
	}


	//////////////////////////////////////////////////////////////////////////
	ValueImpl::ValueImpl()
		: _dataMode(0)
		, _data(NULL)
		, _cdt(0)
		, _dataDeleter(NULL)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ValueImpl::~ValueImpl()
	{
		reset();
	}

	//////////////////////////////////////////////////////////////////////////
	void ValueImpl::mkSql(std::string &result)
	{
		result += "v";
	}

}
