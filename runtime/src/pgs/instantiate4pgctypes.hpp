#ifndef _PGS_INSTANTIATE4PGCTYPES_HPP_
#define _PGS_INSTANTIATE4PGCTYPES_HPP_

#include "pgc/cppDataType.hpp"

#define INSTANTIATE4PGCTYPES(Class)						\
	template Class<std::string>;						\
	template Class<bool>;								\
	template Class<float>;								\
	template Class<double>;								\
	template Class<boost::int8_t>;						\
	template Class<boost::int16_t>;						\
	template Class<boost::int32_t>;						\
	template Class<boost::int64_t>;						\
	template Class<boost::uint8_t>;						\
	template Class<boost::uint16_t>;					\
	template Class<boost::uint32_t>;					\
	template Class<boost::uint64_t>;					\
	template Class<std::tm>;							\
	template Class<std::bitset<8> >;					\
	template Class<std::bitset<16> >;					\
	template Class<std::bitset<32> >;					\
	template Class<std::bitset<64> >;					\
	template Class<std::bitset<128> >;					\
	template Class<std::bitset<256> >;					\
	template Class<std::bitset<512> >;					\
	template Class<std::vector<char> >;					\
	template Class<std::vector<unsigned char> >;		\
	template Class<std::vector<signed char> >;			\
	template Class<boost::gregorian::date>;				\
	template Class<boost::posix_time::ptime>;			\
	template Class<boost::gregorian::date_duration>;	\
	template Class<boost::posix_time::time_duration>;	\
	template Class<pgc::DateTimeDuration>;				\
	template Class<pgc::Blob>;							\
	template Class<pgc::Money>;							//\


#endif
