#include "pch.h"
#include "utils/variant.hpp"
#include <new>

#include "variantImpl.hpp"

#define IMPL (static_cast<VariantImpl *>(this))
#define CIMPL (static_cast<const VariantImpl *>(this))

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
		CIMPL->validateType<T>();			\
		CIMPL->validateValue<T>();			\
		return CIMPL->as<T>();				\
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
	bool Variant::isNull() const
	{
		return CIMPL->isNull();
	}

	//////////////////////////////////////////////////////////////////////////
	void Variant::setNull(bool n)
	{
		return IMPL->setNull(n);
	}

	//////////////////////////////////////////////////////////////////////////
	Variant::EType Variant::type() const
	{
		return CIMPL->type();
	}

	//////////////////////////////////////////////////////////////////////////
	void *Variant::data()
	{
		return IMPL->data();
	}

	//////////////////////////////////////////////////////////////////////////
	void const *Variant::data() const
	{
		return CIMPL->data();
	}

	//////////////////////////////////////////////////////////////////////////
	template<typename T> T &Variant::as(bool forceType)
	{
		IMPL->validateType<T>();
		
		if(forceType)
		{
			IMPL->forceType<T>();
			IMPL->setNull(false);
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
		CIMPL->validateType<T>();
		CIMPL->validateValue<T>();
		return CIMPL->as<T>();
	}
#define ENUMTYPES_ONE(T) template Variant::T const &Variant::as<Variant::T>() const;
ENUMTYPES
#undef ENUMTYPES_ONE

	//////////////////////////////////////////////////////////////////////////
	template<typename T> bool Variant::is() const
	{
		CIMPL->validateType<T>();
		return CIMPL->is<T>();
	}
#define ENUMTYPES_ONE(T) template bool Variant::is<Variant::T>() const;
ENUMTYPES
#undef ENUMTYPES_ONE
template bool Variant::is<Variant::Void>() const;

	//////////////////////////////////////////////////////////////////////////
	template<typename T> void Variant::forceType()
	{
		IMPL->validateType<T>();
		return IMPL->forceType<T>();
	}
#define ENUMTYPES_ONE(T) template void Variant::forceType<Variant::T>();
ENUMTYPES
#undef ENUMTYPES_ONE
template void Variant::forceType<Variant::Void>();

	//////////////////////////////////////////////////////////////////////////
	void Variant::forceType(EType et)
	{
		return IMPL->forceType(et);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Variant::operator <(const Variant &v) const
	{
		return CIMPL->less(v);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Variant::operator ==(const Variant &v) const
	{
		return CIMPL->equal(v);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Variant::operator !=(const Variant &v) const
	{
		return !CIMPL->equal(v);
	}

	//////////////////////////////////////////////////////////////////////////
	boost::shared_array<char> Variant::save(boost::uint32_t &size) const
	{
		return CIMPL->save(size);
	}
	
	//////////////////////////////////////////////////////////////////////////
	bool Variant::load(boost::shared_array<char> data, boost::uint32_t size)
	{
		return IMPL->load(data, size);
	}




}


#include "variantDumper.hpp"
