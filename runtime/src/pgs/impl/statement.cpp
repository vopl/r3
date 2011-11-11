#include "stdafx.h"
#include "statement.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		size_t Statement::name2idx(const std::string &name)
		{
			TMName2idx::iterator iter = _name2idx.find(name);
			if(_name2idx.end() == iter)
			{
				assert(!"bad name");
				throw "bad name";
				return -1;
			}
			return iter->second;
		}

		//////////////////////////////////////////////////////////////////////////
		Statement::Statement(pgc::ConnectionImplPtr con, const TMName2idx &name2idx)
			: pgc::StatementPrepImpl(con)
			, _name2idx(name2idx)
		{
		}

	}
}