#include "Stdafx.h"
#include "workers/wProtocol.hpp"
#include <Console.h>
#include <direct.h>
#include "out/file.hpp"
#include "out/styler.hpp"

namespace workers
{
	using namespace GMEConsole;
	using namespace std;
	using namespace boost::filesystem;

	WProtocol::WProtocol(const path &path)
		: _path(path)
		, _tid4C(0)
		, _tid4E(0)
	{

	}
	WProtocol::~WProtocol()
	{

	}

	void WProtocol::operator()(const std::set<FCO> &roots)
	{
		_tid4C = 1000;
		_tid4E = 1000;

		create_directories(_path / "include/r3/protocol");
		out::File hppServer(_path / "include/r3/protocol/server.hpp");
		out::File hppClient(_path / "include/r3/protocol/client.hpp");

		hppServer<<"// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!"<<endl<<endl;
		hppServer<<"#ifndef _r3_protocol_server_hpp_"<<endl;
		hppServer<<"#define _r3_protocol_server_hpp_"<<endl;
		hppServer<<endl;

		hppServer<<"#include \"r3/contextBase.hpp\"\n";
		hppServer<<"#include \"r3/contextUser.hpp\"\n";
		hppServer<<endl;

		hppClient<<"// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!"<<endl<<endl;
		hppClient<<"#ifndef _r3_protocol_server_hpp_"<<endl;
		hppClient<<"#define _r3_protocol_server_hpp_"<<endl;
		hppClient<<endl;

		hppClient<<"#include \"r3/contextBase.hpp\"\n";
		hppClient<<"#include \"r3/contextUser.hpp\"\n";
		hppClient<<endl;

		hppServer<<"namespace r3\n{\nnamespace protocol\n{\nnamespace server\n{\n";
		hppServer<<"}\n}\n}\n\n";

		hppClient<<"namespace r3\n{\nnamespace protocol\n{\nnamespace client\n{\n";
		hppClient<<"}\n}\n}\n\n";

		BOOST_FOREACH(const FCO &fco, roots)
		{
			Protocol protocol(fco);
			if(protocol)
			{
				BOOST_FOREACH(Context ctx, protocol->getContext())
				{
					processContext(ctx, true);
					hppServer<<"#include \""<<evalContextPath(ctx, true, cpt_directoryRel)<<".hpp\"\n";

					processContext(ctx, false);
					hppClient<<"#include \""<<evalContextPath(ctx, false, cpt_directoryRel)<<".hpp\"\n";
				}
			}
		}

		hppServer<<"#endif"<<endl;
		hppServer<<endl;
		hppServer.close();
		out::styler_cpp(hppServer.pathName());

		hppClient<<"#endif"<<endl;
		hppClient<<endl;
		hppClient.close();
		out::styler_cpp(hppClient.pathName());

	}

