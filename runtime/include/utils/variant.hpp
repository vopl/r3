#ifndef _UTILS_DATA_HPP_
#define _UTILS_DATA_HPP_


//для autoexp.dat
#if !defined NDEBUG && defined _MSC_VER
#	define UTILS_VARIANT_DBGDATA
#endif


#include "utils/dateTimeDuration.hpp"
#include <string>
#include <boost/cstdint.hpp>

#include <vector>
#include <map>
#include <set>
#include <deque>
#include <deque>
#include <list>
#include <bitset>

namespace utils
{
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	class Variant
	{
	public:
		enum EType
		{
			etNull						=0,
			etString					=1,
			etFloat						=2,
			etDouble					=3,
			etInt8						=4,
			etInt16						=5,
			etInt32						=6,
			etInt64						=7,
			etUInt8						=8,
			etUInt16					=9,
			etUInt32					=10,
			etUInt64					=11,
			etVectorChar				=12,
			etDate						=13,
			etTime						=14,
			etVectorVariant				=15,
			etMapStringVariant			=16,
			etBool						=17,
			etTm						=18,
			etBitset8					=19,
			etBitset16					=20,
			etBitset32					=21,
			etBitset64					=22,
			etBitset128					=23,
			etBitset256					=24,
			etBitset512					=25,
			etDateDuration				=26,
			etTimeDuration				=27,
			etDateTimeDuration			=28,


			etMapVariantVariant			=29,
			etMultimapVariantVariant	=30,
			etMultimapStringVariant		=31,
			etSetVariant				=32,
			etMultisetVariant			=33,
			etDequeVariant				=34,
			etListVariant				=35,
		};

	public:
		typedef std::string 						String;
		typedef float								Float;
		typedef double								Double;
		typedef boost::int8_t						Int8;
		typedef boost::int16_t						Int16;
		typedef boost::int32_t						Int32;
		typedef boost::int64_t						Int64;
		typedef boost::uint8_t						UInt8;
		typedef boost::uint16_t						UInt16;
		typedef boost::uint32_t						UInt32;
		typedef boost::uint64_t						UInt64;
		typedef std::vector<char>					VectorChar;
		typedef boost::gregorian::date				Date;
		typedef boost::posix_time::ptime			Time;
		typedef std::vector<Variant>				VectorVariant;
		typedef std::map<std::string, Variant>		MapStringVariant;
		typedef bool								Bool;
		typedef std::tm								Tm;
		typedef std::bitset<8>						Bitset8;
		typedef std::bitset<16>						Bitset16;
		typedef std::bitset<32>						Bitset32;
		typedef std::bitset<64>						Bitset64;
		typedef std::bitset<128>					Bitset128;
		typedef std::bitset<256>					Bitset256;
		typedef std::bitset<512>					Bitset512;
		typedef boost::gregorian::date_duration		DateDuration;
		typedef boost::posix_time::time_duration	TimeDuration;
		typedef ::utils::DateTimeDuration			DateTimeDuration;

		typedef std::map<Variant, Variant>			MapVariantVariant;
		typedef std::multimap<std::string, Variant>	MultimapStringVariant;
		typedef std::multimap<Variant, Variant>		MultimapVariantVariant;
		typedef std::set<Variant>					SetVariant;
		typedef std::multiset<Variant>				MultisetVariant;
		typedef std::deque<Variant>					DequeVariant;
		typedef std::list<Variant>					ListVariant;


	public:
		template <class T> struct Type2Enum				{ static const EType et = etNull;	};
		template <> struct Type2Enum<String>			{ static const EType et = etString;	};
		template <> struct Type2Enum<Float>				{ static const EType et = etFloat;	};
		template <> struct Type2Enum<Double>			{ static const EType et = etDouble;	};
		template <> struct Type2Enum<Int8>				{ static const EType et = etInt8;	};
		template <> struct Type2Enum<Int16>				{ static const EType et = etInt16;	};
		template <> struct Type2Enum<Int32>				{ static const EType et = etInt32;	};
		template <> struct Type2Enum<Int64>				{ static const EType et = etInt64;	};
		template <> struct Type2Enum<UInt8>				{ static const EType et = etUInt8;	};
		template <> struct Type2Enum<UInt16>			{ static const EType et = etUInt16;	};
		template <> struct Type2Enum<UInt32>			{ static const EType et = etUInt32;	};
		template <> struct Type2Enum<UInt64>			{ static const EType et = etUInt64;	};
		template <> struct Type2Enum<VectorChar>		{ static const EType et = etVectorChar;	};
		template <> struct Type2Enum<Date>				{ static const EType et = etDate;	};
		template <> struct Type2Enum<Time>				{ static const EType et = etTime;	};
		template <> struct Type2Enum<VectorVariant>		{ static const EType et = etVectorVariant;	};
		template <> struct Type2Enum<MapStringVariant>	{ static const EType et = etMapStringVariant;	};
		template <> struct Type2Enum<Bool>				{ static const EType et = etBool;	};
		template <> struct Type2Enum<Tm>				{ static const EType et = etTm;	};
		template <> struct Type2Enum<Bitset8>			{ static const EType et = etBitset8;	};
		template <> struct Type2Enum<Bitset16>			{ static const EType et = etBitset16;	};
		template <> struct Type2Enum<Bitset32>			{ static const EType et = etBitset32;	};
		template <> struct Type2Enum<Bitset64>			{ static const EType et = etBitset64;	};
		template <> struct Type2Enum<Bitset128>			{ static const EType et = etBitset128;	};
		template <> struct Type2Enum<Bitset256>			{ static const EType et = etBitset256;	};
		template <> struct Type2Enum<Bitset512>			{ static const EType et = etBitset512;	};
		template <> struct Type2Enum<DateDuration>		{ static const EType et = etDateDuration;	};
		template <> struct Type2Enum<TimeDuration>		{ static const EType et = etTimeDuration;	};
		template <> struct Type2Enum<DateTimeDuration>	{ static const EType et = etDateTimeDuration;	};

		template <> struct Type2Enum<MapVariantVariant>	{ static const EType et = etMapVariantVariant;	};
		template <> struct Type2Enum<MultimapStringVariant>		{ static const EType et = etMultimapStringVariant;	};
		template <> struct Type2Enum<MultimapVariantVariant>	{ static const EType et = etMultimapVariantVariant;	};
		template <> struct Type2Enum<SetVariant>		{ static const EType et = etSetVariant;	};
		template <> struct Type2Enum<MultisetVariant>	{ static const EType et = etMultisetVariant;	};
		template <> struct Type2Enum<DequeVariant>		{ static const EType et = etDequeVariant;	};
		template <> struct Type2Enum<ListVariant>		{ static const EType et = etListVariant;	};

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
		Variant(const DateTimeDuration &v);
		Variant(const MapVariantVariant &v);
		Variant(const MultimapVariantVariant &v);
		Variant(const MultimapStringVariant &v);
		Variant(const SetVariant &v);
		Variant(const MultisetVariant &v);
		Variant(const DequeVariant &v);
		Variant(const ListVariant &v);

		//helper
		Variant(const char *v);

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
		Variant &operator=(const DateTimeDuration &v);
		Variant &operator=(const MapVariantVariant &v);
		Variant &operator=(const MultimapVariantVariant &v);
		Variant &operator=(const MultimapStringVariant &v);
		Variant &operator=(const SetVariant &v);
		Variant &operator=(const MultisetVariant &v);
		Variant &operator=(const DequeVariant &v);
		Variant &operator=(const ListVariant &v);

		//helper
		Variant &operator=(const char *v);

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
		operator DateTimeDuration &();
		operator MapVariantVariant &();
		operator MultimapVariantVariant &();
		operator MultimapStringVariant &();
		operator SetVariant &();
		operator MultisetVariant &();
		operator DequeVariant &();
		operator ListVariant &();

		//helper
		operator const char *();


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
		operator DateTimeDuration const &() const;
		operator MapVariantVariant const &() const;
		operator MultimapVariantVariant const &() const;
		operator MultimapStringVariant const &() const;
		operator SetVariant const &() const;
		operator MultisetVariant const &() const;
		operator DequeVariant const &() const;
		operator ListVariant const &() const;

		void swap(Variant &);
		bool empty() const;
		EType type() const;

		void clear();

		void *data();
		void const *data() const;
		template<typename T> T &as(bool forceType = false);
		template<typename T> T const &as() const;
		template<typename T> bool is() const;
		template<typename T> void forceType();
		void forceType(EType et);

	public:
		bool operator <(const Variant &v) const;

	protected:
		static const size_t _dataSize = sizeof(void *)<=8?8:sizeof(void *);
		char _data[_dataSize];
		boost::uint16_t _et;

#ifdef UTILS_VARIANT_DBGDATA
		void *_dbgData;
#endif

	};
}

#endif
