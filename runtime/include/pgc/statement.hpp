#ifndef _PGC_STATEMENT_HPP_
#define _PGC_STATEMENT_HPP_

#include "pgc/cppDataType.hpp"
#include "pgc/result.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	class StatementImpl;
	typedef boost::shared_ptr<StatementImpl> StatementImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class Statement
	{
		StatementImplPtr _impl;
	protected:
		friend class Connection;
		Statement(StatementImplPtr impl);

		void bindHelper(int typIdx, void const *data, size_t idx);

	public:
		~Statement();

		Statement &sql(const char *csz);

		template <class T> Statement &bind(T const &v, size_t idx=0);

		Result exec();
	};

	//////////////////////////////////////////////////////////////////////////
	template <class T> Statement &Statement::bind(T const &v, size_t idx)
	{
		bindHelper(CppDataType<T>::cdt_index, &v, idx);
		return *this;
	}

}
#endif