	//////////////////////////////////////////////////////////////////////////
	void WProtocol::processContext(Context ctx, bool isServer)
	{
		string parentType;
		if(Context(ctx->getParent())) parentType = evalContextPath(Context(ctx->getParent()), isServer, cpt_classScope);
		else parentType = "void";

		path hppDirectory = evalContextPath(ctx, isServer, cpt_directoryAbs);
		create_directories(hppDirectory);
		out::File hpp(path(hppDirectory).replace_extension(".hpp"));
		hpp<<"// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!"<<endl<<endl;

		hpp<<"#ifndef "<<evalContextPath(ctx, isServer, cpt_hppGuard)<<"_hpp_"<<endl;
		hpp<<"#define "<<evalContextPath(ctx, isServer, cpt_hppGuard)<<"_hpp_"<<endl;
		hpp<<endl;

		//пространство имен
		hpp<<"namespace r3 \n{\n namespace protocol \n{\n namespace "<<(isServer?"server":"client")<<"\n{"<<endl;

		//класс контекста
		hpp<<"// класс контекста\n";
		hpp<<"class "<<evalContextPath(ctx, isServer, cpt_classScope)<<endl;
		hpp<<"	: public r3::ContextBase<"<<evalContextPath(ctx, isServer, cpt_classScope)<<", "<<parentType<<">\n{"<<endl;

		hpp<<"typedef ContextBase<"<<evalContextPath(ctx, isServer, cpt_classScope)<<", "<<parentType<<"> BaseType;\n";
		hpp<<endl;

		//идент типа
		hpp<<"public:// идент типа\n";
		hpp<<"static const TypeId tid = "<<getCTid()<<";\n";
		hpp<<endl;

		//классы событий
		hpp<<"public:// классы событий\n";
		BOOST_FOREACH(R3Meta_BON::Event evt, ctx->getEvent())
		{
			hpp<<"/////////////////////////////////\n";
			hpp<<"struct Event_"<<evt->getName()<<"\n";
			hpp<<": public EventBase\n{\n";
			hpp<<"static const TypeId tid = "<<getETid()<<";\n";
			hpp<<"Event_"<<evt->getName()<<"() : EventBase(tid){}\n";
			hpp<<"};\n";
			hpp<<endl;
		}
		hpp<<endl;


		//передварительные объявления дочерних контекстов
		hpp<<"public:// передварительные объявления дочерних контекстов\n";
		BOOST_FOREACH(Context child, ctx->getContext())
		{
			hpp<<"class "<<child->getName()<<";\n";
		}
		hpp<<endl;

		hpp<<"public:// конструктор\n";
		hpp<<ctx->getName()<<"(ContextId id, "<<parentType<<" *parent)\n";
		hpp<<"	: BaseType(id, parent)\n";
		hpp<<"{\n}\n";
		hpp<<endl;


		//обработчики входящих сообщений
		hpp<<"public:// обработчики входящих сообщений\n";
		hpp<<"template <class Event> void handle(const Event &evt)\n{\n";
		hpp<<"return BaseType::handle(evt);\n";
		hpp<<"}\n";
		BOOST_FOREACH(R3Meta_BON::Event evt, ctx->getEvent())
		{
			bool doImpl = false;
			switch(evt->getDirection())
			{
			case EventImpl::s2c_Direction_Type:
				doImpl = isServer;
				break;
			case EventImpl::c2s_Direction_Type:
				doImpl = !isServer;
				break;
			case EventImpl::both_Direction_Type:
				doImpl = true;
				break;
			default:
				assert(!"unknown event direction");
			}

			if(doImpl)
			{
				hpp<<"void handle(const Event_"<<evt->getName()<<" &evt)\n{\n";
				hpp<<"return BaseType::handle(evt);\n";
				hpp<<"}\n";
			}
		}
		hpp<<endl;

		//генераторы исходящих сообщений
		hpp<<"public:// генераторы исходящих сообщений\n";
		hpp<<"template <class Event> void fire(const Event &evt)\n{\n";
		hpp<<"return BaseType::fire(evt);\n";
		hpp<<"}\n";
		BOOST_FOREACH(R3Meta_BON::Event evt, ctx->getEvent())
		{
			bool doImpl = false;
			switch(evt->getDirection())
			{
			case EventImpl::s2c_Direction_Type:
				doImpl = !isServer;
				break;
			case EventImpl::c2s_Direction_Type:
				doImpl = isServer;
				break;
			case EventImpl::both_Direction_Type:
				doImpl = true;
				break;
			default:
				assert(!"unknown event direction");
			}

			if(doImpl)
			{
				hpp<<"void fire(const Event_"<<evt->getName()<<" &evt)\n{\n";
				hpp<<"return BaseType::fire(evt);\n";
				hpp<<"}\n";
			}
		}
		hpp<<endl;



		hpp<<"};// конец класса контекста"<<endl;
		//конец класса контекста

		//конец пространства имен
		hpp<<"}\n}\n}\n"<<endl;


		//все дочерние
		BOOST_FOREACH(Context child, ctx->getContext())
		{
			processContext(child, isServer);
			hpp<<"#include \""<<evalContextPath(child, true, cpt_directoryRel)<<".hpp\"\n";
		}
		hpp<<endl;

		hpp<<"#endif"<<endl;
		hpp<<endl;
		hpp.close();
		out::styler_cpp(hpp.pathName());

	}

	//////////////////////////////////////////////////////////////////////////
	std::string WProtocol::evalContextPath(Context ctx, bool isServer, EContextPathType cpt)
	{
		switch(cpt)
		{
		case cpt_directoryAbs:
			{
				if(!ctx)
				{
					path p = _path/"include/r3/protocol" / (isServer?"server":"client");
					return p.string();
				}

				return (path(evalContextPath(ctx->getParent(), isServer, cpt)) / ctx->getName()).generic_string();
			}
		case cpt_directoryRel:
			{
				if(!ctx)
				{
					path p = path("r3/protocol") / (isServer?"server":"client");
					return p.string();
				}

				return (path(evalContextPath(ctx->getParent(), isServer, cpt)) / ctx->getName()).generic_string();
			}
		case cpt_hppGuard:
			{
				if(!ctx)
				{
					return std::string("_r3_protocol_") + (isServer?"server":"client");
				}

				return evalContextPath(ctx->getParent(), isServer, cpt) + "_" + ctx->getName();
			}
		case cpt_classScope:
			{
				if(!ctx)
				{
					return std::string("");
				}

				string pscope = evalContextPath(ctx->getParent(), isServer, cpt);
				return pscope.empty()?ctx->getName(): pscope +  "::" + ctx->getName();
			}
		}

		assert(!"unknown cpt");
		return "";
	}

	//////////////////////////////////////////////////////////////////////////
	size_t WProtocol::getCTid()
	{
		return _tid4C++;
	}
	//////////////////////////////////////////////////////////////////////////
	size_t WProtocol::getETid()
	{
		return _tid4E++;
	}

}
