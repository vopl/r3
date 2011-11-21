// victim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////
class StateMachineCaller
{
public:
	void operator()(...)
	{
		//...
	}
};

//////////////////////////////////////////////////////////////////////////
class StateMachine
	: public boost::enable_shared_from_this<StateMachine>
{
public:
	template <class SM>
	StateMachineCaller mkCaller(void (SM:: *m)());

	template <class SM, class A1>
	StateMachineCaller mkCaller(void (SM:: *m)(A1 a1), A1 a1);

};
typedef boost::shared_ptr<StateMachine> StateMachinePtr;

//////////////////////////////////////////////////////////////////////////
typedef int TConnection;
class SessionSM
	: public StateMachine
{
public:
	void onNewConnection(TConnection c)
	{
		std::cout<<"void onNewConnection(TConnection c)"<<std::endl;
		(new Authorizer(c))
			->onError(mkCaller(&onAuthError))
			->onOk(mkCaller(&onAuthOk))
			->start(c);
	}

	void onAuthError(TConnection c)
	{
		c->close();
	}

	void onAuthOk(TConnection c)
	{
		c->onSend(mkCaller(&onSend));
		c->onSendError(mkCaller(&onSendError));

		c->onReceive(mkCaller(&onReceive));
		c->onReceiveError(mkCaller(&onReceiveError));
		c->receive();
	}

	void onReceive(TConnection c, Variant data)
	{
		TChild child = getChild(data.destination);
		child->onReceive(data.data)
	}
	void onReceiveError(TConnection c)
	{
		c->close();
	}

	void onSend(TConnection c, Variant data)
	{
		TChild child = getChild(data.destination);
		child->onSend(data.data)
	}
	void onReceiveError(TConnection c)
	{
		c->close();
	}

};
typedef boost::shared_ptr<SessionSM> SessionSMPtr;

//////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	StateMachinePtr sm1(new StateMachine);

	//sm1->method1();

	SessionSMPtr ssm(new SessionSM);

	TConnection c=220;
	ssm->onNewConnection(c);

	//loop
	return 0;
}

