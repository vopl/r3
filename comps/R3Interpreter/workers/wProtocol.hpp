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
		size_t _tid4C;
		size_t _tid4E;

		//для сериализации аккумулятор всех событий в обе стороны
		std::set<R3Meta_BON::Context> _allContexts;
		std::set<R3Meta_BON::Event> _allEvents;
	public:
		WProtocol(const boost::filesystem::path &path);
		~WProtocol();

		void operator()(const std::set<FCO> &roots);

	private:
		void processContext(Context ctx, bool isServer);

		enum EContextPathType
		{
			cpt_directoryAbs,
			cpt_directoryRel,
			cpt_hppGuard,
			cpt_classScope,
		};
		std::string evalContextPath(Context ctx, bool isServer, EContextPathType cpt);

		size_t getCTid();
		size_t getETid();


		void makeEventsSerialization_hpp();
		void makeEventsSerialization_cpp();


	};
}
#endif
