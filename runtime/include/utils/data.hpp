#ifndef _UTILS_DATA_HPP_
#define _UTILS_DATA_HPP_

#include <string>
#include <boost/cstdint.hpp>
#include <boost/date_time/gregorian/greg_date.hpp>
#include <boost/date_time/posix_time/ptime.hpp>

#include <vector>
#include <map>

namespace utils
{
	enum EVariantType
	{
		evtNull,

		// std::string
		evtString,
		// float
		evtFloat,
		// double
		evtDouble,
		// boost::int8_t
		evtInt8,
		// boost::int16_t
		evtInt16,
		// boost::int32_t
		evtInt32,
		// boost::int64_t
		evtInt64,
		// boost::uint8_t
		evtUInt8,
		// boost::uint16_t
		evtUInt16,
		// boost::uint32_t
		evtUInt32,
		// boost::uint64_t
		evtUInt64,
		// std::vector<char>
		evtVectorChar,
		// boost::gregorian::date
		evtDate,
		// boost::posix_time::ptime
		evtTime,

		// std::vector<Variant>
		evtVectorVariant,

		// std::map<std::string, Variant>
		evtMapStringVariant,
	};


	class Variant
	{
	public:
		typedef std::string 					String;
		typedef float							Float;
		typedef double							Double;
		typedef boost::int8_t					Int8;
		typedef boost::int16_t					Int16;
		typedef boost::int32_t					Int32;
		typedef boost::int64_t					Int64;
		typedef boost::uint8_t					UInt8;
		typedef boost::uint16_t					UInt16;
		typedef boost::uint32_t					UInt32;
		typedef boost::uint64_t					UInt64;
		typedef std::vector<char>				VectorChar;
		typedef boost::gregorian::date			Date;
		typedef boost::posix_time::ptime		Time;
		typedef std::vector<Variant>			VectorVariant;
		typedef std::map<std::string, Variant>	MapStringVariant;


	public:
		~Variant();

		Variant();
		Variant(const Variant &v);
		Variant(const String &v);
		Variant(const Float &v);
		Variant(const Double &v);
		Variant(const Int8 &v);
		Variant(const Int16 &v);
		Variant(const Int32 &v);
		Variant(const Int64 &v);
		Variant(const UInt8 &v);
		Variant(const UInt16 &v);
		Variant(const UInt32 &v);
		Variant(const UInt64 &v);
		Variant(const VectorChar &v);
		Variant(const Date &v);
		Variant(const Time &v);
		Variant(const VectorVariant &v);
		Variant(const MapStringVariant &v);

		Variant &operator=(const Variant &v);
		Variant &operator=(const String &v);
		Variant &operator=(const Float &v);
		Variant &operator=(const Double &v);
		Variant &operator=(const Int8 &v);
		Variant &operator=(const Int16 &v);
		Variant &operator=(const Int32 &v);
		Variant &operator=(const Int64 &v);
		Variant &operator=(const UInt8 &v);
		Variant &operator=(const UInt16 &v);
		Variant &operator=(const UInt32 &v);
		Variant &operator=(const UInt64 &v);
		Variant &operator=(const VectorChar &v);
		Variant &operator=(const Date &v);
		Variant &operator=(const Time &v);
		Variant &operator=(const VectorVariant &v);
		Variant &operator=(const MapStringVariant &v);

		// queries
		operator String &();
		operator Float &();
		operator Double &();
		operator Int8 &();
		operator Int16 &();
		operator Int32 &();
		operator Int64 &();
		operator UInt8 &();
		operator UInt16 &();
		operator UInt32 &();
		operator UInt64 &();
		operator VectorChar &();
		operator Date &();
		operator Time &();
		operator VectorVariant &();
		operator MapStringVariant &();


		operator String const &() const;
		operator Float const &() const;
		operator Double const &() const;
		operator Int8 const &() const;
		operator Int16 const &() const;
		operator Int32 const &() const;
		operator Int64 const &() const;
		operator UInt8 const &() const;
		operator UInt16 const &() const;
		operator UInt32 const &() const;
		operator UInt64 const &() const;
		operator VectorChar const &() const;
		operator Date const &() const;
		operator Time const &() const;
		operator VectorVariant const &() const;
		operator MapStringVariant const &() const;

		void swap(Variant &);
		bool empty() const;
		EVariantType type() const;

		template<typename T> T &as();
		template<typename T> const T &as() const;
		template<typename T> bool is() const;
		template<typename T> void forceType();

	protected:
		static const size_t _dataSize = 8;
		char _data[_dataSize];
		EVariantType _evt;

	};
}

#endif
