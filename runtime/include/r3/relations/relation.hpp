#ifndef _R3_RELATIONS_RELATION_HPP_
#define _R3_RELATIONS_RELATION_HPP_


namespace r3 {namespace relations{

	enum ERelationSide
	{
		rs_first,
		rs_second,
	};

	template <ERelationSide side>
	class Relation
	{
	public:
	};
}}

#include "r3/relations/relation_n2n.hpp"
#include "r3/relations/relation_one2n.hpp"
#include "r3/relations/relation_n2one.hpp"
#include "r3/relations/relation_one2one.hpp"

#endif
