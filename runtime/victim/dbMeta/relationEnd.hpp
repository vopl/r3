#ifndef _DBMETA_RELATIONEND_HPP_
#define _DBMETA_RELATIONEND_HPP_

#include "dbMeta/common.hpp"

namespace dbMeta
{
	enum ERelationMult
	{
		ermMany,
		ermOne,
	};

	//////////////////////////////////////////////////////////////////////////
	class RelationEnd
	{
	public:
		//наименование
		std::string		_name;

		//множитель
		ERelationMult	_mult;

		//связанная категория
		CategoryPtr		_category;

		//объемлющая связь
		RelationPtr		_relation;

	};
}

#endif
