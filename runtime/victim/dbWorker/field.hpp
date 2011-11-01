#ifndef _DBWORKER_FIELD_HPP_
#define _DBWORKER_FIELD_HPP_

#include "dbWorker/expression.hpp"

namespace dbWorker
{
	//////////////////////////////////////////////////////////////////////////
	class Field
		: public Expression
	{
		dbMeta::FieldCPtr _metaField;
	public:
		Field();
		Field(dbMeta::FieldCPtr fld);

		dbMeta::FieldCPtr meta() const;
	};
}

#endif
