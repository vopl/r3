#include "pch.h"
#include "clusterImpl.hpp"
#include "pgs/meta/category.hpp"

namespace pgs
{
	namespace meta
	{
		//////////////////////////////////////////////////////////////////////////
		void ClusterImpl::add(boost::shared_ptr<Schema> schema, boost::shared_ptr<SchemaInitializerBase> schemaInitializer)
		{
			if(_isInitialized)
			{
				assert(!"already initialized");
				throw "already initialized";
				return;
			}

			schemaInitializer->setStorage(this);
			_schemaInitializers.push_back(schemaInitializer);
			_schemas_heap.push_back(schema);

			return;
		}


		//////////////////////////////////////////////////////////////////////////
		bool ClusterImpl::collectInheritance(CategoryPtrs &res, CategoryPtr c, bool bases)
		{
			CategoryPtrs &list = bases?c->_bases:c->_deriveds;

			res.insert(res.end(), list.begin(), list.end());
			BOOST_FOREACH(CategoryPtr b, list)
			{
				if(!collectInheritance(res, b, bases)) return false;
			}
			return true;
		}

		//////////////////////////////////////////////////////////////////////////
		bool ClusterImpl::doInheritance()
		{
			BOOST_FOREACH(SchemaPtr s, _schemas)
			{
				BOOST_FOREACH(CategoryPtr c, s->_categories)
				{
					if(!collectInheritance(c->_allBases, c, true)) return false;
					if(!collectInheritance(c->_allDeriveds, c, false)) return false;

					c->_fields.insert(c->_fields.end(), c->_ownFields.begin(), c->_ownFields.end());
					c->_indices.insert(c->_indices.end(), c->_ownIndices.begin(), c->_ownIndices.end());
					c->_relationEnds.insert(c->_relationEnds.end(), c->_ownRelationEnds.begin(), c->_ownRelationEnds.end());
					BOOST_FOREACH(CategoryPtr b, c->_allBases)
					{
						c->_fields.insert(c->_fields.end(), b->_ownFields.begin(), b->_ownFields.end());
						c->_indices.insert(c->_indices.end(), b->_ownIndices.begin(), b->_ownIndices.end());
						c->_relationEnds.insert(c->_relationEnds.end(), b->_ownRelationEnds.begin(), b->_ownRelationEnds.end());
					}
				}
			}

			BOOST_FOREACH(SchemaPtr s, _schemas)
			{
				BOOST_FOREACH(CategoryPtr c, s->_categories)
				{
					BOOST_FOREACH(FieldPtr f, c->_ownFields)
					{
						f->_categories.push_back(c);
						f->_categories.insert(f->_categories.end(), c->_allDeriveds.begin(), c->_allDeriveds.end());
					}
					BOOST_FOREACH(IndexPtr i, c->_ownIndices)
					{
						i->_categories.push_back(c);
						i->_categories.insert(i->_categories.end(), c->_allDeriveds.begin(), c->_allDeriveds.end());
					}
					BOOST_FOREACH(RelationEndPtr re, c->_ownRelationEnds)
					{
						re->_categories.push_back(c);
						re->_categories.insert(re->_categories.end(), c->_allDeriveds.begin(), c->_allDeriveds.end());
					}
				}
			}

			return true;
		}

		//////////////////////////////////////////////////////////////////////////
		ClusterImpl::ClusterImpl()
			: _isInitialized(false)
		{

		}

		//////////////////////////////////////////////////////////////////////////
		void ClusterImpl::initialize()
		{
			if(_isInitialized)
			{
				assert(!"already initialized");
				throw "already initialized";
				return;
			}

			BOOST_FOREACH(boost::shared_ptr<SchemaInitializerBase> si, _schemaInitializers)
			{
				if(!si->preInit())
				{
					assert(!"preInit failed");
					throw "preInit failed";
					return;
				}
			}
			BOOST_FOREACH(boost::shared_ptr<SchemaInitializerBase> si, _schemaInitializers)
			{
				if(!si->checkDependencies())
				{
					assert(!"checkDependencies failed");
					throw "checkDependencies failed";
					return;
				}
			}
			BOOST_FOREACH(boost::shared_ptr<SchemaInitializerBase> si, _schemaInitializers)
			{
				if(!si->createObjects())
				{
					assert(!"createObjects failed");
					throw "createObjects failed";
					return;
				}
			}
			BOOST_FOREACH(boost::shared_ptr<SchemaInitializerBase> si, _schemaInitializers)
			{
				if(!si->linkObjects())
				{
					assert(!"linkObjects failed");
					throw "linkObjects failed";
					return;
				}
			}

			if(!doInheritance())
			{
				assert(!"doInheritance failed");
				throw "doInheritance failed";
				return;
			}

			BOOST_FOREACH(boost::shared_ptr<SchemaInitializerBase> si, _schemaInitializers)
			{
				if(!si->postInit())
				{
					assert(!"postInit failed");
					throw "postInit failed";
					return;
				}
			}

			_schemaInitializers.clear();
			_isInitialized = true;
		}

		//////////////////////////////////////////////////////////////////////////
		bool ClusterImpl::isInitialized() const
		{
			return _isInitialized;
		}

		//////////////////////////////////////////////////////////////////////////
		SchemaCPtr ClusterImpl::getByName(const std::string &name) const
		{
			return _schemas[name];
		}

		//////////////////////////////////////////////////////////////////////////
		const SchemaPtrs &ClusterImpl::getSchemas() const
		{
			return _schemas;
		}
	}
}
