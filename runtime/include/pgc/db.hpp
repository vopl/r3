#ifndef _PGC_DB_HPP_
#define _PGC_DB_HPP_

#include "async/service.hpp"
#include "pgc/connection.hpp"
#include "async/future.hpp"

/*!	\ingroup pgc
	\brief Пространство имен низкоуровневого клиента postgres
*/
namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	class DbImpl;
	typedef boost::shared_ptr<DbImpl> DbImplPtr;

	//////////////////////////////////////////////////////////////////////////
	/*!	\ingroup pgc
		\brief Интерфейс к БД

		Позволяет устанавливать соединения с БД (они уже дальше будут исполнять запросы)

		Реализован с использованием pimpl, несколько объектов могут шарить один и тот 
		же impl.
		
		Объект Db может быть пустым (impl нулевой).

		Пустой объект может быть полезен в случае если в каком то месте нужна переменная,
		но инициализировать ее пока нечем.

		Пустой объект можно переприсвоить нормальным через оператор присваивания или 
		конструктор копирования (оба реализованы по умолчанию)

		Пример
		\code
		Db myDb;
		//myDb пустой

		myDb = Db("host=localhost port=5432 dbname=test user=test password=test");
		//теперь можно использовать
		\endcode

		Проверить на пустоту можно с помощью операторов 
		- operator bool() const;
		- bool operator!() const;

		Для пустого объекта нельзя вызывать allocConnection, поведение не определено
	*/
	class PG_API Db
	{
	protected:
		typedef DbImplPtr ImplPtr;
		ImplPtr	_impl;

	public:
		/*!	\brief Конструирование пустого объекта
		*/
		Db();

		/*!	\brief Конструирование
			
			\param conninfo строка подключения по правилам libpq, например
				\verbatim
					"host=localhost port=5432 dbname=test user=test password=test"
				\endverbatim

			\param maxConnections максимальное количество одновременно открытых подключений

			\param onConnectionMade пользовательский функтор, будет вызван при установлении 
				нового подключения, size_t параметр будет отображать количество установленных 
				подключений на момент вызова. Если не задан - то, соответственн, вызван 
				не будет.
			\param onConnectionLost аналогично, при потере (или закрытии) соединения

			\attention предлагаю зафиксировать правило: maxConnections всегда делать не 
				меньше 5 - это позволит развязать руки многим функционалам, которые 
				оптимально работают с несколькими соединениями одновременно.
		*/
		Db(const char *conninfo,
			size_t maxConnections=10,
			boost::function<void (size_t)> onConnectionMade = boost::function<void (size_t)>(),
			boost::function<void (size_t)> onConnectionLost = boost::function<void (size_t)>());

		/*!	\brief Деструктор

			В случае, если разрушаемый объект владеет уникальным impl - будет произведено 
			закрытие всех подключений.
		*/
		~Db();

		/// Проверка на пустоту
		operator bool() const;

		/// Проверка на пустоту
		bool operator!() const;

		/*! \brief Сброс объекта в пустое состояние
			
			В случае, если объект владеет уникальным impl - будет произведено 
			закрытие всех подключений.
		*/
		void reset();

		/*!	\brief Создание подключения
			
			Производит подключение к БД. Кэширует созданные соединения, то 
			есть если ранее соединение было создано и его объект pgc::Connection разрушен -
			то соединение с сервером не закрывается и может быть выделено вновь в новом
			pgc::Connection.

			Установление нового соединения производится асинхронно, смотри async::Future.

			В случае если невозможно выделить новое соединение (достигнут предел 
			maxConnections, сервер не отвечает, ...) - async::Future не будет переведен в
			сигнальное состояние. Как только появится возможность предоставить соединение 
			(разрушен ранее выделенный объект pgc::Connection, сервер БД поднялся, ...) - 
			это сразу будет сделано.

			\warning В случае останова Db пользователю может быть возвращен пустой pgc::Connection (см 
			pgc::Connection::operator bool).

			\warning Осторожнее с одновременным выделением большого числа коннектов! 
			Пример проблемы:
			\code
				//инициировали бд, максимум 2 соединения
				myDb = Db("host=localhost port=5432 dbname=test user=test password=test", 2);

				Future<Connection> с1 = myDb.allocConnection();
				Future<Connection> с2 = myDb.allocConnection();
				Future<Connection> с3 = myDb.allocConnection();//вызов пройдет нормально

				с1.wait();//нормально
				с2.wait();//нормально
				с3.wait();//не пройдет никогда, потому что лимит в 2 соединения исчерпан
				//фибер висит навсегда (deadlock). Ну или экземпляр останавливается (сработал
				//последний деструктор Db, явный вызов reset, ...) - тогда вызов c3.wait() 
				//завершится.
			\endcode
		*/
		async::Future<Connection> allocConnection();
	};
}
#endif
