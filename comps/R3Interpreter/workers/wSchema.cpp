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

	WSchema::WSchema()
	{

	}
	WSchema::~WSchema()
	{

	}

	void WSchema::operator()(const std::set<FCO> &roots)
	{
		_mkdir("runtime");
		_mkdir("runtime/include");
		_mkdir("runtime/include/r3");
		_mkdir("runtime/include/r3/model");

		//собрать все категории и распредилить по схемам
		std::map<std::string, std::set<Category> > schema2cats;

		BOOST_FOREACH(const FCO &fco, roots)
		{
			Categories categories(fco);
			if(categories)
			{
				BOOST_FOREACH(const Category &cat, categories->getCategory())
				{
					schema2cats[cat->getSchema()].insert(cat);
				}
				BOOST_FOREACH(const CategoryReference &catref, categories->getCategoryReference())
				{
					const Category &cat = catref->getCategory();
					schema2cats[cat->getSchema()].insert(cat);
				}
			}
		}

		typedef std::pair<std::string, std::set<Category> > TP;
		BOOST_FOREACH(const TP &p, schema2cats)
		{
			processSchema(p.first, p.second);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void WSchema::processSchema(const std::string &name, const std::set<Category> &cats)
	{
		Console::Out::WriteLine(("process schema "+name).c_str());

		processSchema_hpp(name, cats);
		processSchema_cpp(name, cats);


		//DDL дл€ Ѕƒ
		//cpp файлы схемы

		BOOST_FOREACH(const Category &cat, cats)
		{
			assert(name == cat->getSchema());
			processCategory(cat);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void WSchema::processSchema_hpp(const std::string &name, const std::set<Category> &cats)
	{
		out::File hpp("runtime/include/r3/model/"+name+".hpp");

		hpp<<"#ifndef _r3_model_"<<name<<"_hpp_"<<endl;
		hpp<<"#define _r3_model_"<<name<<"_hpp_"<<endl;
		hpp<<endl;

		hpp<<"#include \"r3/schemaBase.hpp\""<<endl;
		hpp<<endl;

		//include дл€ категорий
		BOOST_FOREACH(const Category &cat, cats)
		{
			hpp<<"#include \"r3/model/"<<name<<"/"<<cat->getName()<<".hpp\""<<endl;
		}
		hpp<<endl;

		hpp<<"namespace r3"<<endl<<"{"<<endl<<"namespace model"<<endl<<"{"<<endl;

		hpp<<"namespace s_"<<name<<"{}"<<endl;

		//указатель
		hpp<<"class "<<name<<";"<<endl;
		hpp<<"typedef boost::shared_ptr<"<<name<<"> "<<name<<"_ptr;"<<endl;


		//класс
		hpp<<"class "<<name<<endl;
		hpp<<": public SchemaBase<"<<name<<">"<<endl;
		hpp<<"{"<<endl;
		hpp<<endl;

		hpp<<"public:"<<endl;

		//указатели на экземпл€ры категорий
		BOOST_FOREACH(const Category &cat, cats)
		{
			hpp<<"s_"<<name<<"::"<<cat->getName()<<"_ptr\t_"<<cat->getName()<<";"<<endl;
		}
		hpp<<endl;

		hpp<<"public:"<<endl;

		//конструктор
		hpp<<""<<name<<"(const char *id)"<<endl;
		hpp<<": SchemaBase<"<<name<<">(id, \""<<name<<"\")"<<endl;
		hpp<<"{"<<endl;
		hpp<<"init();"<<endl;
		hpp<<"}"<<endl;

		//деструктор
		hpp<<"~"<<name<<"()"<<endl;
		hpp<<"{}"<<endl;
		hpp<<endl;

		//перечисление типизированных экземпл€ров категорий
		hpp<<"template <class Oper> void enumCategories(Oper o)"<<endl;
		hpp<<"{"<<endl;
		hpp<<""<<name<<" *s = ("<<name<<"*)this;"<<endl;
		BOOST_FOREACH(const Category &cat, cats)
		{
			hpp<<"o(s, _"<<cat->getName()<<");";
			hpp<<endl;
		}
		hpp<<"}"<<endl;
		hpp<<endl;


		//шаблон дл€ доступа к экземпл€ру по типу
		hpp<<"template <class C> boost::shared_ptr<C> getCategory()"<<endl;
		hpp<<"{"<<endl;
		hpp<<"return boost::shared_ptr<C>();"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;

		BOOST_FOREACH(const Category &cat, cats)
		{
			hpp<<"template <> s_"<<name<<"::"<<cat->getName()<<"_ptr\t"<<"getCategory<s_"<<name<<"::"<<cat->getName()<<">()"<<endl;
			hpp<<"{"<<endl;
			hpp<<"return _"<<cat->getName()<<";";
			hpp<<"}"<<endl;
			hpp<<endl;
		}
		hpp<<endl;

		//геттеры дл€ категорий
		BOOST_FOREACH(const Category &cat, cats)
		{
			hpp<<"s_"<<name<<"::"<<cat->getName()<<"_ptr\t"<<"get"<<cat->getName()<<"()"<<endl;
			hpp<<"{"<<endl;
			hpp<<"return _"<<cat->getName()<<";";
			hpp<<"}"<<endl;
			hpp<<endl;
		}
		hpp<<endl;

		hpp<<"};"<<endl;
		//конец класса

		//конец пространства имен
		hpp<<"}"<<endl<<"}"<<endl;

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
		_mkdir(("runtime/include/r3/model/"+cat->getSchema()).c_str());

		std::string name = cat->getName();


		//////////////////////////////////////////////////
		std::set<CategoryOrReference> cors;
		BOOST_FOREACH(Reference ref, cat->getReferredBy())
		{
			cors.insert(ref);
		}
		cors.insert(cat);


		//перечень базовых и производных
		std::set<Category> bases;
		std::set<Category> deriveds;
		BOOST_FOREACH(CategoryOrReference cor, cors)
		{
			BOOST_FOREACH(CategoryOrReference bas, cor->getCategoryInheritanceDsts())
			{
				Category scat(bas);
				CategoryReference sref(bas);
				if(sref)
				{
					scat = sref->getCategory();
				}

				bases.insert(scat);
			}


			BOOST_FOREACH(CategoryOrReference der, cor->getCategoryInheritanceSrcs())
			{
				Category scat(der);
				CategoryReference sref(der);
				if(sref)
				{
					scat = sref->getCategory();
				}

				deriveds.insert(scat);
			}
		}


		out::File hpp("runtime/include/r3/model/"+cat->getSchema()+"/"+name+".hpp");

		hpp<<"#ifndef _r3_model_"<<cat->getSchema()<<"_"<<name<<"_hpp_"<<endl;
		hpp<<"#define _r3_model_"<<cat->getSchema()<<"_"<<name<<"_hpp_"<<endl;
		hpp<<endl;

		hpp<<"#include \"r3/categoryBase.hpp\""<<endl;
		hpp<<endl;


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

		//предварительные объ€влени€ базовых и производных
		if(bases.size())
		{
			hpp<<"//bases"<<endl;
			BOOST_FOREACH(Category cat, bases)
			{
				hpp<<"class "<<cat->getName()<<";"<<endl;
				hpp<<"typedef boost::shared_ptr<"<<cat->getName()<<"> "<<cat->getName()<<"_ptr;"<<endl;
			}
			hpp<<endl;
		}

		if(deriveds.size())
		{
			hpp<<"//deriveds"<<endl;
			BOOST_FOREACH(Category cat, deriveds)
			{
				hpp<<"class "<<cat->getName()<<";"<<endl;
				hpp<<"typedef boost::shared_ptr<"<<cat->getName()<<"> "<<cat->getName()<<"_ptr;"<<endl;
			}
			hpp<<endl;
		}


		//класс
		hpp<<"class "<<name<<endl;
		hpp<<": public CategoryBase<"<<name<<">"<<endl;
		hpp<<"{"<<endl;
		hpp<<endl;

		hpp<<"public:"<<endl;

		//вектор базовых
		hpp<<"typedef bmpl::vector<";
		bool first = true;
		BOOST_FOREACH(const Category &cat, bases)
		{
			hpp<<endl<<"\t";
			if(!first)
				hpp<<", ";
			else
			{
				hpp<<"  ";
				first = false;
			}
			hpp<<""<<cat->getName();
		}
		hpp<<endl<<"> TVBases;"<<endl;
		hpp<<endl;

		//вектор производных
		hpp<<"typedef bmpl::vector<";
		first = true;
		BOOST_FOREACH(const Category &cat, deriveds)
		{
			hpp<<endl<<"\t";
			if(!first)
				hpp<<", ";
			else
			{
				hpp<<"  ";
				first = false;
			}
			hpp<<""<<cat->getName();
		}
		hpp<<endl<<"> TVDeriveds;"<<endl;
		hpp<<endl;

		//вектор полей
		hpp<<endl;

		hpp<<"public:"<<endl;
		//тип схемы
		hpp<<"typedef "<<cat->getSchema()<<" Schema;"<<endl;
		hpp<<"typedef boost::shared_ptr<"<<cat->getSchema()<<"> Schema_ptr;"<<endl;
		hpp<<"typedef boost::weak_ptr<"<<cat->getSchema()<<"> Schema_wtr;"<<endl;

		hpp<<"Schema *_schema;"<<endl;
		hpp<<endl;

		hpp<<"public:"<<endl;

		//конструктор
		hpp<<""<<name<<"(Schema *s)"<<endl;
		hpp<<": CategoryBase<"<<name<<">(\""<<name<<"\")"<<endl;
		hpp<<", _schema(s)"<<endl;
		hpp<<"{"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;

		//деструктор
		hpp<<"~"<<name<<"()"<<endl;
		hpp<<"{"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;

		//геттер дл€ схемы
		hpp<<"Schema *schema()"<<endl;
		hpp<<"{"<<endl;
		hpp<<"return _schema;"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;


		hpp<<"};"<<endl;
		//конец класса

		//указатель
		hpp<<"typedef boost::shared_ptr<"<<name<<"> "<<name<<"_ptr;"<<endl;

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


}
