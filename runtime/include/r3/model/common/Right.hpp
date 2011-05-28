#ifndef _r3_model_common_Right_hpp_
#define _r3_model_common_Right_hpp_

#include "r3/categoryBase.hpp"

namespace r3
{
	namespace model
	{
	
		class common;
		typedef boost::shared_ptr<common> common_ptr;
		
		namespace s_common
		{
		
			class Right
				: public CategoryBase<Right>
			{
			
			public:
				static const bool isAbstract = false;
				
				struct Domainvalue
				{
					static const size_t amount = 3;
					static const char *values[amount];
				};
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Right
					Right *c_Right = _schema->getCategory<Right>().get();
					o(this, c_Right, (r3::fields::String *)NULL, "name");
					o(this, c_Right, (r3::fields::Enum<Right::Domainvalue>*)NULL, "value");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//Right
					Right *c_Right = _schema->getCategory<Right>().get();
					o(this, c_Right, _schema->getCategory<HasRights>().get(), (r3::relations::Relation2n *)NULL,	"rights",	(r3::relations::Relation2n *)NULL,	"owners",	rs_src);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Right
				}
				
			public:
				typedef common Schema;
				typedef boost::shared_ptr<common> Schema_ptr;
				typedef boost::weak_ptr<common> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Right(Schema *s)
					: CategoryBase<Right>("Right")
					, _schema(s)
				{
				}
				
				~Right()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Right> Right_ptr;
		}
	}
}

#endif
