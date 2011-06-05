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
		
			namespace tuples
			{
				struct DomainPeoplesex
				{
					static const size_t amount = 0;
					static const char *values[amount];
				};
				
				struct People
						: public TupleBase<People>
				{
					// People
					r3::fields::Date birth;
					r3::fields::String middlename;
					r3::fields::String name;
					r3::fields::Image photo;
					r3::fields::Enum<DomainPeoplesex> sex;
					r3::fields::String surname;
					r3::relations::Relation2n<s_Test::Service> observableServices;
					
					static const size_t _fieldsAmount = 6;
					static const size_t _relationsAmount = 1;
					
				};
				typedef boost::shared_ptr<People> People_ptr;
				
			}
			
			class People
				: public CategoryBase<Test, People, tuples::People>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::People Tuple;
				typedef tuples::People_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~People();
				Test *schema();
				
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
			
			template <class Oper> void People::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//People
				People *c_People = _schema->getCategory<People>().get();
				o(this, c_People, &tup.birth, "birth");
				o(this, c_People, &tup.middlename, "middlename");
				o(this, c_People, &tup.name, "name");
				o(this, c_People, &tup.photo, "photo");
				o(this, c_People, &tup.sex, "sex");
				o(this, c_People, &tup.surname, "surname");
			}
			
			template <class Oper> void People::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//People
				People *c_People = _schema->getCategory<People>().get();
				o(this, c_People, _schema->getCategory<Service>().get(), &tup.observableServices,	"observableServices",	(r3::relations::Relation2n<s_Test::People>*)NULL,	"observers",	rs_dst);
			}
			
			template <class Oper> void People::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//People
			}
			
			inline People::People(Test *s)
				: CategoryBase<Test, People, tuples::People>("People")
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
			
		}
	}
}

#endif
