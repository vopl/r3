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

		operator bool() const;
		bool operator!() const;

		async::Future<Result> query(const char *sql);
		async::Future<Result> query(const char *, const utils::Variant &data);
		async::Future<Result> query(const std::string &sql);
		async::Future<Result> query(const std::string &sql, const utils::Variant &data);
		async::Future<Result> query(Statement s, bool withPrepare=true);
		async::Future<Result> query(Statement s, const utils::Variant &data, bool withPrepare=true);

		EConnectionStatus status();
	};
}
#endif
