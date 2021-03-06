#include "Stdafx.h"
#include "workers/wSchema.hpp"
#include <Console.h>
#include <direct.h>
#include "out/styler.hpp"

namespace workers
{
	using namespace GMEConsole;
	using namespace std;

	WSchema::WSchema(const boost::filesystem::path &path)
		: _path(path)
	{

	}
	WSchema::~WSchema()
	{

	}




	//////////////////////////////////////////////////////////////////////////
	void WSchema::collectInheriance(std::set<Category> &res, Category cat, bool bases, bool recursive)
	{
		if(res.end() != res.find(cat))
		{
			//��� ���� ����� ���� � �� ������ �� ��������
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
	std::set<CategoryRelation> WSchema::collectRelations(Category cat, bool in, bool out)
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
	std::vector<Field> WSchema::collectFields(Category cat)
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
	std::vector<Index> WSchema::collectIndices(Category cat)
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
	void WSchema::mk(const std::set<FCO> &roots)
	{
		//������� ��� ��������� � ������������ �� ������
		BOOST_FOREACH(const FCO &fco, roots)
		{
			Schema schema(fco);
			if(schema)
			{
				mkSchema(schema);
			}
		}
	}

	
	//////////////////////////////////////////////////////////////////////////
	void WSchema::mkSchema(const Schema &schema)
	{
		Console::Out::WriteLine(("mkSchema: "+schema->getName()).c_str());
		boost::filesystem::create_directories(_path/"schemas");

		{
			out::File hpp(_path / "schemas" / (schema->getName()+".hpp"));
			hpp<<"// schema: "<<schema->getName()<<endl;
			hpp<<"#ifndef _PGS_META_SCHEMAS_"<<schema->getName()<<"_hpp"<<endl;
			hpp<<"#define _PGS_META_SCHEMAS_"<<schema->getName()<<"_hpp"<<endl;
			hpp<<endl;
			hpp<<"#include \"pgs/meta/schema.hpp\""<<endl;
			hpp<<"#include \"pgs/meta/category.hpp\""<<endl;
			hpp<<"#include \"pgs/meta/relation.hpp\""<<endl;
			hpp<<"#include \"pgs/meta/relationEnd.hpp\""<<endl;
			hpp<<"#include \"pgs/meta/field.hpp\""<<endl;
			hpp<<"#include \"pgs/meta/fieldScanty.hpp\""<<endl;
			hpp<<"#include \"pgs/meta/index.hpp\""<<endl;
			hpp<<endl;

			mkSchemaTypes(hpp, schema);

			hpp<<"#endif"<<endl;
			hpp<<endl;
			hpp.close();
			out::styler_cpp(hpp.pathName());
		}

		{
			out::File hpp(_path / "schemas" / (schema->getName()+"_initializer.hpp"));
			hpp<<"// schema: "<<schema->getName()<<endl;
			hpp<<"#ifndef _PGS_META_SCHEMAS_"<<schema->getName()<<"_INITIALIZER_hpp"<<endl;
			hpp<<"#define _PGS_META_SCHEMAS_"<<schema->getName()<<"_INITIALIZER_hpp"<<endl;
			hpp<<endl;
			hpp<<"#include \"pgs/meta/schemas/"<<schema->getName()<<".hpp\""<<endl;
			hpp<<"#include \"pgs/meta/schemaInitializer.hpp\""<<endl;
			hpp<<endl;

			mkSchemaInitializer(hpp, schema);

			hpp<<"#endif"<<endl;
			hpp<<endl;
			hpp.close();
			out::styler_cpp(hpp.pathName());
		}

	}

	//////////////////////////////////////////////////////////////////////////
	void WSchema::mkSchemaTypes(out::File &hpp, const Schema &schema)
	{
		//////////////////////////////////////////////////////////////////////////
		hpp<<"namespace pgs\n{\nnamespace meta\n{"<<endl;

		//////////////////////////////////////////////////////////////////////////

		//������� ��� ����, �������, �����
		std::set<Field> allFields;
		std::set<Index> allIndices;
		BOOST_FOREACH(const Category &cat, schema->getCategory())
		{
			std::set<FCO> fields = cat->getChildFCOs();
			allFields.insert(fields.begin(), fields.end());

			std::set<Index> indices = cat->getIndex();
			allIndices.insert(indices.begin(), indices.end());
		}
		allFields.erase(Field());
		allIndices.erase(Index());

		//////////////////////////////////////////////////////////////////////////
		//��������������� ����������
		//���� �����
		hpp<<"namespace fields\n{"<<endl;
		BOOST_FOREACH(const Category &cat, schema->getCategory())
		{
			mkFieldClass(hpp, cat, "id", true);
		}
		BOOST_FOREACH(const Field &fld, allFields)
		{
			mkFieldClass(hpp, fld, true);
		}
		hpp<<"}"<<endl;

		//���� ���������
		hpp<<"namespace categories\n{"<<endl;
		BOOST_FOREACH(const Category &cat, schema->getCategory())
		{
			mkCategoryClass(hpp, cat, true);
		}
		hpp<<"}"<<endl;

		//���� ������
		hpp<<"namespace relations\n{"<<endl;
		BOOST_FOREACH(const CategoryRelation &rel, schema->getCategoryRelation())
		{
			mkRelationClass(hpp, rel, true);
		}
		hpp<<"}"<<endl;

		//��������������� ���������� ������ �����
		hpp<<"namespace schemas\n{"<<endl;
		hpp<<"class "<<schemaClassName(schema)<<";"<<endl;
		hpp<<"typedef "<<schemaClassName(schema)<<" *"<<schemaClassName(schema)<<"Ptr;"<<endl;
		hpp<<"typedef const "<<schemaClassName(schema)<<" *"<<schemaClassName(schema)<<"CPtr;"<<endl;
		hpp<<"}"<<endl;





		//////////////////////////////////////////////////////////////////////////
		//���� �����
		hpp<<"namespace fields\n{"<<endl;
		BOOST_FOREACH(const Category &cat, schema->getCategory())
		{
			mkFieldClass(hpp, cat, "id", false);
		}
		BOOST_FOREACH(const Field &fld, allFields)
		{
			mkFieldClass(hpp, fld);
		}
		hpp<<"}"<<endl;

		//���� ���������
		hpp<<"namespace categories\n{"<<endl;
		BOOST_FOREACH(const Category &cat, schema->getCategory())
		{
			mkCategoryClass(hpp, cat);
		}
		hpp<<"}"<<endl;

		//���� ������
		hpp<<"namespace relations\n{"<<endl;
		BOOST_FOREACH(const CategoryRelation &rel, schema->getCategoryRelation())
		{
			mkRelationClass(hpp, rel);
		}
		hpp<<"}"<<endl;





		//////////////////////////////////////////////////////////////////////////
		//����� �����
		hpp<<"namespace schemas\n{"<<endl;
		hpp<<"class "<<schemaClassName(schema)<<"\n	: public ::pgs::meta::Schema\n{"<<endl;

		hpp<<"public:"<<endl;
		//���������
		BOOST_FOREACH(const Category &cat, schema->getCategory())
		{
			hpp<<"categories::"<<categoryClassName(cat)<<" *"
				""<<cat->getName()<<";"<<endl;
		}

		//����� ������ �����
		hpp<<"};"<<endl;





		hpp<<"}"<<endl;
		hpp<<"}\n}"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WSchema::mkCategoryClass(out::File &hpp, const Category &cat, bool fwd)
	{
		hpp<<"class "<<categoryClassName(cat);
		if(fwd)
		{
			hpp<<";"<<endl;
			return;
		}

		hpp<<"\n : public ::pgs::meta::Category\n{"<<endl;
		hpp<<"public:"<<endl;


		//����
		hpp<<"fields::"<<fieldClassName(cat, "id")<<" *id;"<<endl;
		BOOST_FOREACH(const Field &fld, collectFields(cat))
		{
			hpp<<"fields::"<<fieldClassName(fld)<<" *"<<fld->getName()<<";"<<endl;
		}

		//������������ �����
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
	void WSchema::mkFieldClass(out::File &hpp, const Field &fld, bool fwd)
	{
		hpp<<"class "<<fieldClassName(fld);
		if(fwd)
		{
			hpp<<";"<<endl;
			return;
		}

		hpp<<"\n : public ::pgs::meta::";
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
	
	void WSchema::mkFieldClass(out::File &hpp, const Category &cat, const std::string &name, bool fwd)
	{
		hpp<<"class "<<fieldClassName(cat, name);
		if(fwd)
		{
			hpp<<";"<<endl;
			return;
		}

		hpp<<"\n : public ::pgs::meta::Field";
		hpp<<"\n{"<<endl;
		hpp<<"public:"<<endl;

		hpp<<"};\n"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WSchema::mkRelationClass(out::File &hpp, const CategoryRelation &rel, bool fwd)
	{
		hpp<<"class "<<relationClassName(rel);
		if(fwd)
		{
			hpp<<";"<<endl;
			return;
		}

		hpp<<"\n : public ::pgs::meta::Relation\n{"<<endl;
		hpp<<"public:"<<endl;

		hpp<<"};\n"<<endl;

	}

	//////////////////////////////////////////////////////////////////////////
	std::string WSchema::relEndName(const CategoryRelation &rel, bool src)
	{
		if(src)
		{
			return rel->getName1();
		}
		return rel->getName2();
	}


	//////////////////////////////////////////////////////////////////////////
	std::string WSchema::fieldClassName(const Field &obj)
	{
		return fieldClassName(Category(obj->getParent()), obj->getName());
	}

	//////////////////////////////////////////////////////////////////////////
	std::string WSchema::fieldClassName(const Category &obj, const std::string &name)
	{
		return 
			obj->getParent()->getName()+"_"+
			obj->getName()+"_"+
			name;
	}


	//////////////////////////////////////////////////////////////////////////
	std::string WSchema::relationClassName(const CategoryRelation &obj)
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
	std::string WSchema::relationName(const CategoryRelation &obj)
	{
		return 
			obj->getSrc()->getName()+"_"+
			obj->getName1()+"_"+
			obj->getDst()->getName()+"_"+
			obj->getName2();
	}

	//////////////////////////////////////////////////////////////////////////
	std::string WSchema::categoryClassName(const Category &obj)
	{
		return 
			obj->getParent()->getName()+"_"+
			obj->getName();
	}

	//////////////////////////////////////////////////////////////////////////
	std::string WSchema::schemaClassName(const Schema &obj)
	{
		return 
			obj->getName();
	}




















	//////////////////////////////////////////////////////////////////////////
	void WSchema::mkSchemaInitializer(out::File &hpp, const Schema &schema)
	{
		//////////////////////////////////////////////////////////////////////////
		hpp<<"namespace pgs\n{\nnamespace meta\n{"<<endl;

		mkSchemaInitializerPre(hpp, schema);
		mkSchemaInitializerDeps(hpp, schema);
		mkSchemaInitializerCreate(hpp, schema);
		mkSchemaInitializerLinks(hpp, schema);
		mkSchemaInitializerPost(hpp, schema);

		hpp<<"}\n}"<<endl;
	}


	//////////////////////////////////////////////////////////////////////////
	void WSchema::mkSchemaInitializerPre(out::File &hpp, const Schema &schema)
	{
		hpp<<"template <>\n"
			"bool SchemaInitializer<schemas::"<<schemaClassName(schema)<<">::preInit()\n"
			"{\n"
				"_schema->_name = \""<<schema->getName()<<"\";\n"
				"if(_storage->_schemas[_schema->_name]) \n"
				"{\n"
					"assert(!\"duplicated category: "<<schema->getName()<<"\");\n"
					"return false;\n"
				"}\n"
				"_schema->_storage = _storage;\n"
				"_storage->_schemas.push_back(_schema);\n"
				"return true;\n"
			"}\n"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WSchema::mkSchemaInitializerDeps(out::File &hpp, const Schema &schema)
	{

		std::set<Schema> aliens;
		BOOST_FOREACH(CategoryReference ref, schema->getCategoryReference())
		{
			Category alienCat = ref->getCategory();
			if(schema != alienCat->getParent())
			{
				aliens.insert(Schema(alienCat->getParent()));
			}
		}


		hpp<<"template <>\n"
			"bool SchemaInitializer<schemas::"<<schemaClassName(schema)<<">::checkDependencies()\n"
			"{\n";


		BOOST_FOREACH(Schema alien, aliens)
		{
			hpp<<"if(!_storage->_schemas[\""<<alien->getName()<<"\"])\n"
			"{\n"
				"assert(!\"dependency absent: "<<alien->getName()<<" for "<<schema->getName()<<"\");\n"
				"return false;\n"
			"}\n";
		}


		hpp<<"return true;\n"
			"}\n"<<endl;

	}
	
	//////////////////////////////////////////////////////////////////////////
	void WSchema::mkSchemaInitializerCreate(out::File &hpp, const Schema &schema)
	{
		hpp<<"template <>\n"
			"bool SchemaInitializer<schemas::"<<schemaClassName(schema)<<">::createObjects()\n"
			"{\n";

			BOOST_FOREACH(Category cat, schema->getCategory())
			{
				hpp<<
				"{\n"
				"	boost::shared_ptr<categories::"<<categoryClassName(cat)<<"> c(new categories::"<<categoryClassName(cat)<<");\n"
				"	c->_name = \""<<cat->getName()<<"\";"
				"	c->_isAbstract = "<<(cat->isAbstract()?"true":"false")<<";\n"
				"	c->_schema = _schema;\n"
				"	_storage->_categories_heap.push_back(c);\n"
				"	_schema->_categories.push_back(c.get());\n";



				//���� id, ������ ��� ����� �������
				if(cat->getCategoryInheritanceDsts().empty())
				{
					hpp<<
						"{\n"
						"	boost::shared_ptr<fields::"<<fieldClassName(cat, "id")<<"> f(new fields::"<<fieldClassName(cat, "id")<<");\n"
						"	f->_name = \"id\";\n"
						"	f->_allowNull = false;\n"
						"	f->_type = eftId;\n"
						"	f->_category = c.get();\n"
						"	_storage->_fields_heap.push_back(f);\n"
						"	c->_ownFields.push_back(f.get());\n"
						"}\n";
				}

				//��������� ���� �� ������
				BOOST_FOREACH(Field fld, cat->getChildFCOs())
				{
					if(fld)
					{
						hpp<<
							"{\n"
							"	boost::shared_ptr<fields::"<<fieldClassName(fld)<<"> f(new fields::"<<fieldClassName(fld)<<");\n"
							"	f->_name = \""<<fld->getName()<<"\";\n"
							"	f->_allowNull = "<<(fld->isAllowNull()?"true":"false")<<";\n"
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

				//������ �������
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
						hpp<<";\n";


					BOOST_FOREACH(Field fld, idx->getIndexOnCategoryFieldSrcs())
					{
						hpp<<"	i->_fields.push_back(c->_ownFields[\""+fld->getName()+"\"]);\n";
					}

					hpp<<
						"	i->_category = c.get();\n";

					hpp<<
						"	_storage->_indices_heap.push_back(i);\n"
						"	c->_ownIndices.push_back(i.get());\n";

					hpp<<"}\n";
				}

				hpp<<
				"}\n";
			}


			BOOST_FOREACH(CategoryRelation rel, schema->getCategoryRelation())
			{
				hpp<<
					"{\n"
					"	boost::shared_ptr<relations::"<<relationClassName(rel)<<"> r(new relations::"<<relationClassName(rel)<<");\n"
					"	r->_name = \""<<relationName(rel)<<"\";"
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
	void WSchema::mkSchemaInitializerLinks(out::File &hpp, const Schema &schema)
	{
		//������ ����������
		hpp<<"template <>\n"
			"bool SchemaInitializer<schemas::"<<schemaClassName(schema)<<">::linkObjects()\n"
			"{\n";

		BOOST_FOREACH(Category cat, schema->getCategory())
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

		BOOST_FOREACH(CategoryRelation rel, schema->getCategoryRelation())
		{
			hpp<<"{\n";
			Category catSrc = rel->getSrc();
			if(!catSrc) catSrc = CategoryReference(rel->getSrc())->getCategory();

			Category catDst = rel->getDst();
			if(!catDst) catDst = CategoryReference(rel->getDst())->getCategory();

			hpp<<
				"RelationPtr r = _storage->_schemas[\""<<rel->getParent()->getName()<<"\"]->_relations[\""<<relationName(rel)<<"\"];\n"
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
	void WSchema::mkSchemaInitializerPost(out::File &hpp, const Schema &schema)
	{
		hpp<<"template <>\n"
			"bool SchemaInitializer<schemas::"<<schemaClassName(schema)<<">::postInit()\n"
			"{\n";

			hpp<<"schemas::"<<schemaClassName(schema)<<" *s = static_cast<schemas::"<<schemaClassName(schema)<<" *>(_schema);\n";

		BOOST_FOREACH(Category cat, schema->getCategory())
		{
			hpp<<"{\n";
			hpp<<"categories::"<<categoryClassName(cat)<<" *c = static_cast<categories::"<<categoryClassName(cat)<<" *>(_schema->_categories[\""<<cat->getName()<<"\"]);\n";

			hpp<<"s->"<<cat->getName()<<" = c;\n";

			//����
			hpp<<"c->id = adoptField<fields::"<<fieldClassName(cat, "id")<<">(c, \"id\");\n";
			BOOST_FOREACH(const Field &fld, collectFields(cat))
			{
				hpp<<"c->"<<fld->getName()<<" = adoptField<fields::"<<fieldClassName(fld)<<">(c, \""<<fld->getName()<<"\");\n";
			}

			//������������ �����
			BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, true, false))
			{
				hpp<<"c->"<<relEndName(rel, false)<<" = adoptRelationEnd(c, \""<<relEndName(rel, false)<<"\");\n";
			}
			BOOST_FOREACH(const CategoryRelation &rel, collectRelations(cat, false, true))
			{
				hpp<<"c->"<<relEndName(rel, true)<<" = adoptRelationEnd(c, \""<<relEndName(rel, true)<<"\");\n";
			}

			//�������
			BOOST_FOREACH(const Index &idx, collectIndices(cat))
			{
				hpp<<"adoptIndex(c, \""<<idx->getName()<<"\");\n";
			}


			hpp<<"}\n";
		}

		hpp<<"return true;\n"
			"}\n"<<endl;




		hpp<<"template <>\n"
			"const std::string SchemaInitializer<schemas::"<<schemaClassName(schema)<<">::_sname=\""<<schema->getName()<<"\";\n";

	}



}
