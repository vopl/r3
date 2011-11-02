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

		//признак первого конца
		bool			_isInput;

		//множитель
		ERelationMult	_mult;

		//связанная категория
		CategoryPtr		_category;
		CategoryPtrs	_categories;

		//второй край
		RelationEndPtr	_anotherEnd;

		//объемлющая связь
		RelationPtr		_relation;

	};
}

#endif
