#include "pch.h"

#include "pgs/meta/cluster.hpp"
#include "clusterImpl.hpp"

namespace pgs
{
	namespace meta
	{

		//////////////////////////////////////////////////////////////////////////
		void Cluster::add(boost::shared_ptr<Schema> schema, boost::shared_ptr<SchemaInitializerBase> schemaInitializer)
		{
			return _impl->add(schema, schemaInitializer);
		}

		//////////////////////////////////////////////////////////////////////////
		Cluster::Cluster()
			: _impl(new ClusterImpl)
		{

		}

		//////////////////////////////////////////////////////////////////////////
		void Cluster::initialize()
		{
			return _impl->initialize();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Cluster::isInitialized() const
		{
			return _impl->isInitialized();
		}

		//////////////////////////////////////////////////////////////////////////
		SchemaCPtr Cluster::getByName(const std::string &name) const
		{
			return _impl->getByName(name);
		}

		//////////////////////////////////////////////////////////////////////////
		const SchemaPtrs &Cluster::getSchemas() const
		{
			return _impl->getSchemas();
		}

	}
}
