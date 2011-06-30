#ifndef _PGS_VALUE_HPP_
#define _PGS_VALUE_HPP_

#include "pgs/expr.hpp"

namespace pgs
{
	enum EDataMode
	{
		//владеет копией объекта
		dm_isCopy = 1,

		//надо разрушать при отсвобождении
		dm_doDeleteOnFree = 2,

		//надо освобождать после первого использования
		dm_doFreeAfterUse = 4,
	};

	//////////////////////////////////////////////////////////////////////////
	class Value
		: public Expr
	{
	public:
		Value();

		template <class CppType>
		Value(const CppType *v, int dataMode = dm_doFreeAfterUse);

		template <class CppType>
		void set(const CppType *v=NULL, int dataMode = dm_doFreeAfterUse);

		template <class CppType>
		Value(const CppType &v, int dataMode = dm_doFreeAfterUse);

		template <class CppType>
		void set(const CppType &v, int dataMode = dm_doFreeAfterUse);

		~Value();
	};

}
#endif
