#ifndef _DBWORKER_FIELD_HPP_
#define _DBWORKER_FIELD_HPP_

namespace dbWorker
{
	//////////////////////////////////////////////////////////////////////////
	class Field
	{
		dbMeta::FieldCPtr _metaField;
	public:
		Field(dbMeta::FieldCPtr fld);
	};
}

#endif
