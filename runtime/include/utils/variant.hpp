#ifndef _UTILS_VARIANT_HPP_
#define _UTILS_VARIANT_HPP_


//для autoexp.dat
#if !defined NDEBUG && defined _MSC_VER
#	define UTILS_VARIANT_DBGDATA
#endif


#include "utils/dateTimeDuration.hpp"
#include <string>
#include <boost/cstdint.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>
#include <boost/uuid/uuid.hpp>

#include <vector>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <bitset>

namespace utils
{






	//////////////////////////////////////////////////////////////////////////
#define ENUM_VARIANT_TYPES\
	ENUM_VARIANT_TYPE(String)\
	ENUM_VARIANT_TYPE(Float)\
	ENUM_VARIANT_TYPE(Double)\
	ENUM_VARIANT_TYPE(Int8)\
	ENUM_VARIANT_TYPE(Int16)\
	ENUM_VARIANT_TYPE(Int32)\
	ENUM_VARIANT_TYPE(Int64)\
	ENUM_VARIANT_TYPE(UInt8)\
	ENUM_VARIANT_TYPE(UInt16)\
	ENUM_VARIANT_TYPE(UInt32)\
	ENUM_VARIANT_TYPE(UInt64)\
	ENUM_VARIANT_TYPE(VectorChar)\
	ENUM_VARIANT_TYPE(Date)\
	ENUM_VARIANT_TYPE(Datetime)\
	ENUM_VARIANT_TYPE(VectorVariant)\
	ENUM_VARIANT_TYPE(MapStringVariant)\
	ENUM_VARIANT_TYPE(Bool)\
	ENUM_VARIANT_TYPE(Tm)\
	ENUM_VARIANT_TYPE(Bitset8)\
	ENUM_VARIANT_TYPE(Bitset16)\
	ENUM_VARIANT_TYPE(Bitset32)\
	ENUM_VARIANT_TYPE(Bitset64)\
	ENUM_VARIANT_TYPE(Bitset128)\
	ENUM_VARIANT_TYPE(Bitset256)\
	ENUM_VARIANT_TYPE(Bitset512)\
	ENUM_VARIANT_TYPE(DateDuration)\
	ENUM_VARIANT_TYPE(TimeDuration)\
	ENUM_VARIANT_TYPE(DateTimeDuration)\
	ENUM_VARIANT_TYPE(MapVariantVariant)\
	ENUM_VARIANT_TYPE(MultimapStringVariant)\
	ENUM_VARIANT_TYPE(MultimapVariantVariant)\
	ENUM_VARIANT_TYPE(SetVariant)\
	ENUM_VARIANT_TYPE(MultisetVariant)\
	ENUM_VARIANT_TYPE(DequeVariant)\
	ENUM_VARIANT_TYPE(ListVariant)\
	ENUM_VARIANT_TYPE(Char)\
	ENUM_VARIANT_TYPE(Uuid)\
	ENUM_VARIANT_TYPE(VariantPtr)\





	//////////////////////////////////////////////////////////////////////////
	class Variant;
	typedef boost::shared_ptr<Variant> VariantPtr;

	//////////////////////////////////////////////////////////////////////////
	class Variant
	{
	public:
		//енум с числовыми значениями для типов
		enum EType
		{
			etUnknown					=0,//ub
			etVoid						=1,
			etString 					=2,
			etFloat 					=3,
			etDouble 					=4,
			etInt8 						=5,
			etInt16 					=6,
			etInt32 					=7,
			etInt64 					=8,
			etUInt8 					=9,
			etUInt16 					=10,
			etUInt32 					=11,
			etUInt64 					=12,
			etVectorChar 				=13,
			etDate 						=14,
			etDatetime 					=15,
			etVectorVariant 			=16,
			etMapStringVariant 			=17,
			etBool 						=18,
			etTm 						=19,
			etBitset8 					=20,
			etBitset16 					=21,
			etBitset32 					=22,
			etBitset64 					=23,
			etBitset128 				=24,
			etBitset256 				=25,
			etBitset512 				=26,
			etDateDuration 				=27,
			etTimeDuration 				=28,
			etDateTimeDuration 			=29,
			etMapVariantVariant 		=30,
			etMultimapStringVariant 	=31,
			etMultimapVariantVariant 	=32,
			etSetVariant 				=33,
			etMultisetVariant 			=34,
			etDequeVariant 				=35,
			etListVariant 				=36,
			etChar 						=37,
			etUuid 						=38,
			etVariantPtr 				=39,
		};

