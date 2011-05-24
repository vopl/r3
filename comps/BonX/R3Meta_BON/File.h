#ifndef R3META_BONFILE_H
#define R3META_BONFILE_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   FileImpl
//*******************************************************************
class FileImpl :
	  public FieldImpl
{
public:
	typedef enum
	{
		bytea_FileStoreKind_Type,
		blob_FileStoreKind_Type
	} FileStoreKind_Type;

	//
	// attribute getters and setters
	virtual R3Meta_BON::FileImpl::FileStoreKind_Type  getFileStoreKind();
	virtual void        setFileStoreKind( FileImpl::FileStoreKind_Type val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
