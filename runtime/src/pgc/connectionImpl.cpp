#include "pch.h"
#include "connectionImpl.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	ConnectionImpl::ConnectionImpl(ConnectionHolderPtr holder)
		: _holder(holder)
	{
		_holder->beginWork();
	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionImpl::~ConnectionImpl()
	{
		_holder->endWork();
	}
}
