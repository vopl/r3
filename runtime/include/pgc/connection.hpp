#ifndef _PGC_CONNECTION_HPP_
#define _PGC_CONNECTION_HPP_

#include "pgc/statement.hpp"
#include "pgc/result.hpp"
#include "utils/variant.hpp"
#include "async/future.hpp"

namespace pgc
{
	/*!	\ingroup pgc
		\brief Статус соединения

		Смотри pgc::Connection::status
	*/
	enum EConnectionStatus
	{
		ecsNull,	//!< объект Connection пустой
		ecsLost,	//!< соединение с сервером было но туперь утеряно
		ecsOk,		//!< соединение в порядке
	};


	//////////////////////////////////////////////////////////////////////////
	class ConnectionImpl;
	typedef boost::shared_ptr<ConnectionImpl> ConnectionImplPtr;

	//////////////////////////////////////////////////////////////////////////
	/*!	\ingroup pgc
		\brief Представляет одно соединение с БД.

		Данный интерфейсный класс реализует возможности по исполнению запросов в БД,
		одноразовых (SQL запроса передается в query как строка) или с использованием 
		prepared statements (SQL запроса обернут в pgc::Statement).

		В случае prepared statements имеет место \em "время жизни подготовленного запроса".
		По истечении этого времени подготовленный запрос ликвидируется. Ликвидация 
		производится в момент разрушения pgc::Connection. 
		
		Время жизни отсчитывается от момента создания prepared statement (первое исполнение 
		запроса, обернутого в pgc::Statement - это \em создание prepared statement и его 
		дальнейшее  исполнение). Величина этого времени на текущий момент жестко прописана 
		в коде и составляет \b "1 час". Возможно, в будущем, вынесу в конфиг. Это время 
		необходимо в силу динамики статистических свойств данных и оптимизатора запросов, 
		который формирует план исполнения запроса на момент его создания.
		Дабы не случилась ситуация, когда запрос был создан на малых данных, потом данные 
		подросли - и запрос исполняется с неактуальным планом - это может проблемно 
		сказываться на производительности.
	*/
	class PG_API Connection
	{
	protected:
		typedef ConnectionImplPtr ImplPtr;
		ImplPtr	_impl;

	public:
		/*!	\brief Создание нового пустого объекта соединения

			pimpl NULL

			Можно переприсвоить или переконструировать по копии из нормального.
		*/
		Connection();

		/*!	\brief Разрушение интерфейсного объекта

			Если разрушаемый объект владеет уникальным impl - то низкоуровневое соединение
			будет возвращено в pgc::Db. Так же, будет произведено удаление всех prepared 
			statements, время жизни которых истекло.
		*/
		~Connection();

		/// Проверка на пустой объект
		operator bool() const;

		/// Проверка на пустой объект
		bool operator!() const;

		/*!	\brief Простое исполнение запроса

			\param sql текст запроса, например "SELECT 220". В одном запросе может быть 
				несколько SQL команд, разделенных точкой с запятой, например 
				"SELECT 220; SELECT 380". В случае нескольких команд будет возвращен 
				результат исполнения только последней команды.

			\return объект Future, содержащий результат выполнения запроса pgc::Result

			Исполнение запроса будет произведено асинхронно, по готовности возвращаемый 
			Future будет установлен в сигнальное состояние и его pgc::Result будет 
			содержать результат выполнения.
		*/
		async::Future<Result> query(const char *sql);

