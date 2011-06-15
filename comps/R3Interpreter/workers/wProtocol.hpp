#ifndef _WORKERS_WPROTOCOL_HPP_
#define _WORKERS_WPROTOCOL_HPP_

#include "BON.h"
#include "BONImpl.h"
#include <ComponentConfig.h>
#include "R3MetaBonX.h"
#include <algorithm>
#include <boost/filesystem.hpp>

namespace workers
{
	using namespace BON;
	using namespace R3Meta_BON;

	class WProtocol
	{
		const boost::filesystem::path _path;
	public:
		WProtocol(const boost::filesystem::path &path);
		~WProtocol();

		void operator()(const std::set<FCO> &roots);

	private:
		void processContext(Context ctx, bool isServer);
		boost::filesystem::path evalContextHppPath(Context ctx, bool isServer);
	};
}
#endif
