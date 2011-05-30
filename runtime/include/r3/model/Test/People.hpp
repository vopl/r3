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
				
				struct Domainsex
				{
					static const size_t amount = 0;
					static const char *values[amount];
				};
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//People
					People *c_People = _schema->getCategory<People>().get();
					o(this, c_People, (r3::fields::Date *)NULL, "birth");
					o(this, c_People, (r3::fields::String *)NULL, "middlename");
					o(this, c_People, (r3::fields::String *)NULL, "name");
					o(this, c_People, (r3::fields::Image *)NULL, "photo");
					o(this, c_People, (r3::fields::Enum<People::Domainsex>*)NULL, "sex");
					o(this, c_People, (r3::fields::String *)NULL, "surname");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//People
					People *c_People = _schema->getCategory<People>().get();
					o(this, c_People, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)NULL,	"observableServices",	(r3::relations::Relation2n<People>*)NULL,	"observers",	rs_dst);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//People
				}
				
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
				typedef Test Schema;
				typedef boost::shared_ptr<Test> Schema_ptr;
				typedef boost::weak_ptr<Test> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				People(Schema *s)
					: CategoryBase<People>("People")
					, _schema(s)
				{
				}
				
				~People()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<People> People_ptr;
		}
	}
}

#endif
