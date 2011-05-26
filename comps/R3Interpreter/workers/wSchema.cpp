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
		out::File hpp("runtime/include/r3/model/"+name+".hpp");

		hpp<<"#ifndef _r3_model_"<<name<<"_hpp_"<<endl;
		hpp<<"#define _r3_model_"<<name<<"_hpp_"<<endl;
		hpp<<endl;

		hpp<<"#include \"r3/schemaBase.hpp\""<<endl;
		hpp<<endl;

		//include ��� ���������
		BOOST_FOREACH(const Category &cat, cats)
		{
			hpp<<"#include \"r3/model/"<<name<<"/"<<cat->getName()<<".hpp\""<<endl;
		}
		hpp<<endl;

		hpp<<"namespace r3"<<endl<<"{"<<endl<<"namespace model"<<endl<<"{"<<endl;

		hpp<<"namespace s_"<<name<<"{}"<<endl;

		//���������
		hpp<<"class "<<name<<";"<<endl;
		hpp<<"typedef boost::shared_ptr<"<<name<<"> "<<name<<"_ptr;"<<endl;


		//�����
		hpp<<"class "<<name<<endl;
		hpp<<": public SchemaBase<"<<name<<">"<<endl;
		hpp<<"{"<<endl;
		hpp<<endl;

		hpp<<"public:"<<endl;

		//��������� �� ���������� ���������
		BOOST_FOREACH(const Category &cat, cats)
		{
			hpp<<"s_"<<name<<"::"<<cat->getName()<<"_ptr\t_"<<cat->getName()<<";"<<endl;
		}
		hpp<<endl;

		hpp<<"public:"<<endl;

		//�����������
		hpp<<""<<name<<"(const char *id)"<<endl;
		hpp<<": SchemaBase<"<<name<<">(id, \""<<name<<"\")"<<endl;
		hpp<<"{"<<endl;
		hpp<<"init();"<<endl;
		hpp<<"}"<<endl;

		//����������
		hpp<<"~"<<name<<"()"<<endl;
		hpp<<"{}"<<endl;
		hpp<<endl;

		//������������ �������������� ����������� ���������
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


		//������ ��� ������� � ���������� �� ����
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

		//������� ��� ���������
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
		//����� ������

		//����� ������������ ����
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

		//DDL ��� ��
		//cpp ����� ���������

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
		std::set<Category> basesAndSelf(bases);
		basesAndSelf.insert(cat);


		out::File hpp("runtime/include/r3/model/"+cat->getSchema()+"/"+name+".hpp");

		hpp<<"#ifndef _r3_model_"<<cat->getSchema()<<"_"<<name<<"_hpp_"<<endl;
		hpp<<"#define _r3_model_"<<cat->getSchema()<<"_"<<name<<"_hpp_"<<endl;
		hpp<<endl;

		hpp<<"#include \"r3/categoryBase.hpp\""<<endl;
		hpp<<endl;

		//������� ��� �������
		if(bases.size())
		{
			hpp<<"//bases"<<endl;
			BOOST_FOREACH(Category bcat, bases)
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

		//��������������� ���������� �����
		hpp<<"class "<<cat->getSchema()<<";"<<endl;
		hpp<<"typedef boost::shared_ptr<"<<cat->getSchema()<<"> "<<cat->getSchema()<<"_ptr;"<<endl;
		hpp<<endl;

		hpp<<"namespace s_"<<cat->getSchema()<<endl
			<<"{"<<endl;
		hpp<<endl;

		//��������������� ���������� �����������
		if(deriveds.size())
		{
			hpp<<"//deriveds"<<endl;
			BOOST_FOREACH(Category dcat, deriveds)
			{
				assert(dcat->getSchema() == cat->getSchema());
				hpp<<"class "<<dcat->getName()<<";"<<endl;
				hpp<<"typedef boost::shared_ptr<"<<dcat->getName()<<"> "<<dcat->getName()<<"_ptr;"<<endl;
			}
			hpp<<endl;
		}


		//�����
		hpp<<"class "<<name<<endl;
		hpp<<": public CategoryBase<"<<name<<">"<<endl;
		hpp<<"{"<<endl;
		hpp<<endl;

		hpp<<"public:"<<endl;

		hpp<<"static const bool isAbstract = "<<(cat->isAbstract()?"true":"false")<<";"<<endl;
		hpp<<endl;

		//������
		std::set<FCO> enums = cat->getChildFCOsAs("Enum");
		std::set<FCO> sets = cat->getChildFCOsAs("Set");
		std::set<FCO> scanties(enums);
		scanties.insert(sets.begin(), sets.end());
		BOOST_FOREACH(Scanty s, scanties)
		{
			assert(s);

			hpp<<"struct Domain"<<s->getName()<<endl;
			hpp<<"{"<<endl;

			std::set<FCO> vals = s->getChildFCOsAs("ScantyValue");
			hpp<<"static const size_t amount = "<<vals.size()<<";"<<endl;

			hpp<<"static const char *values[amount];"<<endl;

			hpp<<"};"<<endl;
			hpp<<endl;
		}

		//���� ���� � ��� �� �������
		hpp<<"template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)"<<endl;
		hpp<<"{"<<endl;
		BOOST_FOREACH(Category cat, basesAndSelf)
		{
			hpp<<"//"<<cat->getName()<<endl;

			std::set<BON::FCO> fields = cat->getChildFCOs();

			hpp<<cat->getName()<<"* c_"<<cat->getName()<<" = _schema->getCategory<"<<cat->getName()<<">().get();"<<endl;

			BOOST_FOREACH(Field fld, fields)
			{
				if(!fld) continue;

				hpp
					<<"o(this, c_"<<cat->getName()<<", "
					<<"(r3::fields::"<<fld->getObjectMeta().name();
					
				if(Scanty(fld))
				{
					Category pcat = fld->getParentModel();
					hpp<<"<"<<pcat->getName()<<"::Domain"<<fld->getName()<<">";
				}
					
				hpp
					<<"*)NULL, "
					<<"\""<<fld->getName()<<"\""
					<<");"
					<<endl;
			}
		}
		hpp<<"}"<<endl;
		hpp<<endl;



		//������� ���� � ��� �� �������
		hpp<<"template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)"<<endl;
		hpp<<"{"<<endl;
		BOOST_FOREACH(Category cat, basesAndSelf)
		{
			hpp<<"//"<<cat->getName()<<endl;

			std::set<BON::FCO> fields = cat->getChildFCOs();

			hpp<<cat->getName()<<"* c_"<<cat->getName()<<" = _schema->getCategory<"<<cat->getName()<<">().get();"<<endl;

			BOOST_FOREACH(Index ind, fields)
			{
				if(!ind) continue;

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


				BOOST_FOREACH(IndexOnCategoryField link, ind->getInIndexOnCategoryFieldLinks())
				{
					Field fld = link->getSrc();
					hpp<<", (r3::fields::"<<fld->getObjectMeta().name();
					if(Scanty(fld))
					{
						Category pcat = fld->getParentModel();
						hpp<<"<"<<pcat->getName()<<"::Domain"<<fld->getName()<<">";
					}
					hpp<<"*)NULL, ";
					hpp<<"\""<<fld->getName()<<"\"";
				}

				hpp<<");"<<endl;
			}
		}
		hpp<<"}"<<endl;
		hpp<<endl;


		hpp<<"public:"<<endl;
		//��� �����
		hpp<<"typedef "<<cat->getSchema()<<" Schema;"<<endl;
		hpp<<"typedef boost::shared_ptr<"<<cat->getSchema()<<"> Schema_ptr;"<<endl;
		hpp<<"typedef boost::weak_ptr<"<<cat->getSchema()<<"> Schema_wtr;"<<endl;

		hpp<<"protected:"<<endl;
		hpp<<"Schema *_schema;"<<endl;
		hpp<<endl;

		hpp<<"public:"<<endl;

		//�����������
		hpp<<""<<name<<"(Schema *s)"<<endl;
		hpp<<": CategoryBase<"<<name<<">(\""<<name<<"\")"<<endl;
		hpp<<", _schema(s)"<<endl;
		hpp<<"{"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;

		//����������
		hpp<<"~"<<name<<"()"<<endl;
		hpp<<"{"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;

		//������ ��� �����
		hpp<<"Schema *schema()"<<endl;
		hpp<<"{"<<endl;
		hpp<<"return _schema;"<<endl;
		hpp<<"}"<<endl;
		hpp<<endl;


		hpp<<"};"<<endl;
		//����� ������

		//���������
		hpp<<"typedef boost::shared_ptr<"<<name<<"> "<<name<<"_ptr;"<<endl;

		//����� ������������ ����
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