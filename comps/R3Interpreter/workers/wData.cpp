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

		//////////////////////////////////////////////////////////////////////////
		//предварительное объ€вление класса схемы
		hpp<<"class "<<data->getName()<<";"<<endl;

		//собрать все пол€, индексы, св€зи
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
		//предварительные объ€влени€
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

		//типы св€зей
		hpp<<"namespace relations\n{"<<endl;
		BOOST_FOREACH(const CategoryRelation &rel, data->getCategoryRelation())
		{
			mkRelationClass(hpp, rel, true);
		}
		hpp<<"}"<<endl;
		//класс схемы
		hpp<<"class "<<data->getName()<<";"<<endl;





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

		//типы св€зей
		hpp<<"namespace relations\n{"<<endl;
		BOOST_FOREACH(const CategoryRelation &rel, data->getCategoryRelation())
		{
			mkRelationClass(hpp, rel);
		}
		hpp<<"}"<<endl;





		//////////////////////////////////////////////////////////////////////////
		//класс схемы
		hpp<<"class "<<data->getName()<<"\n	: public ::dbMeta::Schema\n{"<<endl;

		hpp<<"public:"<<endl;

		hpp<<"struct __SchemaInternals\n{"<<endl;
		hpp<<"int stub;"<<endl;

		hpp<<"__SchemaInternals(const "<<data->getName()<<" *schema);"<<endl;
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
		//объекты св€зей
		BOOST_FOREACH(const CategoryRelation &rel, data->getCategoryRelation())
		{
			hpp<<"relations::"<<relName(rel)<<" "
				"relation_"<<relName(rel)<<";"<<endl;
		}
		hpp<<"} __schemaInternals;"<<endl;


		hpp<<"public:"<<endl;
		//объекты категорий
		BOOST_FOREACH(const Category &cat, data->getCategory())
		{
			hpp<<"categories::"<<cat->getName()<<" "
				""<<cat->getName()<<";"<<endl;
		}


		hpp<<"public:"<<endl;

		//конструктор
		hpp<<data->getName()<<"(ManagerPtr manager);"<<endl;


		//конец класса схемы
		hpp<<"};"<<endl;




		//методы полей
		hpp<<"namespace fields\n{"<<endl;
		BOOST_FOREACH(const Field &fld, allFields)
		{
			mkFieldCode(hpp, fld);
		}
		hpp<<"}"<<endl;

		//методы индексов
		hpp<<"namespace indices\n{"<<endl;
		BOOST_FOREACH(const Index &idx, allIndices)
		{
			mkIndexCode(hpp, idx);
		}
		hpp<<"}"<<endl;

		//типы категорий
		hpp<<"namespace categories\n{"<<endl;
		BOOST_FOREACH(const Category &cat, data->getCategory())
		{
			mkCategoryCode(hpp, cat);
		}
		hpp<<"}"<<endl;

		//типы св€зей
		hpp<<"namespace relations\n{"<<endl;
		BOOST_FOREACH(const CategoryRelation &rel, data->getCategoryRelation())
		{
			mkRelationCode(hpp, rel);
		}
		hpp<<"}"<<endl;


		//тело конструктора
		hpp<<"inline "<<data->getName()<<"::"<<data->getName()<<"(ManagerPtr manager)"<<endl;
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
			//св€зи
			hpp<<"boost::assign::list_of<const RelationPtr>()";
			BOOST_FOREACH(const CategoryRelation &rel, data->getCategoryRelation())
			{
				hpp<<" (&__schemaInternals.relation_"<<relName(rel)<<")";
			}
		hpp<<")"<<endl;
		//категории
		BOOST_FOREACH(const Category &cat, data->getCategory())
		{
			hpp<<", "<<cat->getName()<<"(this)"<<endl;
		}

		hpp<<", __schemaInternals(this)"<<endl;

		hpp<<"{}"<<endl;

		hpp<<"inline "<<data->getName()<<"::"<<"__SchemaInternals::__SchemaInternals(const "<<data->getName()<<" *schema)"<<endl;
		hpp<<": stub()"<<endl;
		//св€зи
		BOOST_FOREACH(const CategoryRelation &rel, data->getCategoryRelation())
		{
			hpp<<", relation_"<<relName(rel)<<"(schema)"<<endl;
		}
		//пол€
		BOOST_FOREACH(const Field &fld, allFields)
		{
			hpp<<", field_"<<fld->getParent()->getName()<<"_"<<fld->getName()<<"(&schema->"<<fld->getParent()->getName()<<")"<<endl;
		}
		//индексы
		BOOST_FOREACH(const Index &idx, allIndices)
		{
			hpp<<", index_"<<idx->getParent()->getName()<<"_"<<idx->getName()<<"(&schema->"<<idx->getParent()->getName()<<")"<<endl;
		}
		hpp<<"{}"<<endl;


		hpp<<"}\n}"<<endl;

		hpp<<"#pragma warning( default : 4355 )"<<endl;

		hpp<<"#endif"<<endl;
		hpp<<endl;
		hpp.close();
		out::styler_cpp(hpp.pathName());
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkCategoryClass(out::File &hpp, const Category &cat, bool fwd)
	{
		hpp<<"class "<<cat->getName();
		if(fwd)
		{
			hpp<<";"<<endl;
			return;
		}

		hpp<<"\n : public ::dbMeta::Category\n{"<<endl;
		hpp<<"public:"<<endl;

		//конструктор
		hpp<<cat->getName()<<"(const "<<cat->getParent()->getName()<<"* schema);"<<endl;

		//пол€
		BOOST_FOREACH(const Field &fld, collectFields(cat))
		{
			hpp<<"const fields::"<<fld->getParent()->getName()<<"_"<<fld->getName()<<" &"<<fld->getName()<<";"<<endl;
		}
		//индексы
		BOOST_FOREACH(const Index &idx, collectIndices(cat))
		{
			hpp<<"const indices::"<<idx->getParent()->getName()<<"_"<<idx->getName()<<" &index_"<<idx->getName()<<";"<<endl;
		}
		//подключенные св€зи
		BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, true, false))
		{
			hpp<<"const RelationEnd &"<<relEndName(rel, false)<<";";
		}
		BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, false, true))
		{
			hpp<<"const RelationEnd &"<<relEndName(rel, true)<<";";
		}

		hpp<<"};\n"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkFieldClass(out::File &hpp, const Field &fld, bool fwd)
	{
		hpp<<"class "<<fld->getParent()->getName()<<"_"<<fld->getName();
		if(fwd)
		{
			hpp<<";"<<endl;
			return;
		}

		hpp<<"\n : public ::dbMeta::Field\n{"<<endl;
		hpp<<"public:"<<endl;

		//конструктор
		hpp<<fld->getParent()->getName()<<"_"<<fld->getName()<<"(const categories::"<<fld->getParent()->getName()<<"* category);"<<endl;

		hpp<<"};\n"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkIndexClass(out::File &hpp, const Index &idx, bool fwd)
	{
		hpp<<"class "<<idx->getParent()->getName()<<"_"<<idx->getName();
		if(fwd)
		{
			hpp<<";"<<endl;
			return;
		}

		hpp<<"\n : public ::dbMeta::Index\n{"<<endl;
		hpp<<"public:"<<endl;

		//конструктор
		hpp<<idx->getParent()->getName()<<"_"<<idx->getName()<<"(const categories::"<<idx->getParent()->getName()<<"* category);"<<endl;


		hpp<<"};\n"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkRelationClass(out::File &hpp, const CategoryRelation &rel, bool fwd)
	{
		hpp<<"class "<<relName(rel);
		if(fwd)
		{
			hpp<<";"<<endl;
			return;
		}

		hpp<<"\n : public ::dbMeta::Relation\n{"<<endl;
		hpp<<"public:"<<endl;

		//конструктор
		hpp<<relName(rel)<<"(const "<<rel->getParent()->getName()<<"* schema);"<<endl;

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
	void WData::mkCategoryCode(out::File &hpp, const Category &cat)
	{
		//конструктор
		hpp<<"inline "<<cat->getName()<<"::"<<cat->getName()<<"(const "<<cat->getParent()->getName()<<"* schema)"<<endl;
		hpp<<": ::dbMeta::Category("<<endl;
		//родительска€ схема
		hpp<<"schema,"<<endl;
		//абстракт
		hpp<<(cat->isAbstract()?"true":"false")<<","<<endl;
		//наименование
		hpp<<"\""<<cat->getName()<<"\","<<endl;
		//пол€
		hpp<<"boost::assign::list_of<const FieldPtr>()";
		BOOST_FOREACH(const Field &fld, collectFields(cat))
		{
			hpp<<" (&schema->__schemaInternals.field_"<<fld->getParent()->getName()<<"_"<<fld->getName()<<")";
		}
		hpp<<","<<endl;
		//индексы
		hpp<<"boost::assign::list_of<const IndexPtr>()";
		BOOST_FOREACH(const Index &idx, collectIndices(cat))
		{
			hpp<<" (&schema->__schemaInternals.index_"<<idx->getParent()->getName()<<"_"<<idx->getName()<<")";
		}
		hpp<<","<<endl;
		//подключенные св€зи
		hpp<<"boost::assign::list_of<const RelationEndPtr>()";
		BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, true, false))
		{
			hpp<<" (schema->__schemaInternals.relation_"<<relName(rel)<<"._inputEnd)";
		}
		BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, false, true))
		{
			hpp<<" (schema->__schemaInternals.relation_"<<relName(rel)<<"._outputEnd)";
		}
		hpp<<")\n";

		//пол€
		BOOST_FOREACH(const Field &fld, collectFields(cat))
		{
			hpp<<", "<<fld->getName()<<"(schema->__schemaInternals.field_"<<fld->getParent()->getName()<<"_"<<fld->getName()<<")\n";
		}
		//индексы
		BOOST_FOREACH(const Index &idx, collectIndices(cat))
		{
			hpp<<", index_"<<idx->getName()<<"(schema->__schemaInternals.index_"<<idx->getParent()->getName()<<"_"<<idx->getName()<<")\n";
		}
		//подключенные св€зи
		BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, true, false))
		{
			hpp<<", "<<relEndName(rel, false)<<"(*schema->__schemaInternals.relation_"<<relName(rel)<<"._inputEnd)\n";
		}
		BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, false, true))
		{
			hpp<<", "<<relEndName(rel, true)<<"(*schema->__schemaInternals.relation_"<<relName(rel)<<"._outputEnd)\n";
		}

		hpp<<"{\n};"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkFieldCode(out::File &hpp, const Field &fld)
	{
		//конструктор
		hpp<<"inline "<<fld->getParent()->getName()<<"_"<<fld->getName()<<"::"<<fld->getParent()->getName()<<"_"<<fld->getName()<<"(const categories::"<<fld->getParent()->getName()<<"* category)"<<endl;
		hpp<<": ::dbMeta::Field("<<endl;
		//родительска€ категори€
		hpp<<"category,"<<endl;
		//тип пол€
		hpp<<"eft"<<fld->getFCOMeta().name()<<","<<endl;
		//наименование
		hpp<<"\""<<fld->getName()<<"\","<<endl;
		//нул
		hpp<<(fld->isAllowNull()?"true":"false");
		hpp<<")\n{\n};"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkIndexCode(out::File &hpp, const Index &idx)
	{
		//конструктор
		hpp<<"inline "<<idx->getParent()->getName()<<"_"<<idx->getName()<<"::"<<idx->getParent()->getName()<<"_"<<idx->getName()<<"(const categories::"<<idx->getParent()->getName()<<"* category)"<<endl;
		hpp<<": ::dbMeta::Index("<<endl;
		//родительска€ категори€
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
		//пол€
		hpp<<"boost::assign::list_of<const FieldPtr>()";

		BOOST_FOREACH(const Field &fld, idx->getIndexOnCategoryFieldSrcs())
		{
			hpp<<" (&category->"<<fld->getName()<<")";
		}

		hpp<<")\n{\n};"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkRelationCode(out::File &hpp, const CategoryRelation &rel)
	{
		//конструктор
		hpp<<"inline "<<relName(rel)<<"::"<<relName(rel)<<"(const "<<rel->getParent()->getName()<<"* schema)"<<endl;
		hpp<<": ::dbMeta::Relation("<<endl;
		//родительска€ схема
		hpp<<"schema"<<endl;
		hpp<<")\n{\n};"<<endl;
	}

}
