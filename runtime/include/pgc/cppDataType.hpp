#ifndef _PGC_CPPDATATYPE_HPP_
#define _PGC_CPPDATATYPE_HPP_

#include "pgc/common.h"
#include "utils/variant.hpp"

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
// 		enum {cdt_index = utils::Variant::Type2Enum<char *>::et};
// 	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::string>
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<std::string>::et};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<bool>
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<bool>::et};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<float>
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<float>::et};
	};


	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<double>
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<double>::et};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::int8_t>
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<boost::int8_t>::et};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::int16_t>
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<boost::int16_t>::et};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::int32_t>
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<boost::int32_t>::et};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::int64_t>
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<boost::int64_t>::et};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::uint8_t>
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<boost::uint8_t>::et};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::uint16_t>
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<boost::uint16_t>::et};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::uint32_t>
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<boost::uint32_t>::et};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::uint64_t>
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<boost::uint64_t>::et};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::tm>
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<std::tm>::et};
	};








	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<8> >
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<std::bitset<8> >::et};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<16> >
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<std::bitset<16> >::et};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<32> >
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<std::bitset<32> >::et};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<64> >
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<std::bitset<64> >::et};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<128> >
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<std::bitset<128> >::et};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<256> >
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<std::bitset<256> >::et};
	};
	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::bitset<512> >
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<std::bitset<512> >::et};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<std::vector<char> >
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<std::vector<char> >::et};
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
		enum {cdt_index = utils::Variant::Type2Enum<boost::gregorian::date>::et};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::posix_time::ptime>
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<boost::posix_time::ptime>::et};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::gregorian::date_duration>
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<boost::gregorian::date_duration>::et};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<boost::posix_time::time_duration>
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<boost::posix_time::time_duration>::et};
	};

	//////////////////////////////////////////////////////////////////////////
	template <> struct CppDataType<utils::DateTimeDuration>
	{
		static const bool known = true;
		enum {cdt_index = utils::Variant::Type2Enum<utils::DateTimeDuration>::et};
	};

	//////////////////////////////////////////////////////////////////////////
	class Blob;
	template <> struct CppDataType<Blob>
	{
		static const bool known = true;
		enum {cdt_index = -__LINE__};
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
		enum {cdt_index = -__LINE__};
	};
}

#endif
