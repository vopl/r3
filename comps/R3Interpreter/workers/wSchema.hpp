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
		void processSchema(const std::string &name, const std::set<Category> &cats);
		void processSchema_hpp(const std::string &name, const std::set<Category> &cats);
		void processSchema_cpp(const std::string &name, const std::set<Category> &cats);
		
		void processCategory(Category cat);
		void processCategory_hpp(Category cat);
		void processCategory_cpp(Category cat);
	};
}
#endif
