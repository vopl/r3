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
		ClusterStoragePtr	_storage;
		SchemaPtr			_schema;

		static const std::string _sname;

	public:
		SchemaInitializer(ClusterStorage *storage, SchemaPtr schema);

		bool preInit();
		bool checkDependencies();
		bool createObjects();
		bool linkObjects();
		bool postInit();

		static const std::string &getName();

	private:
		template <class Field>
		Field *adoptField(CategoryPtr c, const char *name);
		RelationEndPtr adoptRelationEnd(CategoryPtr c, const char *name);
		IndexPtr adoptIndex(CategoryPtr c, const char *name);
	};

	//////////////////////////////////////////////////////////////////////////
	template <class Schema>
	SchemaInitializer<Schema>::SchemaInitializer(ClusterStorage *storage, SchemaPtr schema)
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

	//////////////////////////////////////////////////////////////////////////
	template <class Schema>
	const std::string &SchemaInitializer<Schema>::getName()
	{
		return _sname;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Schema>
	template <class Field>
	Field *SchemaInitializer<Schema>::adoptField(CategoryPtr c, const char *name)
	{
		Field *fld = static_cast<Field *>(c->_fields[name]);
		if(fld->_category != c)
		{
			boost::shared_ptr<Field> adopted(new Field);
			*adopted = *fld;
			adopted->_category = c;

			c->_fields.replace(adopted.get());
			_storage->_fields_heap.push_back(adopted);
		}

		return fld;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Schema>
	RelationEndPtr SchemaInitializer<Schema>::adoptRelationEnd(CategoryPtr c, const char *name)
	{
		RelationEndPtr re = c->_relationEnds[name];
		if(re->_category != c)
		{
			boost::shared_ptr<RelationEnd> adopted(new RelationEnd);
			*adopted = *re;
			adopted->_category = c;

			c->_relationEnds.replace(adopted.get());
			_storage->_relationEnds_heap.push_back(adopted);
		}

		return re;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Schema>
	IndexPtr SchemaInitializer<Schema>::adoptIndex(CategoryPtr c, const char *name)
	{
		IndexPtr idx = c->_indices[name];
		if(idx->_category != c)
		{
			boost::shared_ptr<Index> adopted(new Index);
			*adopted = *idx;
			adopted->_category = c;

			c->_indices.replace(adopted.get());
			_storage->_indices_heap.push_back(adopted);
		}

		return idx;
	}

}

#endif