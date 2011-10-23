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
	protected:
		Index(
			const Category &category,
			const EIndexType type,
			const std::string &name,
			const FieldPtrs fields);

	public:
		const CategoryPtr	_category;
		const EIndexType	_type;
		const std::string	_name;
		const FieldPtrs		_fields;
	};
}

#endif
