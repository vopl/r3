#ifndef _PGS_META_RELATIONEND_HPP_
#define _PGS_META_RELATIONEND_HPP_

#include "pgs/meta/common.hpp"

namespace pgs
{
	namespace meta
	{
		enum ERelationMult
		{
			ermMany,
			ermOne
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
}

#endif
