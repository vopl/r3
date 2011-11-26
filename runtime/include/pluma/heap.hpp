#ifndef _PLUMA_HEAP_HPP_
#define _PLUMA_HEAP_HPP_

#include "pluma/config.hpp"

namespace pluma
{
	PLUMA_API void *alloc(unsigned int s);
	PLUMA_API void free(void *p);
}

#endif //_PLUMA_HEAP_HPP_
