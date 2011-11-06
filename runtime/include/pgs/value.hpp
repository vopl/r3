#ifndef _PGS_VALUE_HPP_
#define _PGS_VALUE_HPP_

#include "pgs/expression.hpp"

namespace pgs
{
	enum EValueDataMode
	{
		vdm_null = 0,

		//владеет копией объекта
		vdm_makeCopy = 1,

		//надо разрушать при отсвобождении
		vdm_doDeleteOnFree = 4,
	};

	//////////////////////////////////////////////////////////////////////////
	class Value
		: public Expression
	{
	public:
		Value();
		~Value();

		template <class CppType>
		Value(const CppType *v, EValueDataMode vdm = vdm_doDeleteOnFree);

		template <class CppType>
		Value(const CppType &v, EValueDataMode vdm = vdm_null);

		template <class CppType>
		void set(const CppType *v, EValueDataMode vdm = vdm_doDeleteOnFree);

		template <class CppType>
		void set(const CppType &v, EValueDataMode vdm = vdm_null);

		void reset();
	};
}

#endif
