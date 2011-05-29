#ifndef _WORKERS_WSCHEMA_HPP_
#define _WORKERS_WSCHEMA_HPP_

#include "BON.h"
#include "BONImpl.h"
#include <ComponentConfig.h>
#include "R3MetaBonX.h"
#include <algorithm>

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

		void collectInheriance(std::set<Category> &res, Category cat, bool bases, bool recursive);
		void collectRelations(std::set<CategoryRelation> &res, Category cat, bool bases, bool recursive);


		//////////////////////////////////////////////////////////////////////////
		struct OrderCatsPred
		{
			template <class T>
			bool operator()(const T &a, const T &b) const
			{
				if(!a) return true;
				if(!b) return false;
				return a->getName() < b->getName();
			}
		};

		template <class T>
		std::vector<T> orderByName(std::set<T> cats)
		{
			std::vector<T> res(cats.begin(), cats.end());
			std::sort(res.begin(), res.end(), OrderCatsPred());
			return res;
		}
	};
}
#endif
