#ifndef _DBMETA_FIELD_HPP_
#define _DBMETA_FIELD_HPP_

#include "dbMeta/common.hpp"

namespace dbMeta
{
	enum EFieldType
	{
		eftAudio,
		eftBinary,
		eftBool,
		eftDate,
		eftDateTimeInterval,
		eftEnum,
		eftFile,
		eftImage,
		eftInt16,
		eftInt32,
		eftInt64,
		eftInt8,
		eftMoney,
		eftReal32,
		eftReal64,
		eftSet,
		eftString,
		eftTime,
		eftTimestamp,
		eftVideo,
	};

	//////////////////////////////////////////////////////////////////////////
	class Field
	{
	protected:
		Field(
			const Category &category,
			const EFieldType type,
			const std::string &name,
			const bool allowNull);

	public:
		const Category &	_category;
		const EFieldType	_type;
		const std::string	_name;
		const bool			_allowNull;
	};
}

#endif
