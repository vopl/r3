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
#include <boost/preprocessor.hpp>

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
		typedef ::utils::VariantPtr 				VariantPtr;

	public:
		template <class T> struct Type2Enum				{ static const EType et = etUnknown;	};


	public:
		~Variant();

		//////////////////////////////////////////////////////////////////////////
		//конструкторы
		Variant();
		Variant(const Variant &v);
		Variant(const char *v);//String
#define ENUM_VARIANT_TYPE(T) Variant(const T &v);
		ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE




		//////////////////////////////////////////////////////////////////////////
		//присваивание
		Variant &operator=(const Variant &v);
		Variant &operator=(const char *v);//String
#define ENUM_VARIANT_TYPE(T) Variant &operator=(const T &v);
		ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE

		//////////////////////////////////////////////////////////////////////////
		void swap(Variant &);

		//////////////////////////////////////////////////////////////////////////
		//проверки

		//на NULL
		bool isNull() const;
		//на внутренний тип
		template<typename T> bool is() const;
		//на возможность использования operator[](string)
		bool isMap() const;
		//на возможность использования operator[](size_t)
		bool isArray() const;
		//на скаляр
		bool isScalar() const;

		//////////////////////////////////////////////////////////////////////////
		//внутренние преобразования
		//установить нул/ненул для текущего типа
		void setNull(bool n=true);

		//установить нул/ненул для заданного типа, старое значение сохраняется если не нул и тип не изменился
		template<typename T> void setNull(bool n=true);

		//установить заданный тип, старое значение сохраняется если не нул и тип не изменился
		template<typename T> void forceType();
		//установить заданный тип, старое значение сохраняется если не нул и тип не изменился
		void forceType(EType et);

		//////////////////////////////////////////////////////////////////////////
		//доступ к сырым данным
		//тип
		EType type() const;
		//адрес хранимого объекта
		void *data();
		void const *data() const;

		//доступ ко ссылке на хранимый объект
		template<typename T> T &as(bool forceType);
		template<typename T> T const &as() const;
		template<typename T> T &as();

		//////////////////////////////////////////////////////////////////////////
		//матричное преобразование
		template<typename T> T to() const;
		template<typename T> void to(T &dst) const;
		template<typename T> void convert();
		void convert(EType et);

#ifdef _DEBUG
		template<typename T> bool canConvert() const;
		bool canConvert(EType et) const;
#endif

#define ENUM_VARIANT_TYPE(T) operator T () const;
		ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE

	public://интерфейс ассоциативной карты и индексируемого массива
		Variant operator[](const std::string &key);
		Variant operator[](const char *key);
		Variant operator[](const Variant &key);
		Variant operator[](size_t idx);
		Variant operator[](int idx);

	public:
		//для упорядоченного контейнера
		bool operator <(const Variant &v) const;
		//на всякий случай
		bool operator ==(const Variant &v) const;
		bool operator !=(const Variant &v) const;

	public:
		//сериализация в портабельный бинарник
		boost::shared_array<char> serialize(boost::uint32_t &size) const;
		bool deserialize(boost::shared_array<char> data, boost::uint32_t size);

		//загрузка из текстового файла (JSON-подобного)
		bool load(const char *fileName, std::string *errors=NULL);

	protected:
		//буфер
		static const size_t _dataSize = sizeof(void *)<=4?12:24;
		char _data[_dataSize];

		//тип
		typedef boost::int16_t ETypeStorage;//негативный - null
		ETypeStorage _et;

		//для отладчика помогалка
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









//////////////////////////////////////////////////////////////////////////
//генераторы вектора и карты
/*
	вектор использовать так:
	MVA();//сформирует вариант типа etVectorVariant, не нул, пустой
	MVA(220);//с одним элементом типа int
	MVA(220, "elem2", MVA(2,3));//вектор из трех элементов, последний сам вектор из двух

	MVA может принять до MVX_MAXELEMS аргументов


	карту:
	MVM();//сформирует вариант типа etMapStringVariant, не нул, пустой
	MVM("220", 220);//с одной парой ключ "220", значение 220
	MVM("elem2", 220, "complex", MVA(2,3));//

	MVM может принять до MVX_MAXELEMS пар ключ-значение
*/
#ifndef MVX_MAXELEMS
#	define MVX_MAXELEMS 20
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////
#define declareMVASet(z, n, _) res.push_back(BOOST_PP_CAT(t,n));

#define declareMVA(z, n, _) \
	template <BOOST_PP_ENUM_PARAMS(n, class T)> \
	inline Variant MVA(BOOST_PP_ENUM_BINARY_PARAMS(n, T, t)) \
	{ \
		Variant::VectorVariant res; \
		BOOST_PP_REPEAT_FROM_TO(0, n, declareMVASet, _) \
		return res; \
	} \

//////////////////////////////////////////////////////////////////////////////////////////////////////
#define declareMVMSet(z, n, _) res.insert(BOOST_PP_CAT(t, BOOST_PP_MUL(n, 2)), BOOST_PP_CAT(t, BOOST_PP_INC(BOOST_PP_MUL(n, 2))));

#define declareMVM(z, n, _) \
	template <BOOST_PP_ENUM_PARAMS(BOOST_PP_MUL(n, 2), class T)> \
	inline Variant MVM(BOOST_PP_ENUM_BINARY_PARAMS(BOOST_PP_MUL(n, 2), T, t)) \
	{ \
		Variant::MapStringVariant res; \
		BOOST_PP_REPEAT_FROM_TO(0, n, declareMVMSet, _) \
		return res; \
	} \

namespace utils
{
	inline Variant MVM()
	{
		Variant::MapStringVariant res;
		return res;
	}
	inline Variant MVA()
	{
		Variant::VectorVariant res;
		return res;
	}


	BOOST_PP_REPEAT_FROM_TO(1, MVX_MAXELEMS, declareMVM, _)

	BOOST_PP_REPEAT_FROM_TO(1, MVX_MAXELEMS, declareMVA, _)

}

#undef declareMVASet
#undef declareMVA
#undef declareMVMSet
#undef declareMVM


#endif
