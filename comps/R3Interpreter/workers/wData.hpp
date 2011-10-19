#ifndef _WORKERS_WDATA_HPP_
#define _WORKERS_WDATA_HPP_

#include "BON.h"
#include "BONImpl.h"
#include <ComponentConfig.h>
#include "R3MetaBonX.h"
#include <algorithm>
#include <boost/filesystem.hpp>
#include "out/file.hpp"

namespace workers
{
	using namespace BON;
	using namespace R3Meta_BON;

	class WData
	{
		const boost::filesystem::path _path;
	public:
		WData(const boost::filesystem::path &path);
		~WData();
	private:
		void collectInheriance(std::set<Category> &res, Category cat, bool bases, bool recursive);
		std::set<CategoryRelation> collectRelations(Category cat, bool in, bool out);
		std::vector<Field> collectFields(Category cat);
		std::vector<Index> collectIndices(Category cat);


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


	public:
		void mk(const std::set<FCO> &roots);
	private:
		void mkData(const Data &data);
		void mkCategory(out::File &hpp, const Category &cat);
		void mkField(out::File &hpp, const Field &fld);
		void mkIndex(out::File &hpp, const Index &idx);
		void mkRelation(out::File &hpp, const CategoryRelation &rel);

		std::string relName(const CategoryRelation &rel);
	};
}
#endif
