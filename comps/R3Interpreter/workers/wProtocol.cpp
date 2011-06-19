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
		hppServer<<"#include \"r3/logic.hpp\"\n";
		hppServer<<endl;

		hppClient<<"// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!"<<endl<<endl;
		hppClient<<"#ifndef _r3_protocol_client_hpp_"<<endl;
		hppClient<<"#define _r3_protocol_client_hpp_"<<endl;
		hppClient<<endl;

		hppClient<<"#include \"r3/contextBase.hpp\"\n";
		hppClient<<"#include \"r3/logic.hpp\"\n";
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


		makeEventsSerialization_hpp();
		makeEventsSerialization_cpp();

	}

	//////////////////////////////////////////////////////////////////////////
	void WProtocol::processContext(Context ctx, bool isServer)
	{
		string parentType;
		if(Context(ctx->getParent())) parentType = evalContextPath(Context(ctx->getParent()), isServer, cpt_classScope);
		else parentType = "void";


		std::set<R3Meta_BON::Event> eventsIn, eventsOut;

		BOOST_FOREACH(R3Meta_BON::Event evt, ctx->getEvent())
		{
			switch(evt->getDirection())
			{
			case EventImpl::s2c_Direction_Type:
				if(isServer) eventsOut.insert(evt);
				else eventsIn.insert(evt);
				break;
			case EventImpl::c2s_Direction_Type:
				if(isServer) eventsIn.insert(evt);
				else eventsOut.insert(evt);
				break;
			case EventImpl::both_Direction_Type:
				eventsIn.insert(evt);
				eventsOut.insert(evt);
				break;
			default:
				assert(!"unknown event direction");
			}
		}

		//дл€ сериализации накопить все событи€
		_allEvents.insert(eventsIn.begin(), eventsIn.end());
		_allEvents.insert(eventsOut.begin(), eventsOut.end());
		_allContexts.insert(ctx);






		path hppDirectory = evalContextPath(ctx, isServer, cpt_directoryAbs);
		create_directories(hppDirectory);
		out::File hpp(path(hppDirectory).replace_extension(".hpp"));
		hpp<<"// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!"<<endl<<endl;

		hpp<<"#ifndef "<<evalContextPath(ctx, isServer, cpt_hppGuard)<<"_hpp_"<<endl;
		hpp<<"#define "<<evalContextPath(ctx, isServer, cpt_hppGuard)<<"_hpp_"<<endl;
		hpp<<endl;

		if(isServer)
		{
			//серверные заголовки не вклучают клиентские
			if(Context(ctx->getParent()))
			{
				//hpp<<"#include \""<<evalContextPath(Context(ctx->getParent()), true, cpt_directoryRel)<<".hpp\"\n";
			}
			else
			{
				hpp<<"#include \"r3/contextBase.hpp\"\n";
				hpp<<"#include \"r3/logic.hpp\"\n";
				hpp<<"#include \"r3/fields/field.h\"\n";
			}
		}
		else
		{
			//клиентские включают серверные
			hpp<<"#include \""<<evalContextPath(ctx, true, cpt_directoryRel)<<".hpp\"\n";
		}
		hpp<<endl;


		//пространство имен
		hpp<<"namespace r3 \n{\n namespace protocol \n{\n namespace "<<(isServer?"server":"client")<<"\n{"<<endl;

		//класс контекста
		hpp<<"// класс контекста\n";
		hpp<<"class "<<evalContextPath(ctx, isServer, cpt_classScope)<<endl;
		hpp<<"	: public ContextBase<"<<evalContextPath(ctx, isServer, cpt_classScope)<<", "<<parentType<<">\n{"<<endl;

		hpp<<"typedef ContextBase<"<<evalContextPath(ctx, isServer, cpt_classScope)<<", "<<parentType<<"> BaseType;\n";
		hpp<<endl;

		//идент типа
		hpp<<"public:// идент типа\n";
		hpp<<"static const TypeId tid = "<<getCTid()<<";\n";
		hpp<<endl;

		//классы событий
		hpp<<"public:// классы событий\n";
		if(isServer)
		{
			//сервер опередел€ет событи€ сам
			BOOST_FOREACH(R3Meta_BON::Event evt, ctx->getEvent())
			{
				hpp<<"/////////////////////////////////\n";
				hpp<<"struct Event_"<<evt->getName()<<"\n";
				hpp<<": public EventBase\n{\n";
				hpp<<"static const TypeId tid = "<<getETid()<<";\n";
				BOOST_FOREACH(Field fld, evt->getField())
				{
					hpp<<"r3::fields::"<<fld->getObjectMeta().name()<<" "<<fld->getName()<<";\n";
				}
				hpp<<"\n";
				hpp<<"Event_"<<evt->getName()<<"() : EventBase(tid){}\n";

				hpp<<"template<class Archive> void serialize(Archive & ar, const unsigned int file_version);\n";

				hpp<<"};\n";
				hpp<<endl;
			}
		}
		else
		{
			//клиент берет клиентские событи€
			BOOST_FOREACH(R3Meta_BON::Event evt, ctx->getEvent())
			{
				hpp<<"typedef r3::protocol::server::"<<evalContextPath(ctx, false, cpt_classScope)<<"::Event_"<<evt->getName()<<" Event_"<<evt->getName()<<";\n";
			}
		}
		hpp<<endl;


		hpp<<"public:// конструктор\n";
		hpp<<ctx->getName()<<"(ContextId id, "<<parentType<<" *parent)\n";
		hpp<<"	: BaseType(id, parent)\n";
		hpp<<"{\n}\n";
		hpp<<endl;


		//обработчики вход€щих сообщений
		hpp<<"public:// обработчики вход€щих сообщений\n";
		hpp<<"template <class Event> void handle(const Event &evt)\n{\n";
		hpp<<"return BaseType::handle(evt);\n";
		hpp<<"}\n";
		BOOST_FOREACH(R3Meta_BON::Event evt, eventsIn)
		{
			hpp<<"void handle(const Event_"<<evt->getName()<<" &evt)\n{\n";
			hpp<<"return BaseType::handle(evt);\n";
			hpp<<"}\n";
		}
		hpp<<endl;

		//генераторы исход€щих сообщений
		hpp<<"public:// генераторы исход€щих сообщений\n";
		hpp<<"template <class Event> void fire(const Event &evt)\n{\n";
		hpp<<"return BaseType::fire(evt);\n";
		hpp<<"}\n";
		BOOST_FOREACH(R3Meta_BON::Event evt, eventsOut)
		{
			hpp<<"void fire(const Event_"<<evt->getName()<<" &evt)\n{\n";
			hpp<<"return BaseType::fire(evt);\n";
			hpp<<"}\n";
		}
		hpp<<endl;

		//передварительные объ€влени€ дочерних контекстов
		hpp<<"public:// передварительные объ€влени€ дочерних контекстов\n";
		BOOST_FOREACH(Context child, ctx->getContext())
		{
			hpp<<"class "<<child->getName()<<";\n";
			hpp<<"typedef boost::shared_ptr<"<<child->getName()<<"> "<<child->getName()<<"_ptr;\n";
		}
		hpp<<endl;

		//контейнеры дочерних контекстов
		hpp<<"private:// контейнеры дочерних контекстов\n";
		BOOST_FOREACH(Context child, ctx->getContext())
		{
			hpp<<"std::map<ContextId, boost::shared_ptr<Logic<"<<child->getName()<<">::Context> > map_"<<child->getName()<<";\n";
		}
		hpp<<endl;


		hpp<<"public:\n";
		//создание экземпл€ра дочернего контекста
		hpp<<"// создание экземпл€ра дочернего контекста\n";
		hpp<<"ContextId startup(TypeId tid, ContextId id);\n";

		//уничтожение экземпл€ра дочернего контекста
		hpp<<"// уничтожение экземпл€ра дочернего контекста\n";
		hpp<<"void shutdown(TypeId tid, ContextId id);\n";

		//проводка вход€щего сообщени€ в экземпл€р дочернего контекста
		hpp<<"// проводка вход€щего сообщени€ в экземпл€р дочернего контекста\n";
		hpp<<"void dispatch(Path p, const EventBase *evt);\n";


		hpp<<"};// конец класса контекста"<<endl;
		//конец класса контекста

		//конец пространства имен
		hpp<<"}\n}\n}\n"<<endl;


		//все дочерние
		BOOST_FOREACH(Context child, ctx->getContext())
		{
			processContext(child, isServer);
			hpp<<"#include \""<<evalContextPath(child, isServer, cpt_directoryRel)<<".hpp\"\n";
		}
		hpp<<endl;

		//пространство имен
		hpp<<"namespace r3 \n{\n namespace protocol \n{\n namespace "<<(isServer?"server":"client")<<"\n{"<<endl;

		//startup
		hpp<<"inline ContextId "<<evalContextPath(ctx, isServer, cpt_classScope)<<"::startup(TypeId tid, ContextId id)\n";
		hpp<<"{\n";

		if(ctx->getContext().size())
		{
			hpp<<"switch(tid)\n{\n";

			BOOST_FOREACH(Context child, ctx->getContext())
			{
				hpp<<"case "<<child->getName()<<"::tid:\n";
				hpp<<"return startupImpl(map_"<<child->getName()<<", id);\n";
			}

			hpp<<"default:\nassert(0);throw 220;\n}\n";
		}
		else
		{
			hpp<<"//нет дочерних, некого создавать\n";
			hpp<<"assert(0);\n";
		}
		hpp<<"}\n";
		hpp<<endl;

		//shutdown
		hpp<<"inline void "<<evalContextPath(ctx, isServer, cpt_classScope)<<"::shutdown(TypeId tid, ContextId id)\n";
		hpp<<"{\n";

		if(ctx->getContext().size())
		{
			hpp<<"switch(tid)\n{\n";

			BOOST_FOREACH(Context child, ctx->getContext())
			{
				hpp<<"case "<<child->getName()<<"::tid:\n";
				hpp<<"return shutdownImpl(map_"<<child->getName()<<", id);\n";
			}

			hpp<<"default:\nassert(0);throw 220;\n}\n";
		}
		else
		{
			hpp<<"//нет дочерних, некого уничтожать\n";
			hpp<<"assert(0);\n";
		}
		hpp<<"}\n";
		hpp<<endl;

		//dispatch
		hpp<<"inline void "<<evalContextPath(ctx, isServer, cpt_classScope)<<"::dispatch(Path p, const EventBase *evt)\n";
		hpp<<"{\n";

		hpp<<"if(p.empty())\n"
			"{\n";

		if(eventsIn.size())
		{
			hpp<<"	switch(evt->tid)\n"
				"	{\n";

			BOOST_FOREACH(R3Meta_BON::Event evt, eventsIn)
			{
				hpp<<"	case Event_"<<evt->getName()<<"::tid:\n"
					"		return handleImpl((const Event_"<<evt->getName()<<" *)evt);\n";
			}

			hpp<<"	default:\n"
				"		dispatchCommon(evt);\n"
				"	}\n";
		}
		else
		{
			hpp<<"dispatchCommon(evt);\n";
		}
		hpp<<"}\n"
			"else\n"
			"{\n"
			"	ContextPathItem &pi = p.front();\n"
			"	p.pop_front();\n";

		if(ctx->getContext().size())
		{
			hpp<<"switch(pi.tid)\n{\n";

			BOOST_FOREACH(Context child, ctx->getContext())
			{
				hpp<<"case "<<child->getName()<<"::tid:\n";
				hpp<<"return dispatchImpl(map_"<<child->getName()<<", pi.id, p, evt);\n";
			}

			hpp<<"default:\nassert(0);throw 220;\n}\n";
		}
		else
		{
			hpp<<"//нет дочерних, некому проводить\n";
			hpp<<"assert(0);\n";
		}
		hpp<<"}\n";

		hpp<<"}\n";
		hpp<<endl;

		//конец пространства имен
		hpp<<"}\n}\n}\n"<<endl;


		if(isServer)
		{
// 			BOOST_FOREACH(R3Meta_BON::Event evt, ctx->getEvent())
// 			{
// 				Context ctx = evt->getParent();
// 				hpp<<"BOOST_CLASS_EXPORT_KEY(";
// 				hpp<<"r3::protocol::client::";
// 				hpp<<evalContextPath(ctx, false, cpt_classScope)<<"::Event_"<<evt->getName()<<");\n";
// 			}
// 			hpp<<endl;
		}



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

	//////////////////////////////////////////////////////////////////////////
	void WProtocol::makeEventsSerialization_hpp()
	{
		create_directories(_path / "src/r3/protocol");
		out::File hpp(_path / "src/r3/protocol/serialization.hpp");
		hpp<<"// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!"<<endl<<endl;

		hpp<<"#ifndef _R3_PROTOCOL_SERIALIZATION_HPP_"<<endl;
		hpp<<"#define _R3_PROTOCOL_SERIALIZATION_HPP_"<<endl;
		hpp<<endl;

		BOOST_FOREACH(Context ctx, _allContexts)
		{
			if(!Context(ctx->getParent()))
			{
				hpp<<"#include \""<<evalContextPath(ctx, true, cpt_directoryRel)<<".hpp\"\n";
			}
		}
		hpp<<endl;

		BOOST_FOREACH(R3Meta_BON::Event evt, _allEvents)
		{
			Context ctx = evt->getParent();

			hpp<<"//////////////////////////////////////////////////////////////////////////\n";
			hpp<<"template<class Archive>\n";
			hpp<<"void r3::protocol::server::"<<evalContextPath(ctx, false, cpt_classScope)<<"::Event_"<<evt->getName()<<"::serialize(Archive & ar, const unsigned int file_version)\n";
			hpp<<"{\n";
			hpp<<"ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(EventBase);\n";

			BOOST_FOREACH(Field fld, evt->getField())
			{
				hpp<<"ar & BOOST_SERIALIZATION_NVP("<<fld->getName()<<");\n";
			}

			hpp<<"}\n\n";
		}

		hpp<<endl;
		hpp<<"#endif";
		hpp<<endl;
		hpp.close();
		out::styler_cpp(hpp.pathName());
	}

	//////////////////////////////////////////////////////////////////////////
	void WProtocol::makeEventsSerialization_cpp()
	{
		create_directories(_path / "src/r3/protocol");
		out::File cpp(_path / "src/r3/protocol/serialization_protocol.cpp");
		cpp<<"// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!"<<endl<<endl;

		cpp<<"#include \"stdafx.h\"\n";
		cpp<<"#include \"r3/protocol/serialization.hpp\"\n";
		cpp<<"#include <boost/serialization/export.hpp>\n";
		cpp<<endl;

		BOOST_FOREACH(R3Meta_BON::Event evt, _allEvents)
		{
			Context ctx = evt->getParent();

			cpp<<"BOOST_CLASS_EXPORT(r3::protocol::server::"<<evalContextPath(ctx, false, cpt_classScope)<<"::Event_"<<evt->getName()<<");\n";
		}

		cpp<<endl;
		cpp.close();
		out::styler_cpp(cpp.pathName());
	}

}
