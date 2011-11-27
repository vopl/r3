#include "heap/heap.hpp"
#include <malloc.h>

namespace heap
{
	HEAP_API void *alloc(unsigned int s)
	{
		return (char *)::malloc(s+10) + 10;
	}

	HEAP_API void free(void *p)
	{
		return ::free((char *)p - 10);
	}
}

