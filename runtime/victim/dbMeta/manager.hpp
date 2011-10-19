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
		void add();

		const SchemaPtr getSchema(const std::string &name) const;
		const SchemaPtrs &getSchemas() const;
	};

	///
	template <class T>
	void Manager::add()
	{
// 		T *p = new T();
// 
// 		if(_mschemas.end() != _mschemas.find(p->getName()))
// 		{
// 			throw std::logic_error("schema "+p->getName()+" already added");
// 			return;
// 		}
// 
// 		((dbMeta::Schema *)p)->init(this);
// 
// 		_vschemas.push_back(p);
// 		_mschemas[p->getName()] = p;
	}

}

#endif
