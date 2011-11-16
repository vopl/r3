#include "utils/streambufOnArray.hpp"
#include "utils/serialization.hpp"

//warning C4127: conditional expression is constant
#pragma warning (push)
#pragma warning (disable: 4127)

namespace utils
{
	namespace
	{
		//////////////////////////////////////////////////////////////////////////
		inline bool operator <(const std::tm &v1,const std::tm &v2)
		{
			std::tm cv1(v1),cv2(v2);
			return mktime(&cv1) < mktime(&cv2);
		}

		//////////////////////////////////////////////////////////////////////////
		template <size_t N>
		bool operator <(const std::bitset<N> &v1,const std::bitset<N> &v2)
		{
			if(N <= sizeof(unsigned long))
			{
				return v1.to_ulong() < v2.to_ulong();
			}
			else
			{
				for(size_t i(N-1); i<N; i--)
				{
					if(!v1[i] && v2[i]) return true;
					if(v1[i] && !v2[i]) return false;
				}
				return false;
			}
		}

		//////////////////////////////////////////////////////////////////////////
		inline bool operator ==(const std::tm &v1,const std::tm &v2)
		{
			return 0 == memcmp(&v1, &v2, sizeof(std::tm));
		}

	}

	//////////////////////////////////////////////////////////////////////////
#define ENUMTYPES					\
	ENUMTYPES_ONE(String)			\
	ENUMTYPES_ONE(Float)			\
	ENUMTYPES_ONE(Double)			\
	ENUMTYPES_ONE(Int8)				\
	ENUMTYPES_ONE(Int16)			\
	ENUMTYPES_ONE(Int32)			\
	ENUMTYPES_ONE(Int64)			\
	ENUMTYPES_ONE(UInt8)			\
	ENUMTYPES_ONE(UInt16)			\
	ENUMTYPES_ONE(UInt32)			\
	ENUMTYPES_ONE(UInt64)			\
	ENUMTYPES_ONE(VectorChar)		\
	ENUMTYPES_ONE(Date)				\
	ENUMTYPES_ONE(Time)				\
	ENUMTYPES_ONE(VectorVariant)	\
	ENUMTYPES_ONE(MapStringVariant)	\
	ENUMTYPES_ONE(Bool)				\
	ENUMTYPES_ONE(Tm)				\
	ENUMTYPES_ONE(Bitset8)			\
	ENUMTYPES_ONE(Bitset16)			\
	ENUMTYPES_ONE(Bitset32)			\
	ENUMTYPES_ONE(Bitset64)			\
	ENUMTYPES_ONE(Bitset128)		\
	ENUMTYPES_ONE(Bitset256)		\
	ENUMTYPES_ONE(Bitset512)		\
	ENUMTYPES_ONE(DateDuration)		\
	ENUMTYPES_ONE(TimeDuration)		\
	ENUMTYPES_ONE(DateTimeDuration)	\
	ENUMTYPES_ONE(MapVariantVariant)		\
	ENUMTYPES_ONE(MultimapVariantVariant)	\
	ENUMTYPES_ONE(MultimapStringVariant)	\
	ENUMTYPES_ONE(SetVariant)				\
	ENUMTYPES_ONE(MultisetVariant)			\
	ENUMTYPES_ONE(DequeVariant)				\
	ENUMTYPES_ONE(ListVariant)				//\






