#include "utils/variant.hpp"
#include <new>

#include "variantImpl.hpp"

namespace utils
{
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
	Variant::Variant(const char *v)
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

Variant &Variant::operator=(const char * v)
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

	Variant::operator const char *()
	{
		IMPL->validateType<String>();
		IMPL->validateValue<String>();
		return IMPL->as<String>().data();
	}


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
		if(this != &v)
		{
			static const size_t s = sizeof(*this);
			char tmp[s];
			memcpy(tmp, this, s);
			memcpy(this, &v, s);
			memcpy(&v, tmp, s);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	bool Variant::empty() const
	{
		return etNull == _et;
	}

	//////////////////////////////////////////////////////////////////////////
	Variant::EType Variant::type() const
	{
		return (EType)_et;
	}

	//////////////////////////////////////////////////////////////////////////
	void Variant::clear()
	{
		return IMPL->clear();
	}

	//////////////////////////////////////////////////////////////////////////
	void *Variant::data()
	{
		return IMPL->data();
	}

	//////////////////////////////////////////////////////////////////////////
	void const *Variant::data() const
	{
		return IMPL->data();
	}

	//////////////////////////////////////////////////////////////////////////
	template<typename T> T &Variant::as(bool forceType)
	{
		IMPL->validateType<T>();
		
		if(forceType)
		{
			IMPL->forceType<T>();
		}
		else
		{
			IMPL->validateValue<T>();
		}

		return IMPL->as<T>();
	}
#define ENUMTYPES_ONE(T) template Variant::T &Variant::as<Variant::T>(bool forceType);
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
	void Variant::forceType(EType et)
	{
		return IMPL->forceType(et);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Variant::operator <(const Variant &v) const
	{
		return IMPL->less(v);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Variant::operator ==(const Variant &v) const
	{
		return IMPL->equal(v);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Variant::operator !=(const Variant &v) const
	{
		return !IMPL->equal(v);
	}




}


#include "variantDumper.hpp"
