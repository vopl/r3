#include "stdafx.h"
#include "utils/variant.hpp"
#include <new>
#include <typeinfo>

namespace utils
{

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
	ENUMTYPES_ONE(TimeDuration)		//\










	//////////////////////////////////////////////////////////////////////////
	class VariantImpl
		: private Variant
	{
		//тип в енум типа
		template <class T> struct Type2Evt	{ static const EVariantType evt = evtNull;	};
#define ENUMTYPES_ONE(T) template <> struct Type2Evt<T>	{ static const EVariantType evt = evt ## T;	};
ENUMTYPES
#undef ENUMTYPES_ONE

		//выделение блока памяти под данные
		template <class T> void alloc()
		{
			if(sizeof(T) <= sizeof(_data))
			{
				return;
			}
			as<T*>() = (T*)new char[sizeof(T)];
		}
		template <class T> void free()
		{
			if(sizeof(T) <= sizeof(_data))
			{
				return;
			}
			delete [] (char *)as<T*>();
		}

	public:
		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void validateType()
		{
			if(evtNull == Type2Evt<T>::evt)
			{
				throw std::bad_cast();
			}
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void validateValue()
		{
			if(_evt != Type2Evt<T>::evt)
			{
				throw std::bad_cast();
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void construct()
		{
			_evt = evtNull;
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void construct()
		{
			_evt = Type2Evt<T>::evt;
			alloc<T>();
			new (&as<T>()) T;
		}
		
		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void construct(const T &v)
		{
			_evt = Type2Evt<T>::evt;
			alloc<T>();
			new (&as<T>()) T(v);
		}

		template <>
		void construct(const Variant &v)
		{
			_evt = v.type();

			switch(_evt)
			{
			case evtNull: break;

#define ENUMTYPES_ONE(T) case evt ## T: alloc<T>(); new (&as<T>()) T(v.as<T>()); break;
				ENUMTYPES
#undef ENUMTYPES_ONE
			default:
				assert(!"bad evt for destruct");
				throw "bad evt for destruct";
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void destruct()
		{
			switch(_evt)
			{
			case evtNull: break;
#define ENUMTYPES_ONE(T) case evt ## T: destruct<T>(); break;
ENUMTYPES
#undef ENUMTYPES_ONE
			default:
				assert(!"bad evt for destruct");
				throw "bad evt for destruct";
			}
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void destruct()
		{
			(&as<T>())->~T();
			free<T>();
			_evt = evtNull;
		}


		template <class T>
		void assign(const T &v)
		{
			if(is<T>())
			{
				as<T>() = v;
				return;
			}

			destruct();
			construct<T>(v);
		}

		template <>
		void assign(const Variant &v)
		{
			if(v.type() == _evt)
			{
				switch(_evt)
				{
#define ENUMTYPES_ONE(T) case evt ## T: assign<T>(v.as<T>()); break;
					ENUMTYPES
#undef ENUMTYPES_ONE
				default:
					assert(!"bad evt for destruct");
					throw "bad evt for destruct";
				}
				return;
			}

			destruct();
			construct<Variant>(v);
		}

		template <class T>
		T &as()
		{
			if(sizeof(T) <= sizeof(_data))
			{
				return *(T*)_data;
			}
			return **(T**)(void *)_data;
		}

		template <class T>
		const T &as() const
		{
			if(sizeof(T) <= sizeof(_data))
			{
				return *(T*)_data;
			}
			return **(T**)(void *)_data;
		}

		template<typename T> 
		bool is() const
		{
			return _evt == Type2Evt<T>::evt;
		}

		template<typename T> 
		void forceType()
		{
			if(is<T>())
			{
				return;
			}

			destruct();
			construct<T>();
		}

		void forceType(EVariantType evt)
		{
			if(evt == _evt)
			{
				return;
			}

			destruct();
			switch(_evt)
			{
			case evtNull: break;

#define ENUMTYPES_ONE(T) case evt ## T: construct<T>(); break;
				ENUMTYPES
#undef ENUMTYPES_ONE
			default:
				assert(!"bad evt for destruct");
				throw "bad evt for destruct";
			}
		}
	};
#define IMPL ((VariantImpl *)this)

	//////////////////////////////////////////////////////////////////////////
	Variant::~Variant()
	{
		IMPL->destruct();
	}

	//////////////////////////////////////////////////////////////////////////
	Variant::Variant()
	{
		IMPL->construct();
	}














	//////////////////////////////////////////////////////////////////////////
#define ENUMTYPES_ONE(T)			\
	Variant::Variant(const T &v)	\
	{								\
			IMPL->validateType<T>();\
			IMPL->construct(v);		\
	}								//\

ENUMTYPES
#undef ENUMTYPES_ONE
	Variant::Variant(const Variant &v)
	{
		IMPL->construct(v);
	}

//////////////////////////////////////////////////////////////////////////
#define ENUMTYPES_ONE(T)					\
	Variant &Variant::operator=(const T &v)	\
	{										\
		IMPL->validateType<T>();			\
		IMPL->assign(v);					\
		return *this;						\
	}										//\

ENUMTYPES
#undef ENUMTYPES_ONE
	Variant &Variant::operator=(const Variant &v)
	{
		IMPL->assign(v);
		return *this;
	}

//////////////////////////////////////////////////////////////////////////
#define ENUMTYPES_ONE(T)			\
	Variant::operator T &()			\
	{								\
		IMPL->validateType<T>();	\
		IMPL->validateValue<T>();	\
		return IMPL->as<T>();		\
	}								//\

ENUMTYPES
#undef ENUMTYPES_ONE


//////////////////////////////////////////////////////////////////////////
#define ENUMTYPES_ONE(T)					\
	Variant::operator T const &() const		\
	{										\
		IMPL->validateType<T>();			\
		IMPL->validateValue<T>();			\
		return IMPL->as<T>();				\
	}										//\

ENUMTYPES
#undef ENUMTYPES_ONE


	//////////////////////////////////////////////////////////////////////////
	void Variant::swap(Variant & v)
	{
		std::swap(_evt, v._evt);
		//std::swap(_data, v._data);
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Variant::empty() const
	{
		return evtNull == _evt;
	}

	//////////////////////////////////////////////////////////////////////////
	EVariantType Variant::type() const
	{
		return (EVariantType)_evt;
	}

	//////////////////////////////////////////////////////////////////////////
	template<typename T> T &Variant::as()
	{
		IMPL->validateType<T>();
		IMPL->validateValue<T>();
		return IMPL->as<T>();
	}
#define ENUMTYPES_ONE(T) template Variant::T &Variant::as<Variant::T>();
ENUMTYPES
#undef ENUMTYPES_ONE


	//////////////////////////////////////////////////////////////////////////
	template<typename T> T const &Variant::as() const
	{
		IMPL->validateType<T>();
		IMPL->validateValue<T>();
		return IMPL->as<T>();
	}
#define ENUMTYPES_ONE(T) template Variant::T const &Variant::as<Variant::T>() const;
ENUMTYPES
#undef ENUMTYPES_ONE

	//////////////////////////////////////////////////////////////////////////
	template<typename T> bool Variant::is() const
	{
		IMPL->validateType<T>();
		return IMPL->is<T>();
	}
#define ENUMTYPES_ONE(T) template bool Variant::is<Variant::T>() const;
ENUMTYPES
#undef ENUMTYPES_ONE

	//////////////////////////////////////////////////////////////////////////
	template<typename T> void Variant::forceType()
	{
		IMPL->validateType<T>();
		return IMPL->forceType<T>();
	}
#define ENUMTYPES_ONE(T) template void Variant::forceType<Variant::T>();
ENUMTYPES
#undef ENUMTYPES_ONE

	//////////////////////////////////////////////////////////////////////////
	void Variant::forceType(EVariantType evt)
	{
		return IMPL->forceType(evt);
	}

}



// #include <boost/variant.hpp>
// 
// #include <iostream>
// int f()
// {
// #define ENUMTYPES_ONE(T) std::cout<< # T <<":\t"<<sizeof(utils::Variant::T)<<std::endl;
// 	ENUMTYPES
// #undef ENUMTYPES_ONE
// 
// 	std::cout<< "Variant" <<":\t"<<sizeof(utils::Variant)<<std::endl;
// 
// 	typedef boost::variant<char, std::string, std::bitset<512> > BV;
// 
// 	std::cout<< "BV" <<":\t"<<sizeof(BV)<<std::endl;
// 
// 	return 220;
// }
// static int i = f();