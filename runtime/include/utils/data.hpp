#ifndef _UTILS_DATA_HPP_
#define _UTILS_DATA_HPP_

#include <string>
#include <boost/cstdint.hpp>
#include <boost/date_time/gregorian/greg_date.hpp>
#include <boost/date_time/posix_time/ptime.hpp>

#include <vector>
#include <map>
#include <boost/variant.hpp>

namespace impl
{
	class Variant
		: public boost::make_recursive_variant <

		std::string
		, float
		, double
		, boost::int8_t
		, boost::int16_t
		, boost::int32_t
		, boost::int64_t
		, boost::uint8_t
		, boost::uint16_t
		, boost::uint32_t
		, boost::uint64_t
		, std::vector<char>
		, boost::gregorian::date
		, boost::posix_time::ptime
		, std::vector<Variant>
		, std::map<std::string, Variant>

		> ::type
	{
	public:
		Variant();
		Variant(const Variant &);
		template<typename T> Variant(const T &);


		void swap(variant &);
		Variant & operator=(const Variant &);
		template<typename T> variant & operator=(const T &);

		// 	// queries
		// 	int which() const;
		// 	bool empty() const;
		// 	const std::type_info & type() const;

		template<typename T> T &as();
		template<typename T> bool is();
	};
}

#endif
