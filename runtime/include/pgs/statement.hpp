#ifndef _PGS_STATEMENT_HPP_
#define _PGS_STATEMENT_HPP_

#include "pgs/result.hpp"
#include <boost/shared_ptr.hpp>
#include "pgc/cppDataType.hpp"

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
		: public pgc::Statement
	{
	protected:
		typedef impl::Statement_ptr Impl_ptr;

		friend class Select;
		Statement(Impl_ptr impl);
	public:

		using pgc::Statement::bind;
		using pgc::Statement::bindNative;
		using pgc::Statement::unbind;

		void bindNative(int typCpp, void const *valCpp, const char *name);
		template <class T> Statement &bind(T const &v, const char *name);
		template <class T> Statement &bind(T const *pv, const char *name);
		Statement &unbind(const char *name);

		Result exec();
	};

	//////////////////////////////////////////////////////////////////////////
	template <class T> Statement &Statement::bind(T const &v, const char *name)
	{
		bindNative(pgc::CppDataType<T>::cdt_index, &v, name);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class T> Statement &Statement::bind(T const *pv, const char *name)
	{
		bindNative(pgc::CppDataType<T>::cdt_index, pv, name);
		return *this;
	}


}
#endif
