#ifndef _DBWORKER_SELECT_HPP_
#define _DBWORKER_SELECT_HPP_

namespace dbWorker
{
	class CatOrFld
	{
	public:
		CatOrFld(dbMeta::CategoryCPtr cat);
		CatOrFld(dbMeta::FieldCPtr fld);
	};

	//////////////////////////////////////////////////////////////////////////
	class Select
	{
	public:
		Select();
		Select(CatOrFld cof);
		Select(CatOrFld cof, CatOrFld cof2);
		Select(CatOrFld cof, CatOrFld cof2, CatOrFld cof3);

		Select &link(...);
		Select &where(...);
		Select &limit(...);
		Select &offset(...);
		Select &order(...);
	};
}

#endif
