#include "valueImpl.hpp"
#include "statementImpl.hpp"
#include "utils/ntoa.hpp"

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
		, _number(0)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ValueImpl::~ValueImpl()
	{
		reset();
	}

	//////////////////////////////////////////////////////////////////////////
	void ValueImpl::setNumber(size_t num)
	{
		_number = num;
	}


	//////////////////////////////////////////////////////////////////////////
	void ValueImpl::reg(StatementImpl *s)
	{
		s->regValue(boost::shared_static_cast<ValueImpl>(shared_from_this()));
	}

	//////////////////////////////////////////////////////////////////////////
	void ValueImpl::mkSql(std::string &result)
	{
		result += "$";
		char buf[32];
		result += utils::_ntoa(_number, buf);
	}

}
