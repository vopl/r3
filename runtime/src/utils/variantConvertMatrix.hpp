#ifndef _UTILS_IMPL_VARIANTCONVERTMATRIX_HPP_
#define _UTILS_IMPL_VARIANTCONVERTMATRIX_HPP_

namespace utils
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		template <class Dst, class Src>
		struct VariantConvertMatrix
		{
			static bool exec(Dst &dst, const Src &src)
			{
				assert(!"no transform");
				return false;
			}
		};


		//////////////////////////////////////////////////////////////////////////
		//identity
		template <class T>
		struct VariantConvertMatrix<T, T>
		{
			static bool exec(T &dst, const T &src)
			{
				dst = src;
				return true;
			}
		};
	}
}

#endif
