#include "pluma/heap.hpp"
#include <new>



//////////////////////////////////////////////////////////////////////////
void operator delete[](void *p) throw()
{
	pluma::free(p);
}
void operator delete(void *p) throw()
{
	pluma::free(p);
}

#ifdef _MSC_VER
void *operator new[](size_t s) throw(...)
#else
void *operator new[](std::size_t s) throw(std::bad_alloc)
#endif
{
	return pluma::alloc((unsigned int)s);
}
#ifdef _MSC_VER
void *operator new(size_t s) throw(...)
#else
void *operator new(std::size_t s) throw(std::bad_alloc)
#endif
{
	return pluma::alloc((unsigned int)s);
}






#ifdef _MSC_VER
#if _MSC_VER < 1200
void * operator new(
	size_t s,
	int,
	const char *,
	int
	)
{
	return pluma::alloc((unsigned int)s);
}

void * operator new[](
	size_t s,
	int,
	const char *,
	int
	)
{
	return pluma::alloc((unsigned int)s);
}

void operator delete(void * p, int, const char *, int)
{
	pluma::free(p);
}

void operator delete[](void * p, int, const char *, int)
{
	pluma::free(p);
}

#endif
#endif