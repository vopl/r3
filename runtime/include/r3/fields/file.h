#ifndef _R3_FIELDS_FILE_H
#define _R3_FIELDS_FILE_H

#include "r3/fields/field.h"

#include "pgc/blob.hpp"

namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   File
	//*******************************************************************
	class File
		: public Field
	{
		std::string		_name;
		std::string		_ext;
		pgc::Blob		_blob;

	public:
		std::string &name();
		std::string &ext();
		pgc::Blob &blob();

		File &operator=(const std::string &from);
		File &operator=(const pgc::Blob &from);

		operator std::string();
		operator pgc::Blob();

	}; // class
}}  // namespace


#endif
