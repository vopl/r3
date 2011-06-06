#ifndef _R3_TUPLEBASE_HPP_
#define _R3_TUPLEBASE_HPP_

#include "r3/fields/field.h"

namespace r3
{
	template <class T>
	struct TupleBase
	{
		boost::uint32_t tableoid;
		fields::Id id;

		TupleBase();
		~TupleBase();
	};

	//////////////////////////////////////////////////////////////////////////
	template <class T>
	inline TupleBase<T>::TupleBase()
		: tableoid(0)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class T>
	inline TupleBase<T>::~TupleBase()
	{

	}
}



#endif
