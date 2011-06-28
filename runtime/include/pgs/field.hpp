#ifndef _PGS_FIELD_HPP_
#define _PGS_FIELD_HPP_

#include "pgs/atom.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	class Field
		: public Atom<CppType>
	{

// 		string _table;
// 		string _name;
	public:
		Field(const char *field, const char *table, const char *schema, const char *tableId=NULL);
		~Field();
	};

}
#endif
