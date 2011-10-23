#ifndef _DBMETA_CATEGORY_HPP_
#define _DBMETA_CATEGORY_HPP_

#include "dbMeta/common.hpp"

namespace dbMeta
{
	class Category
	{
	protected:
		Category(
			const Schema &schema,
			const bool isAbstract,
			const std::string &name,
			const FieldPtrs fields,
			const IndexPtrs indices,
			const RelationEndPtrs relationEnds);

	public:
		const Schema &			_schema;
		const bool				_isAbstract;
		const std::string		_name;
		const FieldPtrs			_fields;
		const IndexPtrs			_indices;
		const RelationEndPtrs	_relationEnds;
	};
}

#endif
