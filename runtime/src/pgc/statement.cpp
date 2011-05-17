#include "pgc/statement.hpp"
#include "statementImpl.hpp"

namespace pgc
{
	void Statement::bindHelper(int typIdx, void const *data, size_t idx)
	{
		_impl->bind(typIdx, data, idx);
	}

	Statement::Statement(StatementImplPtr impl)
		: _impl(impl)
	{
	}
	Statement::~Statement()
	{
		_impl.reset();
	}

	Statement &Statement::sql(const char *csz)
	{
		_impl->sql(csz);
		return *this;
	}
	Result Statement::exec()
	{
		return Result(_impl->exec());
	}

}