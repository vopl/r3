#ifndef _PGC_STATEMENT_HPP_
#define _PGC_STATEMENT_HPP_

#include "pgc/api.h"
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	class StatementImpl;
	typedef boost::shared_ptr<StatementImpl> StatementImplPtr;

	//////////////////////////////////////////////////////////////////////////
	/*!	\ingroup pgc
		\brief Обертка для текста запроса

		Фактически представляет собой лишь контейнер для std::string. Необходима в силу 
		следующих причин:
			- копирование std::string дорого по сравнению с копированием умного указателя
			- std::string не удобно использовать в качестве ключа, а такое использщование
				необходимо при работе с prepared statements
			- на этом классе будут базироваться более сложные запросы (из pgs), которые 
				состоят более чем из одного текста

		Объекты данного класса используются при вызовах
		pgc::Connection::query(Statement s, bool withPrepare), 
		pgc::Connection::query(Statement s, const utils::Variant &data, bool withPrepare)
	*/
	class PG_API Statement
	{
	protected:
		typedef StatementImplPtr ImplPtr;
		ImplPtr	_impl;

	public:
		/*!	\brief Конструировние пустого объекта
			
			Для пустого объекта нельзя делать вызов getSql
		*/
		Statement();

		/*!	\brief Конструирование с заданным текстом запроса
		*/
		Statement(const char *sql);

		/*!	\brief Конструирование с заданным текстом запроса
		*/
		Statement(const std::string &sql);

		/*!	\brief Разрушение
		*/
		~Statement();

		/*!	\brief Проверка на пустоту
		*/
		operator bool() const;

		/*!	\brief Проверка на пустоту
		*/
		bool operator!() const;

		/*!	\brief Получение текста запроса
		*/
		const std::string &getSql();
	};
}
#endif
