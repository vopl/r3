#ifndef _PGS_VALUEIMPL_HPP_
#define _PGS_VALUEIMPL_HPP_

#include "exprImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class ValueImpl
		: public ExprImpl
	{
	public:
		ValueImpl();

		template <class CppType>
		ValueImpl(const CppType *v, int dataMode = dsm_ptr|ddm_drop|dom_own);

		template <class CppType>
		void set(const CppType *v=NULL, int dataMode = dsm_ptr|ddm_drop|dom_own);

		template <class CppType>
		ValueImpl(const CppType &v, int dataMode = dsm_value);

		template <class CppType>
		void set(const CppType &v, int dataMode = dsm_value);

		~ValueImpl();
	};



	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	ValueImpl::ValueImpl(const CppType *v, int dataMode)
	{
		assert(0);
	}

	template <class CppType>
	void ValueImpl::set(const CppType *v, int dataMode)
	{
		assert(0);
	}

	template <class CppType>
	ValueImpl::ValueImpl(const CppType &v, int dataMode)
	{
		assert(0);
	}

	template <class CppType>
	void ValueImpl::set(const CppType &v, int dataMode)
	{
		assert(0);
	}


}
#endif
