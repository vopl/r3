// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_Base4fields_hpp_
#define _r3_model_Test_Base4fields_hpp_

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
				struct DomainBase4fieldsEnum1
				{
					static const size_t amount = 9;
					static const char *values[amount];
				};
				
				struct DomainBase4fieldsEnum2
				{
					static const size_t amount = 19;
					static const char *values[amount];
				};
				
				struct DomainBase4fieldsSet1
				{
					static const size_t amount = 7;
					static const char *values[amount];
				};
				
				struct DomainBase4fieldsSet2
				{
					static const size_t amount = 15;
					static const char *values[amount];
				};
				
				struct Base4fields
						: public TupleBase<Base4fields>
				{
					// Base4fields
					r3::fields::Audio Audio;
					r3::fields::Binary Binary;
					r3::fields::Bool Bool;
					r3::fields::Date Date;
					r3::fields::DateTimeInterval DateTimeInterval;
					r3::fields::Enum<DomainBase4fieldsEnum1> Enum1;
					r3::fields::Enum<DomainBase4fieldsEnum2> Enum2;
					r3::fields::File File;
					r3::fields::Image Image;
					r3::fields::Int16 Int16;
					r3::fields::Int32 Int32;
					r3::fields::Int64 Int64;
					r3::fields::Int8 Int8;
					r3::fields::Money Money;
					r3::fields::Real32 Real32;
					r3::fields::Real64 Real64;
					r3::fields::Set<DomainBase4fieldsSet1> Set1;
					r3::fields::Set<DomainBase4fieldsSet2> Set2;
					r3::fields::String String;
					r3::fields::Time Time;
					r3::fields::Timestamp Timestamp;
					r3::fields::Video Video;
					
					static const size_t _fieldsAmount = 22;
					static const size_t _relationsAmount = 0;
					
				};
				typedef boost::shared_ptr<Base4fields> Base4fields_ptr;
				
			}
			
			class Base4fields
				: public CategoryBase<Test, Base4fields, tuples::Base4fields>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::Base4fields Tuple;
				typedef tuples::Base4fields_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~Base4fields();
				Test *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				Base4fields(Test *s);
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<Base4fields> Base4fields_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Base4fields::enumBasesFirst(Oper o)
			{
			}
			
			template <class Oper> void Base4fields::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Base4fields
				Base4fields *c_Base4fields = _schema->getCategory<Base4fields>().get();
				o(this, c_Base4fields, &tup.Audio, "Audio");
				o(this, c_Base4fields, &tup.Binary, "Binary");
				o(this, c_Base4fields, &tup.Bool, "Bool");
				o(this, c_Base4fields, &tup.Date, "Date");
				o(this, c_Base4fields, &tup.DateTimeInterval, "DateTimeInterval");
				o(this, c_Base4fields, &tup.Enum1, "Enum1");
				o(this, c_Base4fields, &tup.Enum2, "Enum2");
				o(this, c_Base4fields, &tup.File, "File");
				o(this, c_Base4fields, &tup.Image, "Image");
				o(this, c_Base4fields, &tup.Int16, "Int16");
				o(this, c_Base4fields, &tup.Int32, "Int32");
				o(this, c_Base4fields, &tup.Int64, "Int64");
				o(this, c_Base4fields, &tup.Int8, "Int8");
				o(this, c_Base4fields, &tup.Money, "Money");
				o(this, c_Base4fields, &tup.Real32, "Real32");
				o(this, c_Base4fields, &tup.Real64, "Real64");
				o(this, c_Base4fields, &tup.Set1, "Set1");
				o(this, c_Base4fields, &tup.Set2, "Set2");
				o(this, c_Base4fields, &tup.String, "String");
				o(this, c_Base4fields, &tup.Time, "Time");
				o(this, c_Base4fields, &tup.Timestamp, "Timestamp");
				o(this, c_Base4fields, &tup.Video, "Video");
			}
			
			template <class Oper> void Base4fields::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Base4fields
			}
			
			template <class Oper> void Base4fields::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Base4fields
			}
			
			inline Base4fields::Base4fields(Test *s)
				: CategoryBase<Test, Base4fields, tuples::Base4fields>("Base4fields")
				, _schema(s)
			{
			}
			
			inline Base4fields::~Base4fields()
			{
			}
			
			inline Test *Base4fields::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
