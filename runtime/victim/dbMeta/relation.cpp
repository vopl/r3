#include "stdafx.h"
#include "dbMeta/relation.hpp"

//warning C4355: 'this' : used in base member initializer list
#pragma warning( disable : 4355 )

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	Relation::Relation(
		const Schema &schema, 
		const std::string &name,
		ERelationMult inputMult,
		ERelationMult outputMult)
		: _schema(&schema)
		, _name(name)
		, __inputEnd(*this, inputMult)
		, __outputEnd(*this, outputMult)
		, inputEnd(__inputEnd)
		, outputEnd(__outputEnd)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	bool Relation::setCategories()
	{
		__inputEnd.__categories.clear();
		__outputEnd.__categories.clear();

		//_schema->_manager->getSchema("Mixed")
		return true;
	}

}

#pragma warning( default : 4355 )

