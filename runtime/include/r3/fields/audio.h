#ifndef _R3_FIELDS_AUDIO_H
#define _R3_FIELDS_AUDIO_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Audio
	//*******************************************************************

	class Audio
		: public File
	{
	public:
		Audio &operator=(const std::string &from);
		Audio &operator=(const pgc::Blob &from);

		Audio &operator=(EFieldValueState from)
		{
			Field::operator =(from);
			return *this;
		}
		bool operator==(const EFieldValueState with) const
		{
			return Field::operator ==(with);
		}

	}; // class
}}  // namespace


#endif
