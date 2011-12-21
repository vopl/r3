
#ifdef libasync_EXPORTS
#	define ASYNC_API __declspec(dllexport)
#else
#	define ASYNC_API __declspec(dllimport)
#endif