	//////////////////////////////////////////////////////////////////////////
	class VariantImpl
		: private Variant
	{
		//////////////////////////////////////////////////////////////////////////
		//выделение блока памяти под данные
		template <class T> void alloc()
		{
			if(sizeof(T) <= sizeof(_data))
			{
				//для autoexp.dat
#ifdef UTILS_VARIANT_DBGDATA
				_dbgData = &as<T>();
#endif
				return;
			}
			as<T*>() = (T*)new char[sizeof(T)];
			//для autoexp.dat
#ifdef UTILS_VARIANT_DBGDATA
			_dbgData = &as<T>();
#endif
		}
		
		//////////////////////////////////////////////////////////////////////////
		template <class T> void free()
		{
			//для autoexp.dat
#ifdef UTILS_VARIANT_DBGDATA
			_dbgData = NULL;
#endif
			if(sizeof(T) <= sizeof(_data))
			{
				return;
			}
			delete [] (char *)as<T*>();
		}

	public:
		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void validateType() const
		{
			if(etUnknown == Type2Enum<T>::et)
			{
				throw std::bad_cast();
			}
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void validateValue() const
		{
			if(type() != Type2Enum<T>::et || isNull())
			{
				throw std::bad_cast();
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void construct()
		{
			_et = -(ETypeStorage)etVoid;
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void construct()
		{
			_et = Type2Enum<T>::et;
			alloc<T>();
			new (&as<T>()) T();
		}

		//////////////////////////////////////////////////////////////////////////
		template <>
		void construct<Tm>()
		{
			_et = Type2Enum<Tm>::et;
			alloc<Tm>();
			new (&as<Tm>()) Tm;
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void construct(const T &v)
		{
			_et = Type2Enum<T>::et;
			alloc<T>();
			new (&as<T>()) T(v);
		}

		//////////////////////////////////////////////////////////////////////////
		template <>
		void construct(const Variant &v)
		{
			if(v.isNull())
			{
				_et = -(ETypeStorage)v.type();
				return;
			}
			else
			{
				_et = (ETypeStorage)v.type();
			}

			switch(type())
			{
			case etVoid: break;

#define ENUMTYPES_ONE(T) case et ## T: alloc<T>(); new (&as<T>()) T(v.as<T>()); break;
				ENUMTYPES
#undef ENUMTYPES_ONE
			default:
				assert(!"bad et");
				throw "bad et";
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void construct(const char *v)
		{
			_et = Type2Enum<String>::et;
			alloc<String>();
			new (&as<String>()) String(v);
		}

		//////////////////////////////////////////////////////////////////////////
		void destruct()
		{
			switch(type())
			{
			case etVoid: break;
#define ENUMTYPES_ONE(T) case et ## T: destruct<T>(); break;
				ENUMTYPES
#undef ENUMTYPES_ONE
			default:
				assert(!"bad et");
				throw "bad et";
			}
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void destruct()
		{
			assert(type() == (ETypeStorage)Type2Enum<T>::et);

			if(isNull())
			{
				return;
			}

			(&as<T>())->~T();
			free<T>();
			_et = -(ETypeStorage)Type2Enum<T>::et;
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void assign(const T &v)
		{
			if(is<T>())
			{
				setNull(false);
				as<T>() = v;
				return;
			}

			destruct();
			construct(v);
		}

		//////////////////////////////////////////////////////////////////////////
		template <>
		void assign(const Variant &v)
		{
			if(v.type() == type())
			{
				if(v.isNull())
				{
					setNull(true);
				}
				else
				{
					switch(type())
					{
					case etVoid: destruct(); break;
#define ENUMTYPES_ONE(T) case et ## T: assign<T>(v.as<T>()); break;
						ENUMTYPES
#undef ENUMTYPES_ONE
					default:
						assert(!"bad et");
						throw "bad et";
					}
				}
				return;
			}

			destruct();
			construct<Variant>(v);
		}

		//////////////////////////////////////////////////////////////////////////
		void assign(const char *v)
		{
			if(is<String>())
			{
				setNull(false);
				as<String>() = v;
				return;
			}

			destruct();
			construct(v);
		}

		//////////////////////////////////////////////////////////////////////////
		bool isNull() const
		{
			return _et < 0;
		}

		//////////////////////////////////////////////////////////////////////////
		void setNull(bool n)
		{
			if(n)
			{
				if(!isNull())
				{
					destruct();
				}
			}
			else
			{
				if(isNull())
				{
					switch(type())
					{
					case etVoid: break;

#define ENUMTYPES_ONE(T) case et ## T: construct<T>(); break;
						ENUMTYPES
#undef ENUMTYPES_ONE
					default:
						assert(!"bad et");
						throw "bad et";
					}
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////
		EType type() const
		{
			return (EType)(_et<0?-_et:_et);
		}

		//////////////////////////////////////////////////////////////////////////
		const void *data() const
		{
			if(isNull())
			{
				return NULL;
			}

			switch(type())
			{
			case etVoid: return NULL;
#define ENUMTYPES_ONE(T) case et ## T: return &as<T>();
				ENUMTYPES
#undef ENUMTYPES_ONE
			default:
				assert(!"bad et");
				throw "bad et";
			}

			//never here
			return NULL;
		}

		//////////////////////////////////////////////////////////////////////////
		void *data()
		{
			if(isNull())
			{
				return NULL;
			}

			switch(type())
			{
			case etVoid: return NULL;
#define ENUMTYPES_ONE(T) case et ## T: return &as<T>();
				ENUMTYPES
#undef ENUMTYPES_ONE
			default:
				assert(!"bad et");
				throw "bad et";
			}

			//never here
			return NULL;
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		T &as()
		{
			if(sizeof(T) <= sizeof(_data))
			{
				return *(T*)_data;
			}
			return **(T**)(void *)_data;
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		const T &as() const
		{
			if(sizeof(T) <= sizeof(_data))
			{
				return *(T*)_data;
			}
			return **(T**)(void *)_data;
		}

		//////////////////////////////////////////////////////////////////////////
		template<typename T> 
		bool is() const
		{
			return type() == Type2Enum<T>::et;
		}

		//////////////////////////////////////////////////////////////////////////
		template<typename T> 
		void forceType()
		{
			if(is<T>())
			{
				return;
			}

			destruct();
			_et = -(ETypeStorage)Type2Enum<T>::et;
		}
		//////////////////////////////////////////////////////////////////////////
		template<> 
		void forceType<Void>()
		{
			if(is<Void>())
			{
				return;
			}

			destruct();
			_et = -(ETypeStorage)Type2Enum<Void>::et;
		}

		//////////////////////////////////////////////////////////////////////////
		void forceType(EType et)
		{
			if(et == type())
			{
				return;
			}

			destruct();
			_et = -(ETypeStorage)et;
		}

		//////////////////////////////////////////////////////////////////////////
		bool less(const Variant &v) const
		{
			if(type() < v.type())
			{
				return true;
			}
			if(type() > v.type())
			{
				return false;
			}

			if(isNull())
			{
				if(!v.isNull())
				{
					return true;
				}
				return false;
			}
			else
			{
				if(v.isNull())
				{
					return false;
				}

				switch(type())
				{
				case etVoid: return false;
#define ENUMTYPES_ONE(T) case et ## T: return as<T>() < v.as<T>();
					ENUMTYPES
#undef ENUMTYPES_ONE
				default:
					assert(!"bad et");
					throw "bad et";
				}

			}


			//never here
			return false;
		}

		//////////////////////////////////////////////////////////////////////////
		bool equal(const Variant &v) const
		{
			if(type() != v.type() || isNull() != v.isNull())
			{
				return false;
			}

			if(isNull())
			{
				if(v.isNull())
				{
					return true;
				}
				return false;
			}
			else
			{
				if(v.isNull())
				{
					return false;
				}
				switch(type())
				{
				case etVoid: return true;
#define ENUMTYPES_ONE(T) case et ## T: return as<T>() == v.as<T>();
					ENUMTYPES
#undef ENUMTYPES_ONE
				default:
					assert(!"bad et");
					throw "bad et";
				}
			}

			//never here
			return false;
		}

		//////////////////////////////////////////////////////////////////////////
		boost::shared_array<char> save(size_t &size) const;
		bool load(boost::shared_array<char> data, size_t size);

	private:
		friend class boost::serialization::access;

		template<class Archive> void save(Archive & ar, const unsigned int version) const;
		template<class Archive> void load(Archive & ar, const unsigned int version);
		BOOST_SERIALIZATION_SPLIT_MEMBER()
	};
}

//BOOST_CLASS_TRACKING(utils::VariantImpl, boost::serialization::track_always)

//////////////////////////////////////////////////////////////////////////
//utils::Variant 
namespace boost 
{
	namespace serialization 
	{
		//////////////////////////////////////////////////////////////////////////
		template<class Archive>
		void serialize(Archive & ar, utils::Variant &x, const unsigned int /*version*/)
		{
			ar & static_cast<utils::VariantImpl &>(x);
		}
	} // namespace serialization
} // namespace boost


namespace utils
{
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	boost::shared_array<char> VariantImpl::save(size_t &size) const
	{
		utils::StreambufOnArray sbuf;
		{
			std::ostream os(&sbuf);
			utils::serialization::polymorphic_binary_portable_oarchive oa(os, boost::archive::no_header|boost::archive::no_codecvt);

			oa << *this;
		}

		size = sbuf.size();
		return sbuf.data();
	}

	//////////////////////////////////////////////////////////////////////////
	bool VariantImpl::load(boost::shared_array<char> data, size_t size)
	{
		try
		{
			utils::StreambufOnArray sbuf(data, size);
			{
				std::istream is(&sbuf);
				utils::serialization::polymorphic_binary_portable_iarchive ia(is, boost::archive::no_header|boost::archive::no_codecvt);

				ia >> *this;
			}
			return true;
		}
		catch(...)
		{
			std::cerr<<"exception in "<<__FUNCTION__<<std::endl;
		}

		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	template<class Archive>
	void VariantImpl::save(Archive & ar, const unsigned int /*version*/) const
	{
		ar & _et;

		if(!isNull())
		{
			switch(_et)
			{
			case etVoid: break;
#define ENUMTYPES_ONE(T) case et ## T: ar & as<T>(); break;
				ENUMTYPES
#undef ENUMTYPES_ONE
			default:
				assert(!"bad et");
				throw "bad et";
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	template<class Archive>
	void VariantImpl::load(Archive & ar, const unsigned int /*version*/)
	{
		boost::int16_t et;
		ar & et;

		if(et < 0)
		{
			destruct();
			forceType((EType)-et);
		}
		else
		{
			switch(et)
			{
			case etVoid: destruct(); break;
#define ENUMTYPES_ONE(T) case et ## T: forceType<T>(); setNull(false); ar & as<T>(); break;
				ENUMTYPES
#undef ENUMTYPES_ONE
			default:
				assert(!"bad et");
				throw "bad et";
			}
		}
	}
}

#pragma warning (pop)
