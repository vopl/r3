
#if defined OS_WINDOWS
#   ifdef libasync_EXPORTS
#	    define ASYNC_API __declspec(dllexport)
#   else
#	    define ASYNC_API __declspec(dllimport)
#   endif
#else
#	    define ASYNC_API
#endif
