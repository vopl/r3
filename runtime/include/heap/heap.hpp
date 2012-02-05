#ifndef _HEAP_HEAP_HPP_
#define _HEAP_HEAP_HPP_



#if defined(OS_WINDOWS)
#	ifndef HEAP_STATIC
#		ifdef HEAP_EXPORTS
#			define HEAP_API __declspec(dllexport)
#		else
#			define HEAP_API __declspec(dllimport)
#		endif
#	else
#		define HEAP_API
#	endif
#else
#	define HEAP_API
#endif







namespace heap
{
	HEAP_API void *alloc(unsigned int s);
	HEAP_API void free(void *p);
}

#endif
