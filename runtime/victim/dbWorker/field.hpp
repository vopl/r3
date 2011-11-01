#ifndef _DBWORKER_FIELD_HPP_
#define _DBWORKER_FIELD_HPP_

namespace dbWorker
{
	//////////////////////////////////////////////////////////////////////////
	class Field
	{
		dbMeta::FieldCPtr _metaField;
	public:
		Field();
		Field(dbMeta::FieldCPtr fld);

		dbMeta::FieldCPtr meta() const;
	};
}

#endif
