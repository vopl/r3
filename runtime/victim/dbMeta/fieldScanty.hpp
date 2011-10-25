#ifndef _DBMETA_FIELDSCANTY_HPP_
#define _DBMETA_FIELDSCANTY_HPP_

#include "dbMeta/field.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	//set, enum
	class FieldScantyValue
	{
	public:
		std::string _name;
		int			_key;
		std::string _shortDescription;
		std::string _longDescription;
	};

	//////////////////////////////////////////////////////////////////////////
	//set, enum
	class FieldScanty
		: Field
	{
	public:
		//значения
		FieldScantyValuePtrs _values;
	};

}

#endif
