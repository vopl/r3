#ifndef _ASYNC_MUTEX_HPP_
#define _ASYNC_MUTEX_HPP_

#include "async/api.h"
#include <boost/shared_ptr.hpp>


//////////////////////////////////////////////////////////////////////////
namespace async
{
	class MutexImpl;
	typedef boost::shared_ptr<MutexImpl> MutexImplPtr;

	//////////////////////////////////////////////////////////////////////////
	//мутекс над ресурсом
	class ASYNC_API Mutex
	{
		MutexImplPtr	_impl;

	public:
		Mutex();

		bool tryLock();
		void lock();
		bool isLocked();
		void unlock();

	public:
		struct ScopedLock
		{
		public:
			ScopedLock(Mutex &mutex)
				: _mutex(mutex)
			{
				_mutex.lock();
				_locked = true;
			}

			~ScopedLock()
			{
				unlock();
			}

			void lock()
			{
				if (!_locked)
				{
					_mutex.lock();
					_locked = true;
				}
			}

			void unlock()
			{
				if (_locked)
				{
					_mutex.unlock();
					_locked = false;
				}
			}

		private:
			Mutex &_mutex;
			bool _locked;
		};

	};
}

#endif
