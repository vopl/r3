
#ifdef libpgc_EXPORTS
#	define PGC_API __declspec(dllexport)
#else
#	define PGC_API __declspec(dllimport)
#endif
