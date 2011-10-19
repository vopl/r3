#ifndef _DBMETA_MANAGER_HPP_
#define _DBMETA_MANAGER_HPP_

#include "dbMeta/field.hpp"
#include "dbMeta/index.hpp"
#include "dbMeta/category.hpp"
#include "dbMeta/schema.hpp"

namespace dbMeta
{
	class Manager
	{
		SchemaPtrs _vschemas;

		typedef std::map<std::string, SchemaPtr> TMSchemas;
		TMSchemas _mschemas;

	public:
		template <class Schema>
		const Schema &add();

		const SchemaPtr getSchema(const std::string &name) const;
		const SchemaPtrs &getSchemas() const;
	};

	///
	template <class T>
	const T &Manager::add()
	{
		T *p = new T(this);

		if(_mschemas.end() != _mschemas.find(p->_name))
		{
			delete p;
			throw std::logic_error("schema "+p->_name+" already added");
		}

		_vschemas.push_back(p);
		_mschemas[p->_name] = p;

		return *p;
	}

}

#endif
