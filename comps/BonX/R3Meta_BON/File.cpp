#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
R3Meta_BON::FileImpl::FileStoreKind_Type R3Meta_BON::FileImpl::getFileStoreKind()
{
	std::string val = FCOImpl::getAttribute("FileStoreKind")->getStringValue();

	if ( val == "bytea") return bytea_FileStoreKind_Type;
	else if ( val == "blob") return blob_FileStoreKind_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::FileImpl::setFileStoreKind( FileImpl::FileStoreKind_Type val)
{
	std::string str_val = "";

	if ( val == bytea_FileStoreKind_Type) str_val = "bytea";
	else if ( val == blob_FileStoreKind_Type) str_val = "blob";
	else throw("None of the possible items");

	FCOImpl::getAttribute("FileStoreKind")->setStringValue( str_val);
}


