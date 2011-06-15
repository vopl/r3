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

	WProtocol::WProtocol(const boost::filesystem::path &path)
		: _path(path)
	{

	}
	WProtocol::~WProtocol()
	{

	}

	void WProtocol::operator()(const std::set<FCO> &roots)
	{
		boost::filesystem::create_directories(_path/"include/r3/protocol/client");
		boost::filesystem::create_directories(_path/"include/r3/protocol/server");
		boost::filesystem::create_directories(_path/"src/r3/protocol");

		BOOST_FOREACH(const FCO &fco, roots)
		{
			Protocol protocol(fco);
			if(protocol)
			{
				BOOST_FOREACH(Context ctx, protocol->getContext())
				{
					processContext(ctx, true);
					processContext(ctx, false);
				}
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void WProtocol::processContext(Context ctx, bool isServer)
	{
		boost::filesystem::path hppPath = evalContextHppPath(ctx, isServer);
		boost::filesystem::create_directories(hppPath);
		hppPath.replace_extension(".hpp");

		out::File hpp(hppPath);
		hpp.close();
		out::styler_cpp(hpp.pathName());


		BOOST_FOREACH(Context child, ctx->getContext())
		{
			processContext(child, true);
			processContext(child, false);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	boost::filesystem::path WProtocol::evalContextHppPath(Context ctx, bool isServer)
	{
		if(!ctx)
		{
			boost::filesystem::path p = _path/"include/r3/protocol" / (isServer?"server":"client");
			return p;
		}

		return evalContextHppPath(ctx->getParent(), isServer) / ctx->getName();
	}

}
