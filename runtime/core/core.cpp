// core.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "r3/protocol/server.hpp"
// #include "r3/protocol/client.hpp"

#include "../src/r3/logic/client.hpp"
#include "../src/r3/logic/server.hpp"

#include "net/service.hpp"
using namespace r3;

#include <strstream>



#include "utils/streambufOnArray.hpp"


//////////////////////////////////////////////////////////////////////////
struct Bas
{
public:
	int in_b;
	virtual ~Bas()
	{
	}

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & in_b;
	}
};
struct Der
	: Bas
{
public:
	int in_d;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<Bas>(*this);
		ar & in_d;
	}
};
//BOOST_CLASS_EXPORT(Bas);
//BOOST_CLASS_EXPORT(Der);
BOOST_CLASS_EXPORT_KEY(Der)


int f()
{
	Bas *b = new Bas;
	b->in_b = 12345;
	Der *d = new Der;
	d->in_b = -12346;
	d->in_d = 64321;
	Bas *bd = new Der;
	bd->in_b = 12347;
	((Der*)bd)->in_d = 64322;

	utils::StreambufOnArray sbuf;
	std::ostream os(&sbuf);

	utils::serialization::polymorphic_binary_portable_oarchive oa(os, boost::archive::no_header|boost::archive::no_codecvt);
	//oa.register_type(static_cast<Der *>(NULL));
	// write class instance to archive
	oa & b;
	oa & d;
	oa & bd;

	size_t st = (size_t)-3;
	oa & st;



	{
		Bas *b = NULL;
		Der *d = NULL;
		Bas *bd = NULL;

		utils::StreambufOnArray sbuf2(sbuf.data(), sbuf.size());
        std::istream is2(&sbuf2);

		utils::serialization::polymorphic_binary_portable_iarchive ia(is2, boost::archive::no_header|boost::archive::no_codecvt);
		//ia.register_type(static_cast<Der *>(NULL));
		// write class instance to archive
		ia & b;
		ia & d;
		ia & bd;

		size_t st = 0;
		ia & st;

		std::size_t tail = sbuf2.size();

		int k=220;

	}

	return 4;
}
static int i=f();
//////////////////////////////////////////////////////////////////////////






//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
volatile size_t cnt=0;
volatile bool isServer = true;

struct MyServiceHandler
	: net::IServiceHandler
	, net::IChannelHandler
{
	virtual void onReceive(net::Channel_ptr channel, boost::shared_array<char> data, size_t size)
	{
		utils::StreambufOnArray sbuf(data, size);
        std::istream is(&sbuf);
		utils::serialization::polymorphic_binary_portable_iarchive ia(is, boost::archive::no_header|boost::archive::no_codecvt);

		Bas *bd = NULL;
		ia & (bd);

		utils::StreambufOnArray sbuf2;
        std::ostream os2(&sbuf2);
		utils::serialization::polymorphic_binary_portable_oarchive oa(os2, boost::archive::no_header|boost::archive::no_codecvt);
		oa & (bd);

		if(!(cnt%1000))
		{
			std::cout<<"receive send "<<bd->in_b<<" "<<cnt<<std::endl;
		}
		cnt++;

		delete bd;

		if(isServer)
		{
// 			for(size_t i(0); i<10000; i++)
// 			{
// 				char buf[256];
// 				sprintf(buf, "%08x", rand());
// 			}
		}

		channel->send(sbuf2.data(), sbuf2.size());
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


		utils::StreambufOnArray sbuf;
        std::ostream os(&sbuf);
		utils::serialization::polymorphic_binary_portable_oarchive oa(os, boost::archive::no_header|boost::archive::no_codecvt);

		Bas *bd = new Der;
		bd->in_b = 12347;
		((Der*)bd)->in_d = 64322;

		oa << (bd);
		delete bd;

		channel->send(sbuf.data(), sbuf.size());

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
	{
		Logic<r3::protocol::server::Connection>::Context sc;
		Logic<r3::protocol::client::Connection>::Context cc;


		r3::Path p;
		Event_ping evt;
		sc.dispatch(p, &evt);


		int k=220;
	}

	return 0;
	{
		MyServiceHandler myServiceHandler;

		net::Service srv(&myServiceHandler);


		if(argc>1)
		{
			isServer = false;
			srv.balance(1);
			std::cout<<"connect"<<std::endl;
			srv.connect("127.0.0.1", 1234);
		}
		else
		{
			srv.balance(4);
			std::cout<<"listen"<<std::endl;
			srv.listen("127.0.0.1", 1234);
		}


		char c;
		std::cin>>c;

		srv.balance(0);
	}



	return 0;
}

