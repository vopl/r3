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
#define ENUM_VARIANT_TYPE(i,n,...)		\
	Variant::Variant(const n &v)	\
	{								\
			IMPL->validateType<n>();\
			IMPL->construct(v);		\
	}								//\

ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE
	Variant::Variant(const Variant &v)
	{
		IMPL->construct(v);
	}
	Variant::Variant(const char *v)
	{
		IMPL->construct(v);
	}

//////////////////////////////////////////////////////////////////////////
#define ENUM_VARIANT_TYPE(i,n,...)			\
	Variant &Variant::operator=(const n &v)	\
	{										\
		IMPL->validateType<n>();			\
		IMPL->assign(v);					\
		return *this;						\
	}										//\

ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE
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
#define ENUM_VARIANT_TYPE(i,n,...)	\
	Variant::operator n &()			\
	{								\
		IMPL->validateType<n>();	\
		IMPL->validateValue<n>();	\
		return IMPL->as<n>();		\
	}								//\

ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE

	Variant::operator const char *()
	{
		IMPL->validateType<String>();
		IMPL->validateValue<String>();
		return IMPL->as<String>().data();
	}


//////////////////////////////////////////////////////////////////////////
#define ENUM_VARIANT_TYPE(i,n,...)			\
	Variant::operator n const &() const		\
	{										\
		CIMPL->validateType<n>();			\
		CIMPL->validateValue<n>();			\
		return CIMPL->as<n>();				\
	}										//\

ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE


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
	template<typename T> void setNull(bool n)
	{
		IMPL->validateType<T>();
		IMPL->forceType<T>();
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
#define ENUM_VARIANT_TYPE(i,n,...) template Variant::n &Variant::as<Variant::n>(bool forceType);
ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE


	//////////////////////////////////////////////////////////////////////////
	template<typename T> T const &Variant::as() const
	{
		CIMPL->validateType<T>();
		CIMPL->validateValue<T>();
		return CIMPL->as<T>();
	}
#define ENUM_VARIANT_TYPE(i,n,...) template Variant::n const &Variant::as<Variant::n>() const;
ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE


	//////////////////////////////////////////////////////////////////////////
	template<typename T> T &Variant::as()
	{
		CIMPL->validateType<T>();
		CIMPL->validateValue<T>();
		return IMPL->as<T>();
	}
#define ENUM_VARIANT_TYPE(i,n,...) template Variant::n &Variant::as<Variant::n>();
ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE

	//////////////////////////////////////////////////////////////////////////
	template<typename T> bool Variant::is() const
	{
		CIMPL->validateType<T>();
		return CIMPL->is<T>();
	}
#define ENUM_VARIANT_TYPE(i,n,...) template bool Variant::is<Variant::n>() const;
ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE
template bool Variant::is<Variant::Void>() const;

	//////////////////////////////////////////////////////////////////////////
	template<typename T> void Variant::forceType()
	{
		IMPL->validateType<T>();
		return IMPL->forceType<T>();
	}
#define ENUM_VARIANT_TYPE(i,n,...) template void Variant::forceType<Variant::n>();
ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE
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