		/*!	\brief Простое исполнение запроса с данными

			Поведение аналогично pgc::Connection::query(const char *sql)

			\param sql текст запроса с переменными, например "SELECT $1, $2"
			\param data Данные для биндинга в запрос, например utils::MVA("str", 220)

			\return объект Future, содержащий результат выполнения запроса pgc::Result

			Вариант с данными может быть представлен как скаляр, массив или ассоциативный массив

			- скаляр\n
				Скаляры привязываются в бинарном формате.
				Далее прдставлен перечень типов варианта, которые могут быть привязаны в 
				запрос, для каждого указан OID и наименование, из заголовков libpq:
				- utils::Variant::etString (0 => untyped literal string)
				- utils::Variant::etBool (16 => bool)
				- utils::Variant::etFloat (700 => float4)
				- utils::Variant::etDouble (701 => float8)
				- utils::Variant::etInt8 (21 => int2)
				- utils::Variant::etInt16 (21 => int2)
				- utils::Variant::etInt32 (23 => int4)
				- utils::Variant::etInt64 (20 => int8)
				- utils::Variant::etUInt8 (21 => int2)
				- utils::Variant::etUInt16 (23 => int4)
				- utils::Variant::etUInt32 (20 => int8)
				- utils::Variant::etUInt64 (20 => int8)
				- utils::Variant::etTm (1114 => timestamp)
				- utils::Variant::etDate (1082 => date)
				- utils::Variant::etDatetime (1114 => timestamp)
				- utils::Variant::etDateDuration (1186 => interval)
				- utils::Variant::etTimeDuration (1186 => interval)
				- utils::Variant::etDateTimeDuration (1186 => interval)
				- utils::Variant::etBitset8 (1562 => varbit)
				- utils::Variant::etBitset16 (1562 => varbit)
				- utils::Variant::etBitset32 (1562 => varbit)
				- utils::Variant::etBitset64 (1562 => varbit)
				- utils::Variant::etBitset128 (1562 => varbit)
				- utils::Variant::etBitset256 (1562 => varbit)
				- utils::Variant::etBitset512 (1562 => varbit)
				- utils::Variant::etVectorChar (17 => bytea)
				- utils::Variant::etUuid (2950 => uuid)
				- utils::Variant::etChar (18 => char)
			- массив\n
				Массивы перерабатываются очень просто: перебираются все элементы и каждый 
				биндится как скаляр. Типы вариантов - массивов такие:
				- utils::Variant::etVectorVariant
				- utils::Variant::etSetVariant (не вполне массив, но трактуется как последовательность)
				- utils::Variant::etMultisetVariant (тоже)
				- utils::Variant::etDequeVariant
				- utils::Variant::etListVariant
			- ассоциативный массив\n
				Ассоциативеый массив рассматривается как набор пар ключ-значение, 
				ключ всегда приводится к строке, должен содержать значения в формате "$N",
				где N - число у переменной в запросе. Значение по этому ключу будет связано
				с одноименной переменной в запросе как скаляр. Набор ключе-имен должен 
				соответствовать набору переменных в запросе, иначе поведение не 
				определено (скорее всего будет выброшено какое нибудь злое исключение)
				- utils::Variant::etMapStringVariant
				- utils::Variant::etMapVariantVariant
				- utils::Variant::etMultimapStringVariant
				- utils::Variant::etMultimapVariantVariant

			Пример использования скаляра:
			\code
				relult = query("SELECT $1", utils::Variant("string"));
				relult = query("SELECT $1", utils::Variant(220));
				relult = query("SELECT $1", utils::Variant(std::bitset("11010111001")));
				relult = query("SELECT $1", utils::Variant((boost::uuids::uuid)boost::uuids::random_generator()));
			\endcode


			Пример использования массива:
			\code
				relult = query("SELECT $1, $2, $3", utils::MVA("string", 1, 'c'));
			\endcode

			Пример использования ассоциативного массива:
			\code
				relult = query("SELECT $1, $2, $3", utils::MVM("$2", "string", "$1", 1, "$3", 'c'));
			\endcode
		*/
		async::Future<Result> query(const char *sql, const utils::Variant &data);

		/*!	\copydoc pgc::Connection::query(const char *sql)
		*/
		async::Future<Result> query(const std::string &sql);

		/*!	\copydoc pgc::Connection::query(const char *sql, const utils::Variant &data)
		*/
		async::Future<Result> query(const std::string &sql, const utils::Variant &data);

		/*!	\brief Исполнение запроса с подготовкой

			\param s запрос
			\param withPrepare если установлен в false - то вызов аналогичен 
				pgc::Connection::query(const char *sql), никакие подготовки не делаются,
				текст запроса берется из pgc::Statment::getSql.
				Если true - то будет использована возможность prepared statements.

			\return объект Future, содержащий результат выполнения запроса pgc::Result

			При использовании prepared statements (withPrepare==true), запрос перед 
			исполнением подготавливается, затем исполняется уже подготовленный запрос. 
			Если ранее запрос уже исполнялся на этом экземпляре Connection при 
			withPrepare==true - то исполняется подготовленный ранее запрос.

			Запрос подготавливается для экземпляра Connection, то есть если один и тот же
			запрос исполнять на разных экземплярах Connection - то для каждого будет
			производится подготовка. Такое поведение диктуется устройством postgres.
			
			Подготовленный запрос может быть уничтожен, тогда при повторном вызове он
			будет подготовлен заново. Уничтожение преследует несколько целей:
				- статистические свойств данных со временем изменяются, как следствие - 
					план исполнения, построенный на устаревших статистиках становится не 
					оптимальным. Надо перестраивать план,
				- освобождение ресурсов, занимаемых подготовленными запросами, особенно
					редко исполняемыми.

			Для уничтожения подготовленного запроса есть два критерия
				- время жизни, отсчитывается от момента подготовки. Значение на текущий 
					момент жестко прописано в коде и составляет "1 час", возможно,
					в будущем вынесу эту цифру в конфиг. Уничтожение подготовленного 
					запроса производится когда его время жизни превышает данную цифру
				- количество подготовленных запросов для экземпляра Connection. Значение,
					так же, жестко прописано в коде и составляет 1000 штук. По этому 
					критерию подготовленные запросы уничтожаются следующим образом: 
					у каждого запроса есть маркер времени последнего доступа, все 
					запросы упорядочиваются по этому маркеру и уничтожаются те, которые
					не вошли в первую тысячу
		*/
		async::Future<Result> query(Statement s, bool withPrepare=true);

		/*!	\brief Исполнение запроса с подготовкой и с данными
			
			По prepared statements этот метод аналогичен pgc::Connection::query(Statement s, bool withPrepare).

			По данным - смотри pgc::Connection::query(const char *sql, const utils::Variant &data).
		*/
		async::Future<Result> query(Statement s, const utils::Variant &data, bool withPrepare=true);

		/*!	\brief Предоставляет статус соединения
			
			\return статус, значения смотри pgc::EConnectionStatus
		*/
		EConnectionStatus status();
	};
}
#endif
