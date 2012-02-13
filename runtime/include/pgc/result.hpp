#ifndef _PGC_RESULT_HPP_
#define _PGC_RESULT_HPP_

#include "pgc/api.h"
#include "utils/variant.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	/*! \ingroup pgc
		\brief Статус результата запроса

		Смотри pgc::Result::status
	*/
	enum EResultStatus
	{
		/*!	\brief Команда успешно выполнена

			Запрос-команда успешно выполнен (DDL или DML), в случае DML можно получить 
			количество переработанных строк, смотри pgc::Result::cmdRows
		*/
		ersCommandOk,

		/*!	\brief Выборка успешно выполнена и есть данные

			Использовать выбранные данные можно через pgc::Result::fetch и другие методы
		*/
		ersTuplesOk,

		/*!	\brief Ошибка при исполнении запроса

			Детали ошибки можно получить через pgc::Result::errorMsg, pgc::Result::errorCode
		*/
		ersError,
	};

	//////////////////////////////////////////////////////////////////////////
	class ResultImpl;
	typedef boost::shared_ptr<ResultImpl> ResultImplPtr;

	//////////////////////////////////////////////////////////////////////////
	/*!	\ingroup pgc
		\brief Результат исполнения запроса

		Объекты Result могут быть получены через pgc::Connection::query.

		Как видно по pgc::EResultStatus, эти объекты предназначены для следующего:
			- предоставление информации о ошибке в запросе
			- для INSERT, UPDATE - предоставление количества переработанных строк, для
				DDL запросов - признак успешного выполнения
			- для SELECT - предоставление выбранных данных

		Все методы являются синхронными, то есть на момент формирования объекта Result
		от сервера уже получены все данные.
	*/
	class PG_API Result
	{

	protected:
		typedef ResultImplPtr ImplPtr;
		ImplPtr	_impl;

	public:
		//Result();

		/*!	\brief Статус результата запроса
			
			Детали смотри в pgc::EResultStatus
		*/
		EResultStatus status();

		/*!	\brief Текст сообщения об ошибке

			\retval сообщение - в случае если status вернул ersError
			\retval пусто (пустая строка, не NULL) - если ошибки не было
		*/
		const char *errorMsg();

		/*!	\brief Код ошибки
			
			Аналогично errorMsg, но возвращается код. Значения смотри в документации 
			postgres, в приложении A, например тут 
			http://www.postgresql.org/docs/9.1/interactive/errcodes-appendix.html

			\retval код - в случае если status вернул ersError
			\retval пусто (пустая строка, не NULL) - если ошибки не было
		*/
		const char *errorCode();

		/*!	\brief Количество переработанных строк для DML запросов

			\return Количество переработанных строк для DML запросов
		*/
		size_t cmdRows();

		/*!	\brief Количество выбранных строк

			\return Количество выбранных строк
		*/
		size_t rows();

		/*!	\brief Количество выбранных столбцов

			\return Количество выбранных столбцов
		*/
		size_t cols();

		/*!	\brief Проекция имени колонки в ее индекс

			\param colName имя колонки
			\return индекс, который можно использовать в isNull, fetch
		*/
		size_t colIdx(const char *colName);

		/*!	\brief Проекция индекса колонки в ее имя

			\param columnIdx индекс колонки
			\return имя колонки, значение такое же как в ключи из fetchRowMap и 
				других fetch...Map
		*/
		const char *colName(size_t columnIdx);

		/*!	\brief Проекция индекса колонки в ее тип

			\param columnIdx индекс колонки
			\return тип колонки, данный тип будет использоваться при извлечении значений, 
				смотри fetch

			Типы значений могут быть такие (oid => имя из заголовков libpq, 
			соответствующий тип варианта):
				- 21 => int2\n
					utils::Variant::etInt16
				- 23 => int4\n
					utils::Variant::etInt32
				- 20 => int8\n
					utils::Variant::etInt64
				- 1700 => numeric\n
					utils::Variant::etString
				- 700 => float4\n
					utils::Variant::etFloat
				- 701 => float8\n
					utils::Variant::etDouble
				- 790 => money\n
					utils::Variant::etInt64
				- 705 => unknown\n
					utils::Variant::etString
				- 1043 => varchar\n
					utils::Variant::etString
				- 1042 => bpchar\n
					utils::Variant::etString
				- 25 => text\n
					utils::Variant::etString
				- 17 => bytea\n
					utils::Variant::etVectorChar
				- 1114 => timestamp\n
					utils::Variant::etDatetime
				- 1184 => timestamptz\n
					utils::Variant::etDatetime
				- 1186 => interval\n
					utils::Variant::etDateTimeDuration
				- 1082 => date\n
					utils::Variant::etDate
				- 1083 => time\n
					utils::Variant::etTimeDuration
				- 1266 => timetz\n
					utils::Variant::etTimeDuration
				- 16 => bool\n
					utils::Variant::etBool
				- 1560 => bit\n
					в зависимости от длины, будет использован одни из
					- utils::Variant::etBitset8\n
					- utils::Variant::etBitset16
					- utils::Variant::etBitset32
					- utils::Variant::etBitset64
					- utils::Variant::etBitset128
					- utils::Variant::etBitset256
					- utils::Variant::etBitset512\n
					Если длина больше 512 - то будет обрезана до 512
				- 1562 => varbit\n
					аналогично предыдущему
				- 26 => oid\n
					utils::Variant::etUInt32
				- 2950 => uuid\n
					utils::Variant::etUuid
				- 18 => char\n
					utils::Variant::etChar

			Все остальные типы считаются не поддерживаемыми и fetch будет 
			возвращать false.
		*/
		utils::Variant::EType colType(size_t columnIdx);

		/*!	\brief Проверка выбранного значения на NULL
			
			\param columnIdx индекс колонки значения
			\param rowIdx индекс строки значения

			\retval true если значение NULL
			\retval false если значение не NULL
		*/
		bool isNull(size_t columnIdx, size_t rowIdx);

		/*!	\brief Извлечение выбранного значения

			\param v ссылка на вариант, в который будет складировано выбранное значение
			\param columnIdx индекс колонки значения
			\param rowIdx индекс строки значения

			\retval true если значение успешно помещено в вариант
			\retval false если не возможно получить значение
				- хотя бы один из индексов не правильный
				- тип данных в указанной колонке не поддерживается (смотри colType)


			Если указанное индексами значение NULL то значение варианта будет
			установлено в пустое (utils::Variant::isNull)

			Пример использования:
			\code
				pgc::Result res = con.query("SELECT 220");

				utils::Variant var;

				//получить значение из 0 колонки и 0 строки, положить его в вариант var
				bool b = res.fetch(var, 0, 0);

				//значение сформировано
				assert(b);

				//тип
				assert(var.type() == utils::Variant::etInt32)

				//значение
				assert(220 == (int)var);

				/////////////////////
				res = con.query("SELECT NULL::smallint");
				b = fetch(var, 0, 0);

				//тип
				assert(var.type() == utils::Variant::etInt16)

				//значение
				assert(var.isNull());
			\endcode
		*/
		bool fetch(utils::Variant &v, size_t columnIdx, size_t rowIdx);

		//////////////////////////////////////////////////////////////////////////
		/*!	\brief Извлечение строки значений
			\param v ссылка на вариант, в который будет складированы выбранные значения.
			
			Если на момент вызова вариант имеет тип
				- utils::Variant::etDequeVariant <- по умолчанию
				- utils::Variant::etListVariant
				- utils::Variant::etVectorVariant

			то тип не изменится, соответствующий контейнер внутри варианта будет 
			приведен к нужному размеру и в него будут складированы значения 
			извлекаемой строки.

			Если вариант имеет другой тип, то тип будет приведен 
			к utils::Variant::etDequeVariant, далее аналогично.

			\param rowIdx индекс извлекаемой строки

			\retval true если значения успешно помещены в вариант
			\retval false если не возможно получить значение
				- индекс строки не правильный
				- тип данных хотя бы в одном столбце не поддерживается, перечень типов смотри
					в colType

			Пример:
			\code
				res = con.query("SELECT 1, '2', NULL::varchar");
				b = res.fetchRowList(var, 0);

				assert(b);
				assert(var.type() == utils::Variant::etDequeVariant)
				assert(1 == (int)var[0]);
				assert('2' == (char)var[1]);
				assert(var[2].isNull());
			\endcode
		*/
		bool fetchRowList(utils::Variant &v, size_t rowIdx=0);

		/*!	\brief Извлечение строки значений

			\param v ссылка на вариант, в который будет складированы выбранные значения.
			\param rowIdx индекс извлекаемой строки

			\retval true если значения успешно помещены в вариант
			\retval false если не возможно получить значение
				- индекс строки не правильный
				- тип данных хотя бы в одном столбце не поддерживается, перечень типов смотри
					в colType

			Работает аналогично fetchRowList но данные складирует не в массив а в 
			ассоциативный массив, в котором ключами являются наименования столбцов.

			Тип контейнера всегда utils::Variant::etMapStringVariant.

			Пример:
			\code
				res = con.query("SELECT 1 AS first, '2' AS second, NULL::varchar AS third");
				res.fetchRowMap(var, 0);

				TLOG(var);

				//будет выведено:
				//MapStringVariant# {
				//		first => Int32# 1,
				//		second => String# 2,
				//		third => String# Null,
				//}
			\endcode

		*/
		bool fetchRowMap(utils::Variant &v, size_t rowIdx=0);

		/*!	\brief Извлечение значений из нескольких строк

			Извлекает значения из заданного диапазона строк и складирует их в двумерный массив

			\param v ссылка на вариант, в который будет складированы выбранные значения.
			\param rowBeginIdx индекс первой извлекаемой строки
			\param rowEndIdx индекс извлекаемой строки, следующей за последней извлекаемой

			\retval true если значения успешно помещены в вариант
			\retval false если не возможно получить значение
				- тип данных хотя бы в одном столбце не поддерживается, перечень типов смотри
					в colType

			Если индекс rowEndIdx превосходит размер выборки - то он будет скорректирован.
			Если индекс rowBeginIdx больше чем rowEndIdx - то он будет скорректирован.

			Тип массивов в v может быть
				- utils::Variant::etDequeVariant <- по умолчанию
				- utils::Variant::etListVariant
				- utils::Variant::etVectorVariant
			Если тип другой - будет приведен к utils::Variant::etDequeVariant

			Пример:
			\code
				res = con.query("SELECT 1, '2' UNION (SELECT 3, '4')");
				res.fetchRowsList(var, 0, 2);

				TLOG(var);

				//будет выведено:
				// DequeVariant# [
				//         DequeVariant# [
				//                 Int32# 1,
				//                 String# 2,
				//         ],
				//         DequeVariant# [
				//                 Int32# 3,
				//                 String# 4,
				//         ],
				// ]
			\endcode
		*/
		bool fetchRowsList(utils::Variant &v, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		/*!	\brief Извлечение значений из нескольких строк

			Извлекает значения из заданного диапазона строк и складирует их в массив 
			ассоциативных массивов

			\param v ссылка на вариант, в который будет складированы выбранные значения.
			\param rowBeginIdx индекс первой извлекаемой строки
			\param rowEndIdx индекс извлекаемой строки, следующей за последней извлекаемой

			\retval true если значения успешно помещены в вариант
			\retval false если не возможно получить значение
				- тип данных хотя бы в одном столбце не поддерживается, перечень типов смотри
					в colType

			Если индекс rowEndIdx превосходит размер выборки - то он будет скорректирован.
			Если индекс rowBeginIdx больше чем rowEndIdx - то он будет скорректирован.

			Тип массива в v может быть
				- utils::Variant::etDequeVariant <- по умолчанию
				- utils::Variant::etListVariant
				- utils::Variant::etVectorVariant
			Если тип другой - будет приведен к utils::Variant::etDequeVariant

			Тип вложенных массивов - всегда utils::Variant::etMapStringVariant

			Пример:
			\code
				res = con.query("SELECT 1 AS a, '2' AS b UNION (SELECT 3 AS a, '4' AS b)");
				res.fetchRowsMap(var, 0, 220);

				TLOG(var);

				//будет выведено:
				// DequeVariant# [
				//         MapStringVariant# {
				//                 a => Int32# 1,
				//                 b => String# 2,
				//         },
				//         MapStringVariant# {
				//                 a => Int32# 3,
				//                 b => String# 4,
				//         },
				// ]
				assert(1 == (int)var[0]["a"]);
			\endcode
		*/
		bool fetchRowsMap(utils::Variant &v, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		//////////////////////////////////////////////////////////////////////////
		/*!	\brief Извлечение строки значений для заданных столбцов

			Работает аналогично pgc::Result::fetchRowList(utils::Variant &v, size_t rowIdx),
			но выбирает не все столбцы а только указанные в colIndices.

			Если хотя бы один индекс в colIndices не правильный то вернет false.
		*/
		bool fetchRowList(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx=0);

		/*!	\brief Извлечение строки значений для заданных столбцов

			Работает аналогично pgc::Result::fetchRowMap(utils::Variant &v, size_t rowIdx),
			но выбирает не все столбцы а только указанные в colIndices.

			Если хотя бы один индекс в colIndices не правильный то вернет false.
		*/
		bool fetchRowMap(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx=0);

		/*!	\brief Извлечение значений из нескольких строк, для заданных столбцов

			Работает аналогично pgc::Result::fetchRowsList(utils::Variant &v, size_t rowBeginIdx, size_t rowEndIdx),
			но выбирает не все столбцы а только указанные в colIndices.

			Если хотя бы один индекс в colIndices не правильный то вернет false.
		*/
		bool fetchRowsList(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		/*!	\brief Извлечение значений из нескольких строк, для заданных столбцов

			Работает аналогично pgc::Result::fetchRowsMap(utils::Variant &v, size_t rowBeginIdx, size_t rowEndIdx),
			но выбирает не все столбцы а только указанные в colIndices.

			Если хотя бы один индекс в colIndices не правильный то вернет false.
		*/
		bool fetchRowsMap(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		/*!	\brief Извлечение значений из колонки

			Извлекает значения из заданной колонки и заданного диапазона строк и 
			складирует их в массив 

			\param v ссылка на вариант, в который будет складированы выбранные значения.
			\param columnIdx индекс извлекаемой колонки
			\param rowBeginIdx индекс первой извлекаемой строки
			\param rowEndIdx индекс извлекаемой строки, следующей за последней извлекаемой

			\retval true если значения успешно помещены в вариант
			\retval false если не возможно получить значение
				- columnIdx не правильный
				- тип данных хотя бы в столбце не поддерживается, перечень типов смотри
					в colType

			Если индекс rowEndIdx превосходит размер выборки - то он будет скорректирован.
			Если индекс rowBeginIdx больше чем rowEndIdx - то он будет скорректирован.

			Тип массива в v может быть
				- utils::Variant::etDequeVariant <- по умолчанию
				- utils::Variant::etListVariant
				- utils::Variant::etVectorVariant
			Если тип другой - будет приведен к utils::Variant::etDequeVariant

			Пример:
			\code
				res = con.query("SELECT 1 AS a, '2' AS b UNION SELECT 3 AS a, '4' AS b UNION SELECT 5 AS a, '6' AS b");
				res.fetchColumn(var, 1);

				TLOG(var);
				//выведет
				// DequeVariant# [
				//         String# 6,
				//         String# 2,
				//         String# 4,
				// ]
			\endcode
		*/
		bool fetchColumn(utils::Variant &v, size_t columnIdx, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		//////////////////////////////////////////////////////////////////////////
		/*!	\brief Помогалка для извлечения целого значения

			\param columnIdx индекс колонки
			\param rowIdx индекс строки

			\retval целое


			Если по указаным индескам не возможно извлеч значение (плохие индексы, 
			NULL, плохой тип, ...) то будет возвращен 0

			Если тип данных, возвращенный сервером не является целым, но вариант может 
			преобразовать - будет произведено преобразование, смотри 
			utils::Vatiant::convert
		*/
		boost::int32_t fetchInt32(size_t columnIdx, size_t rowIdx);

		/*!	\brief Помогалка для извлечения целого значения

			Работает аналогично pgc::Result::fetchInt32, но тип без знака
		*/
		boost::uint32_t fetchUInt32(size_t columnIdx, size_t rowIdx);

		/*!	\brief Помогалка для извлечения целого значения

			Работает аналогично pgc::Result::fetchInt32 и pgc::Result::fetchUInt32, но тип - строка символов
		*/
		std::string fetchString(size_t columnIdx, size_t rowIdx);
	};
}
#endif
