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
	public:
		//добавить по типу
		template <class Schema> void add();

		//сериализация
		void serialize();
	};

	///
	template <class T>
	void Manager::add()
	{
		return;
	}

}

#endif
