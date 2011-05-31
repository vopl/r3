#include "Stdafx.h"
#include "workers/wSchema.hpp"
#include <Console.h>
#include <direct.h>
#include "out/file.hpp"
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

	void WSchema::operator()(const std::set<FCO> &roots)
	{
		boost::filesystem::create_directories(_path/"include/r3/model");
		boost::filesystem::create_directories(_path/"src/r3/model");

		//собрать все категории и распредилить по схемам
		std::map<std::string, std::set<Category> > schema2cats;
		std::set<std::string> schemas;

		BOOST_FOREACH(const FCO &fco, roots)
		{
			Categories categories(fco);
			if(categories)
			{
				BOOST_FOREACH(const Category &cat, categories->getCategory())
				{
					schema2cats[cat->getSchema()].insert(cat);
					schemas.insert(cat->getSchema());
				}
				BOOST_FOREACH(const CategoryReference &catref, categories->getCategoryReference())
				{
					const Category &cat = catref->getCategory();
					schema2cats[cat->getSchema()].insert(cat);
					schemas.insert(cat->getSchema());
				}
			}
		}

		processModel(schemas);

		typedef std::pair<std::string, std::set<Category> > TP;
		BOOST_FOREACH(const TP &p, schema2cats)
		{
			processSchema(p.first, p.second);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void WSchema::processModel(const std::set<std::string> &schemas)
	{
		processModel_hpp(schemas);
		processModel_cpp(schemas);
	}

	void WSchema::processModel_hpp(const std::set<std::string> &schemas)
	{
		out::File hpp(_path / "include/r3/model.hpp");
		hpp<<"// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!"<<endl<<endl;

		hpp<<"#ifndef _r3_model_hpp_"<<endl;
		hpp<<"#define _r3_model_hpp_"<<endl;
		hpp<<endl;

		hpp<<"#include \"r3/modelBase.hpp\""<<endl;
		hpp<<endl;

		BOOST_FOREACH(std::string schemaName, schemas)
		{
			hpp<<"#include \"r3/model/"<<schemaName<<".hpp\""<<endl;
		}
		hpp<<endl;

		hpp<<"namespace r3"<<endl<<"{"<<endl;

		hpp<<"class Model"<<endl;
		hpp<<": public ModelBase"<<endl;
		hpp<<"{"<<endl;


		//тип карты id->schema ptr
		BOOST_FOREACH(std::string schemaName, schemas)
		{
			hpp<<"typedef std::map<std::string, r3::model::"<<schemaName<<"_ptr> TM"<<schemaName<<";"<<endl;
			hpp<<"TM"<<schemaName<<" _"<<schemaName<<";"<<endl;
		}
		hpp<<endl;


		hpp<<"public:"<<endl;


		//геттеры дл€ схем
		BOOST_FOREACH(std::string schemaName, schemas)
		{
			hpp<<"r3::model::"<<schemaName<<"_ptr get"<<schemaName<<"(const char *id)"<<endl;
			hpp<<"{"<<endl;
			hpp<<"return getSchemaImpl(_"<<schemaName<<", id);"<<endl;
			hpp<<"}"<<endl;
		}
		hpp<<endl;



		hpp<<"};"<<endl;
		hpp<<endl;

		hpp<<"}"<<endl;
		hpp<<endl;


		hpp<<"#endif"<<endl;
		hpp<<endl;
		hpp.close();
		out::styler_cpp(hpp.pathName());

	}

	void WSchema::processModel_cpp(const std::set<std::string> &schemas)
	{

	}


	//////////////////////////////////////////////////////////////////////////
	void WSchema::processSchema(const std::string &name, const std::set<Category> &cats)
	{
		Console::Out::WriteLine(("process schema "+name).c_str());

		processSchema_hpp(name, cats);
		processSchema_cpp(name, cats);


		//DDL дл€ Ѕƒ
		//cpp файлы схемы

		BOOST_FOREACH(const Category &cat, orderByName(cats))
		{
			assert(name == cat->getSchema());
			processCategory(cat);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void WSchema::processSchema_hpp(const std::string &name, const std::set<Category> &cats)
	{
		out::File hpp(_path / "include/r3/model" / (name+".hpp"));
		hpp<<"// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!"<<endl<<endl;

		hpp<<"#ifndef _r3_model_"<<name<<"_hpp_"<<endl;
		hpp<<"#define _r3_model_"<<name<<"_hpp_"<<endl;
		hpp<<endl;

		hpp<<"#include \"r3/schemaBase.hpp\""<<endl;
		hpp<<endl;

		hpp<<"namespace r3"<<endl<<"{"<<endl;

		hpp<<"class Model;"<<endl;
		
		hpp<<"namespace model"<<endl<<"{"<<endl;

		hpp<<"namespace s_"<<name<<endl<<"{"<<endl;

		//предварительные объ€влени€ типов категорий
		BOOST_FOREACH(Category cat, orderByName(cats))
		{
			hpp<<"class "<<cat->getName()<<";"<<endl;
			hpp<<"typedef boost::shared_ptr<"<<cat->getName()<<"> "<<cat->getName()<<"_ptr;"<<endl;
			hpp<<endl;
		}

		hpp<<"}"<<endl;
		hpp<<endl;

		//указатель
		hpp<<"class "<<name<<";"<<endl;
		hpp<<"typedef boost::shared_ptr<"<<name<<"> "<<name<<"_ptr;"<<endl;
		hpp<<endl;


		//класс
		hpp<<"class "<<name<<endl;
		hpp<<": public SchemaBase<"<<name<<">"<<endl;
		hpp<<"{"<<endl;
		hpp<<endl;

		hpp<<"public:"<<endl;

		//указатели на экземпл€ры категорий
		BOOST_FOREACH(Category cat, orderByName(cats))
		{
			hpp<<"s_"<<name<<"::"<<cat->getName()<<"_ptr\t_"<<cat->getName()<<";"<<endl;
		}
		hpp<<endl;

		hpp<<"public:"<<endl;

		//конструктор
		hpp<<""<<name<<"(Model *model, const char *id);"<<endl;
		//деструктор
		hpp<<"~"<<name<<"();"<<endl;
		hpp<<endl;

		//перечисление типизированных экземпл€ров категорий
		hpp<<"template <class Oper> void enumCategories(Oper o);"<<endl;


		//шаблон дл€ доступа к экземпл€ру по типу
		hpp<<"template <class C> boost::shared_ptr<C> getCategory();"<<endl;
		hpp<<endl;

		//геттеры дл€ категорий
		BOOST_FOREACH(Category cat, orderByName(cats))
		{
			hpp<<"s_"<<name<<"::"<<cat->getName()<<"_ptr\t"<<"get"<<cat->getName()<<"();"<<endl;
		}
		hpp<<endl;

		hpp<<"};"<<endl;
		//конец класса


		hpp<<endl;
		hpp<<endl;
		hpp<<"//////////////////////////////////////////////////////////////////////////"<<endl;
		hpp<<"//////////////////////////////////////////////////////////////////////////"<<endl;
		

		//конструктор
		hpp<<"inline "<<name<<"::"<<name<<"(Model *model, const char *id)"<<endl;
		hpp<<": SchemaBase<"<<name<<">(model, id, \""<<name<<"\")"<<endl;
		hpp<<"{"<<endl;
		hpp<<"init();"<<endl;
		hpp<<"}"<<endl;

		//деструктор
		hpp<<"inline "<<name<<"::~"<<name<<"()"<<endl;
		hpp<<"{"<<endl<<"}"<<endl;
		hpp<<endl;


		//перечисление типизированных экземпл€ров категорий
		hpp<<"template <class Oper> void "<<name<<"::enumCategories(Oper o)"<<endl;
		hpp<<"{"<<endl;
		hpp<<""<<name<<" *s = ("<<name<<"*)this;"<<endl;
		BOOST_FOREACH(Category cat, orderByName(cats))
		{
			hpp<<"o(s, _"<<cat->getName()<<");";
			hpp<<endl;
		}
		hpp<<"}"<<endl;
		hpp<<endl;


		//шаблонный геттер дл€ категорий
		BOOST_FOREACH(Category cat, orderByName(cats))
		{
			hpp<<"template <> s_"<<name<<"::"<<cat->getName()<<"_ptr\t"<<name<<"::getCategory<s_"<<name<<"::"<<cat->getName()<<">()"<<endl;
			hpp<<"{"<<endl;
			hpp<<"return _"<<cat->getName()<<";";
			hpp<<"}"<<endl;
			hpp<<endl;
		}
		hpp<<endl;


		//именованные геттеры дл€ категорий
		BOOST_FOREACH(Category cat, orderByName(cats))
		{
			hpp<<"s_"<<name<<"::"<<cat->getName()<<"_ptr\t"<<name<<"::"<<"get"<<cat->getName()<<"()"<<endl;
			hpp<<"{"<<endl;
			hpp<<"return _"<<cat->getName()<<";";
			hpp<<"}"<<endl;
			hpp<<endl;
		}
		hpp<<endl;

		//конец пространства имен
		hpp<<"}"<<endl<<"}"<<endl;
		hpp<<endl;

		//include дл€ категорий
		BOOST_FOREACH(Category cat, orderByName(cats))
		{
			hpp<<"#include \"r3/model/"<<name<<"/"<<cat->getName()<<".hpp\""<<endl;
		}
		hpp<<endl;



		hpp<<"#endif"<<endl;
		hpp.close();
		out::styler_cpp(hpp.pathName());
	}

	//////////////////////////////////////////////////////////////////////////
	void WSchema::processSchema_cpp(const std::string &name, const std::set<Category> &cats)
	{

	}


	//////////////////////////////////////////////////////////////////////////
	void WSchema::processCategory(Category cat)
	{
		Console::Out::WriteLine(("process category "+cat->getName()).c_str());

		//DDL дл€ Ѕƒ
		//cpp файлы категории

		processCategory_hpp(cat);
		processCategory_cpp(cat);

	}

	//////////////////////////////////////////////////////////////////////////
	void WSchema::processCategory_hpp(Category cat)
	{
		boost::filesystem::create_directories(_path/"include/r3/model"/cat->getSchema());

		std::string name = cat->getName();


		//////////////////////////////////////////////////
		std::set<CategoryOrReference> cors;
		BOOST_FOREACH(Reference ref, cat->getReferredBy())
		{
			cors.insert(ref);
		}
		cors.insert(cat);


		//перечень базовых и производных
		std::set<Category> basesFirst;
		std::set<Category> bases;
		std::set<Category> deriveds;

		collectInheriance(basesFirst, cat, true, false);
		collectInheriance(bases, cat, true, true);
		collectInheriance(deriveds, cat, false, true);

		std::set<Category> basesAndSelf(bases);
		basesAndSelf.insert(cat);


		out::File hpp(_path / "include/r3/model" / cat->getSchema() / (name+".hpp"));
		hpp<<"// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!"<<endl<<endl;

		hpp<<"#ifndef _r3_model_"<<cat->getSchema()<<"_"<<name<<"_hpp_"<<endl;
		hpp<<"#define _r3_model_"<<cat->getSchema()<<"_"<<name<<"_hpp_"<<endl;
		hpp<<endl;

		hpp<<"#include \"r3/categoryBase.hpp\""<<endl;
		hpp<<endl;

		//инклюды дл€ базовых
		if(basesFirst.size())
		{
			hpp<<"//bases"<<endl;
			BOOST_FOREACH(Category bcat, orderByName(basesFirst))
			{
				assert(bcat->getSchema() == cat->getSchema());
				hpp<<"#include \"r3/model/"<<bcat->getSchema()<<"/"<<bcat->getName()<<".hpp\""<<endl;
			}
			hpp<<endl;
		}


		hpp<<"namespace r3"<<endl
			<<"{"<<endl
			<<"namespace model"<<endl
			<<"{"<<endl;
		hpp<<endl;

		//предварительное объ€вление схемы
		hpp<<"class "<<cat->getSchema()<<";"<<endl;
		hpp<<"typedef boost::shared_ptr<"<<cat->getSchema()<<"> "<<cat->getSchema()<<"_ptr;"<<endl;
		hpp<<endl;

		hpp<<"namespace s_"<<cat->getSchema()<<endl
			<<"{"<<endl;
		hpp<<endl;

// 		//предварительные объ€влени€ производных
// 		if(deriveds.size())
// 		{
// 			hpp<<"//deriveds"<<endl;
// 			BOOST_FOREACH(Category dcat, orderByName(deriveds))
// 			{
// 				assert(dcat->getSchema() == cat->getSchema());
// 				hpp<<"class "<<dcat->getName()<<";"<<endl;
// 				hpp<<"typedef boost::shared_ptr<"<<dcat->getName()<<"> "<<dcat->getName()<<"_ptr;"<<endl;
// 			}
// 			hpp<<endl;
// 		}


		//////////////////////////////////////////////////////////////////////////
		hpp<<"namespace tuple"<<endl;
		hpp<<"{"<<endl;

		//домены
		std::set<FCO> enums = cat->getChildFCOsAs("Enum");
		std::set<FCO> sets = cat->getChildFCOsAs("Set");
		std::set<FCO> scanties(enums);
		scanties.insert(sets.begin(), sets.end());
		BOOST_FOREACH(Scanty s, orderByName(scanties))
		{
			assert(s);

			hpp<<"struct Domain"<<name<<s->getName()<<endl;
			hpp<<"{"<<endl;

			std::set<FCO> vals = s->getChildFCOsAs("ScantyValue");
			hpp<<"static const size_t amount = "<<vals.size()<<";"<<endl;

			hpp<<"static const char *values[amount];"<<endl;

			hpp<<"};"<<endl;
			hpp<<endl;
		}


		//тупла
		hpp<<"struct "<<name<<endl;
		hpp<<": public TupleBase<"<<name<<">"<<endl;
		hpp<<"{"<<endl;

		BOOST_FOREACH(Category cat, orderByName(basesAndSelf))
		{
			hpp<<"// "<<cat->getName()<<endl;

			//пол€
			std::set<BON::FCO> fields = cat->getChildFCOs();
			BOOST_FOREACH(Field fld, orderByName(fields))
			{
				if(!fld) continue;

				hpp
					<<"r3::fields::"<<fld->getObjectMeta().name();

				if(Scanty(fld))
				{
					Category pcat = fld->getParentModel();
					hpp<<"<"<<"Domain"<<pcat->getName()<<fld->getName()<<">";
				}

				hpp
					<<" "<<fld->getName()<<";"
					<<endl;
			}

			//св€зи
			std::set<CategoryRelation> rels;
			collectRelations(rels, cat, true, true);
			BOOST_FOREACH(CategoryRelation rel, orderByName(rels))
			{
				assert(rel);

				Category src = rel->getSrc();
				if(!src) src = CategoryReference(rel->getSrc())->getCategory();

				Category dst = rel->getDst();
				if(!dst) dst = CategoryReference(rel->getDst())->getCategory();

				if(src == cat)
				{
					switch(rel->getMultiplier1())
					{
					case CategoryRelationImpl::_1_Multiplier1_Type: hpp<<"r3::relations::Relation2one"; break;
					case CategoryRelationImpl::n_Multiplier1_Type:  hpp<<"r3::relations::Relation2n"; break;
					default:assert(0); hpp<<"r3::relations::Relation2one";break;
					}
					hpp<<"<"<<dst->getName()<<"> "<<rel->getName1()<<";"<<endl;
				}
				else
				{
					switch(rel->getMultiplier2())
					{
					case CategoryRelationImpl::_1_Multiplier1_Type: hpp<<"r3::relations::Relation2one"; break;
					case CategoryRelationImpl::n_Multiplier1_Type:  hpp<<"r3::relations::Relation2n"; break;
					default:assert(0); hpp<<"r3::relations::Relation2one";break;
					}
					hpp<<"<"<<src->getName()<<"> "<<rel->getName2()<<";"<<endl;
				}
			}
		}
		hpp<<"};"<<endl;
		hpp<<"typedef boost::shared_ptr<"<<name<<"> "<<name<<"_ptr;"<<endl;
		hpp<<endl;

		hpp<<"}"<<endl;
		hpp<<endl;


		//класс
		hpp<<"class "<<name<<endl;
		hpp<<": public CategoryBase<"<<cat->getSchema()<<", "<<name<<", tuple::"<<name<<">"<<endl;
		hpp<<"{"<<endl;
		hpp<<endl;

		hpp<<"public:"<<endl;
		hpp<<"static const bool isAbstract = "<<(cat->isAbstract()?"true":"false")<<";"<<endl;
		hpp<<endl;

		hpp<<"typedef tuple::"<<name<<" Tuple;"<<endl;
		hpp<<"typedef tuple::"<<name<<"_ptr Tuple_ptr;"<<endl;
		hpp<<endl;

		hpp<<"typedef "<<cat->getSchema()<<" Schema;"<<endl;
		hpp<<endl;





		hpp<<"public:"<<endl;
		//перечисление базовых
		hpp<<"template <class Oper> void enumBasesFirst(Oper o);"<<endl;

		//пол€ свои и все от базовых
		hpp<<"template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);"<<endl;

		//св€зи свои и все от базовых
		hpp<<"template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);"<<endl;

		//индексы свои и все от базовых
		hpp<<"template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);"<<endl;
		hpp<<endl;


		hpp<<"public:"<<endl;

		//деструктор
		hpp<<"~"<<name<<"();"<<endl;

		//геттер дл€ схемы
		hpp<<""<<cat->getSchema()<<" *schema();"<<endl;
		hpp<<endl;

		//ins
		hpp<<"void ins(Tuple &tup);"<<endl;
		hpp<<"void ins(Tuple_ptr tup);"<<endl;
		hpp<<endl;
		//upd
		hpp<<"void upd(Tuple &tup);"<<endl;
		hpp<<"void upd(Tuple_ptr tup);"<<endl;
		hpp<<endl;
		//del
		hpp<<"void del(const fields::Id &id);"<<endl;
		hpp<<"void del(Tuple &tup);"<<endl;
		hpp<<"void del(Tuple_ptr tup);"<<endl;
		hpp<<endl;
		//sel
		hpp<<"Tuple_ptr sel(const fields::Id &id);"<<endl;
		hpp<<"Tuple_ptr sel(Tuple_ptr tup);"<<endl;
		hpp<<endl;

		hpp<<"protected:"<<endl;
		//конструктор
		hpp<<"template <class S> friend class SchemaBase;"<<endl;
		hpp<<""<<name<<"("<<cat->getSchema()<<" *s);"<<endl;
		hpp<<endl;


		hpp<<"protected:"<<endl;
		hpp<<""<<cat->getSchema()<<" *_schema;"<<endl;
		hpp<<endl;

		hpp<<"protected:"<<endl;
		hpp<<"std::string tupleFillKey(Tuple &tup);"<<endl;
		hpp<<"std::string tupleInsSql(Tuple &tup);"<<endl;
		hpp<<"std::string tupleUpdSql(Tuple &tup);"<<endl;
		hpp<<"std::string tupleSelSql(Tuple &tup);"<<endl;
		hpp<<"void tupleInsBind(Tuple &tup, pgc::Statement &stm);"<<endl;
		hpp<<"void tupleUpdBind(Tuple &tup, pgc::Statement &stm);"<<endl;
		hpp<<endl;

		hpp<<"};"<<endl;
		//конец класса

		//указатель
		hpp<<"typedef boost::shared_ptr<"<<name<<"> "<<name<<"_ptr;"<<endl;


		hpp<<endl;
		hpp<<endl;

		hpp<<"//////////////////////////////////////////////////////////////////////////"<<endl;
		hpp<<"//////////////////////////////////////////////////////////////////////////"<<endl;

		//перечисление базовых
		hpp<<"template <class Oper> void "<<name<<"::enumBasesFirst(Oper o)"<<endl;
		hpp<<"{"<<endl;
		BOOST_FOREACH(Category bcat, orderByName(basesFirst))
		{
			assert(bcat->getSchema() == cat->getSchema());
			hpp<<"o(this, schema()->getCategory<"<<bcat->getName()<<">().get());"<<endl;
		}
		hpp<<"}"<<endl;
		hpp<<endl;


		//пол€ свои и все от базовых
		hpp<<"template <class Oper> void "<<name<<"::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)"<<endl;
		hpp<<"{"<<endl;
		BOOST_FOREACH(Category cat, orderByName(basesAndSelf))
		{
			hpp<<"//"<<cat->getName()<<endl;


			std::set<BON::FCO> fcos = cat->getChildFCOs();
			std::set<Field> fields(fcos.begin(), fcos.end());
			if(fields.empty()) continue;

			hpp<<cat->getName()<<"* c_"<<cat->getName()<<" = _schema->getCategory<"<<cat->getName()<<">().get();"<<endl;

			BOOST_FOREACH(Field fld, orderByName(fields))
			{
				if(!fld) continue;

				hpp
					<<"o(this, c_"<<cat->getName()<<", "
					<<"(r3::fields::"<<fld->getObjectMeta().name();

				if(Scanty(fld))
				{
					Category pcat = fld->getParentModel();
					hpp<<"<"<<"tuple::Domain"<<pcat->getName()<<fld->getName()<<">";
				}

				hpp
					<<"*)&tup."<<fld->getName()<<", "
					<<"\""<<fld->getName()<<"\""
					<<");"
					<<endl;
			}
		}
		hpp<<"}"<<endl;
		hpp<<endl;











		//св€зи свои и все от базовых
		hpp<<"template <class Oper> void "<<name<<"::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)"<<endl;
		hpp<<"{"<<endl;
		BOOST_FOREACH(Category cat, orderByName(basesAndSelf))
		{
			hpp<<"//"<<cat->getName()<<endl;

			//std::set<BON::FCO> fields = cat->getChildFCOs();
			std::set<CategoryRelation> rels;
			collectRelations(rels, cat, true, true);

			if(rels.empty()) continue;

			hpp<<cat->getName()<<"* c_"<<cat->getName()<<" = _schema->getCategory<"<<cat->getName()<<">().get();"<<endl;

			BOOST_FOREACH(CategoryRelation rel, orderByName(rels))
			{
				assert(rel);

				Category src = rel->getSrc();
				if(!src) src = CategoryReference(rel->getSrc())->getCategory();

				Category dst = rel->getDst();
				if(!dst) dst = CategoryReference(rel->getDst())->getCategory();

				hpp<<"o(this, c_"<<cat->getName()<<", ";

				if(src == cat)
				{
					hpp<<"_schema->getCategory<"<<dst->getName()<<">().get(), ";

					switch(rel->getMultiplier1())
					{
					case CategoryRelationImpl::_1_Multiplier1_Type: hpp<<"(r3::relations::Relation2one"; break;
					case CategoryRelationImpl::n_Multiplier1_Type:  hpp<<"(r3::relations::Relation2n"; break;
					default:assert(0); hpp<<"(r3::relations::Relation2one";break;
					}
					hpp<<"<"<<dst->getName()<<">*)&tup."<<rel->getName1()<<",\t\""<<rel->getName1()<<"\",\t";

					switch(rel->getMultiplier2())
					{
					case CategoryRelationImpl::_1_Multiplier2_Type: hpp<<"(r3::relations::Relation2one"; break;
					case CategoryRelationImpl::n_Multiplier2_Type:  hpp<<"(r3::relations::Relation2n"; break;
					default:assert(0); hpp<<"(r3::relations::Relation2one";break;
					}
					hpp<<"<"<<src->getName()<<">*)NULL,\t\""<<rel->getName2()<<"\",\t";

					hpp<<"rs_src";
				}
				else
				{
					hpp<<"_schema->getCategory<"<<src->getName()<<">().get(), ";
					switch(rel->getMultiplier2())
					{
					case CategoryRelationImpl::_1_Multiplier2_Type: hpp<<"(r3::relations::Relation2one"; break;
					case CategoryRelationImpl::n_Multiplier2_Type:  hpp<<"(r3::relations::Relation2n"; break;
					default:assert(0); hpp<<"(r3::relations::Relation2one";break;
					}
					hpp<<"<"<<src->getName()<<">*)&tup."<<rel->getName2()<<",\t\""<<rel->getName2()<<"\",\t";

					switch(rel->getMultiplier1())
					{
					case CategoryRelationImpl::_1_Multiplier1_Type: hpp<<"(r3::relations::Relation2one"; break;
					case CategoryRelationImpl::n_Multiplier1_Type:  hpp<<"(r3::relations::Relation2n"; break;
					default:assert(0); hpp<<"(r3::relations::Relation2one";break;
					}
					hpp<<"<"<<dst->getName()<<">*)NULL,\t\""<<rel->getName1()<<"\",\t";

					hpp<<"rs_dst";
				}

				hpp<<");"<<endl;
			}
		}
		hpp<<"}"<<endl;
		hpp<<endl;







		//индексы свои и все от базовых
		hpp<<"template <class Oper> void "<<name<<"::enumIndicesFromBasesAndSelf(Oper o)"<<endl;
		hpp<<"{"<<endl;
		BOOST_FOREACH(Category cat, orderByName(basesAndSelf))
		{
			hpp<<"//"<<cat->getName()<<endl;

			std::set<Index> indices = cat->getIndex();
			if(indices.empty()) continue;

			hpp<<cat->getName()<<"* c_"<<cat->getName()<<" = _schema->getCategory<"<<cat->getName()<<">().get();"<<endl;

			BOOST_FOREACH(Index ind, orderByName(indices))
			{
				assert(ind);

				if(ind->getInIndexOnCategoryFieldLinks().empty()) continue;

				hpp<<"o(this, c_"<<cat->getName()<<", ";
				hpp<<"\""<<ind->getName()<<"\", ";

				switch(ind->getIndexType())
				{
				case IndexImpl::tree_IndexType_Type:
					hpp<<"im_tree";
					break;
				case IndexImpl::hash_IndexType_Type:
					hpp<<"im_hash";
					break;
				default:
					hpp<<"im_tree";
					assert(!"unknown index method!");
				}

				std::set<Field> targetFields;
				BOOST_FOREACH(IndexOnCategoryField link, ind->getInIndexOnCategoryFieldLinks())
				{
					targetFields.insert(link->getSrc());
				}

				BOOST_FOREACH(Field fld, orderByName(targetFields))
				{
					hpp<<", (r3::fields::"<<fld->getObjectMeta().name();
					if(Scanty(fld))
					{
						Category pcat = fld->getParentModel();
						hpp<<"<"<<"tuple::Domain"<<pcat->getName()<<fld->getName()<<">";
					}
					hpp<<"*)NULL, ";
					hpp<<"\""<<fld->getName()<<"\"";
				}

				hpp<<");"<<endl;
			}
		}
		hpp<<"}"<<endl;
		hpp<<endl;


		//конструктор
		hpp<<"inline "<<name<<"::"<<name<<"("<<cat->getSchema()<<" *s)"<<endl;
		hpp<<": CategoryBase<"<<cat->getSchema()<<", "<<name<<", tuple::"<<name<<">(\""<<name<<"\")"<<endl;
		hpp<<", _schema(s)"<<endl;
		hpp<<"{"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;

		//деструктор
		hpp<<"inline "<<name<<"::"<<"~"<<name<<"()"<<endl;
		hpp<<"{"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;

		//геттер дл€ схемы
		hpp<<"inline "<<cat->getSchema()<<" *"<<name<<"::schema()"<<endl;
		hpp<<"{"<<endl;
		hpp<<"return _schema;"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;


		//ins
		hpp<<"inline void "<<name<<"::ins("<<name<<"::Tuple &tup)"<<endl;
		hpp<<"{"<<endl;
		hpp<<"pgc::Statement stm_ = stm(tupleFillKey(tup)+\"_ins_tuple\");"<<endl;
		hpp<<"if(stm_.empty())stm_.sql(tupleInsSql(tup));"<<endl;
		hpp<<"tupleInsBind(tup, stm_);"<<endl;
		hpp<<"stm_.exec().throwIfError();"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;

		hpp<<"inline void "<<name<<"::ins("<<name<<"::Tuple_ptr tup)"<<endl;
		hpp<<"{"<<endl;
		hpp<<"return ins(*tup);"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;

		//upd
		hpp<<"inline void "<<name<<"::upd("<<name<<"::Tuple &tup)"<<endl;
		hpp<<"{"<<endl;
		hpp<<"pgc::Statement stm_ = stm(tupleFillKey(tup)+\"_upd_tuple\");"<<endl;
		hpp<<"if(stm_.empty())stm_.sql(tupleUpdSql(tup));"<<endl;
		hpp<<"tupleUpdBind(tup, stm_);"<<endl;
		hpp<<"stm_.exec().throwIfError();"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;

		hpp<<"inline void "<<name<<"::upd("<<name<<"::Tuple_ptr tup)"<<endl;
		hpp<<"{"<<endl;
		hpp<<"return upd(*tup);"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;

		//del
		hpp<<"inline void "<<name<<"::del(const fields::Id &id)"<<endl;
		hpp<<"{"<<endl;
		hpp<<"pgc::Statement stm_ = stm(\"del_id\");"<<endl;
		hpp<<"if(stm_.empty()) stm_.sql(\"DELETE FROM \"+db_sname()+\" WHERE id=$1::INT8\");"<<endl;
		hpp<<"stm_.bind(id.value());"<<endl;
		hpp<<"stm_.exec().throwIfError();"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;

		hpp<<"inline void "<<name<<"::del("<<name<<"::Tuple &tup)"<<endl;
		hpp<<"{"<<endl;
		hpp<<"del(tup.id);"<<endl;
		hpp<<"tup.id.value() = 0;"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;

		hpp<<"inline void "<<name<<"::del("<<name<<"::Tuple_ptr tup)"<<endl;
		hpp<<"{"<<endl;
		hpp<<"return del(*tup);"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;

		//sel
		hpp<<"inline "<<name<<"::Tuple_ptr  "<<name<<"::sel(const fields::Id &id)"<<endl;
		hpp<<"{"<<endl;
		hpp<<"Tuple_ptr tup(new Tuple);"<<endl;
		hpp<<"tup->id = id;"<<endl;
		hpp<<"return sel(tup);"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;

		hpp<<"inline "<<name<<"::Tuple_ptr "<<name<<"::sel("<<name<<"::Tuple_ptr tup)"<<endl;
		hpp<<"{"<<endl;
		hpp<<"pgc::Statement stm_ = stm(\"sel_id\");"<<endl;
		hpp<<"if(stm_.empty()) stm_.sql(tupleSelSql(*tup));"<<endl;
		hpp<<"stm_.bind(tup->id.value());"<<endl;
		hpp<<"stm_.exec().throwIfError();"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;






		//tupleFillKey
		hpp<<"inline std::string  "<<name<<"::tupleFillKey(Tuple &tup)"<<endl;
		hpp<<"{"<<endl;

		std::vector<Field> fields = collectFields(cat);
		hpp<<"std::string res("<<fields.size()<<", '0');"<<endl;
		for(size_t i(0); i<fields.size(); i++)
		{
			hpp<<"if(tup."<<fields[i]->getName()<<".fvs() != fields::fvs_notset) res["<<i<<"] = '1';"<<endl;
		}

		hpp<<"return res;"<<endl;
		hpp<<"}"<<endl;

		//tupleInsSql
		hpp<<"inline std::string  "<<name<<"::tupleInsSql(Tuple &tup)"<<endl;
		hpp<<"{"<<endl;
		hpp<<"std::string res;"<<endl;
		hpp<<"std::string vals;"<<endl;
		hpp<<"size_t idx(0);"<<endl;
		hpp<<"char buf[32];"<<endl;
		for(size_t i(0); i<fields.size(); i++)
		{
			hpp<<"if(tup."<<fields[i]->getName()<<".fvs() != fields::fvs_notset)"<<endl;
			hpp<<"{"<<endl;
			hpp<<"if(idx)"<<endl;
			hpp<<"{"<<endl;
			hpp<<"res += \",\";"<<endl;
			hpp<<"vals += \",\";"<<endl;
			hpp<<"}"<<endl;
			hpp<<"res += \"\\\"_"+fields[i]->getName()+"_\\\"\";"<<endl;
			hpp<<"vals += \"$\";"<<endl;
			hpp<<"vals += utils::_ntoa(idx+1,buf);"<<endl;
			hpp<<"idx++;";
			hpp<<"}"<<endl;
		}
		hpp<<"res = \"INSERT INTO \"+db_sname()+\"(\"+res;"<<endl;
		hpp<<"res += \") VALUES (\"+vals+\")\";"<<endl;
		hpp<<"return res;"<<endl;
		hpp<<"}"<<endl;

		//tupleUpdSql
		hpp<<"inline std::string  "<<name<<"::tupleUpdSql(Tuple &tup)"<<endl;
		hpp<<"{"<<endl;
		hpp<<"assert(0);"<<endl;
		hpp<<"return \"\";"<<endl;
		hpp<<"}"<<endl;

		//tupleSelSql
		hpp<<"inline std::string  "<<name<<"::tupleSelSql(Tuple &tup)"<<endl;
		hpp<<"{"<<endl;
		hpp<<"assert(0);"<<endl;
		hpp<<"return \"\";"<<endl;
		hpp<<"}"<<endl;

		//tupleInsBind
		hpp<<"inline void  "<<name<<"::tupleInsBind(Tuple &tup, pgc::Statement &stm)"<<endl;
		hpp<<"{"<<endl;
		hpp<<"size_t idx(0);"<<endl;
		for(size_t i(0); i<fields.size(); i++)
		{
			hpp<<"if(tup."<<fields[i]->getName()<<".fvs() != fields::fvs_notset)"<<endl;
			hpp<<"{"<<endl;
			hpp<<"stm.bind(tup."<<fields[i]->getName()<<".value(), idx+1);"<<endl;
			hpp<<"idx++;";
			hpp<<"}"<<endl;
		}
		hpp<<"}"<<endl;

		//tupleUpdBind
		hpp<<"inline void  "<<name<<"::tupleUpdBind(Tuple &tup, pgc::Statement &stm)"<<endl;
		hpp<<"{"<<endl;
		hpp<<"assert(0);"<<endl;
		hpp<<"}"<<endl;



		//конец пространства имен
		hpp<<"}"<<endl<<"}"<<endl<<"}"<<endl;

		hpp<<endl;


		hpp<<"#endif"<<endl;

		hpp.close();
		out::styler_cpp(hpp.pathName());
	}
	
	//////////////////////////////////////////////////////////////////////////
	void WSchema::processCategory_cpp(Category cat)
	{

	}


	//////////////////////////////////////////////////////////////////////////
	void WSchema::collectInheriance(std::set<Category> &res, Category cat, bool bases, bool recursive)
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
	void WSchema::collectRelations(std::set<CategoryRelation> &res, Category cat, bool bases, bool recursive)
	{
		std::set<CategoryOrReference> cors;
		BOOST_FOREACH(Reference ref, cat->getReferredBy())
		{
			cors.insert(ref);
		}
		cors.insert(cat);

		BOOST_FOREACH(CategoryOrReference cor, cors)
		{
			std::set<CategoryRelation> rels = cor->getCategoryRelationLinks();

			res.insert(rels.begin(), rels.end());
		}
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

}
