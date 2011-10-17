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

		hpp<<"// инклюды классов схем"<<endl;
		BOOST_FOREACH(std::string schemaName, schemas)
		{
			hpp<<"#include \"r3/data/"<<schemaName<<".hpp\""<<endl;
		}
		hpp<<endl;

		hpp<<"namespace r3"<<endl<<"{"<<endl;

		hpp<<"// вся дата"<<endl;
		hpp<<"class Data"<<endl;
		hpp<<": public DataBase"<<endl;
		hpp<<"{"<<endl;


		//тип карты id->schema ptr
		hpp<<"// тип карты id -> schema ptr"<<endl;
		BOOST_FOREACH(std::string schemaName, schemas)
		{
			hpp<<"typedef std::map<std::string, r3::data::"<<schemaName<<"_ptr> TM"<<schemaName<<";"<<endl;
			hpp<<"TM"<<schemaName<<" _"<<schemaName<<";"<<endl;
		}
		hpp<<endl;


		hpp<<"public:"<<endl;


		//геттеры для схем
		hpp<<"// геттеры для схем"<<endl;
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


		//DDL для БД
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

		hpp<<"// предварительное объявление класса даты"<<endl;
		hpp<<"class Data;"<<endl;
		
		hpp<<"namespace data"<<endl<<"{"<<endl;

		hpp<<"namespace s_"<<name<<endl<<"{"<<endl;

		//предварительные объявления типов категорий
		hpp<<"// предварительные объявления типов категорий"<<endl;
		BOOST_FOREACH(Category cat, orderByName(cats))
		{
			hpp<<"class "<<cat->getName()<<";"<<endl;
			hpp<<"typedef boost::shared_ptr<"<<cat->getName()<<"> "<<cat->getName()<<"_ptr;"<<endl;
			hpp<<endl;
		}

		hpp<<"}"<<endl;
		hpp<<endl;

		//указатель
		hpp<<"// указатель"<<endl;
		hpp<<"class "<<name<<";"<<endl;
		hpp<<"typedef boost::shared_ptr<"<<name<<"> "<<name<<"_ptr;"<<endl;
		hpp<<endl;


		//класс
		hpp<<"// класс"<<endl;
		hpp<<"class "<<name<<endl;
		hpp<<": public SchemaBase<"<<name<<">"<<endl;
		hpp<<"{"<<endl;
		hpp<<endl;

		hpp<<"private:"<<endl;

		//указатели на экземпляры категорий
		hpp<<"// указатели на экземпляры категорий"<<endl;
		BOOST_FOREACH(Category cat, orderByName(cats))
		{
			hpp<<"s_"<<name<<"::"<<cat->getName()<<"_ptr\t_"<<cat->getName()<<";"<<endl;
		}
		hpp<<endl;

		hpp<<"public:"<<endl;

		//конструктор
		hpp<<"// конструктор"<<endl;
		hpp<<""<<name<<"(Data *data, const char *id);"<<endl;
		//деструктор
		hpp<<"// деструктор"<<endl;
		hpp<<"~"<<name<<"();"<<endl;
		hpp<<endl;

		//перечисление типизированных экземпляров категорий
		hpp<<"// перечисление типизированных экземпляров категорий"<<endl;
		hpp<<"template <class Oper> void enumCategories(Oper o);"<<endl;


		//шаблон для доступа к категориям по типу
		hpp<<"// шаблон для доступа к категориям по типу"<<endl;
		hpp<<"template <class C> boost::shared_ptr<C> getCategory();"<<endl;
		hpp<<endl;

		//именованные геттеры для категорий
		hpp<<"// именованные геттеры для категорий"<<endl;
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


		//перечисление типизированных экземпляров категорий
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


		//шаблонный геттер для категорий
		BOOST_FOREACH(Category cat, orderByName(cats))
		{
			hpp<<"template <> inline s_"<<name<<"::"<<cat->getName()<<"_ptr\t"<<name<<"::getCategory<s_"<<name<<"::"<<cat->getName()<<">()"<<endl;
			hpp<<"{"<<endl;
			hpp<<"return _"<<cat->getName()<<";";
			hpp<<"}"<<endl;
			hpp<<endl;
		}
		hpp<<endl;


		//именованные геттеры для категорий
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

		//include для категорий
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

		//DDL для БД
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

		//инклюды для базовых
		hpp<<"// инклюды для базовых"<<endl;
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

		//предварительное объявление схемы
		hpp<<"// предварительное объявление схемы"<<endl;
		hpp<<"class "<<cat->getSchema()<<";"<<endl;
		hpp<<"typedef boost::shared_ptr<"<<cat->getSchema()<<"> "<<cat->getSchema()<<"_ptr;"<<endl;
		hpp<<endl;

		hpp<<"namespace s_"<<cat->getSchema()<<endl
			<<"{"<<endl;
		hpp<<endl;


		//класс
		hpp<<"// класс"<<endl;
		hpp<<"class "<<name<<endl;
		hpp<<": public CategoryBase<"<<cat->getSchema()<<", "<<name<<", tuples::"<<name<<">"<<endl;
		hpp<<"{"<<endl;
		hpp<<endl;

		hpp<<"public:"<<endl;
		hpp<<"static const bool isAbstract = "<<(cat->isAbstract()?"true":"false")<<";"<<endl;
		hpp<<endl;

		hpp<<"// тупла с указателем"<<endl;
		hpp<<"typedef tuples::"<<name<<" Tuple;"<<endl;
		hpp<<"typedef tuples::"<<name<<"_ptr Tuple_ptr;"<<endl;
		hpp<<endl;

		hpp<<"// и схема"<<endl;
		hpp<<"typedef "<<cat->getSchema()<<" Schema;"<<endl;
		hpp<<endl;





		hpp<<"public:"<<endl;
		//перечисление базовых
		hpp<<"// перечисление базовых"<<endl;
		hpp<<"template <class Oper> void enumBasesFirst(Oper o);"<<endl;

		//поля свои и от всех базовых
		hpp<<"// поля свои и от всех базовых"<<endl;
		hpp<<"template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);"<<endl;

		//связи свои и от всех базовых
		hpp<<"// связи свои и от всех базовых"<<endl;
		hpp<<"template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);"<<endl;

		//индексы свои и от всех базовых
		hpp<<"// индексы свои и от всех базовых"<<endl;
		hpp<<"template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);"<<endl;
		hpp<<endl;


		hpp<<"public:"<<endl;

		//деструктор
		hpp<<"// деструктор"<<endl;
		hpp<<"~"<<name<<"();"<<endl;

		//геттер для схемы
		hpp<<"// геттер для схемы"<<endl;
		hpp<<""<<cat->getSchema()<<" *schema();"<<endl;
		hpp<<endl;

		hpp<<"protected:"<<endl;
		//конструктор
		hpp<<"// конструктор"<<endl;
		hpp<<"template <class S> friend class SchemaBase;"<<endl;
		hpp<<""<<name<<"("<<cat->getSchema()<<" *s);"<<endl;
		hpp<<endl;


		hpp<<"protected:"<<endl;
		hpp<<"// хранимый экземпляр схемы"<<endl;
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


		//поля свои и все от базовых
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











		//связи свои и все от базовых
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
					case CategoryRelationImpl::one_Multiplier2_Type: hpp<<"(r3::relations::Relation2one"; break;
					case CategoryRelationImpl::many_Multiplier2_Type:  hpp<<"(r3::relations::Relation2many"; break;
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
					case CategoryRelationImpl::one_Multiplier1_Type: hpp<<"(r3::relations::Relation2one"; break;
					case CategoryRelationImpl::many_Multiplier1_Type:  hpp<<"(r3::relations::Relation2many"; break;
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

		//геттер для схемы
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

		//инклюды для базовых, там могут быть домены
		if(basesFirst.size())
		{
			hpp<<"// инклюды для базовых, там могут быть домены"<<endl;
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

// 		//предварительное объявление класса категории
// 		hpp<<"class "<<name<<";"<<endl;



		//////////////////////////////////////////////////////////////////////////
		hpp<<"namespace tuples"<<endl;
		hpp<<"{"<<endl;


		//предварительное объявление классов туплов по связям
		hpp<<"// предварительное объявление классов туплов по связям"<<endl;
		BOOST_FOREACH(Category cat, orderByName(basesAndSelf))
		{
			hpp<<"// "<<cat->getName()<<endl;

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
		hpp<<"// !предварительное объявление классов туплов по связям"<<endl;

		//домены
		hpp<<"// домены"<<endl;
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
		hpp<<"// тупла"<<endl;
		hpp<<"struct "<<name<<endl;
		hpp<<": public TupleBase<"<<name<<">"<<endl;
		hpp<<"{"<<endl;

// 		hpp<<"typedef r3::data::s_"<<cat->getSchema()<<"::"<<name<<" Category;"<<endl;
// 		hpp<<endl;

		size_t fieldsAmount = 0;
		size_t relationsAmount = 0;
		BOOST_FOREACH(Category cat, orderByName(basesAndSelf))
		{
			hpp<<"// "<<cat->getName()<<endl;

			//поля
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

			//связи
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
					case CategoryRelationImpl::one_Multiplier1_Type: hpp<<"r3::relations::Relation2one"; break;
					case CategoryRelationImpl::many_Multiplier1_Type:  hpp<<"r3::relations::Relation2many"; break;
					default:assert(0); hpp<<"r3::relations::Relation2one";break;
					}
					hpp<<"<r3::data::s_"<<dst->getSchema()<<"::tuples::"<<dst->getName()<<"> "<<rel->getName1()<<";"<<endl;
				}
				else
				{
					switch(rel->getMultiplier2())
					{
					case CategoryRelationImpl::one_Multiplier1_Type: hpp<<"r3::relations::Relation2one"; break;
					case CategoryRelationImpl::many_Multiplier1_Type:  hpp<<"r3::relations::Relation2many"; break;
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


// 		//подключить заголовки с зависимостями от других схем
// 		std::set<std::string> datasOnRefs;
// 		BOOST_FOREACH(const CategoryReference &catRef, data->getCategoryReference())
// 		{
// 			Category cat = catRef->getCategory();
// 			Data d = cat->getParentModel("Data");
// 			datasOnRefs.insert(d->getName());
// 		}
// 		datasOnRefs.erase(data->getName());
// 		if(!datasOnRefs.empty())
// 		{
// 			BOOST_FOREACH(const std::string &s, datasOnRefs)
// 			{
// 				hpp<<"#include \"data/"<<s<<".hpp\""<<endl;
// 			}
// 			hpp<<endl;
// 		}

		hpp<<"namespace dbMeta\n{\nnamespace schemas\n{"<<endl;

		hpp<<"class "<<data->getName()<<"\n	: public ::dbMeta::Schema\n{"<<endl;

		//свои категории
		BOOST_FOREACH(const Category &cat, data->getCategory())
		{
			mkCategory(hpp, cat);
		}

		//связи

		hpp<<"};"<<endl;

		hpp<<"}\n}"<<endl;
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


		//свои поля
		BOOST_FOREACH(const FCO &childFco, cat->getChildFCOs())
		{
			Field fld(childFco);
			if(fld)
			{
				mkField(hpp, fld);
			}
		}
		//свои индексы
		BOOST_FOREACH(const FCO &childFco, cat->getChildFCOs())
		{
			Index idx(childFco);
			if(idx)
			{
				mkIndex(hpp, idx);
			}
		}

		hpp<<"};\n"<<endl;

	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkField(out::File &hpp, const Field &fld)
	{
		Console::Out::WriteLine(("fld: "+fld->getName()).c_str());

		hpp<<"//////////////////////////////////////////////////////////////////////////"<<endl;
		hpp<<"class "<<fld->getName()<<"\n : public ::dbMeta::Field\n{"<<endl;


		hpp<<"};\n"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WData::mkIndex(out::File &hpp, const Index &idx)
	{
		Console::Out::WriteLine(("idx: "+idx->getName()).c_str());

		hpp<<"//////////////////////////////////////////////////////////////////////////"<<endl;
		hpp<<"class "<<idx->getName()<<"\n : public ::dbMeta::Index\n{"<<endl;

		//наименование
		hpp<<"std::string getName()\n{\n return \"";
		hpp<<idx->getName();
		hpp<<"\";\n}"<<endl;

		//тип индекса
		hpp<<"EIndexType getType()\n{\n return ";
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
		hpp<<";\n}"<<endl;

		//поля индекса
		hpp<<"FieldPtrs getFields()\n{"<<endl;
		hpp<<"FieldPtrs ret;"<<endl;
		BOOST_FOREACH(const Field &fld, idx->getIndexOnCategoryFieldSrcs())
		{
			hpp<<"ret.insert(getCategory()->getField(\""<<fld->getName()<<"\"));"<<endl;
		}
		hpp<<"return ret;"<<endl;
		hpp<<"}\n";

		hpp<<"};\n"<<endl;
	}

}
