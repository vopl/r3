#ifndef _PGS_STATEMENT_HPP_
#define _PGS_STATEMENT_HPP_

#include "pgs/result.hpp"
#include <boost/shared_ptr.hpp>

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	namespace impl
	{
		class Statement;
		typedef boost::shared_ptr<Statement> Statement_ptr;
	}

	//////////////////////////////////////////////////////////////////////////
	class Statement
	{
	protected:
		typedef impl::Statement_ptr Impl_ptr;
		Impl_ptr _impl;

		void bindNative(int typCpp, void const *valCpp, size_t idx);
		void bindNative(int typCpp, void const *valCpp, const std::string &name);

	public:
		Statement(const Impl_ptr &impl);

		template <class T> Statement &bind(T const &v, size_t idx=0);
		template <class T> Statement &bind(T const *pv, size_t idx=0);
		Statement &unbind(size_t idx=0);
		template <class T> Statement &bind(T const &v, const std::string &name);
		template <class T> Statement &bind(T const *pv, const std::string &name);
		Statement &unbind(const std::string &name);

		Result exec();
	};

	//////////////////////////////////////////////////////////////////////////
	template <class T> Statement &Statement::bind(T const &v, size_t idx)
	{
		bindNative(pgc::CppDataType<T>::cdt_index, &v, idx);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class T> Statement &Statement::bind(T const *pv, size_t idx)
	{
		bindNative(pgc::CppDataType<T>::cdt_index, pv, idx);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class T> Statement &Statement::bind(T const &v, const std::string &name)
	{
		bindNative(pgc::CppDataType<T>::cdt_index, &v, name);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class T> Statement &Statement::bind(T const *pv, const std::string &name)
	{
		bindNative(pgc::CppDataType<T>::cdt_index, pv, name);
		return *this;
	}

}
#endif
