#ifndef _PGS_IMPL_ACCESS_HPP_
#define _PGS_IMPL_ACCESS_HPP_

#include "pgs/expression.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	class ImplAccess
		: public Base
	{
	public:
		ImplAccess(const Base &base);
		ImplAccess(const typename Base::Impl_ptr &impl);

		typename Base::Impl_ptr impl();
		operator typename Base::Impl_ptr();
	};


	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	ImplAccess<Base>::ImplAccess(const Base &base)
		: Base(base)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	ImplAccess<Base>::ImplAccess(const typename Base::Impl_ptr &impl)
	{
		_impl = impl;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	typename Base::Impl_ptr ImplAccess<Base>::impl()
	{
		return boost::static_pointer_cast<typename Base::Impl_ptr::element_type>(_impl);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	ImplAccess<Base>::operator typename Base::Impl_ptr()
	{
		return boost::static_pointer_cast<typename Base::Impl_ptr::element_type>(_impl);
	}
}

#endif
