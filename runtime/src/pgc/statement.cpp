#include "pgc/statement.hpp"
#include "statementImpl.hpp"

namespace pgc
{
	void Statement::bindHelper(int typCpp, void const *valCpp, size_t idx)
	{
		_impl->bind(typCpp, valCpp, idx);
	}

	Statement::Statement(StatementImplPtr impl)
		: _impl(impl)
	{
	}
	Statement::Statement()
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
	Statement &Statement::unbind(size_t idx)
	{
		_impl->unbind(idx);
		return *this;
	}
	Result Statement::exec()
	{
		return Result(_impl->exec());
	}

}