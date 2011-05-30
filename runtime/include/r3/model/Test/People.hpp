// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_People_hpp_
#define _r3_model_Test_People_hpp_

#include "r3/categoryBase.hpp"

namespace r3
{
	namespace model
	{
	
		class Test;
		typedef boost::shared_ptr<Test> Test_ptr;
		
		namespace s_Test
		{
		
			class People
				: public CategoryBase<People>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
				struct Domainsex
				{
					static const size_t amount = 0;
					static const char *values[amount];
				};
				
				
			public:
				struct Tuple
						: public CategoryBase<People>::Tuple
				{
					r3::fields::Date birth;
					r3::fields::String middlename;
					r3::fields::String name;
					r3::fields::Image photo;
					r3::fields::Enum<People::Domainsex> sex;
					r3::fields::String surname;
					r3::relations::Relation2n<Service> observableServices;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~People();
				Test *schema();
				
				void ins(Tuple &tup);
				void ins(Tuple_ptr tup);
				
				void upd(Tuple &tup);
				void upd(Tuple_ptr tup);
				
				void del(const fields::Id &id);
				void del(Tuple &tup);
				void del(Tuple_ptr tup);
				
				Tuple_ptr sel(const fields::Id &id);
				Tuple_ptr sel(Tuple_ptr tup);
				
			protected:
				template <class S> friend class SchemaBase;
				People(Test *s);
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<People> People_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void People::enumBasesFirst(Oper o)
			{
			}
			
			template <class Oper> void People::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//People
				People *c_People = _schema->getCategory<People>().get();
				o(this, c_People, (r3::fields::Date *)&tup.birth, "birth");
				o(this, c_People, (r3::fields::String *)&tup.middlename, "middlename");
				o(this, c_People, (r3::fields::String *)&tup.name, "name");
				o(this, c_People, (r3::fields::Image *)&tup.photo, "photo");
				o(this, c_People, (r3::fields::Enum<People::Domainsex>*)&tup.sex, "sex");
				o(this, c_People, (r3::fields::String *)&tup.surname, "surname");
			}
			
			template <class Oper> void People::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//People
				People *c_People = _schema->getCategory<People>().get();
				o(this, c_People, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)&tup.observableServices,	"observableServices",	(r3::relations::Relation2n<People>*)NULL,	"observers",	rs_dst);
			}
			
			template <class Oper> void People::enumIndicesFromBasesAndSelf(Oper o)
			{
				//People
			}
			
			inline People::People(Test *s)
				: CategoryBase<People>("People")
				, _schema(s)
			{
			}
			
			inline People::~People()
			{
			}
			
			inline Test *People::schema()
			{
				return _schema;
			}
			
			inline void People::ins(People::Tuple &tup)
			{
				return CategoryBase<People>::ins(this, tup);
			}
			
			inline void People::ins(People::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void People::upd(People::Tuple &tup)
			{
				return CategoryBase<People>::upd(this, tup);
			}
			
			inline void People::upd(People::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void People::del(const fields::Id &id)
			{
				return CategoryBase<People>::del(this, id);
			}
			
			inline void People::del(People::Tuple &tup)
			{
				return CategoryBase<People>::del(this, tup);
			}
			
			inline void People::del(People::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline People::Tuple_ptr  People::sel(const fields::Id &id)
			{
				return CategoryBase<People>::sel(this, id);
			}
			
			inline People::Tuple_ptr People::sel(People::Tuple_ptr tup)
			{
				return CategoryBase<People>::sel(this, tup);
			}
			
		}
	}
}

#endif
