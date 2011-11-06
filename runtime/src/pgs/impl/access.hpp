#ifndef _PGS_IMPL_ACCESS_HPP_
#define _PGS_IMPL_ACCESS_HPP_

#include "pgs/expression.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		template <class Base>
		class Access
			: public Base
		{
		public:
			Access(const Base &base);
			Access(const typename Base::Impl_ptr &impl);

			typename Base::Impl_ptr impl();
			operator typename Base::Impl_ptr();
		};


		//////////////////////////////////////////////////////////////////////////
		template <class Base>
		Access<Base>::Access(const Base &base)
			: Base(base)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		template <class Base>
		Access<Base>::Access(const typename Base::Impl_ptr &impl)
		{
			_impl = impl;
		}

		//////////////////////////////////////////////////////////////////////////
		template <class Base>
		typename Base::Impl_ptr Access<Base>::impl()
		{
			return boost::static_pointer_cast<typename Base::Impl_ptr::element_type>(_impl);
		}

		//////////////////////////////////////////////////////////////////////////
		template <class Base>
		Access<Base>::operator typename Base::Impl_ptr()
		{
			return boost::static_pointer_cast<typename Base::Impl_ptr::element_type>(_impl);
		}

	}
}

#endif
