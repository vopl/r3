#include "stdafx.h"
#include "dbMeta/manager.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	Manager::Manager()
		: _isInitialized(false)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void Manager::initialize()
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
		BOOST_FOREACH(boost::shared_ptr<SchemaInitializerBase> si, _schemaInitializers)
		{
			if(!si->postInit())
			{
				assert(!"postInit failed");
				throw "postInit failed";
				return;
			}
		}

		_isInitialized = true;
	}

}