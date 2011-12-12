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
	ENUM_VARIANT_TYPE(2,	String,						std::string)\
	ENUM_VARIANT_TYPE(3,	Float,						float)\
	ENUM_VARIANT_TYPE(4,	Double,						double)\
	ENUM_VARIANT_TYPE(5,	Int8,						boost::int8_t)\
	ENUM_VARIANT_TYPE(6,	Int16,						boost::int16_t)\
	ENUM_VARIANT_TYPE(7,	Int32,						boost::int32_t)\
	ENUM_VARIANT_TYPE(8,	Int64,						boost::int64_t)\
	ENUM_VARIANT_TYPE(9,	UInt8,						boost::uint8_t)\
	ENUM_VARIANT_TYPE(10,	UInt16,						boost::uint16_t)\
	ENUM_VARIANT_TYPE(11,	UInt32,						boost::uint32_t)\
	ENUM_VARIANT_TYPE(12,	UInt64,						boost::uint64_t)\
	ENUM_VARIANT_TYPE(13,	VectorChar,					std::vector<char>)\
	ENUM_VARIANT_TYPE(14,	Date,						boost::gregorian::date)\
	ENUM_VARIANT_TYPE(15,	Datetime,					boost::posix_time::ptime)\
	ENUM_VARIANT_TYPE(16,	VectorVariant,				std::vector<Variant>)\
	ENUM_VARIANT_TYPE(17,	MapStringVariant,			std::map<std::string, Variant>)\
	ENUM_VARIANT_TYPE(18,	Bool,						bool)\
	ENUM_VARIANT_TYPE(19,	Tm,							std::tm)\
	ENUM_VARIANT_TYPE(20,	Bitset8,					std::bitset<8>)\
	ENUM_VARIANT_TYPE(21,	Bitset16,					std::bitset<16>)\
	ENUM_VARIANT_TYPE(22,	Bitset32,					std::bitset<32>)\
	ENUM_VARIANT_TYPE(23,	Bitset64,					std::bitset<64>)\
	ENUM_VARIANT_TYPE(24,	Bitset128,					std::bitset<128>)\
	ENUM_VARIANT_TYPE(25,	Bitset256,					std::bitset<256>)\
	ENUM_VARIANT_TYPE(26,	Bitset512,					std::bitset<512>)\
	ENUM_VARIANT_TYPE(27,	DateDuration,				boost::gregorian::date_duration)\
	ENUM_VARIANT_TYPE(28,	TimeDuration,				boost::posix_time::time_duration)\
	ENUM_VARIANT_TYPE(29,	DateTimeDuration,			::utils::DateTimeDuration)\
	ENUM_VARIANT_TYPE(30,	MapVariantVariant,			std::map<Variant, Variant>)\
	ENUM_VARIANT_TYPE(31,	MultimapStringVariant,		std::multimap<std::string, Variant>)\
	ENUM_VARIANT_TYPE(32,	MultimapVariantVariant,		std::multimap<Variant, Variant>)\
	ENUM_VARIANT_TYPE(33,	SetVariant,					std::set<Variant>)\
	ENUM_VARIANT_TYPE(34,	MultisetVariant,			std::multiset<Variant>)\
	ENUM_VARIANT_TYPE(35,	DequeVariant,				std::deque<Variant>)\
	ENUM_VARIANT_TYPE(36,	ListVariant,				std::list<Variant>)\
	ENUM_VARIANT_TYPE(37,	Char,						char)\
	ENUM_VARIANT_TYPE(38,	Uuid,						boost::uuids::uuid)\
	ENUM_VARIANT_TYPE(39,	VariantPtr,					VariantPtr)\





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
#define ENUM_VARIANT_TYPE(i,n,...) et##n = i,
	ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE
		};

	public:
		//короткие алиасы для типов, иена синхронно с EType
		typedef void Void;
#define ENUM_VARIANT_TYPE(i,n,...) typedef __VA_ARGS__ n;
		ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE


	public:
		template <class T> struct Type2Enum				{ static const EType et = etUnknown;	};


	public:
		~Variant();

		//////////////////////////////////////////////////////////////////////////
		Variant();
		Variant(const Variant &v);
		
		//конструкторы
#define ENUM_VARIANT_TYPE(i,n,...) Variant(const __VA_ARGS__ &v);
		ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE

		//helper
		Variant(const char *v);



		//////////////////////////////////////////////////////////////////////////
		Variant &operator=(const Variant &v);
		//присваивание
#define ENUM_VARIANT_TYPE(i,n,...) Variant &operator=(const __VA_ARGS__ &v);
		ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE

		//helper
		Variant &operator=(const char *v);

		//////////////////////////////////////////////////////////////////////////
		// приведение к ссылке на хранимый тип
#define ENUM_VARIANT_TYPE(i,n,...) operator __VA_ARGS__ &();
		ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE

		//helper
		operator const char *();

#define ENUM_VARIANT_TYPE(i,n,...) operator __VA_ARGS__ const &() const;
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
#define ENUM_VARIANT_TYPE(i,n,...) template <> struct Variant::Type2Enum<Variant::n> { static const EType et = Variant::et##n;	};
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
