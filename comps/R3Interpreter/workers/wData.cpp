#include "Stdafx.h"
#include "workers/wData.hpp"
#include <Console.h>
#include <direct.h>
#include "out/file.hpp"
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

	void WData::operator()(const std::set<FCO> &roots)
	{
		boost::filesystem::create_directories(_path/"include/r3/data");
		boost::filesystem::create_directories(_path/"src/r3/data");

		//собрать все категории и распредилить по схемам
		std::map<std::string, std::set<Category> > schema2cats;
		std::set<std::string> schemas;

		BOOST_FOREACH(const FCO &fco, roots)
		{
			Data data(fco);
			if(data)
			{
				BOOST_FOREACH(const Category &cat, data->getCategory())
				{
					schema2cats[cat->getSchema()].insert(cat);
					schemas.insert(cat->getSchema());
				}
				BOOST_FOREACH(const CategoryReference &catref, data->getCategoryReference())
				{
					const Category &cat = catref->getCategory();
					schema2cats[cat->getSchema()].insert(cat);
					schemas.insert(cat->getSchema());
				}
			}
		}

		processData(schemas);

		typedef std::pair<std::string, std::set<Category> > TP;
		BOOST_FOREACH(const TP &p, schema2cats)
		{
			processSchema(p.first, p.second);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::processData(const std::set<std::string> &schemas)
	{
		processData_hpp(schemas);
		processData_cpp(schemas);
	}

	void WData::processData_hpp(const std::set<std::string> &schemas)
	{
		out::File hpp(_path / "include/r3/data.hpp");
		hpp<<"// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!"<<endl<<endl;

		hpp<<"#ifndef _r3_data_hpp_"<<endl;
		hpp<<"#define _r3_data_hpp_"<<endl;
		hpp<<endl;

		hpp<<"#include \"r3/dataBase.hpp\""<<endl;
		hpp<<endl;

		BOOST_FOREACH(std::string schemaName, schemas)
		{
			hpp<<"#include \"r3/data/"<<schemaName<<".hpp\""<<endl;
		}
		hpp<<endl;

		hpp<<"namespace r3"<<endl<<"{"<<endl;

		hpp<<"class Data"<<endl;
		hpp<<": public DataBase"<<endl;
		hpp<<"{"<<endl;


		//тип карты id->schema ptr
		BOOST_FOREACH(std::string schemaName, schemas)
		{
			hpp<<"typedef std::map<std::string, r3::data::"<<schemaName<<"_ptr> TM"<<schemaName<<";"<<endl;
			hpp<<"TM"<<schemaName<<" _"<<schemaName<<";"<<endl;
		}
		hpp<<endl;


		hpp<<"public:"<<endl;


		//геттеры дл€ схем
		BOOST_FOREACH(std::string schemaName, schemas)
		{
			hpp<<"r3::data::"<<schemaName<<"_ptr get"<<schemaName<<"(const char *id)"<<endl;
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

	void WData::processData_cpp(const std::set<std::string> &schemas)
	{

	}


	//////////////////////////////////////////////////////////////////////////
	void WData::processSchema(const std::string &name, const std::set<Category> &cats)
	{
		Console::Out::WriteLine(("process schema "+name).c_str());

		processSchema_hpp(name, cats);
		processSchema_cpp(name, cats);


		//DDL дл€ Ѕƒ
		//cpp файлы схемы

		BOOST_FOREACH(const Category &cat, orderByName(cats))
		{
			assert(name == cat->getSchema());
			processCategoryTuple(cat);
			processCategory(cat);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::processSchema_hpp(const std::string &name, const std::set<Category> &cats)
	{
		out::File hpp(_path / "include/r3/data" / (name+".hpp"));
		hpp<<"// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!"<<endl<<endl;

		hpp<<"#ifndef _r3_data_"<<name<<"_hpp_"<<endl;
		hpp<<"#define _r3_data_"<<name<<"_hpp_"<<endl;
		hpp<<endl;

		hpp<<"#include \"r3/schemaBase.hpp\""<<endl;
		hpp<<endl;

		hpp<<"namespace r3"<<endl<<"{"<<endl;

		hpp<<"class Data;"<<endl;
		
		hpp<<"namespace data"<<endl<<"{"<<endl;

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

		hpp<<"private:"<<endl;

		//указатели на экземпл€ры категорий
		BOOST_FOREACH(Category cat, orderByName(cats))
		{
			hpp<<"s_"<<name<<"::"<<cat->getName()<<"_ptr\t_"<<cat->getName()<<";"<<endl;
		}
		hpp<<endl;

		hpp<<"public:"<<endl;

		//конструктор
		hpp<<""<<name<<"(Data *data, const char *id);"<<endl;
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
		hpp<<"inline "<<name<<"::"<<name<<"(Data *data, const char *id)"<<endl;
		hpp<<": SchemaBase<"<<name<<">(data, id, \""<<name<<"\")"<<endl;
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
			hpp<<"template <> inline s_"<<name<<"::"<<cat->getName()<<"_ptr\t"<<name<<"::getCategory<s_"<<name<<"::"<<cat->getName()<<">()"<<endl;
			hpp<<"{"<<endl;
			hpp<<"return _"<<cat->getName()<<";";
			hpp<<"}"<<endl;
			hpp<<endl;
		}
		hpp<<endl;


		//именованные геттеры дл€ категорий
		BOOST_FOREACH(Category cat, orderByName(cats))
		{
			hpp<<"inline s_"<<name<<"::"<<cat->getName()<<"_ptr\t"<<name<<"::"<<"get"<<cat->getName()<<"()"<<endl;
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
			hpp<<"#include \"r3/data/"<<name<<"/"<<cat->getName()<<".hpp\""<<endl;
		}
		hpp<<endl;



		hpp<<"#endif"<<endl;
		hpp.close();
		out::styler_cpp(hpp.pathName());
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::processSchema_cpp(const std::string &name, const std::set<Category> &cats)
	{

	}


	//////////////////////////////////////////////////////////////////////////
	void WData::processCategory(Category cat)
	{
		Console::Out::WriteLine(("process category "+cat->getName()).c_str());

		//DDL дл€ Ѕƒ
		//cpp файлы категории

		processCategory_hpp(cat);
		processCategory_cpp(cat);

	}

	//////////////////////////////////////////////////////////////////////////
	void WData::processCategory_hpp(Category cat)
	{
		boost::filesystem::create_directories(_path/"include/r3/data"/cat->getSchema());

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


		out::File hpp(_path / "include/r3/data" / cat->getSchema() / (name+".hpp"));
		hpp<<"// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!"<<endl<<endl;

		hpp<<"#ifndef _r3_data_"<<cat->getSchema()<<"_"<<name<<"_hpp_"<<endl;
		hpp<<"#define _r3_data_"<<cat->getSchema()<<"_"<<name<<"_hpp_"<<endl;
		hpp<<endl;

		hpp<<"#include \"r3/categoryBase.hpp\""<<endl;
		hpp<<"#include \"r3/data/"<<cat->getSchema()<<"/tuples/"<<name<<".hpp\""<<endl;
		hpp<<endl;

		//инклюды дл€ базовых
		if(basesFirst.size())
		{
			hpp<<"//bases"<<endl;
			BOOST_FOREACH(Category bcat, orderByName(basesFirst))
			{
				assert(bcat->getSchema() == cat->getSchema());
				hpp<<"#include \"r3/data/"<<bcat->getSchema()<<"/"<<bcat->getName()<<".hpp\""<<endl;
			}
			hpp<<endl;
		}


		hpp<<"namespace r3"<<endl
			<<"{"<<endl
			<<"namespace data"<<endl
			<<"{"<<endl;
		hpp<<endl;

		//предварительное объ€вление схемы
		hpp<<"class "<<cat->getSchema()<<";"<<endl;
		hpp<<"typedef boost::shared_ptr<"<<cat->getSchema()<<"> "<<cat->getSchema()<<"_ptr;"<<endl;
		hpp<<endl;

		hpp<<"namespace s_"<<cat->getSchema()<<endl
			<<"{"<<endl;
		hpp<<endl;


		//класс
		hpp<<"class "<<name<<endl;
		hpp<<": public CategoryBase<"<<cat->getSchema()<<", "<<name<<", tuples::"<<name<<">"<<endl;
		hpp<<"{"<<endl;
		hpp<<endl;

		hpp<<"public:"<<endl;
		hpp<<"static const bool isAbstract = "<<(cat->isAbstract()?"true":"false")<<";"<<endl;
		hpp<<endl;

		hpp<<"typedef tuples::"<<name<<" Tuple;"<<endl;
		hpp<<"typedef tuples::"<<name<<"_ptr Tuple_ptr;"<<endl;
		hpp<<endl;

		hpp<<"typedef "<<cat->getSchema()<<" Schema;"<<endl;
		hpp<<endl;





		hpp<<"public:"<<endl;
		//перечисление базовых
		hpp<<"template <class Oper> void enumBasesFirst(Oper o);"<<endl;

		//пол€ свои и все от базовых
		hpp<<"template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);"<<endl;

		//св€зи свои и все от базовых
		hpp<<"template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);"<<endl;

		//индексы свои и все от базовых
		hpp<<"template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);"<<endl;
		hpp<<endl;


		hpp<<"public:"<<endl;

		//деструктор
		hpp<<"~"<<name<<"();"<<endl;

		//геттер дл€ схемы
		hpp<<""<<cat->getSchema()<<" *schema();"<<endl;
		hpp<<endl;

		hpp<<"protected:"<<endl;
		//конструктор
		hpp<<"template <class S> friend class SchemaBase;"<<endl;
		hpp<<""<<name<<"("<<cat->getSchema()<<" *s);"<<endl;
		hpp<<endl;


		hpp<<"protected:"<<endl;
		hpp<<""<<cat->getSchema()<<" *_schema;"<<endl;
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
		hpp<<"template <class Oper> void "<<name<<"::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)"<<endl;
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
					<<"&tup."<<fld->getName()<<", "
					<<"\""<<fld->getName()<<"\""
					<<");"
					<<endl;
			}
		}
		hpp<<"}"<<endl;
		hpp<<endl;











		//св€зи свои и все от базовых
		hpp<<"template <class Oper> void "<<name<<"::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)"<<endl;
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

					hpp<<"&tup."<<rel->getName1()<<",\t\""<<rel->getName1()<<"\",\t";

					switch(rel->getMultiplier2())
					{
					case CategoryRelationImpl::_1_Multiplier2_Type: hpp<<"(r3::relations::Relation2one"; break;
					case CategoryRelationImpl::n_Multiplier2_Type:  hpp<<"(r3::relations::Relation2n"; break;
					default:assert(0); hpp<<"(r3::relations::Relation2one";break;
					}
					hpp<<"<r3::data::s_"<<src->getSchema()<<"::tuples::"<<src->getName()<<">*)NULL,\t\""<<rel->getName2()<<"\",\t";

					hpp<<"rs_src";
				}
				else
				{
					hpp<<"_schema->getCategory<"<<src->getName()<<">().get(), ";
					hpp<<"&tup."<<rel->getName2()<<",\t\""<<rel->getName2()<<"\",\t";

					switch(rel->getMultiplier1())
					{
					case CategoryRelationImpl::_1_Multiplier1_Type: hpp<<"(r3::relations::Relation2one"; break;
					case CategoryRelationImpl::n_Multiplier1_Type:  hpp<<"(r3::relations::Relation2n"; break;
					default:assert(0); hpp<<"(r3::relations::Relation2one";break;
					}
					hpp<<"<r3::data::s_"<<dst->getSchema()<<"::tuples::"<<dst->getName()<<">*)NULL,\t\""<<rel->getName1()<<"\",\t";

					hpp<<"rs_dst";
				}

				hpp<<");"<<endl;
			}
		}
		hpp<<"}"<<endl;
		hpp<<endl;







		//индексы свои и все от базовых
		hpp<<"template <class Oper> void "<<name<<"::enumIndicesFromBasesAndSelf(Oper &o)"<<endl;
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
						hpp<<"<"<<"tuples::Domain"<<pcat->getName()<<fld->getName()<<">";
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
		hpp<<": CategoryBase<"<<cat->getSchema()<<", "<<name<<", tuples::"<<name<<">(\""<<name<<"\")"<<endl;
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




		//конец пространства имен
		hpp<<"}"<<endl<<"}"<<endl<<"}"<<endl;

		hpp<<endl;


		hpp<<"#endif"<<endl;

		hpp.close();
		out::styler_cpp(hpp.pathName());
	}
	
	//////////////////////////////////////////////////////////////////////////
	void WData::processCategory_cpp(Category cat)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void WData::processCategoryTuple(Category cat)
	{
		processCategoryTuple_hpp(cat);
		processCategoryTuple_cpp(cat);
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::processCategoryTuple_hpp(Category cat)
	{
		boost::filesystem::create_directories(_path/"include/r3/data"/cat->getSchema()/"tuples");

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


		out::File hpp(_path / "include/r3/data" / cat->getSchema() / "tuples" / (name+".hpp"));
		hpp<<"// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!"<<endl<<endl;

		hpp<<"#ifndef _r3_data_"<<cat->getSchema()<<"_tuples_"<<name<<"_hpp_"<<endl;
		hpp<<"#define _r3_data_"<<cat->getSchema()<<"_tuples_"<<name<<"_hpp_"<<endl;
		hpp<<endl;

		//инклюды дл€ базовых
		if(basesFirst.size())
		{
			BOOST_FOREACH(Category bcat, orderByName(basesFirst))
			{
				assert(bcat->getSchema() == cat->getSchema());
				hpp<<"#include \"r3/data/"<<bcat->getSchema()<<"/tuples/"<<bcat->getName()<<".hpp\""<<endl;
			}
		}
		else
		{
			hpp<<"#include \"r3/tupleBase.hpp\""<<endl;
		}
		hpp<<endl;


		hpp<<"namespace r3"<<endl
			<<"{"<<endl
			<<"namespace data"<<endl
			<<"{"<<endl;
		hpp<<endl;


		hpp<<"namespace s_"<<cat->getSchema()<<endl
			<<"{"<<endl;
		hpp<<endl;

		//предварительное объ€вление класса категории
		hpp<<"class "<<name<<";"<<endl;



		//////////////////////////////////////////////////////////////////////////
		hpp<<"namespace tuples"<<endl;
		hpp<<"{"<<endl;


		//предварительное объ€вление классов туплов по св€з€м
		BOOST_FOREACH(Category cat, orderByName(basesAndSelf))
		{
			hpp<<"// "<<cat->getName()<<endl;

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
					hpp<<"struct "<<dst->getName()<<";"<<endl;
				}
				else
				{
					hpp<<"struct "<<src->getName()<<";"<<endl;
				}
			}
		}

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

		hpp<<"typedef r3::data::s_"<<cat->getSchema()<<"::"<<name<<" Category;"<<endl;
		hpp<<endl;

		size_t fieldsAmount = 0;
		size_t relationsAmount = 0;
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
				fieldsAmount++;
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
					hpp<<"<r3::data::s_"<<dst->getSchema()<<"::tuples::"<<dst->getName()<<"> "<<rel->getName1()<<";"<<endl;
				}
				else
				{
					switch(rel->getMultiplier2())
					{
					case CategoryRelationImpl::_1_Multiplier1_Type: hpp<<"r3::relations::Relation2one"; break;
					case CategoryRelationImpl::n_Multiplier1_Type:  hpp<<"r3::relations::Relation2n"; break;
					default:assert(0); hpp<<"r3::relations::Relation2one";break;
					}
					hpp<<"<r3::data::s_"<<src->getSchema()<<"::tuples::"<<src->getName()<<"> "<<rel->getName2()<<";"<<endl;
				}
				relationsAmount++;
			}
		}
		hpp<<endl;
		hpp<<"static const size_t _fieldsAmount = "<<fieldsAmount<<";"<<endl;
		hpp<<"static const size_t _relationsAmount = "<<relationsAmount<<";"<<endl;
		hpp<<endl;
		hpp<<"};"<<endl;
		hpp<<"typedef boost::shared_ptr<"<<name<<"> "<<name<<"_ptr;"<<endl;
		hpp<<endl;

		hpp<<"}"<<endl;
		hpp<<endl;

		//конец пространства имен
		hpp<<"}"<<endl<<"}"<<endl<<"}"<<endl;

		hpp<<endl;


		hpp<<"#endif"<<endl;

		hpp.close();
		out::styler_cpp(hpp.pathName());

	}

	//////////////////////////////////////////////////////////////////////////
	void WData::processCategoryTuple_cpp(Category cat)
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
	void WData::collectRelations(std::set<CategoryRelation> &res, Category cat, bool bases, bool recursive)
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

}
