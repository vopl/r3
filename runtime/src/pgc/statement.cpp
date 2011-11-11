#include "pgc/statement.hpp"
#include "statementImpl.hpp"

namespace pgc
{
	void Statement::bindNative(int typCpp, void const *valCpp, size_t idx)
	{
		_impl->bind(typCpp, valCpp, idx);
	}

	Statement::Statement(StatementImplPtr impl)
		: _impl(impl)
	{
	}
	Statement::~Statement()
	{
		_impl.reset();
	}

	Statement &Statement::sql(const char *sql)
	{
		_impl->sql(sql);
		return *this;
	}
	Statement &Statement::sql(const std::string &sql)
	{
		_impl->sql(sql);
		return *this;
	}

	bool Statement::empty() const
	{
		return _impl->empty();
	}

	Statement &Statement::unbind(size_t idx)
	{
		_impl->unbind(idx);
		return *this;
	}
	Result Statement::exec()
	{
		return Result(ResultImplPtr(new ResultImpl(_impl->con(), _impl->exec())));
	}

}