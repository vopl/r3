#ifndef _R3_FIELDS_VIDEO_H
#define _R3_FIELDS_VIDEO_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Video
	//*******************************************************************

	class Video
		: public File
	{
		boost::int32_t _width;
		boost::int32_t _height;
	public:
		Video()
			: _width(0)
			, _height(0)
		{

		}
		boost::int32_t &width();
		boost::int32_t &height();

	}; // class
}}  // namespace


#endif
