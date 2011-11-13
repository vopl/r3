#include "pgc/statement.hpp"
#include "statementImpl.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	bool Statement::bindNative(int typCpp, void const *valCpp, size_t idx)
	{
		return _impl->bind(typCpp, valCpp, idx);
	}

	//////////////////////////////////////////////////////////////////////////
	Statement::Statement(StatementImplPtr impl)
		: _impl(impl)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Statement::~Statement()
	{
		_impl.reset();
	}

	//////////////////////////////////////////////////////////////////////////
	Statement &Statement::sql(const char *sql)
	{
		_impl->sql(sql);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Statement &Statement::sql(const std::string &sql)
	{
		_impl->sql(sql);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Statement::empty() const
	{
		return _impl->empty();
	}

	//////////////////////////////////////////////////////////////////////////
	Statement &Statement::bind(const utils::Variant &v, size_t idx)
	{
		if(!bindNative(v.type(), v.data(), idx))
		{
			throw std::invalid_argument("for Statement::bind");
		}
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Statement &Statement::bindMany(const utils::Variant::VectorVariant &v, size_t idx)
	{
		utils::Variant::VectorVariant::const_iterator iter = v.begin();
		utils::Variant::VectorVariant::const_iterator end = v.end();

		for(; iter!=end; iter++)
		{
			if(!bindNative(iter->type(), iter->data(), idx))
			{
				throw std::invalid_argument("for Statement::bindMany");
			}
			if(idx)
			{
				idx++;
			}
		}
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Statement &Statement::unbind(size_t idx)
	{
		_impl->unbind(idx);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Result Statement::exec()
	{
		return Result(ResultImplPtr(new ResultImpl(_impl->con(), _impl->exec())));
	}

}