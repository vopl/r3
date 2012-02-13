#ifndef _ASYNC_EXCEPTION_HPP_
#define _ASYNC_EXCEPTION_HPP_

#include <stdexcept>

//////////////////////////////////////////////////////////////////////////
namespace async
{
	//////////////////////////////////////////////////////////////////////////
	/*! \ingroup async
		\brief Тип исключения для нештатных ситуаций

		выбрасываеется в различных нештатных ситуациях, например
			- вызван async::Mutex::unlock без предварительного async::Mutex::lock
			- вызван async::EventWaiter::current без вызова async::EventWaiter::wait
			- вызван exec в чужом потоке
			- провален какой либо системный вызов (например swapcontext)

		предполагается, что если вдруг случился выброс исключения - то программа дальше работать не может
	*/
	class exception
		: public std::runtime_error
	{
	public:
		exception(const std::string &arg)
			: std::runtime_error(arg)
		{
		}
	};
}

#endif
