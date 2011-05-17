#ifndef _PGC_COMMON_HPP_
#define _PGC_COMMON_HPP_

#include <boost/cstdint.hpp>
#include <string>
#include <exception>
#include <boost/shared_ptr.hpp>

namespace pgc
{
}

#ifdef LIBPGC_EXPORTS
#define LIBPGC_API __declspec(dllexport)
#else
#define LIBPGC_API __declspec(dllimport)
#endif

#endif
