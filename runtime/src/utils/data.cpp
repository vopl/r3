#include "stdafx.h"
#include "utils/data.hpp"

namespace utils
{
	class VariantImpl
		: private Variant
	{
	public:
		template <class T>
		void construct(const T &v)
		{
			assert(0);
		}
		void construct()
		{
			assert(0);
		}
		void destruct()
		{
			assert(0);
		}

		template <class T>
		void assign(const T &v)
		{
			assert(0);
		}

		template <class T>
		T &as()
		{
			assert(0);
			static T t;
			return t;
		}

		template <class T>
		const T &as() const
		{
			assert(0);
			static T t;
			return t;
		}

		template<typename T> 
		bool is() const
		{
			assert(0);
			return false;
		}

		template<typename T> 
		void forceType()
		{
			assert(0);
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
	ENUMTYPES_ONE(MapStringVariant)	//\







	//////////////////////////////////////////////////////////////////////////
#define ENUMTYPES_ONE(T)			\
	Variant::Variant(const T &v)	\
	{								\
			IMPL->construct(v);		\
	}								//\

ENUMTYPES_ONE(Variant)
ENUMTYPES
#undef ENUMTYPES_ONE

//////////////////////////////////////////////////////////////////////////
#define ENUMTYPES_ONE(T)					\
	Variant &Variant::operator=(const T &v)	\
	{										\
		IMPL->assign(v);					\
		return *this;						\
	}										//\

ENUMTYPES_ONE(Variant)
ENUMTYPES
#undef ENUMTYPES_ONE

//////////////////////////////////////////////////////////////////////////
#define ENUMTYPES_ONE(T)			\
	Variant::operator T &()			\
	{								\
		return IMPL->as<T>();		\
	}								//\

ENUMTYPES
#undef ENUMTYPES_ONE


//////////////////////////////////////////////////////////////////////////
#define ENUMTYPES_ONE(T)					\
	Variant::operator T const &() const		\
	{										\
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
		return _evt;
	}

	template<typename T> T &Variant::as()
	{
		return IMPL->as<T>();
	}

	template<typename T> const T &Variant::as() const
	{
		return IMPL->as<T>();
	}

	template<typename T> bool Variant::is() const
	{
		return IMPL->is<T>();
	}

	template<typename T> void Variant::forceType()
	{
		return IMPL->forceType<T>();
	}
}
