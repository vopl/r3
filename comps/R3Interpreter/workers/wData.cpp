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

		{
			out::File hpp(_path / "schemas" / (data->getName()+".hpp"));
			hpp<<"// data: "<<data->getName()<<endl;
			hpp<<"#ifndef _DBMETA_SCHEMAS_"<<data->getName()<<"_hpp"<<endl;
			hpp<<"#define _DBMETA_SCHEMAS_"<<data->getName()<<"_hpp"<<endl;
			hpp<<endl;
			hpp<<"#include \"dbMeta/schema.hpp\""<<endl;
			hpp<<"#include \"dbMeta/category.hpp\""<<endl;
			hpp<<"#include \"dbMeta/relation.hpp\""<<endl;
			hpp<<"#include \"dbMeta/relationEnd.hpp\""<<endl;
			hpp<<"#include \"dbMeta/field.hpp\""<<endl;
			hpp<<"#include \"dbMeta/fieldScanty.hpp\""<<endl;
			hpp<<"#include \"dbMeta/index.hpp\""<<endl;
			hpp<<endl;

			mkSchemaTypes(hpp, data);

			hpp<<"#endif"<<endl;
			hpp<<endl;
			hpp.close();
			out::styler_cpp(hpp.pathName());
		}

		{
			out::File hpp(_path / "schemas" / (data->getName()+"_initializer.hpp"));
			hpp<<"// data: "<<data->getName()<<endl;
			hpp<<"#ifndef _DBMETA_SCHEMAS_"<<data->getName()<<"_INITIALIZER_hpp"<<endl;
			hpp<<"#define _DBMETA_SCHEMAS_"<<data->getName()<<"_INITIALIZER_hpp"<<endl;
			hpp<<endl;
			hpp<<"#include \"dbMeta/schemas/"<<data->getName()<<".hpp\""<<endl;
			hpp<<"#include \"dbMeta/schemaInitializer.hpp\""<<endl;
			hpp<<endl;

			mkSchemaInitializer(hpp, data);

			hpp<<"#endif"<<endl;
			hpp<<endl;
			hpp.close();
			out::styler_cpp(hpp.pathName());
		}

	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkSchemaTypes(out::File &hpp, const Data &data)
	{
		//////////////////////////////////////////////////////////////////////////
		hpp<<"namespace dbMeta\n{"<<endl;

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
		hpp<<"namespace schemas\n{"<<endl;
		hpp<<"class "<<schemaClassName(data)<<";"<<endl;
		hpp<<"typedef "<<schemaClassName(data)<<" *"<<schemaClassName(data)<<"Ptr;"<<endl;
		hpp<<"typedef const "<<schemaClassName(data)<<" *"<<schemaClassName(data)<<"CPtr;"<<endl;
		hpp<<"}"<<endl;





		//////////////////////////////////////////////////////////////////////////
		//типы полей
		hpp<<"namespace fields\n{"<<endl;
		BOOST_FOREACH(const Field &fld, allFields)
		{
			mkFieldClass(hpp, fld);
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
		hpp<<"namespace schemas\n{"<<endl;
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
		hpp<<"}"<<endl;
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

		hpp<<"\n : public ::dbMeta::";
		if(Scanty(fld))
		{
			hpp<<"FieldScanty";
		}
		else
		{
			hpp<<"Field";
		}
		hpp<<"\n{"<<endl;
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




















	//////////////////////////////////////////////////////////////////////////
	void WData::mkSchemaInitializer(out::File &hpp, const Data &data)
	{
		//////////////////////////////////////////////////////////////////////////
		hpp<<"namespace dbMeta\n{"<<endl;

		mkSchemaInitializerPre(hpp, data);
		mkSchemaInitializerDeps(hpp, data);
		mkSchemaInitializerCreate(hpp, data);
		mkSchemaInitializerLinks(hpp, data);
		mkSchemaInitializerPost(hpp, data);

		hpp<<"}"<<endl;
	}


	//////////////////////////////////////////////////////////////////////////
	void WData::mkSchemaInitializerPre(out::File &hpp, const Data &data)
	{
		hpp<<"template <>\n"
			"bool SchemaInitializer<schemas::"<<schemaClassName(data)<<">::preInit()\n"
			"{\n"
				"_schema->_name = \""<<data->getName()<<"\";\n"
				"if(_storage->_schemas[_schema->_name]) \n"
				"{\n"
					"assert(!\"duplicated category: "<<data->getName()<<"\");\n"
					"return false;\n"
				"}\n"
				"_schema->_storage = _storage;\n"
				"_storage->_schemas.push_back(_schema);\n"
				"return true;\n"
			"}\n"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkSchemaInitializerDeps(out::File &hpp, const Data &data)
	{

		std::set<Data> aliens;
		BOOST_FOREACH(CategoryReference ref, data->getCategoryReference())
		{
			Category alienCat = ref->getCategory();
			if(data != alienCat->getParent())
			{
				aliens.insert(Data(alienCat->getParent()));
			}
		}


		hpp<<"template <>\n"
			"bool SchemaInitializer<schemas::"<<schemaClassName(data)<<">::checkDependencies()\n"
			"{\n";


		BOOST_FOREACH(Data alien, aliens)
		{
			hpp<<"if(!_storage->_schemas[\""<<alien->getName()<<"\"])\n"
			"{\n"
				"assert(!\"dependency absent: "<<alien->getName()<<" for "<<data->getName()<<"\");\n"
				"return false;\n"
			"}\n";
		}


		hpp<<"return true;\n"
			"}\n"<<endl;

	}
	
	//////////////////////////////////////////////////////////////////////////
	void WData::mkSchemaInitializerCreate(out::File &hpp, const Data &data)
	{
		hpp<<"template <>\n"
			"bool SchemaInitializer<schemas::"<<schemaClassName(data)<<">::createObjects()\n"
			"{\n";

			BOOST_FOREACH(Category cat, data->getCategory())
			{
				hpp<<
				"{\n"
				"	boost::shared_ptr<categories::"<<categoryClassName(cat)<<"> c(new categories::"<<categoryClassName(cat)<<");\n"
				"	c->_name = \""<<cat->getName()<<"\";"
				"	c->_isAbstract = "<<(cat->isAbstract()?"true":"false")<<";\n"
				"	c->_schema = _schema;\n"
				"	_storage->_categories_heap.push_back(c);\n"
				"	_schema->_categories.push_back(c.get());\n";

				BOOST_FOREACH(Field fld, cat->getChildFCOs())
				{
					if(fld)
					{
						hpp<<
							"{\n"
							"	boost::shared_ptr<fields::"<<fieldClassName(fld)<<"> f(new fields::"<<fieldClassName(fld)<<");\n"
							"	f->_name = \""<<fld->getName()<<"\";\n"
							"	f->_type = eft"<<fld->getFCOMeta().name()<<";\n"
							"	f->_category = c.get();\n";
							
							if(Scanty(fld))
							{
								Scanty sf(fld);
								hpp<<"f->_values.reserve("<<sf->getScantyValue().size()<<");\n";

								BOOST_FOREACH(ScantyValue sv, sf->getScantyValue())
								{
									hpp<<"{\n"
										"boost::shared_ptr<FieldScantyValue> sv(new FieldScantyValue);"
										"sv->_name = \""<<sv->getName()<<"\";\n"
										"sv->_key = "<<sv->getScantyValueKey()<<";\n"
										"sv->_shortDescription = \""<<sv->getShortDescription()<<"\";\n"
										"sv->_longDescription = \""<<sv->getLongDescription()<<"\";\n"
										"sv->_field = f.get();\n"
										"_storage->_fieldScantyValues_heap.push_back(sv);\n"
										"f->_values.push_back(sv.get());\n";

									hpp<<"}\n";
								}
							}

							hpp<<
							"	_storage->_fields_heap.push_back(f);\n"
							"	c->_ownFields.push_back(f.get());\n";
							
							hpp<<"}\n";
					}
				}

				//теперь индексы
				BOOST_FOREACH(Index idx, cat->getIndex())
				{
					hpp<<
						"{\n"
						"	boost::shared_ptr<Index> i(new Index);\n"
						"	i->_name = \""<<idx->getName()<<"\";\n"
						"	i->_type = eit";
						switch(idx->getIndexType())
						{
						default:
							assert(0);
						case IndexImpl::tree_IndexType_Type:
							hpp<<"Tree";
							break;
						case IndexImpl::hash_IndexType_Type:
							hpp<<"Hash";
							break;
						}
						hpp<<";\n"
						"	i->_category = c.get();\n";

					hpp<<
						"	_storage->_indices_heap.push_back(i);\n"
						"	c->_ownIndices.push_back(i.get());\n";

					hpp<<"}\n";
				}

				hpp<<
				"}\n";
			}


			BOOST_FOREACH(CategoryRelation rel, data->getCategoryRelation())
			{
				hpp<<
					"{\n"
					"	boost::shared_ptr<relations::"<<relationClassName(rel)<<"> r(new relations::"<<relationClassName(rel)<<");\n"
					"	r->_name = \""<<relationClassName(rel)<<"\";"
					"	r->_schema = _schema;\n";

					hpp<<"{\n"
						"boost::shared_ptr<RelationEnd> re(new RelationEnd);\n"

						"re->_name = \""<<relEndName(rel, true)<<"\";\n"
						"re->_isInput = true;\n"
						"re->_mult = erm";
						switch(rel->getMultiplier1())
						{
						default:
							assert(0);
						case CategoryRelationImpl::one_Multiplier1_Type:
							hpp<<"One";
							break;
						case CategoryRelationImpl::many_Multiplier1_Type:
							hpp<<"Many";
							break;
						}
						hpp<<";\n"
						"re->_relation = r.get();\n"
						"r->_inputEnd = re.get();\n"
						"_storage->_relationEnds_heap.push_back(re);\n";
					hpp<<"}\n";

					hpp<<"{\n"
						"boost::shared_ptr<RelationEnd> re(new RelationEnd);\n"

						"re->_name = \""<<relEndName(rel, false)<<"\";\n"
						"re->_isInput = false;\n"
						"re->_mult = erm";
						switch(rel->getMultiplier2())
						{
						default:
							assert(0);
						case CategoryRelationImpl::one_Multiplier2_Type:
							hpp<<"One";
							break;
						case CategoryRelationImpl::many_Multiplier2_Type:
							hpp<<"Many";
							break;
						}
						hpp<<";\n"
						"re->_relation = r.get();\n"
						"r->_outputEnd = re.get();\n"
						"_storage->_relationEnds_heap.push_back(re);\n";
					hpp<<"}\n"

					"	r->_outputEnd->_anotherEnd = r->_inputEnd;\n"
					"	r->_inputEnd->_anotherEnd = r->_outputEnd;\n"

					"	_storage->_relations_heap.push_back(r);\n"
					"	_schema->_relations.push_back(r.get());\n";

				hpp<<"}\n"<<endl;
			}
			hpp<<"return true;\n"
			"}\n"<<endl;
	}
	
	//////////////////////////////////////////////////////////////////////////
	void WData::mkSchemaInitializerLinks(out::File &hpp, const Data &data)
	{
		//теперь связывание
		hpp<<"template <>\n"
			"bool SchemaInitializer<schemas::"<<schemaClassName(data)<<">::linkObjects()\n"
			"{\n";

		BOOST_FOREACH(Category cat, data->getCategory())
		{
			hpp<<"{\n";
			hpp<<"CategoryPtr c = _schema->_categories[\""<<cat->getName()<<"\"];\n";

			std::set<Category> cats;
			//bases
			cats.clear(); collectInheriance(cats, cat, true, false);
			BOOST_FOREACH(Category cat2, cats)
			{
				hpp<<"c->_bases.push_back(_storage->_schemas[\""<<cat2->getParent()->getName()<<"\"]->_categories[\""<<cat2->getName()<<"\"]);\n";
			}
			//deriveds
			cats.clear(); collectInheriance(cats, cat, false, false);
			BOOST_FOREACH(Category cat2, cats)
			{
				hpp<<"c->_deriveds.push_back(_storage->_schemas[\""<<cat2->getParent()->getName()<<"\"]->_categories[\""<<cat2->getName()<<"\"]);\n";
			}
			hpp<<"}\n";
		}

		BOOST_FOREACH(CategoryRelation rel, data->getCategoryRelation())
		{
			hpp<<"{\n";
			Category catSrc = rel->getSrc();
			if(!catSrc) catSrc = CategoryReference(rel->getSrc())->getCategory();

			Category catDst = rel->getDst();
			if(!catDst) catDst = CategoryReference(rel->getDst())->getCategory();

			hpp<<
				"RelationPtr r = _storage->_schemas[\""<<rel->getParent()->getName()<<"\"]->_relations[\""<<relationClassName(rel)<<"\"];\n"
				"CategoryPtr in = _storage->_schemas[\""<<catSrc->getParent()->getName()<<"\"]->_categories[\""<<catSrc->getName()<<"\"];\n"
				"CategoryPtr out = _storage->_schemas[\""<<catDst->getParent()->getName()<<"\"]->_categories[\""<<catDst->getName()<<"\"];\n"


				"r->_inputEnd->_category = in;\n"
				"in->_ownRelationEnds.push_back(r->_inputEnd);\n"

				"r->_outputEnd->_category = out;\n"
				"out->_ownRelationEnds.push_back(r->_outputEnd);\n";


			hpp<<"}\n"<<endl;
		}
		hpp<<"return true;\n"
			"}\n"<<endl;
	}


	//////////////////////////////////////////////////////////////////////////
	void WData::mkSchemaInitializerPost(out::File &hpp, const Data &data)
	{
		hpp<<"template <>\n"
			"bool SchemaInitializer<schemas::"<<schemaClassName(data)<<">::postInit()\n"
			"{\n";

			hpp<<"schemas::"<<schemaClassName(data)<<" *s = static_cast<schemas::"<<schemaClassName(data)<<" *>(_schema);\n";

		BOOST_FOREACH(Category cat, data->getCategory())
		{
			hpp<<"{\n";
			hpp<<"categories::"<<categoryClassName(cat)<<" *c = static_cast<categories::"<<categoryClassName(cat)<<" *>(_schema->_categories[\""<<cat->getName()<<"\"]);\n";

			hpp<<"s->"<<cat->getName()<<" = c;\n";

			//поля
			BOOST_FOREACH(const Field &fld, collectFields(cat))
			{
				hpp<<"c->"<<fld->getName()<<" = adoptField<fields::"<<fieldClassName(fld)<<">(c, \""<<fld->getName()<<"\");\n";
			}

			//подключенные связи
			BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, true, false))
			{
				hpp<<"c->"<<relEndName(rel, false)<<" = adoptRelationEnd(c, \""<<relEndName(rel, false)<<"\");\n";
			}
			BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, false, true))
			{
				hpp<<"c->"<<relEndName(rel, true)<<" = adoptRelationEnd(c, \""<<relEndName(rel, true)<<"\");\n";
			}

			//индексы
			BOOST_FOREACH(const Index &idx, collectIndices(cat))
			{
				hpp<<"adoptIndex(c, \""<<idx->getName()<<"\");\n";
			}


			hpp<<"}\n";
		}

		hpp<<"return true;\n"
			"}\n"<<endl;




		hpp<<"template <>\n"
			"const std::string SchemaInitializer<schemas::"<<schemaClassName(data)<<">::_sname=\""<<data->getName()<<"\";\n";

	}



}
