#ifndef _ASYNC_SERVICEWORKER_HPP_
#define _ASYNC_SERVICEWORKER_HPP_

#include <boost/thread.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "fiberImpl.hpp"
#include "fiberRootImpl.hpp"
#include <set>
#include <deque>

#include "fiberPool.hpp"

namespace async
{
	class ServiceImpl;
	typedef shared_ptr<ServiceImpl> ServiceImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class WorkerImpl
		: public enable_shared_from_this<WorkerImpl>
	{
		ServiceImplPtr	_service;
		thread			_thread;
		volatile bool	_stop;

	private:
		typedef function<void()> TTask;

		//РіРѕР»РѕРІРЅРѕР№ С„РёР±РµСЂ, РІ РЅРµРј РёСЃРїРѕР»РЅСЏРµС‚СЃСЏ С†РёРєР» РІС‹РєР°С‡РёРІР°РЅРёСЏ СЃРѕР±С‹С‚РёР№ РїСЂРѕР°РєС‚РѕСЂР°
		FiberRootImplPtr	_fiberRoot;

		//С€Р°СЂРµРЅС‹Р№ Р±СѓС„РµСЂ СЃ С„РёР±РµСЂР°РјРё, РІ РЅРµРј РїСЂРѕСЃС‚Р°РёРІР°СЋС‰РёРµ Р±РµР· РєРѕРґР° Рё РіРѕС‚РѕРІС‹Рµ Рє РёСЃРїРѕР»РЅРµРЅРёСЋ
		FiberPoolPtr		_fiberPool;

		static ThreadLocalStorage<WorkerImpl *>
							_current;

	private:
		void threadProc();

	private:
		void processReadyFibers();

	public://РґР»СЏ С„РёР±РµСЂРѕРІ

		//РЅРµ СѓРјРЅС‹Р№ РїРѕС‚РѕРјСѓ С‡С‚Рѕ СЌС‚РѕС‚ РјРµС‚РѕРґ Р±СѓРґРµС‚ РІС‹Р·С‹РІР°С‚СЊСЃСЏ РёР· СЂР°Р±РѕС‡РµР№ РїСЂРѕС†РµРґСѓСЂС‹ С„РёР±РµСЂР° Рё РѕРЅР° РЅРµ РґРѕР»Р¶РЅР° РґРµР»Р°С‚СЊ RAII С‡С‚РѕР±С‹ РЅРµ СѓРЅРµСЃС‚Рё СЃ СЃРѕР±РѕР№ РѕР±СЉРµРєС‚ С„РёР±РµСЂР° РїСЂРё СЂР°Р·СЂСѓС€РµРЅРёРё
		void fiberExecuted(FiberImpl *fiber);
		void fiberReady(FiberImplPtr fiber);
		bool fiberReadyIfWait(FiberImplPtr fiber);
		void fiberYield();

	public://РґР»СЏ РІСЂР°РїРµСЂР° asio
		void exec(const TTask &);
		void yield();

	public:
		WorkerImpl(ServiceImplPtr service, FiberPoolPtr	fiberPool);
		~WorkerImpl();

		const ServiceImplPtr &service();

		static WorkerImpl *current();
	};
	typedef shared_ptr<WorkerImpl> WorkerImplPtr;
}

#endif
