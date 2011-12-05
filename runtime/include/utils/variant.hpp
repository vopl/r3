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
	class Variant;
	typedef boost::shared_ptr<Variant> VariantPtr;

	//////////////////////////////////////////////////////////////////////////
	class Variant
	{
	public:
		enum EType
		{
			etUnknown					=0,//ub

			etVoid						=1,
			etString					=2,
			etFloat						=3,
			etDouble					=4,
			etInt8						=5,
			etInt16						=6,
			etInt32						=7,
			etInt64						=8,
			etUInt8						=9,
			etUInt16					=10,
			etUInt32					=11,
			etUInt64					=12,
			etVectorChar				=13,
			etDate						=14,
			etTime						=15,
			etVectorVariant				=16,
			etMapStringVariant			=17,
			etBool						=18,
			etTm						=19,
			etBitset8					=20,
			etBitset16					=21,
			etBitset32					=22,
			etBitset64					=23,
			etBitset128					=24,
			etBitset256					=25,
			etBitset512					=26,
			etDateDuration				=27,
			etTimeDuration				=28,
			etDateTimeDuration			=29,


			etMapVariantVariant			=30,
			etMultimapVariantVariant	=31,
			etMultimapStringVariant		=32,
			etSetVariant				=33,
			etMultisetVariant			=34,
			etDequeVariant				=35,
			etListVariant				=36,

			etChar						=37,
			etUuid						=38,

			etVariantPtr				=39,
		};

	public:
		typedef void		 						Void;
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
		typedef char								Char;
		typedef boost::uuids::uuid					Uuid;
		typedef VariantPtr							VariantPtr;


	public:
		template <class T> struct Type2Enum				{ static const EType et = etUnknown;	};


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
		Variant(const Char &v);
		Variant(const Uuid &v);
		Variant(const VariantPtr &v);

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
		Variant &operator=(const Char &v);
		Variant &operator=(const Uuid &v);
		Variant &operator=(const VariantPtr &v);

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
		operator Char &();
		operator Uuid &();
		operator VariantPtr &();

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
		operator Char const &() const;
		operator Uuid const &() const;
		operator VariantPtr const &() const;

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
		boost::shared_array<char> save(boost::uint32_t &size) const;
		bool load(boost::shared_array<char> data, boost::uint32_t size);

	protected:
		static const size_t _dataSize = sizeof(void *)<=8?8:sizeof(void *);
		char _data[_dataSize];

		typedef boost::int16_t ETypeStorage;//негативный null
		ETypeStorage _et;

#ifdef UTILS_VARIANT_DBGDATA
		void *_dbgData;
#endif
	};


	template <> struct Variant::Type2Enum<Variant::Void>				{ static const EType et = Variant::etVoid;	};
	template <> struct Variant::Type2Enum<Variant::String>				{ static const EType et = Variant::etString;	};
	template <> struct Variant::Type2Enum<Variant::Float>				{ static const EType et = Variant::etFloat;	};
	template <> struct Variant::Type2Enum<Variant::Double>				{ static const EType et = Variant::etDouble;	};
	template <> struct Variant::Type2Enum<Variant::Int8>				{ static const EType et = Variant::etInt8;	};
	template <> struct Variant::Type2Enum<Variant::Int16>				{ static const EType et = Variant::etInt16;	};
	template <> struct Variant::Type2Enum<Variant::Int32>				{ static const EType et = Variant::etInt32;	};
	template <> struct Variant::Type2Enum<Variant::Int64>				{ static const EType et = Variant::etInt64;	};
	template <> struct Variant::Type2Enum<Variant::UInt8>				{ static const EType et = Variant::etUInt8;	};
	template <> struct Variant::Type2Enum<Variant::UInt16>				{ static const EType et = Variant::etUInt16;	};
	template <> struct Variant::Type2Enum<Variant::UInt32>				{ static const EType et = Variant::etUInt32;	};
	template <> struct Variant::Type2Enum<Variant::UInt64>				{ static const EType et = Variant::etUInt64;	};
	template <> struct Variant::Type2Enum<Variant::VectorChar>			{ static const EType et = Variant::etVectorChar;	};
	template <> struct Variant::Type2Enum<Variant::Date>				{ static const EType et = Variant::etDate;	};
	template <> struct Variant::Type2Enum<Variant::Time>				{ static const EType et = Variant::etTime;	};
	template <> struct Variant::Type2Enum<Variant::VectorVariant>		{ static const EType et = Variant::etVectorVariant;	};
	template <> struct Variant::Type2Enum<Variant::MapStringVariant>	{ static const EType et = Variant::etMapStringVariant;	};
	template <> struct Variant::Type2Enum<Variant::Bool>				{ static const EType et = Variant::etBool;	};
	template <> struct Variant::Type2Enum<Variant::Tm>					{ static const EType et = Variant::etTm;	};
	template <> struct Variant::Type2Enum<Variant::Bitset8>				{ static const EType et = Variant::etBitset8;	};
	template <> struct Variant::Type2Enum<Variant::Bitset16>			{ static const EType et = Variant::etBitset16;	};
	template <> struct Variant::Type2Enum<Variant::Bitset32>			{ static const EType et = Variant::etBitset32;	};
	template <> struct Variant::Type2Enum<Variant::Bitset64>			{ static const EType et = Variant::etBitset64;	};
	template <> struct Variant::Type2Enum<Variant::Bitset128>			{ static const EType et = Variant::etBitset128;	};
	template <> struct Variant::Type2Enum<Variant::Bitset256>			{ static const EType et = Variant::etBitset256;	};
	template <> struct Variant::Type2Enum<Variant::Bitset512>			{ static const EType et = Variant::etBitset512;	};
	template <> struct Variant::Type2Enum<Variant::DateDuration>		{ static const EType et = Variant::etDateDuration;	};
	template <> struct Variant::Type2Enum<Variant::TimeDuration>		{ static const EType et = Variant::etTimeDuration;	};
	template <> struct Variant::Type2Enum<Variant::DateTimeDuration>	{ static const EType et = Variant::etDateTimeDuration;	};

	template <> struct Variant::Type2Enum<Variant::MapVariantVariant>	{ static const EType et = Variant::etMapVariantVariant;	};
	template <> struct Variant::Type2Enum<Variant::MultimapStringVariant>		{ static const EType et = Variant::etMultimapStringVariant;	};
	template <> struct Variant::Type2Enum<Variant::MultimapVariantVariant>	{ static const EType et = Variant::etMultimapVariantVariant;	};
	template <> struct Variant::Type2Enum<Variant::SetVariant>			{ static const EType et = Variant::etSetVariant;	};
	template <> struct Variant::Type2Enum<Variant::MultisetVariant>		{ static const EType et = Variant::etMultisetVariant;	};
	template <> struct Variant::Type2Enum<Variant::DequeVariant>		{ static const EType et = Variant::etDequeVariant;	};
	template <> struct Variant::Type2Enum<Variant::ListVariant>			{ static const EType et = Variant::etListVariant;	};
	template <> struct Variant::Type2Enum<Variant::Char>				{ static const EType et = Variant::etChar;	};
	template <> struct Variant::Type2Enum<Variant::Uuid>				{ static const EType et = Variant::etUuid;	};	
	template <> struct Variant::Type2Enum<Variant::VariantPtr>			{ static const EType et = Variant::etVariantPtr;	};	


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
