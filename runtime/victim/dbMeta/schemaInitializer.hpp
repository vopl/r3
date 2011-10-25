#ifndef _DBMETA_SCHEMAINITIALIZER_HPP_
#define _DBMETA_SCHEMAINITIALIZER_HPP_

#include "dbMeta/common.hpp"

namespace dbMeta
{
	class SchemaInitializerBase
	{
	public:
		virtual bool preInit()=0;
		virtual bool checkDependencies()=0;
		virtual bool createObjects()=0;
		virtual bool linkObjects()=0;
		virtual bool postInit()=0;
	};

	//////////////////////////////////////////////////////////////////////////
	template <class Schema>
	class SchemaInitializer
		: public SchemaInitializerBase
	{
		ManagerStorage *_storage;
		SchemaPtr _schema;

	public:
		SchemaInitializer(ManagerStorage *storage, SchemaPtr schema);

		bool preInit();
		bool checkDependencies();
		bool createObjects();
		bool linkObjects();
		bool postInit();
	};

	//////////////////////////////////////////////////////////////////////////
	template <class Schema>
	SchemaInitializer<Schema>::SchemaInitializer(ManagerStorage *storage, SchemaPtr schema)
		: _storage(storage)
		, _schema(schema)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Schema>
	bool SchemaInitializer<Schema>::preInit()
	{
		assert(!"must be reimplemented in target schema");
		throw "must be reimplemented in target schema";
		return false;
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

	//////////////////////////////////////////////////////////////////////////
	template <class Schema>
	bool SchemaInitializer<Schema>::postInit()
	{
		assert(!"must be reimplemented in target schema");
		throw "must be reimplemented in target schema";
		return false;
	}

}

#endif
