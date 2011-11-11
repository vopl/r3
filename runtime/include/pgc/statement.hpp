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
	protected:
		friend class Connection;
		StatementImplPtr _impl;
		Statement(StatementImplPtr impl);

	public:
		~Statement();

		Statement &sql(const char *csz);
		Statement &sql(const std::string &sql);

		bool empty() const;

		void bindNative(int typCpp, void const *valCpp, size_t idx);

		template <class T> Statement &bind(T const &v, size_t idx=0);
		template <class T> Statement &bind(T const *pv, size_t idx=0);
		template <class T> Statement &bind(T &v, size_t idx=0);
		template <class T> Statement &bind(T *pv, size_t idx=0);
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
		bindNative(CppDataType<T>::cdt_index, &v, idx);
		return *this;
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class T> Statement &Statement::bind(T const *pv, size_t idx)
	{
		bindNative(CppDataType<T>::cdt_index, pv, idx);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class T> Statement &Statement::bind(T &v, size_t idx)
	{
		bindNative(CppDataType<T>::cdt_index, &v, idx);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class T> Statement &Statement::bind(T *pv, size_t idx)
	{
		bindNative(CppDataType<T>::cdt_index, pv, idx);
		return *this;
	}

}
#endif
