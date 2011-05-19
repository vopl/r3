#ifndef _PGC_CPPDATATYPE_HPP_
#define _PGC_CPPDATATYPE_HPP_

#include "pgc/common.h"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	template <class T> struct CppDataType {};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<char *>
	{
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::string>
	{
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<bool>
	{
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<float>
	{
		enum {cdt_index = __LINE__};
	};


	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<double>
	{
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::int8_t>
	{
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::int16_t>
	{
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::int32_t>
	{
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::int64_t>
	{
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::uint8_t>
	{
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::uint16_t>
	{
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::uint32_t>
	{
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::uint64_t>
	{
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::tm>
	{
		enum {cdt_index = __LINE__};
	};








	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<8> >
	{
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<16> >
	{
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<32> >
	{
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<64> >
	{
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<128> >
	{
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<256> >
	{
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<512> >
	{
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::vector<unsigned char> >
	{
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::gregorian::date>
	{
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::posix_time::ptime>
	{
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::gregorian::date_duration>
	{
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::posix_time::time_duration>
	{
		enum {cdt_index = __LINE__};
	};

	struct DateTimeDuration
	{
		boost::gregorian::date_duration		_dd;
		boost::posix_time::time_duration	_td;
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<DateTimeDuration>
	{
		enum {cdt_index = __LINE__};
	};

	//blob
}

#endif
