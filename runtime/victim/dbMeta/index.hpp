#ifndef _DBMETA_INDEX_HPP_
#define _DBMETA_INDEX_HPP_

#include "dbMeta/common.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	enum EIndexType
	{
		eitTree,
		eitHash,
	};

	//////////////////////////////////////////////////////////////////////////
	class Index
	{
	public:
		//наименование
		std::string	_name;

		//тип индекса
		EIndexType	_type;

		//задействованные поля
		FieldPtrs	_fields;

		//объемлющая категория
		CategoryPtr	_category;
	};
}

#endif
