#include "Stdafx.h"
#include "workers/wSchema.hpp"
#include <Console.h>
#include <direct.h>
#include "out/file.hpp"

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
		_mkdir("R3_interpret");

		//������� ��� ��������� � ������������ �� ������
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


		//DDL ��� ��
		//cpp ����� �����

		BOOST_FOREACH(const Category &cat, cats)
		{
			assert(name == cat->getSchema());
			processCategory(cat);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void WSchema::processSchema_hpp(const std::string &name, const std::set<Category> &cats)
	{
		out::File hpp("R3_interpret/schema_"+name+".hpp");

		hpp<<"#ifndef _R3_SCHEMA_"<<name<<"_HPP_"<<endl;
		hpp<<"#define _R3_SCHEMA_"<<name<<"_HPP_"<<endl;
		hpp<<endl;

		hpp<<"#include \"schemaBase.hpp\""<<endl;
		hpp<<endl;

		//include ��� ���������
		BOOST_FOREACH(const Category &cat, cats)
		{
			hpp<<"#include \"category_"<<cat->getName()<<".hpp\""<<endl;
		}
		hpp<<endl;

		hpp<<"namespace r3"<<endl<<"{"<<endl;


		//�����
		hpp<<"class Schema_"<<name<<endl;
		hpp<<": public SchemaBase<Schema_"<<name<<">"<<endl;
		hpp<<"{"<<endl;
		hpp<<endl;

		hpp<<"protected:"<<endl;

		//������ ����� ���������
		hpp<<"typedef bmpl::vector<"<<endl;
		bool first = true;
		BOOST_FOREACH(const Category &cat, cats)
		{
			hpp<<"\t";
			if(!first)
				hpp<<", ";
			else
			{
				hpp<<"  ";
				first = false;
			}
			hpp<<"Category_"<<cat->getName()<<endl;
		}
		hpp<<endl<<"> TVCategoryTypes;"<<endl;
		hpp<<endl;

		hpp<<"public:"<<endl;

		//�����������
		hpp<<"Schema_"<<name<<"(const char *id);"<<endl;

		//����������
		hpp<<"~Schema_"<<name<<"();"<<endl;
		hpp<<endl;

		//������� ��� ���������
		BOOST_FOREACH(const Category &cat, cats)
		{
			hpp<<"Category_"<<cat->getName()<<"_ptr\t"<<"getCategory_"<<cat->getName()<<"();"<<endl;
		}
		hpp<<endl;

		hpp<<"};"<<endl;
		//����� ������

		//���������
		hpp<<"typedef boost::shared_ptr<Schema_"<<name<<"> Schema_"<<name<<"_ptr;"<<endl;

		//����� ������������ ����
		hpp<<"}"<<endl;

		hpp<<endl;


		hpp<<"#endif"<<endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void WSchema::processSchema_cpp(const std::string &name, const std::set<Category> &cats)
	{

	}


	//////////////////////////////////////////////////////////////////////////
	void WSchema::processCategory(Category cat)
	{
		Console::Out::WriteLine(("process category "+cat->getName()).c_str());

		//DDL ��� ��
		//cpp ����� ���������

		processCategory_hpp(cat);
		processCategory_cpp(cat);

	}

	//////////////////////////////////////////////////////////////////////////
	void WSchema::processCategory_hpp(Category cat)
	{
		std::string name = cat->getName();


		//////////////////////////////////////////////////
		std::set<CategoryOrReference> cors;
		BOOST_FOREACH(Reference ref, cat->getReferredBy())
		{
			cors.insert(ref);
		}
		cors.insert(cat);


		//�������� ������� � �����������
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



		out::File hpp("R3_interpret/category_"+name+".hpp");

		hpp<<"#ifndef _R3_CATEGORY_"<<name<<"_HPP_"<<endl;
		hpp<<"#define _R3_CATEGORY_"<<name<<"_HPP_"<<endl;
		hpp<<endl;

		hpp<<"#include \"categoryBase.hpp\""<<endl;
		hpp<<endl;


		hpp<<"namespace r3"<<endl<<"{"<<endl;

		//��������������� ���������� �����
		hpp<<"class Schema_"<<cat->getSchema()<<";"<<endl;
		hpp<<"typedef boost::shared_ptr<Schema_"<<cat->getSchema()<<"> Schema_"<<cat->getSchema()<<"_ptr;"<<endl;

		hpp<<endl;

		//�����
		hpp<<"class Category_"<<name<<endl;
		hpp<<": public CategoryBase<Category_"<<name<<">"<<endl;
		hpp<<"{"<<endl;
		hpp<<endl;

		hpp<<"protected:"<<endl;

		//������ �������
		hpp<<"typedef bmpl::vector<"<<endl;
		bool first = true;
		BOOST_FOREACH(const Category &cat, bases)
		{
			hpp<<"\t";
			if(!first)
				hpp<<", ";
			else
			{
				hpp<<"  ";
				first = false;
			}
			hpp<<"Category_"<<cat->getName()<<endl;
		}
		hpp<<endl<<"> TVBases;"<<endl;
		hpp<<endl;

		//������ �����������
		hpp<<"typedef bmpl::vector<"<<endl;
		first = true;
		BOOST_FOREACH(const Category &cat, deriveds)
		{
			hpp<<"\t";
			if(!first)
				hpp<<", ";
			else
			{
				hpp<<"  ";
				first = false;
			}
			hpp<<"Category_"<<cat->getName()<<endl;
		}
		hpp<<endl<<"> TVDeriveds;"<<endl;
		hpp<<endl;

		//������ �����
		hpp<<endl;

		hpp<<"public:"<<endl;
		//��� �����
		hpp<<"typedef Schema_"<<cat->getSchema()<<" Schema;"<<endl;
		hpp<<endl;

		hpp<<"public:"<<endl;

		//�����������
		hpp<<"Category_"<<name<<"();"<<endl;

		//����������
		hpp<<"~Category_"<<name<<"();"<<endl;
		hpp<<endl;

		//������ ��� �����
		hpp<<"Schema_"<<cat->getSchema()<<"_ptr getSchema();"<<endl;


		hpp<<"};"<<endl;
		//����� ������

		//���������
		hpp<<"typedef boost::shared_ptr<Category_"<<name<<"> Category_"<<name<<"_ptr;"<<endl;

		//����� ������������ ����
		hpp<<"}"<<endl;

		hpp<<endl;


		hpp<<"#endif"<<endl;
	}
	
	//////////////////////////////////////////////////////////////////////////
	void WSchema::processCategory_cpp(Category cat)
	{

	}


}
