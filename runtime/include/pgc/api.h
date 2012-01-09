
#ifdef libpg_EXPORTS
#	define PG_API __declspec(dllexport)
#else
#	define PG_API __declspec(dllimport)
#endif
