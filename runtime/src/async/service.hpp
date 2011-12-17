#ifndef _ASYNC_SERVICE_HPP_
#define _ASYNC_SERVICE_HPP_

#include "async/iservice.hpp"
#include <boost/enable_shared_from_this.hpp>

#include "serviceWorker.hpp"

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	class Service
		: public IService
		, public boost::enable_shared_from_this<Service>
	{
		friend class ServiceWorker;
		boost::asio::io_service			_io_service;
		boost::shared_ptr<boost::asio::io_service::work>	_work;

		std::vector<ServiceWorkerPtr>	_workers;

		boost::function<void ()> _threadStart;
		boost::function<void ()> _threadStop;

// 		boost::mutex _mtx;
// 
// 
// 		struct ServiceWorker
// 		{
// 
// 			boost::thread		_thread;
// 			volatile bool		_stop;
// 
// 			//системный фибер
// 			Fiber				_fiberRoot;
// 
// 			std::set<Fiber> _inWork;
// 			set<Fiber> _inIdle;
// 			vector<Fiber> _inWorkReady;
// 			//очередь к исполнению
// 			_taskQueue
// 		};
// 		typedef boost::shared_ptr<ServiceWorker> ServiceWorkerPtr;
// 		void workerProc(ServiceWorkerPtr swp)
// 		{
// 			while(!stop)
// 			{
// 				io_service.run_one();
// 
// 				bool bDone = true;
// 
// 				while(!bDone)
// 				{
// 					bDone = true;
// 					while(!_taskQueue.empty() && !_inWork.empty())
// 					{
// 						bDone = false;
// 						task = _taskQueue.top();
// 						_taskQueue.pop();
// 
// 						fiber = *_inWork.begin();
// 						_inWork.erase(_inWork.begin());
// 						_inWork.insert(fiber);
// 
// 						//взять пустой фибер из пула, отдать ему задачу
// 						fiber.exec(task);
// 					}
// 
// 					while(!_inWorkReady.empty())
// 					{
// 						bDone = false;
// 						fiber = *_inWorkReady.begin();
// 						_inWorkReady.erase(_inWorkReady.begin());
// 
// 						fiber.exec();
// 					}
// 				}
// 
// 			}
// 		}
// 
// 		struct HandlerWrapper
// 		{
// 			boost::function<void()>	_handler;
// 
// 			void operator()
// 			{
// 				_taskQueue.push(_handler);
// 			}
// 		}


	public:
		Service();
		~Service();

		virtual void start(
			size_t numThreads,
			boost::function<void ()> threadStart,
			boost::function<void ()> threadStop);

		virtual void balance(size_t numThreads);
		virtual void stop();

		virtual boost::asio::io_service &get_io_service();
	};
	PLUMA_INHERIT_PROVIDER(Service, IService);
}
#endif
