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
		ImplAccess(const typename Base::ImplPtr &impl);

		typename Base::ImplPtr impl();
		operator typename Base::ImplPtr();
	};


	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	ImplAccess<Base>::ImplAccess(const Base &base)
		: Base(base)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	ImplAccess<Base>::ImplAccess(const typename Base::ImplPtr &impl)
	{
		_impl = impl;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	typename Base::ImplPtr ImplAccess<Base>::impl()
	{
		return boost::static_pointer_cast<typename Base::ImplPtr::element_type>(_impl);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Base>
	ImplAccess<Base>::operator typename Base::ImplPtr()
	{
		return boost::static_pointer_cast<typename Base::ImplPtr::element_type>(_impl);
	}
}

#endif
