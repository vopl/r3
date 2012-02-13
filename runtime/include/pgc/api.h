/*!	\defgroup pg Постгрес клиент (pg)

	Предоставляет 2 уровня доступа к БД PostgreSQL:
		- pgc (postgres client) - низкоуровневый интерфейс, соединится/отсоединится, выполнить SQL запрос, получить данные
		- pgs (postgres structure) - более высокий уровень, аля orm, еще не допилен
*/

/*!	\defgroup pgc Низкоуровневый постгрес клиент (pgс)
	\ingroup pg

	
	Представляет из себя обертку над библиотеклй libpq. Реализует не все возможности 
	libpq (например, нет оповещений, отмены запросов, поддержки COPY, ...). Предоставляет 
	средства для установки соединения, выполнения разовых запросов, выполнение с 
	использованием prepared statements, биндинг данных при исполнении запросов (на базе
	utils::Variant), получение результатов запросов (команд и SELECT-ов)

	Предоставляет возможность работы с сервером БД за счет следующих компонент:
		- db
		- connection
		- statement
		- result

	Примерный сценарий использования:

		- инициировать БД
			\code
				_db = pgc::Db("host=localhost port=5432 dbname=test user=test password=test");
			\endcode
		- произвести подключение
			\code
				pgc::Connection con = _db.allocConnection().data();
				assert(con);
			\endcode
		- исполнить запрос
			\code
				pgc::Result res1 = con.query("CREATE TABLE mytable(field integer);");
				con.query("INSERT INTO mytable VALUES($1);", utils::Variant(220)).wait();
				pgc::Result res2 = con.query("SELECT * FROM mytable WHERE field=$1", utils::Variant(220));
			\endcode
		- работать с результатом
			\code
				assert(pgc::ersCommandOk == res1.status());
				assert(pgc::ersTuplesOk == res2.status());
				int val = res2.fetchInt32(0,0);
				assert(220 == val);
			\endcode
		- подготовить и исполнить запрос prepared statements
			\code
				pgc::Statement stm("SELECT * FROM mytable WHERE field=$1");
				res2 = con.query(stm, utils::Variant(220));
				assert(1 == res2.rows());
				res2 = con.query(stm, utils::Variant(221));
				assert(0 == res2.rows());
				res2 = con.query(stm, utils::Variant(222));
				assert(0 == res2.rows());
				res2 = con.query(stm, utils::Variant(223));
				assert(0 == res2.rows());
			\endcode
		- закрыть все
			\code
				_db.reset();
			\endcode
*/

/*!	\defgroup pgs Высокоуровневый постгрес клиент (pgs)
	\ingroup pg

	TODO: документация
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
