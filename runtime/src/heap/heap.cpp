#include "heap/heap.hpp"
#include <malloc.h>

namespace heap
{
	HEAP_API void *alloc(unsigned int s)
	{
		return ::malloc(s);
	}

	HEAP_API void free(void *p)
	{
		return ::free(p);
	}
}

