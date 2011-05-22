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

		void bindHelper(int typCpp, void const *valCpp, size_t idx);

	public:
		~Statement();

		Statement &sql(const char *csz);

		template <class T> Statement &bind(T const &v, size_t idx=0);
		Statement &unbind(size_t idx=0);

		Result exec();

		template <class T1>
		Result exec(T1 const &b1)
		{
			unbind();
			bind(b1,1);
			return exec();
		}

		template <class T1, class T2>
		Result exec(T1 const &b1, T2 const &b2)
		{
			unbind();
			bind(b2, 2);
			bind(b1, 1);
			return exec();
		}

		template <class T1, class T2, class T3>
		Result exec(T1 const &b1, T2 const &b2, T3 const &b3)
		{
			unbind();
			bind(b3,3);
			bind(b2,2);
			bind(b1,1);
			return exec();
		}

		template <class T1, class T2, class T3, class T4>
		Result exec(T1 const &b1, T2 const &b2, T3 const &b3, T4 const &b4)
		{
			unbind();
			bind(b4,4);
			bind(b3,3);
			bind(b2,2);
			bind(b1,1);
			return exec();
		}

	};

	//////////////////////////////////////////////////////////////////////////
	template <class T> Statement &Statement::bind(T const &v, size_t idx)
	{
		bindHelper(CppDataType<T>::cdt_index, &v, idx);
		return *this;
	}

}
#endif
