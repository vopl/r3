#ifndef _UTILS_DATA_HPP_
#define _UTILS_DATA_HPP_

#include <string>
#include <boost/cstdint.hpp>
#include <boost/date_time/gregorian/greg_date.hpp>
#include <boost/date_time/posix_time/ptime.hpp>

#include <vector>
#include <map>
#include <bitset>

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


		// bool
		evtBool,

		// std::tm
		evtTm,

		// std::bitset<8>
		evtBitset8,

		// std::bitset<16>
		evtBitset16,

		// std::bitset<32>
		evtBitset32,

		// std::bitset<64>
		evtBitset64,

		// std::bitset<128>
		evtBitset128,

		// std::bitset<256>
		evtBitset256,

		// std::bitset<512>
		evtBitset512,

		// boost::gregorian::date_duration
		evtDateDuration,

		// boost::posix_time::time_duration
		evtTimeDuration,

	};

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
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
		
		typedef bool							Bool;
		typedef std::tm							Tm;
		typedef std::bitset<8>					Bitset8;
		typedef std::bitset<16>					Bitset16;
		typedef std::bitset<32>					Bitset32;
		typedef std::bitset<64>					Bitset64;
		typedef std::bitset<128>				Bitset128;
		typedef std::bitset<256>				Bitset256;
		typedef std::bitset<512>				Bitset512;
		typedef boost::gregorian::date_duration		DateDuration;
		typedef boost::posix_time::time_duration	TimeDuration;


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
		Variant(const Bool &v);
		Variant(const Tm &v);
		Variant(const Bitset8 &v);
		Variant(const Bitset16 &v);
		Variant(const Bitset32 &v);
		Variant(const Bitset64 &v);
		Variant(const Bitset128 &v);
		Variant(const Bitset256 &v);
		Variant(const Bitset512 &v);
		Variant(const DateDuration &v);
		Variant(const TimeDuration &v);

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
		Variant &operator=(const Bool &v);
		Variant &operator=(const Tm &v);
		Variant &operator=(const Bitset8 &v);
		Variant &operator=(const Bitset16 &v);
		Variant &operator=(const Bitset32 &v);
		Variant &operator=(const Bitset64 &v);
		Variant &operator=(const Bitset128 &v);
		Variant &operator=(const Bitset256 &v);
		Variant &operator=(const Bitset512 &v);
		Variant &operator=(const DateDuration &v);
		Variant &operator=(const TimeDuration &v);

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
		operator Bool &();
		operator Tm &();
		operator Bitset8 &();
		operator Bitset16 &();
		operator Bitset32 &();
		operator Bitset64 &();
		operator Bitset128 &();
		operator Bitset256 &();
		operator Bitset512 &();
		operator DateDuration &();
		operator TimeDuration &();


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
		operator Bool const &() const;
		operator Tm const &() const;
		operator Bitset8 const &() const;
		operator Bitset16 const &() const;
		operator Bitset32 const &() const;
		operator Bitset64 const &() const;
		operator Bitset128 const &() const;
		operator Bitset256 const &() const;
		operator Bitset512 const &() const;
		operator DateDuration const &() const;
		operator TimeDuration const &() const;

		void swap(Variant &);
		bool empty() const;
		EVariantType type() const;

		template<typename T> T &as();
		template<typename T> const T &as() const;
		template<typename T> bool is() const;
		template<typename T> void forceType();
		void forceType(EVariantType evt);

	protected:
		static const size_t _dataSize = sizeof(void *)<=8?8:sizeof(void *);
		char _data[_dataSize];

		boost::uint16_t _evt;
	};
}

#endif
