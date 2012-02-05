#ifndef _PGS_META_RELATION_HPP_
#define _PGS_META_RELATION_HPP_

#include "pgs/meta/common.hpp"
#include "pgs/meta/relationEnd.hpp"

namespace pgs
{
	namespace meta
	{
		//////////////////////////////////////////////////////////////////////////
		class Relation
		{
		public:
			//наименование
			std::string		_name;

			//входящий край
			RelationEndPtr	_inputEnd;

			//исходящий край
			RelationEndPtr	_outputEnd;

			//объемлющая схема
			SchemaPtr		_schema;
		};
	}
}

#endif
