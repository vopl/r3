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
				mkData(data);
			}
		}
	}

	
	//////////////////////////////////////////////////////////////////////////
	void WData::mkData(const Data &data)
	{
		Console::Out::WriteLine(("mkData: "+data->getName()).c_str());

		boost::filesystem::create_directories(_path/"schemas");
		out::File hpp(_path / "schemas" / (data->getName()+".hpp"));

		hpp<<"// data: "<<data->getName()<<endl;
		hpp<<"#ifndef _DBMETA_SCHEMAS_"<<data->getName()<<"_hpp"<<endl;
		hpp<<"#define _DBMETA_SCHEMAS_"<<data->getName()<<"_hpp"<<endl;
		hpp<<endl;

		hpp<<"#include \"dbMeta/relation.hpp\""<<endl;
		hpp<<endl;

		hpp<<"//warning C4355: 'this' : used in base member initializer list"<<endl;
		hpp<<"#pragma warning( disable : 4355 )"<<endl;
		hpp<<endl;


		//////////////////////////////////////////////////////////////////////////
		hpp<<"namespace dbMeta\n{\nnamespace schemas\n{"<<endl;

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

		//типы полей
		hpp<<"namespace fields\n{"<<endl;
		BOOST_FOREACH(const Field &fld, allFields)
		{
			mkField(hpp, fld);
		}
		hpp<<"}"<<endl;

		//типы индексов
		hpp<<"namespace indices\n{"<<endl;
		BOOST_FOREACH(const Index &idx, allIndices)
		{
			mkIndex(hpp, idx);
		}
		hpp<<"}"<<endl;

		//типы категорий
		hpp<<"namespace categories\n{"<<endl;
		BOOST_FOREACH(const Category &cat, data->getCategory())
		{
			mkCategory(hpp, cat);
		}
		hpp<<"}"<<endl;

		//типы связей
		hpp<<"namespace relations\n{"<<endl;
		BOOST_FOREACH(const CategoryRelation &rel, data->getCategoryRelation())
		{
			mkRelation(hpp, rel);
		}
		hpp<<"}"<<endl;


		//////////////////////////////////////////////////////////////////////////
		//класс схемы
		hpp<<"class "<<data->getName()<<"\n	: public ::dbMeta::Schema\n{"<<endl;

		hpp<<"public:"<<endl;
		//объекты полей
		BOOST_FOREACH(const Field &fld, allFields)
		{
			hpp<<"fields::"<<fld->getParent()->getName()<<"_"<<fld->getName()<<" "
				"field_"<<fld->getParent()->getName()<<"_"<<fld->getName()<<";"<<endl;
		}
		//объекты индексов
		BOOST_FOREACH(const Index &idx, allIndices)
		{
			hpp<<"indices::"<<idx->getParent()->getName()<<"_"<<idx->getName()<<" "
				"index_"<<idx->getParent()->getName()<<"_"<<idx->getName()<<";"<<endl;
		}
		//объекты категорий
		BOOST_FOREACH(const Category &cat, data->getCategory())
		{
			hpp<<"categories::"<<cat->getName()<<" "
				""<<cat->getName()<<";"<<endl;
		}
		//объекты связей
		BOOST_FOREACH(const CategoryRelation &rel, data->getCategoryRelation())
		{
			hpp<<"relations::"<<relName(rel)<<" "
				"relation_"<<relName(rel)<<";"<<endl;
		}

		

		hpp<<"public:"<<endl;
		hpp<<data->getName()<<"(ManagerPtr manager)"<<endl;
		hpp<<": ::dbMeta::Schema("<<endl;
			//объемлющий менеджер
			hpp<<"manager,"<<endl;
			//наименование
			hpp<<"\""<<data->getName()<<"\","<<endl;
			//категории
			hpp<<"boost::assign::list_of<const CategoryPtr>()";
			BOOST_FOREACH(const Category &cat, data->getCategory())
			{
				hpp<<" (&"<<cat->getName()<<")";
			}
			hpp<<","<<endl;
			//связи
			hpp<<"boost::assign::list_of<const RelationPtr>()";
			BOOST_FOREACH(const CategoryRelation &rel, data->getCategoryRelation())
			{
				hpp<<" (&relation_"<<relName(rel)<<")";
			}
		hpp<<")"<<endl;

		//категории
		BOOST_FOREACH(const Category &cat, data->getCategory())
		{
			hpp<<", "<<cat->getName()<<"(this)"<<endl;
		}
		//связи
		BOOST_FOREACH(const CategoryRelation &rel, data->getCategoryRelation())
		{
			hpp<<", relation_"<<relName(rel)<<"(this)"<<endl;
		}

		hpp<<"{}"<<endl;



		hpp<<"};"<<endl;

		hpp<<"}\n}"<<endl;

		hpp<<"#pragma warning( default : 4355 )"<<endl;

		hpp<<"#endif"<<endl;
		hpp<<endl;
		hpp.close();
		out::styler_cpp(hpp.pathName());
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkCategory(out::File &hpp, const Category &cat)
	{
		Console::Out::WriteLine(("cat: "+cat->getName()).c_str());

		hpp<<"//////////////////////////////////////////////////////////////////////////"<<endl;
		hpp<<"class "<<cat->getName()<<"\n : public ::dbMeta::Category\n{"<<endl;

		hpp<<"public:"<<endl;

		//конструктор
		hpp<<cat->getName()<<"(const SchemaPtr schema)"<<endl;
		hpp<<": ::dbMeta::Category("<<endl;
			//родительская схема
			hpp<<"schema,"<<endl;
			//абстракт
			hpp<<(cat->isAbstract()?"true":"false")<<","<<endl;
			//наименование
			hpp<<"\""<<cat->getName()<<"\","<<endl;
			//поля
			hpp<<"boost::assign::list_of<const FieldPtr>()";
			BOOST_FOREACH(const Field &fld, collectFields(cat))
			{
				hpp<<" (schema->getField(\""<<fld->getName()<<"\"))";
			}
			hpp<<","<<endl;
			//индексы
			hpp<<"boost::assign::list_of<const IndexPtr>()";
			BOOST_FOREACH(const Index &idx, collectIndices(cat))
			{
				hpp<<" (schema->getIndex(\""<<idx->getName()<<"\"))";
			}
			hpp<<","<<endl;
			//подключенные связи
			hpp<<"boost::assign::list_of<const RelationEndPtr>()";
			BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, true, false))
			{
				hpp<<" (schema->getRelation(\""<<relName(rel)<<"\")->getInputEnd())";
			}
			BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, false, true))
			{
				hpp<<" (schema->getRelation(\""<<relName(rel)<<"\")->getOutputEnd())";
			}
		hpp<<")\n";

		//поля
		BOOST_FOREACH(const Field &fld, collectFields(cat))
		{
			hpp<<", "<<fld->getName()<<"(*schema->getField(\""<<fld->getName()<<"\"))\n";
		}
		//индексы
		hpp<<"boost::assign::list_of<const IndexPtr>()";
		BOOST_FOREACH(const Index &idx, collectIndices(cat))
		{
			hpp<<", index_"<<idx->getName()<<"(*schema->getField(\""<<idx->getName()<<"\"))\n";
		}
		//подключенные связи
		BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, true, false))
		{
			hpp<<", relation_in_"<<relName(rel)<<"(*schema->getRelation(\""<<relName(rel)<<"\")->getInputEnd())\n";
		}
		BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, false, true))
		{
			hpp<<", relation_out_"<<relName(rel)<<"(*schema->getRelation(\""<<relName(rel)<<"\")->getOutputEnd())\n";
		}

		hpp<<"{\n};"<<endl;


		//поля
		BOOST_FOREACH(const Field &fld, collectFields(cat))
		{
			hpp<<"fields::"<<fld->getParent()->getName()<<"_"<<fld->getName()<<" &"<<fld->getName()<<";"<<endl;
		}
		//индексы
		BOOST_FOREACH(const Index &idx, collectIndices(cat))
		{
			hpp<<"indices::"<<idx->getParent()->getName()<<"_"<<idx->getName()<<" &index_"<<idx->getName()<<";"<<endl;
		}
		//подключенные связи
		BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, true, false))
		{
			hpp<<"RelationEnd &relation_in_"<<relName(rel)<<";";
		}
		BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, false, true))
		{
			hpp<<"RelationEnd &relation_out_"<<relName(rel)<<";";
		}

		hpp<<"};\n"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkField(out::File &hpp, const Field &fld)
	{
		Console::Out::WriteLine(("fld: "+fld->getName()).c_str());

		hpp<<"//////////////////////////////////////////////////////////////////////////"<<endl;
		hpp<<"class "<<fld->getParent()->getName()<<"_"<<fld->getName()<<"\n : public ::dbMeta::Field\n{"<<endl;

		hpp<<"public:"<<endl;

		//конструктор
		hpp<<fld->getParent()->getName()<<"_"<<fld->getName()<<"(const CategoryPtr category)"<<endl;
		hpp<<": ::dbMeta::Field("<<endl;
			//родительская категория
			hpp<<"category,"<<endl;
			//тип поля
			hpp<<"eft"<<fld->getFCOMeta().name()<<","<<endl;
			//наименование
			hpp<<"\""<<fld->getName()<<"\","<<endl;
			//нул
			hpp<<(fld->isAllowNull()?"true":"false");
		hpp<<")\n{\n};"<<endl;

		hpp<<"};\n"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkIndex(out::File &hpp, const Index &idx)
	{
		Console::Out::WriteLine(("idx: "+idx->getName()).c_str());

		hpp<<"//////////////////////////////////////////////////////////////////////////"<<endl;
		hpp<<"class "<<idx->getParent()->getName()<<"_"<<idx->getName()<<"\n : public ::dbMeta::Index\n{"<<endl;

		hpp<<"public:"<<endl;

		//конструктор
		hpp<<idx->getParent()->getName()<<"_"<<idx->getName()<<"(const CategoryPtr category)"<<endl;
		hpp<<": ::dbMeta::Index("<<endl;
			//родительская категория
			hpp<<"category,"<<endl;
			//тип индекса
			switch(idx->getIndexType())
			{
			case IndexImpl::tree_IndexType_Type:
				hpp<<"eitTree";
				break;
			case IndexImpl::hash_IndexType_Type:
				hpp<<"eitHash";
				break;
			default:
				Console::Out::WriteLine(("idx: "+idx->getName()+", bad index type").c_str());
			}
			hpp<<","<<endl;
			//наименование
			hpp<<"\""<<idx->getName()<<"\","<<endl;
			//поля
			hpp<<"boost::assign::list_of<const FieldPtr>()";

			BOOST_FOREACH(const Field &fld, idx->getIndexOnCategoryFieldSrcs())
			{
				hpp<<" (category->getField(\""<<fld->getName()<<"\"))";
			}

		hpp<<")\n{\n};"<<endl;



		hpp<<"};\n"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkRelation(out::File &hpp, const CategoryRelation &rel)
	{
		Console::Out::WriteLine(("rel: "+relName(rel)).c_str());

		hpp<<"//////////////////////////////////////////////////////////////////////////"<<endl;
		hpp<<"class "<<relName(rel)<<"\n : public ::dbMeta::Relation\n{"<<endl;

		hpp<<"public:"<<endl;

		//конструктор
		hpp<<relName(rel)<<"(const SchemaPtr schema)"<<endl;
		hpp<<": ::dbMeta::Relation("<<endl;
			//родительская схема
			hpp<<"schema"<<endl;
		hpp<<")\n{\n};"<<endl;

		hpp<<"};\n"<<endl;

	}

	//////////////////////////////////////////////////////////////////////////
	std::string WData::relName(const CategoryRelation &rel)
	{
		
		return 
			rel->getSrc()->getName()+"_"+
			(CategoryRelationImpl::one_Multiplier1_Type == rel->getMultiplier1() ? "one":"many")+"_"+
			rel->getName1()+"_"+
			rel->getDst()->getName()+"_"+
			(CategoryRelationImpl::one_Multiplier2_Type == rel->getMultiplier2() ? "one":"many")+"_"+
			rel->getName2();
	}

}
