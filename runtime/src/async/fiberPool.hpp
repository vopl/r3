#ifndef _ASYNC_FIBERPOOL_HPP_
#define _ASYNC_FIBERPOOL_HPP_

#include "fiberImpl.hpp"
#include <set>

namespace async
{
	class FiberPool
	{
	public:
		//С„РёР±РµСЂС‹ Р±РµР· Р·Р°РґР°С‡Рё
		std::set<FiberImplPtr>			_fibersIdle;
		//СЂР°Р±РѕС‡РёРµ С„РёР±РµСЂС‹ СЃ Р·Р°РґР°С‡РµР№ Рё РіРѕС‚РѕРІС‹Рµ Рє РёСЃРїРѕР»РЅРµРЅРёСЋ
		std::deque<FiberImplPtr>		_fibersReady;
		mutex							_mtxFibers;


		//РѕС‡РµСЂРµРґСЊ Р·Р°РґР°С‡ РЅР° РєРѕС‚РѕСЂС‹Рµ РЅРµ С…РІР°С‚РёР»Рѕ С„РёР±РµСЂРѕРІ
		std::deque<function<void()> >	_tasks;
		mutex							_mtxTasks;

	public:
	};
	typedef shared_ptr<FiberPool> FiberPoolPtr;
}
#endif