	public:
		//короткие алиасы для типов, иена синхронно с EType
		typedef void								Void;
		typedef std::string 						String;
		typedef float 								Float;
		typedef double 								Double;
		typedef boost::int8_t 						Int8;
		typedef boost::int16_t 						Int16;
		typedef boost::int32_t 						Int32;
		typedef boost::int64_t 						Int64;
		typedef boost::uint8_t 						UInt8;
		typedef boost::uint16_t 					UInt16;
		typedef boost::uint32_t 					UInt32;
		typedef boost::uint64_t 					UInt64;
		typedef std::vector<char> 					VectorChar;
		typedef boost::gregorian::date 				Date;
		typedef boost::posix_time::ptime 			Datetime;
		typedef std::vector<Variant> 				VectorVariant;
		typedef std::map<std::string, Variant> 		MapStringVariant;
		typedef bool 								Bool;
		typedef std::tm 							Tm;
		typedef std::bitset<8> 						Bitset8;
		typedef std::bitset<16> 					Bitset16;
		typedef std::bitset<32> 					Bitset32;
		typedef std::bitset<64> 					Bitset64;
		typedef std::bitset<128> 					Bitset128;
		typedef std::bitset<256> 					Bitset256;
		typedef std::bitset<512> 					Bitset512;
		typedef boost::gregorian::date_duration 	DateDuration;
		typedef boost::posix_time::time_duration 	TimeDuration;
		typedef ::utils::DateTimeDuration 			DateTimeDuration;
		typedef std::map<Variant, Variant> 			MapVariantVariant;
		typedef std::multimap<std::string, Variant>	MultimapStringVariant;
		typedef std::multimap<Variant, Variant> 	MultimapVariantVariant;
		typedef std::set<Variant> 					SetVariant;
		typedef std::multiset<Variant> 				MultisetVariant;
		typedef std::deque<Variant> 				DequeVariant;
		typedef std::list<Variant> 					ListVariant;
		typedef char 								Char;
		typedef boost::uuids::uuid 					Uuid;
		typedef VariantPtr 							VariantPtr;

	public:
		template <class T> struct Type2Enum				{ static const EType et = etUnknown;	};


	public:
		~Variant();

		//////////////////////////////////////////////////////////////////////////
		Variant();
		Variant(const Variant &v);
		
		//конструкторы
#define ENUM_VARIANT_TYPE(T) Variant(const T &v);
		ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE

		//helper
		Variant(const char *v);



		//////////////////////////////////////////////////////////////////////////
		Variant &operator=(const Variant &v);
		//присваивание
#define ENUM_VARIANT_TYPE(T) Variant &operator=(const T &v);
		ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE

		//helper
		Variant &operator=(const char *v);

		//////////////////////////////////////////////////////////////////////////
		// приведение к ссылке на хранимый тип
#define ENUM_VARIANT_TYPE(T) operator T &();
		ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE

		//helper
		operator const char *();

#define ENUM_VARIANT_TYPE(T) operator T const &() const;
		ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE

		//////////////////////////////////////////////////////////////////////////
		void swap(Variant &);

		bool isNull() const;
		void setNull(bool n=true);
		template<typename T> void setNull(bool n=true);

		EType type() const;
		void *data();
		void const *data() const;

		template<typename T> T &as(bool forceType);
		template<typename T> T const &as() const;
		template<typename T> T &as();
		template<typename T> bool is() const;
		template<typename T> void forceType();
		void forceType(EType et);

	public:
		bool operator <(const Variant &v) const;
		bool operator ==(const Variant &v) const;
		bool operator !=(const Variant &v) const;

	public:
		boost::shared_array<char> serialize(boost::uint32_t &size) const;
		bool deserialize(boost::shared_array<char> data, boost::uint32_t size);

		bool load(const char *fileName, std::string *errors=NULL);

	protected:
		static const size_t _dataSize = sizeof(void *)<=8?8:sizeof(void *);
		char _data[_dataSize];

		typedef boost::int16_t ETypeStorage;//негативный - null
		ETypeStorage _et;

#ifdef UTILS_VARIANT_DBGDATA
		void *_dbgData;
#endif
	};


	//////////////////////////////////////////////////////////////////////////
	//тип в число
	template <> struct Variant::Type2Enum<Variant::Void> { static const EType et = Variant::etVoid;	};
#define ENUM_VARIANT_TYPE(T) template <> struct Variant::Type2Enum<Variant::T> { static const EType et = Variant::et##T;	};
	ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE


	//////////////////////////////////////////////////////////////////////////
	// дампер
	std::ostream &operator <<(std::ostream &ostr, const Variant &v);
	std::ostream &operator <<(std::ostream &ostr, const Variant::VectorVariant &v);
	std::ostream &operator <<(std::ostream &ostr, const Variant::MapStringVariant &v);
	std::ostream &operator <<(std::ostream &ostr, const Variant::MapVariantVariant &v);
	std::ostream &operator <<(std::ostream &ostr, const Variant::MultimapStringVariant &v);
	std::ostream &operator <<(std::ostream &ostr, const Variant::MultimapVariantVariant &v);
	std::ostream &operator <<(std::ostream &ostr, const Variant::SetVariant &v);
	std::ostream &operator <<(std::ostream &ostr, const Variant::MultisetVariant &v);
	std::ostream &operator <<(std::ostream &ostr, const Variant::DequeVariant &v);
	std::ostream &operator <<(std::ostream &ostr, const Variant::ListVariant &v);
	std::ostream &operator <<(std::ostream &ostr, const Variant::VariantPtr &v);
}

#endif
