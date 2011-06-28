#ifndef _PGS_VALUE_HPP_
#define _PGS_VALUE_HPP_

#include "pgs/atom.hpp"

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
	template <class CppType>
	class Value
		: public Atom<CppType>
	{
// 		union
// 		{
// 			char			_data[sizeof(CppType)];
// 			const CppType	*_ptr;
// 		} _value;
// 
// 		int		_dataMode;
	public:
		Value(const CppType *v=NULL, int dataMode = dsm_ptr|ddm_drop|dom_own);
		void set(const CppType *v=NULL, int dataMode = dsm_ptr|ddm_drop|dom_own);

		Value(const CppType &v, int dataMode = dsm_value);
		void set(const CppType &v, int dataMode = dsm_value);

		~Value();
	};

}
#endif
