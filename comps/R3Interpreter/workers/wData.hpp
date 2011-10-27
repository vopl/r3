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
		void mkSchema(const Data &data);
		void mkSchemaTypes(out::File &hpp, const Data &data);

		void mkCategoryClass(out::File &hpp, const Category &cat, bool fwd=false);
		void mkFieldClass(out::File &hpp, const Field &fld, bool fwd=false);
		void mkRelationClass(out::File &hpp, const CategoryRelation &rel, bool fwd=false);

		void mkSchemaInitializer(out::File &hpp, const Data &data);
		void mkSchemaInitializerPre(out::File &hpp, const Data &data);
		void mkSchemaInitializerDeps(out::File &hpp, const Data &data);
		void mkSchemaInitializerCreate(out::File &hpp, const Data &data);
		void mkSchemaInitializerLinks(out::File &hpp, const Data &data);
		void mkSchemaInitializerPost(out::File &hpp, const Data &data);

		std::string relEndName(const CategoryRelation &rel, bool src);

		std::string fieldClassName(const Field &obj);
		std::string relationClassName(const CategoryRelation &obj);
		std::string categoryClassName(const Category &obj);
		std::string schemaClassName(const Data &obj);
	};
}
#endif
