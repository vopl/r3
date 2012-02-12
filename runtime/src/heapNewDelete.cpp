#include "heap/heap.hpp"
#include <new>



//////////////////////////////////////////////////////////////////////////
/*!	\ingroup heap
	\brief Удаление массива
*/
void operator delete[](void *p) throw()
{
	heap::free(p);
}
/*!	\ingroup heap
	\brief Удаление объекта
*/
void operator delete(void *p) throw()
{
	heap::free(p);
}

/*!	\ingroup heap
	\brief Создание массива
*/
#ifdef _MSC_VER
void *operator new[](size_t s) throw(...)
#else
void *operator new[](std::size_t s) throw(std::bad_alloc)
#endif
{
	return heap::alloc((unsigned int)s);
}


/*!	\ingroup heap
	\brief Создание объекта
*/
#ifdef _MSC_VER
void *operator new(size_t s) throw(...)
#else
void *operator new(std::size_t s) throw(std::bad_alloc)
#endif
{
	return heap::alloc((unsigned int)s);
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
	return heap::alloc((unsigned int)s);
}

void * operator new[](
	size_t s,
	int,
	const char *,
	int
	)
{
	return heap::alloc((unsigned int)s);
}

void operator delete(void * p, int, const char *, int)
{
	heap::free(p);
}

void operator delete[](void * p, int, const char *, int)
{
	heap::free(p);
}

#endif
#endif