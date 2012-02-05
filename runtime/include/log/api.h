
#if defined OS_WINDOWS
#   ifdef liblog_EXPORTS
#	    define LOG_API __declspec(dllexport)
#   else
#	    define LOG_API __declspec(dllimport)
#   endif
#else
#   define LOG_API
#endif
