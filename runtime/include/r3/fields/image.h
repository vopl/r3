#ifndef _R3_FIELDS_IMAGE_H
#define _R3_FIELDS_IMAGE_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Image
	//*******************************************************************

	class Image
		: public File
	{
	public:
		typedef boost::int32_t TWidth;
		typedef boost::int32_t THeight;
	private:

		boost::int32_t _width;
		boost::int32_t _height;
	public:
		Image()
			: _width(0)
			, _height(0)
		{

		}
		boost::int32_t &width();
		boost::int32_t &height();

		Image &operator=(EFieldValueState from)
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
