#ifndef _DBMETA_SCHEMAINITIALIZER_HPP_
#define _DBMETA_SCHEMAINITIALIZER_HPP_

#include "dbMeta/common.hpp"

namespace dbMeta
{
	class SchemaInitializerBase
	{
	public:
		virtual bool checkDependencies()=0;
		virtual bool createObjects()=0;
		virtual bool linkObjects()=0;
	};

	//////////////////////////////////////////////////////////////////////////
	template <class Schema>
	class SchemaInitializer
		: public SchemaInitializerBase
	{
		ManagerPtr _manager;
		SchemaPtr _schema;

	public:
		SchemaInitializer(ManagerPtr manager, SchemaPtr schema);

		bool checkDependencies();
		bool createObjects();
		bool linkObjects();
	};

	//////////////////////////////////////////////////////////////////////////
	template <class Schema>
	SchemaInitializer<Schema>::SchemaInitializer(ManagerPtr manager, SchemaPtr schema)
		: _manager(manager)
		, _schema(schema)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Schema>
	bool SchemaInitializer<Schema>::checkDependencies()
	{
		assert(!"must be reimplemented in target schema");
		throw "must be reimplemented in target schema";
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Schema>
	bool SchemaInitializer<Schema>::createObjects()
	{
		assert(!"must be reimplemented in target schema");
		throw "must be reimplemented in target schema";
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Schema>
	bool SchemaInitializer<Schema>::linkObjects()
	{
		assert(!"must be reimplemented in target schema");
		throw "must be reimplemented in target schema";
		return false;
	}

}

#endif
