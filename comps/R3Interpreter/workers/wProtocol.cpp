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






		path hppDirectory = evalContextPath(ctx, isServer, cpt_directoryAbs);
		create_directories(hppDirectory);
		out::File hpp(path(hppDirectory).replace_extension(".hpp"));
		hpp<<"// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!"<<endl<<endl;

		hpp<<"#ifndef "<<evalContextPath(ctx, isServer, cpt_hppGuard)<<"_hpp_"<<endl;
		hpp<<"#define "<<evalContextPath(ctx, isServer, cpt_hppGuard)<<"_hpp_"<<endl;
		hpp<<endl;

		hpp<<"#include \"r3/contextBase.hpp\"\n";
		hpp<<"#include \"r3/logic.hpp\"\n";
		hpp<<endl;


		//������������ ����
		hpp<<"namespace r3 \n{\n namespace protocol \n{\n namespace "<<(isServer?"server":"client")<<"\n{"<<endl;

		//����� ���������
		hpp<<"// ����� ���������\n";
		hpp<<"class "<<evalContextPath(ctx, isServer, cpt_classScope)<<endl;
		hpp<<"	: public ContextBase<"<<evalContextPath(ctx, isServer, cpt_classScope)<<", "<<parentType<<">\n{"<<endl;

		hpp<<"typedef ContextBase<"<<evalContextPath(ctx, isServer, cpt_classScope)<<", "<<parentType<<"> BaseType;\n";
		hpp<<endl;

		//����� ����
		hpp<<"public:// ����� ����\n";
		hpp<<"static const TypeId tid = "<<getCTid()<<";\n";
		hpp<<endl;

		//������ �������
		hpp<<"public:// ������ �������\n";
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


		hpp<<"public:// �����������\n";
		hpp<<ctx->getName()<<"(ContextId id, "<<parentType<<" *parent)\n";
		hpp<<"	: BaseType(id, parent)\n";
		hpp<<"{\n}\n";
		hpp<<endl;


		//����������� �������� ���������
		hpp<<"public:// ����������� �������� ���������\n";
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

		//���������� ��������� ���������
		hpp<<"public:// ���������� ��������� ���������\n";
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

		//���������������� ���������� �������� ����������
		hpp<<"public:// ���������������� ���������� �������� ����������\n";
		BOOST_FOREACH(Context child, ctx->getContext())
		{
			hpp<<"class "<<child->getName()<<";\n";
		}
		hpp<<endl;

		//���������� �������� ����������
		hpp<<"private:// ���������� �������� ����������\n";
		BOOST_FOREACH(Context child, ctx->getContext())
		{
			hpp<<"std::map<ContextId, Logic<"<<child->getName()<<">::Context> map_"<<child->getName()<<";\n";
		}
		hpp<<endl;


		hpp<<"public:\n";
		//�������� ���������� ��������� ���������
		hpp<<"// �������� ���������� ��������� ���������\n";
		hpp<<"ContextId startup(TypeId tid, ContextId id);\n";

		//����������� ���������� ��������� ���������
		hpp<<"// ����������� ���������� ��������� ���������\n";
		hpp<<"void shutdown(TypeId tid, ContextId id);\n";

		//�������� ��������� ��������� � ��������� ��������� ���������
		hpp<<"// �������� ��������� ��������� � ��������� ��������� ���������\n";
		hpp<<"void dispatch(Path p, const EventBase *evt);\n";


		hpp<<"};// ����� ������ ���������"<<endl;
		//����� ������ ���������

		//����� ������������ ����
		hpp<<"}\n}\n}\n"<<endl;


		//��� ��������
		BOOST_FOREACH(Context child, ctx->getContext())
		{
			processContext(child, isServer);
			hpp<<"#include \""<<evalContextPath(child, isServer, cpt_directoryRel)<<".hpp\"\n";
		}
		hpp<<endl;

		//������������ ����
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
			hpp<<"//��� ��������, ������ ���������\n";
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
			hpp<<"//��� ��������, ������ ����������\n";
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
			hpp<<"//��� ��������, ������ ���������\n";
			hpp<<"assert(0);\n";
		}
		hpp<<"}\n";

		hpp<<"}\n";
		hpp<<endl;

		//����� ������������ ����
		hpp<<"}\n}\n}\n"<<endl;


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
