#ifndef _WORKERS_WSCHEMA_HPP_
#define _WORKERS_WSCHEMA_HPP_

#include "BON.h"
#include "BONImpl.h"
#include <ComponentConfig.h>
#include "R3MetaBonX.h"

namespace workers
{
	using namespace BON;
	using namespace R3Meta_BON;

	class WSchema
	{
	public:
		WSchema();
		~WSchema();

		void operator()(const std::set<FCO> &roots);

	private:
		void processSchema(std::string name, std::set<Category> cats);
		void processCategory(Category cat);
	};
}
#endif
