#include "heap/heap.hpp"
#include <QtCore/qglobal.h>

namespace heap
{
	HEAP_API void *alloc(unsigned int s)
	{
		return qMalloc(s);
	}

	HEAP_API void free(void *p)
	{
		return qFree(p);
	}
}

