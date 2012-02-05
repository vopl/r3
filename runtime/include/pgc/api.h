
#if defined OS_WINDOWS
#   ifdef libpg_EXPORTS
#	    define PG_API __declspec(dllexport)
#   else
#	    define PG_API __declspec(dllimport)
#   endif
#else
#   define PG_API
#endif
