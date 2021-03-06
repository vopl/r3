/*! \defgroup heap Общая куча (heap)

	Данный функционал используется для совместимости разных модулей при работе с
	объектами, которые требуют динамической памяти (std::string, boost::shared_ptr, ...).

	Модуль реализует функции выделения и освобождения памяти и экспортирует их наружу,
	чтобы пользователь мог получить к ним доступ. Пользователю не предлагаются прям
	malloc и free, но предлагаются операторы new и delete, которые уже и используют 
	эти две экспортируемые функции.

	Таким образом, чтобы использовать общую кучу, необходимо
		- добавить в пользовательский модуль операторы new и delete, которые
			реализованы в файле headNewDelete.cpp
		- слинковать пользовательский модуль с этим модулем

	Теперь можно вполне спокойно передавать всякие std::string через границы модулей
	не беспокоясь за то что они будут крошить разные кучи.
*/

#ifndef _HEAP_HEAP_HPP_
#define _HEAP_HEAP_HPP_


/*!	\ingroup heap
	\def HEAP_API
	\brief Поддержка экспорта/импорта интерфейсным символов модуля heap

	Актуален только для windows, при сборке модуля выставляется в экспорт, при сборках 
	пользовательского кода - в импорт
*/
#if defined(OS_WINDOWS)
#	ifndef HEAP_STATIC
#		ifdef libheap_EXPORTS
#			define HEAP_API __declspec(dllexport)
#		else
#			define HEAP_API __declspec(dllimport)
#		endif
#	else
#		define HEAP_API
#	endif
#else
#	define HEAP_API
#endif






/*!	\ingroup heap
	\brief Головное пространство имен модуля heap
*/
namespace heap
{
	/*!	\ingroup heap
		\brief Выделение блока памяти заданного размера

		\return указатель на память

		Реализован, скорее всего, через вызов функции из стандартной библиотеки C - malloc,
		со всеми вытекающими (выравнивание, NULL при нехватке памяти, ...)
	*/
	HEAP_API void *alloc(unsigned int s);

	/*!	\ingroup heap
		\brief Освобождение блока памяти

		\param p указатель на память

		Реализован, скорее всего, через вызов функции из стандартной библиотеки C - free.
	*/
	HEAP_API void free(void *p);
}

#endif
