#ifndef _PGS_VALUE_HPP_
#define _PGS_VALUE_HPP_

#include "pgs/expr.hpp"

namespace pgs
{
	enum EDataStorageMode
	{
		dsm_ptr=0,
		dsm_value=1,
	};

	enum EDataDropMode
	{
		ddm_drop=0,
		ddm_nodrop=1,
	};

	enum EDataOwnerMode
	{
		dom_own=0,
		dom_alien=4,
	};

	//////////////////////////////////////////////////////////////////////////
	class Value
		: public Expr
	{
	public:
		Value();

		template <class CppType>
		Value(const CppType *v, int dataMode = dsm_ptr|ddm_drop|dom_own);

		template <class CppType>
		void set(const CppType *v=NULL, int dataMode = dsm_ptr|ddm_drop|dom_own);

		template <class CppType>
		Value(const CppType &v, int dataMode = dsm_value);

		template <class CppType>
		void set(const CppType &v, int dataMode = dsm_value);

		~Value();
	};

}
#endif
