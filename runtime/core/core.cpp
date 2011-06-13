// core.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "r3/contextBase.hpp"
#include "r3/contextUser.hpp"
#include "net/service.hpp"

#include <vector>
using namespace r3;

struct MyContextParent
	: r3::ContextBase<MyContextParent, void>
{
public:
	void destroy(TypeId tid, ContextId id);

};

struct MyContext2
	: r3::ContextBase<MyContext2, void>
{
	static const TypeId tid = 1232;
};
struct MyContext3
	: r3::ContextBase<MyContext3, void>
{
	static const TypeId tid = 1233;
};

/////////////////////////////////////////////////
class MyContext
	: public r3::ContextBase<MyContext, MyContextParent>
{
public:
	static const TypeId tid = 1234;

public:
	struct Event1 : EventBase
	{
		static const TypeId tid = 4567;
		Event1():EventBase(tid){}
		//Tuple1	_param1;
		//Int64	_param2;
	};
	struct Event2 : EventBase
	{
		static const TypeId tid = 4568;
		Event2():EventBase(tid){}
		//String	_param1;
	};


public:
	MyContext(ContextId id, MyContextParent *parent)
		: ContextBase(id, parent)
	{

	}

	template <class Event>
	void handle(const Event &evt)
	{
		return r3::ContextBase<MyContext, MyContextParent>::handle(evt);
	}
	void handle(const Event1 &evt)
	{
		return r3::ContextBase<MyContext, MyContextParent>::handle(evt);
	}
	void handle(const Event2 &evt)
	{
		return r3::ContextBase<MyContext, MyContextParent>::handle(evt);
	}

	template <class Event>
	void fire(const Event &evt)
	{
		return r3::ContextBase<MyContext, MyContextParent>::fire(evt);
	}
	void fire(const Event2 &evt)
	{
		return r3::ContextBase<MyContext, MyContextParent>::fire(evt);
	}



protected:
	std::map<ContextId, ContextUser<MyContext2>::User> map_MyContext2;
	std::map<ContextId, ContextUser<MyContext3>::User> map_MyContext3;

	ContextId create(TypeId tid, ContextId id)
	{
		switch(tid)
		{
		case MyContext2::tid:
			return createImpl(map_MyContext2, id);
		case MyContext3::tid:
			return createImpl(map_MyContext3, id);
		default:
			assert(0);
			throw 220;
		}
	}
	void destroy(TypeId tid, ContextId id)
	{
		switch(tid)
		{
		case MyContext2::tid:
			return destroyImpl(map_MyContext2, id);
		case MyContext3::tid:
			return destroyImpl(map_MyContext3, id);
		default:
			assert(0);
			throw 220;
		}
	}

	void dispath(Path p, const EventBase *evt)
	{
		if(p.empty())
		{

			switch(evt->tid)
			{
			case Event_ping::tid:
				return handleImpl((const Event_ping *)evt);
			case Event_pong::tid:
				return handleImpl((const Event_pong *)evt);
			case Event_destroy::tid:
				return handleImpl((const Event_destroy *)evt);
			case Event1::tid:
				return handleImpl((const Event1 *)evt);
			case Event2::tid:
				return handleImpl((const Event2 *)evt);
			default:
				assert(0);
				throw 220;
			}
		}
		else
		{
			ContextPathItem &pi = p.front();
			p.pop_front();

			switch(pi.tid)
			{
			case MyContext2::tid:
				return dispathImpl(map_MyContext2, pi.id, p, evt);
			case MyContext3::tid:
				return dispathImpl(map_MyContext3, pi.id, p, evt);
			default:
				assert(0);
				throw 220;
			}
		}
	}
};





template <> struct ContextUser<MyContext>
{
	class User
		: public MyContext
	{

	};
};














//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
volatile size_t cnt=0;

struct MyServiceHandler
	: net::IServiceHandler
	, net::IChannelHandler
{
	virtual void onReceive(net::Channel_ptr channel, boost::shared_array<char> data, size_t size)
	{
		if(!((cnt++)%1000))
		{
			std::cout<<"receive send "<<cnt<<std::endl;
		}
		channel->send(data, size);
	}

	virtual void onError(net::Channel_ptr channel)
	{

	}

	virtual void onClose(net::Channel_ptr channel)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	virtual void onStart(net::Service *)
	{
	};
	virtual void onStartInThread(net::Service *)
	{
	};

	virtual void onError(net::Service *)
	{
	};

	virtual void onAccept(net::Channel_ptr channel)
	{
		channel->setHandler(this);
	};
	virtual void onConnect(net::Channel_ptr channel)
	{
		channel->setHandler(this);
		std::cout<<"send"<<std::endl;

		boost::shared_array<char> data(new char[8]);

		channel->send(data, 8);
	};

	virtual void onStopInThread()
	{
	};
	virtual void onStop()
	{
	};


};



int _tmain(int argc, _TCHAR* argv[])
{
	MyContext ctx(345, NULL);

	MyServiceHandler myServiceHandler;

	net::Service srv(&myServiceHandler);


	if(argc>1)
	{
		srv.balance(1);
		std::cout<<"connect"<<std::endl;
		srv.connect("127.0.0.1", 1234);
	}
	else
	{
		srv.balance(32);
		std::cout<<"listen"<<std::endl;
		srv.listen("127.0.0.1", 1234);
	}


	char c;
	std::cin>>c;

	srv.balance(0);

	return 0;
}

