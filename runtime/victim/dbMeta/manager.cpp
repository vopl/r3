#include "stdafx.h"
#include "dbMeta/manager.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	const SchemaPtr Manager::getSchema(const std::string &name) const
	{
		TMSchemas::const_iterator iter = _mschemas.find(name);
		if(_mschemas.end() == iter)
		{
			throw std::domain_error("schema "+name+" absent");
			return NULL;
		}

		return iter->second;
	}

	//////////////////////////////////////////////////////////////////////////
	const SchemaPtrs &Manager::getSchemas() const
	{
		return _vschemas;
	}

}