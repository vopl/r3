// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_Derived4fields_hpp_
#define _r3_model_Test_Derived4fields_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/Test/Base4fields.hpp"

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
				struct Derived4fields
						: public TupleBase<Derived4fields>
				{
					// Base4fields
					r3::fields::Audio Audio;
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
					// Derived4fields
					
					static const size_t _fieldsAmount = 21;
					static const size_t _relationsAmount = 0;
					
				};
				typedef boost::shared_ptr<Derived4fields> Derived4fields_ptr;
				
			}
			
			class Derived4fields
				: public CategoryBase<Test, Derived4fields, tuples::Derived4fields>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::Derived4fields Tuple;
				typedef tuples::Derived4fields_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~Derived4fields();
				Test *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				Derived4fields(Test *s);
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<Derived4fields> Derived4fields_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Derived4fields::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<Base4fields>().get());
			}
			
			template <class Oper> void Derived4fields::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Base4fields
				Base4fields *c_Base4fields = _schema->getCategory<Base4fields>().get();
				o(this, c_Base4fields, &tup.Audio, "Audio");
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
				//Derived4fields
			}
			
			template <class Oper> void Derived4fields::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Base4fields
				//Derived4fields
			}
			
			template <class Oper> void Derived4fields::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Base4fields
				//Derived4fields
			}
			
			inline Derived4fields::Derived4fields(Test *s)
				: CategoryBase<Test, Derived4fields, tuples::Derived4fields>("Derived4fields")
				, _schema(s)
			{
			}
			
			inline Derived4fields::~Derived4fields()
			{
			}
			
			inline Test *Derived4fields::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
