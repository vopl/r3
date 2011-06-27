#ifndef _PGS_VALUE_HPP_
#define _PGS_VALUE_HPP_

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	class Value
		: public Atom<CppType>
	{
		Data<CppType> _data;
	public:
		Value(const CppType &ref)
			: _data(ref)
		{
		}
		Value(Data<CppType> data)
			: _data(data)
		{
		}
	};

}
#endif
