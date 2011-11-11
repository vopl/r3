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
		Statement::Statement(pgc::Statement pg, const TMName2idx &name2idx)
			: _pg(pg)
			, _name2idx(name2idx)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		void Statement::bind(int typCpp, void const *valCpp, size_t idx)
		{
			_pg.bindNative(typCpp, valCpp, idx);
		}

		//////////////////////////////////////////////////////////////////////////
		void Statement::bind(int typCpp, void const *valCpp, const std::string &name)
		{
			_pg.bindNative(typCpp, valCpp, name2idx(name));
		}

		//////////////////////////////////////////////////////////////////////////
		void Statement::unbind(size_t idx)
		{
			_pg.unbind(idx);
		}

		//////////////////////////////////////////////////////////////////////////
		void Statement::unbind(const std::string &name)
		{
			_pg.unbind(name2idx(name));
		}

		//////////////////////////////////////////////////////////////////////////
		Result_ptr Statement::exec()
		{
			return Result_ptr(new Result(_pg.exec()));
		}

	}

}