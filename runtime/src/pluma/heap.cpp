#include "pluma/heap.hpp"
#include <malloc.h>

namespace pluma
{
	PLUMA_API void *alloc(unsigned int s)
	{
		return ::malloc(s);
	}

	PLUMA_API void free(void *p)
	{
		return ::free(p);
	}
}

