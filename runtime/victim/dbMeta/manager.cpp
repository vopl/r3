#include "stdafx.h"
#include "dbMeta/manager.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	void Manager::initialize()
	{
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
	}

}