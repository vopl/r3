#ifndef _PGS_META_INDEX_HPP_
#define _PGS_META_INDEX_HPP_

#include "pgs/meta/common.hpp"

namespace pgs
{
	namespace meta
	{
		//////////////////////////////////////////////////////////////////////////
		enum EIndexType
		{
			eitTree,
			eitHash
		};

		//////////////////////////////////////////////////////////////////////////
		class Index
		{
		public:
			//наименование
			std::string		_name;

			//тип индекса
			EIndexType		_type;

			//задействованные поля
			FieldPtrs		_fields;

			//объемлющая категория
			CategoryPtr		_category;
			CategoryPtrs	_categories;
		};
	}
}

#endif
