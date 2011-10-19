#ifndef _DBMETA_CATEGORY_HPP_
#define _DBMETA_CATEGORY_HPP_

#include "dbMeta/common.hpp"

namespace dbMeta
{
	class Category
	{
	protected:
		Category(
			const SchemaPtr _schema,
			const bool _isAbstract,
			const std::string _name,
			const FieldPtrs _fields,
			const IndexPtrs _indices,
			const RelationEndPtrs _relations);

	public:
		const SchemaPtr			_schema;
		const bool				_isAbstract;
		const std::string		_name;
		const FieldPtrs			_fields;
		const IndexPtrs			_indices;
		const RelationEndPtrs	_relationEnds;

		const FieldPtr	getField(const std::string &name);
	};
}

#endif
