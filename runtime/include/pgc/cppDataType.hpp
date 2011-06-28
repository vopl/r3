#ifndef _PGC_CPPDATATYPE_HPP_
#define _PGC_CPPDATATYPE_HPP_

#include "pgc/common.h"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	template <class T> struct CppDataType 
	{
		static const bool known = false;
	};

// 	//////////////////////////////////////////////////////////////////////////
// 	template <> struct CppDataType<char *>
// 	{
//		static const bool known = true;
// 		enum {cdt_index = __LINE__};
// 	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::string>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<bool>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<float>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};


	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<double>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::int8_t>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::int16_t>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::int32_t>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::int64_t>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::uint8_t>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::uint16_t>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::uint32_t>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::uint64_t>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::tm>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};








	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<8> >
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<16> >
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<32> >
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<64> >
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<128> >
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<256> >
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<512> >
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::vector<char> >
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::vector<unsigned char> >
	{
		static const bool known = true;
		enum {cdt_index = CppDataType<std::vector<char> >::cdt_index};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::vector<signed char> >
	{
		static const bool known = true;
		enum {cdt_index = CppDataType<std::vector<char> >::cdt_index};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::gregorian::date>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::posix_time::ptime>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::gregorian::date_duration>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::posix_time::time_duration>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};

	struct DateTimeDuration
	{
		boost::gregorian::date_duration		_dd;
		boost::posix_time::time_duration	_td;

		DateTimeDuration()
			: _dd()
			, _td()
		{}

		DateTimeDuration(boost::gregorian::date_duration dd, boost::posix_time::time_duration td)
			: _dd(dd)
			, _td(td)
		{}

	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<DateTimeDuration>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	class Blob;
	template <> struct CppDataType<Blob>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};

	//////////////////////////////////////////////////////////////////////////
	struct Money
	{
		boost::int64_t _value;

		Money() : _value(0) {}
	};
	template <> struct CppDataType<Money>
	{
		static const bool known = true;
		enum {cdt_index = __LINE__};
	};
}

#endif
