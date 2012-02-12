/*!	\defgroup pg Постгрес клиент (pg)

	Предоставляет 2 уровня доступа к БД PostgreSQL:
		- pgc (postgres client) - низкоуровневый интерфейс, соединится/отсоединится, выполнить SQL запрос, получить данные
		- pgs (postgres structure) - более высокий уровень, аля orm, еще не допилен
*/
#if defined OS_WINDOWS
#   ifdef libpg_EXPORTS
#	    define PG_API __declspec(dllexport)
#   else
#	    define PG_API __declspec(dllimport)
#   endif
#else
#   define PG_API
#endif
