#include "Stdafx.h"
#include "workers/wData.hpp"
#include <Console.h>
#include <direct.h>
#include "out/styler.hpp"

namespace workers
{
	using namespace GMEConsole;
	using namespace std;

	WData::WData(const boost::filesystem::path &path)
		: _path(path)
	{

	}
	WData::~WData()
	{

	}




	//////////////////////////////////////////////////////////////////////////
	void WData::collectInheriance(std::set<Category> &res, Category cat, bool bases, bool recursive)
	{
		if(res.end() != res.find(cat))
		{
			//две базы могут быть и не только по рекурсии
			//assert(!"recursive inheritance");
			return;
		}

		std::set<CategoryOrReference> cors;
		BOOST_FOREACH(Reference ref, cat->getReferredBy())
		{
			cors.insert(ref);
		}
		cors.insert(cat);


		BOOST_FOREACH(CategoryOrReference cor, cors)
		{
			std::multiset<CategoryOrReference> targets;
			if(bases)
			{
				targets = cor->getCategoryInheritanceDsts();
			}
			else
			{
				targets = cor->getCategoryInheritanceSrcs();
			}

			BOOST_FOREACH(CategoryOrReference bas, targets)
			{
				Category scat(bas);
				CategoryReference sref(bas);
				if(sref)
				{
					scat = sref->getCategory();
				}

				if(recursive)
				{
					collectInheriance(res, scat, bases, recursive);
				}

				res.insert(scat);
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	std::set<CategoryRelation> WData::collectRelations(Category cat, bool in, bool out)
	{
		std::set<Category> basesAndSelf;
		collectInheriance(basesAndSelf, cat, true, true);
		basesAndSelf.insert(cat);

		std::set<CategoryOrReference> cors;
		BOOST_FOREACH(Category cat, basesAndSelf)
		{
			BOOST_FOREACH(Reference ref, cat->getReferredBy())
			{
				cors.insert(ref);
			}
			cors.insert(cat);
		}

		std::set<CategoryRelation> res;
		BOOST_FOREACH(CategoryOrReference cor, cors)
		{
			if(in)
			{
				std::set<CategoryRelation> rels = cor->getInCategoryRelationLinks();
				res.insert(rels.begin(), rels.end());
			}
			if(out)
			{
				std::set<CategoryRelation> rels = cor->getOutCategoryRelationLinks();
				res.insert(rels.begin(), rels.end());
			}
		}

		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	std::vector<Field> WData::collectFields(Category cat)
	{
		std::set<Category> basesAndSelf;
		collectInheriance(basesAndSelf, cat, true, true);
		basesAndSelf.insert(cat);

		std::set<Field> fields;
		BOOST_FOREACH(Category cat, orderByName(basesAndSelf))
		{
			std::set<BON::FCO> fcos = cat->getChildFCOs();
			BOOST_FOREACH(Field fld, orderByName(fcos))
			{
				if(!fld) continue;
				fields.insert(fld);
			}
		}

		return orderByName(fields);
	}


	//////////////////////////////////////////////////////////////////////////
	std::vector<Index> WData::collectIndices(Category cat)
	{
		std::set<Category> basesAndSelf;
		collectInheriance(basesAndSelf, cat, true, true);
		basesAndSelf.insert(cat);

		std::set<Index> indices;
		BOOST_FOREACH(Category cat, orderByName(basesAndSelf))
		{
			std::set<Index> fcos = cat->getIndex();
			BOOST_FOREACH(Index idx, orderByName(fcos))
			{
				if(!idx) continue;
				indices.insert(idx);
			}
		}

		return orderByName(indices);
	}









	//////////////////////////////////////////////////////////////////////////
	void WData::mk(const std::set<FCO> &roots)
	{
		//собрать все категории и распредилить по схемам
		BOOST_FOREACH(const FCO &fco, roots)
		{
			Data data(fco);
			if(data)
			{
				mkSchema(data);
			}
		}
	}

	
	//////////////////////////////////////////////////////////////////////////
	void WData::mkSchema(const Data &data)
	{
		Console::Out::WriteLine(("mkSchema: "+data->getName()).c_str());

		boost::filesystem::create_directories(_path/"schemas");
		out::File hpp(_path / "schemas" / (data->getName()+".hpp"));

		hpp<<"// data: "<<data->getName()<<endl;
		hpp<<"#ifndef _DBMETA_SCHEMAS_"<<data->getName()<<"_hpp"<<endl;
		hpp<<"#define _DBMETA_SCHEMAS_"<<data->getName()<<"_hpp"<<endl;
		hpp<<endl;

		hpp<<"#include \"dbMeta/schema.hpp\""<<endl;
		hpp<<"#include \"dbMeta/category.hpp\""<<endl;
		hpp<<"#include \"dbMeta/relation.hpp\""<<endl;
		hpp<<"#include \"dbMeta/relationend.hpp\""<<endl;
		hpp<<"#include \"dbMeta/field.hpp\""<<endl;
		hpp<<"#include \"dbMeta/index.hpp\""<<endl;
		hpp<<"#include \"dbMeta/schemaInitializer.hpp\""<<endl;
		hpp<<endl;

// 		hpp<<"//warning C4355: 'this' : used in base member initializer list"<<endl;
// 		hpp<<"#pragma warning( disable : 4355 )"<<endl;
// 		hpp<<endl;


		//////////////////////////////////////////////////////////////////////////
		hpp<<"namespace dbMeta\n{\nnamespace schemas\n{"<<endl;

		//////////////////////////////////////////////////////////////////////////

		//собрать все поля, индексы, связи
		std::set<Field> allFields;
		std::set<Index> allIndices;
		BOOST_FOREACH(const Category &cat, data->getCategory())
		{
			std::set<FCO> fields = cat->getChildFCOs();
			allFields.insert(fields.begin(), fields.end());

			std::set<Index> indices = cat->getIndex();
			allIndices.insert(indices.begin(), indices.end());
		}
		allFields.erase(Field());
		allIndices.erase(Index());

		//////////////////////////////////////////////////////////////////////////
		//предварительные объявления
		//типы полей
		hpp<<"namespace fields\n{"<<endl;
		BOOST_FOREACH(const Field &fld, allFields)
		{
			mkFieldClass(hpp, fld, true);
		}
		hpp<<"}"<<endl;

		//типы индексов
		hpp<<"namespace indices\n{"<<endl;
		BOOST_FOREACH(const Index &idx, allIndices)
		{
			mkIndexClass(hpp, idx, true);
		}
		hpp<<"}"<<endl;

		//типы категорий
		hpp<<"namespace categories\n{"<<endl;
		BOOST_FOREACH(const Category &cat, data->getCategory())
		{
			mkCategoryClass(hpp, cat, true);
		}
		hpp<<"}"<<endl;

		//типы связей
		hpp<<"namespace relations\n{"<<endl;
		BOOST_FOREACH(const CategoryRelation &rel, data->getCategoryRelation())
		{
			mkRelationClass(hpp, rel, true);
		}
		hpp<<"}"<<endl;
		//предварительное объявление класса схемы
		hpp<<"class "<<schemaClassName(data)<<";"<<endl;





		//////////////////////////////////////////////////////////////////////////
		//типы полей
		hpp<<"namespace fields\n{"<<endl;
		BOOST_FOREACH(const Field &fld, allFields)
		{
			mkFieldClass(hpp, fld);
		}
		hpp<<"}"<<endl;

		//типы индексов
		hpp<<"namespace indices\n{"<<endl;
		BOOST_FOREACH(const Index &idx, allIndices)
		{
			mkIndexClass(hpp, idx);
		}
		hpp<<"}"<<endl;

		//типы категорий
		hpp<<"namespace categories\n{"<<endl;
		BOOST_FOREACH(const Category &cat, data->getCategory())
		{
			mkCategoryClass(hpp, cat);
		}
		hpp<<"}"<<endl;

		//типы связей
		hpp<<"namespace relations\n{"<<endl;
		BOOST_FOREACH(const CategoryRelation &rel, data->getCategoryRelation())
		{
			mkRelationClass(hpp, rel);
		}
		hpp<<"}"<<endl;





		//////////////////////////////////////////////////////////////////////////
		//класс схемы
		hpp<<"class "<<schemaClassName(data)<<"\n	: public ::dbMeta::Schema\n{"<<endl;

		hpp<<"public:"<<endl;
		//категории
		BOOST_FOREACH(const Category &cat, data->getCategory())
		{
			hpp<<"categories::"<<categoryClassName(cat)<<" *"
				""<<cat->getName()<<";"<<endl;
		}

		//конец класса схемы
		hpp<<"};"<<endl;





		hpp<<"}"<<endl;

		mkSchemaInitializerDeps(hpp, data);
		mkSchemaInitializerCreate(hpp, data);
		mkSchemaInitializerLinks(hpp, data);

		hpp<<"}"<<endl;

// 		hpp<<"#pragma warning( default : 4355 )"<<endl;

		hpp<<"#endif"<<endl;
		hpp<<endl;
		hpp.close();
		out::styler_cpp(hpp.pathName());
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkCategoryClass(out::File &hpp, const Category &cat, bool fwd)
	{
		hpp<<"class "<<categoryClassName(cat);
		if(fwd)
		{
			hpp<<";"<<endl;
			return;
		}

		hpp<<"\n : public ::dbMeta::Category\n{"<<endl;
		hpp<<"public:"<<endl;


		//поля
		BOOST_FOREACH(const Field &fld, collectFields(cat))
		{
			hpp<<"fields::"<<fieldClassName(fld)<<" *"<<fld->getName()<<";"<<endl;
		}

		//подключенные связи
		BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, true, false))
		{
			hpp<<"RelationEnd *"<<relEndName(rel, false)<<";";
		}
		BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, false, true))
		{
			hpp<<"RelationEnd *"<<relEndName(rel, true)<<";";
		}

		hpp<<"};\n"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkFieldClass(out::File &hpp, const Field &fld, bool fwd)
	{
		hpp<<"class "<<fieldClassName(fld);
		if(fwd)
		{
			hpp<<";"<<endl;
			return;
		}

		hpp<<"\n : public ::dbMeta::Field\n{"<<endl;
		hpp<<"public:"<<endl;

		hpp<<"};\n"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkIndexClass(out::File &hpp, const Index &idx, bool fwd)
	{
		hpp<<"class "<<indexClassName(idx);
		if(fwd)
		{
			hpp<<";"<<endl;
			return;
		}

		hpp<<"\n : public ::dbMeta::Index\n{"<<endl;
		hpp<<"public:"<<endl;

		hpp<<"};\n"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkRelationClass(out::File &hpp, const CategoryRelation &rel, bool fwd)
	{
		hpp<<"class "<<relationClassName(rel);
		if(fwd)
		{
			hpp<<";"<<endl;
			return;
		}

		hpp<<"\n : public ::dbMeta::Relation\n{"<<endl;
		hpp<<"public:"<<endl;

		hpp<<"};\n"<<endl;

	}

	//////////////////////////////////////////////////////////////////////////
	std::string WData::relEndName(const CategoryRelation &rel, bool src)
	{
		if(src)
		{
			return rel->getName1();
		}
		return rel->getName2();
	}

	//////////////////////////////////////////////////////////////////////////
	std::string WData::fieldClassName(const Field &obj)
	{
		return 
			obj->getParent()->getParent()->getName()+"_"+
			obj->getParent()->getName()+"_"+
			obj->getName();
	}

	//////////////////////////////////////////////////////////////////////////
	std::string WData::indexClassName(const Index &obj)
	{
		return 
			obj->getParent()->getParent()->getName()+"_"+
			obj->getParent()->getName()+"_"+
			obj->getName();
	}

	//////////////////////////////////////////////////////////////////////////
	std::string WData::relationClassName(const CategoryRelation &obj)
	{
		return 
			obj->getParent()->getName()+"_"+
			obj->getSrc()->getName()+"_"+
			(CategoryRelationImpl::one_Multiplier1_Type == obj->getMultiplier1() ? "one":"many")+"_"+
			obj->getName1()+"_"+
			obj->getDst()->getName()+"_"+
			(CategoryRelationImpl::one_Multiplier2_Type == obj->getMultiplier2() ? "one":"many")+"_"+
			obj->getName2();
	}

	//////////////////////////////////////////////////////////////////////////
	std::string WData::categoryClassName(const Category &obj)
	{
		return 
			obj->getParent()->getName()+"_"+
			obj->getName();
	}

	//////////////////////////////////////////////////////////////////////////
	std::string WData::schemaClassName(const Data &obj)
	{
		return 
			obj->getName();
	}
























	void WData::mkSchemaInitializerDeps(out::File &hpp, const Data &data)
	{
		hpp<<"template <>\n"
			"bool SchemaInitializer<schemas::"<<schemaClassName(data)<<">::checkDependencies()\n"
			"{\n"
			"return false;\n"
			"}\n"<<endl;

	}
	void WData::mkSchemaInitializerCreate(out::File &hpp, const Data &data)
	{
		hpp<<"template <>\n"
			"bool SchemaInitializer<schemas::"<<schemaClassName(data)<<">::createObjects()\n"
			"{\n"
			"return false;\n"
			"}\n"<<endl;
	}
	void WData::mkSchemaInitializerLinks(out::File &hpp, const Data &data)
	{
		hpp<<"template <>\n"
			"bool SchemaInitializer<schemas::"<<schemaClassName(data)<<">::linkObjects()\n"
			"{\n"
			"return false;\n"
			"}\n"<<endl;
	}





}
