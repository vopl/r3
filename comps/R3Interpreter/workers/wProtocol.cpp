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
		boost::filesystem::create_directories(_path/"include/r3/protocol");
		boost::filesystem::create_directories(_path/"src/r3/protocol");

		BOOST_FOREACH(const FCO &fco, roots)
		{
			Protocol protocol(fco);
			if(protocol)
			{
			}
		}
	}

}
