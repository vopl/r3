#ifndef _R3_SCHEMABASE_HPP_
#define _R3_SCHEMABASE_HPP_

#include "pgc/connection.hpp"

namespace r3
{
	//////////////////////////////////////////////////////////////////////////
	class Model;

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	class SchemaBase
		: public boost::enable_shared_from_this<S>
	{
	public:
		SchemaBase(Model *model, const char *id, const char *name);
		~SchemaBase();

		pgc::Connection con();

		const std::string &id();
		const std::string &name();
		std::string db_name();

	public:
		void dbCreate();
		void dbDrop();

	public:


	private:
		struct enumOper_init;
		struct enumOper_createTable;
		struct enumOper_createFields;
		struct enumOper_createIndices;
		struct enumOper_createRelations;
		struct enumOper_createInheritances;

	private:
		Model *_model;
		std::string _id;
		std::string _name;

	protected:
		void init();
	};

	///////////////////////////
	template <class S>
	struct SchemaBase<S>::enumOper_init
	{
		template <typename Schema, typename CategoryPtr> void operator()(Schema *s, CategoryPtr &c)
		{
			c.reset(new typename CategoryPtr::element_type(s));
		}
	};


	///////////////////////////
	template <class S>
	struct SchemaBase<S>::enumOper_createTable
	{
		template <typename Schema, typename CategoryPtr> void operator()(Schema *s, CategoryPtr &c)
		{
			c->dbCreateTable();
		}
	};
	///////////////////////////
	template <class S>
	struct SchemaBase<S>::enumOper_createFields
	{
		template <typename Schema, typename CategoryPtr> void operator()(Schema *s, CategoryPtr &c)
		{
			c->dbCreateFields();
		}
	};
	///////////////////////////
	template <class S>
	struct SchemaBase<S>::enumOper_createIndices
	{
		template <typename Schema, typename CategoryPtr> void operator()(Schema *s, CategoryPtr &c)
		{
			c->dbCreateIndices();
		}
	};
	///////////////////////////
	template <class S>
	struct SchemaBase<S>::enumOper_createRelations
	{
		template <typename Schema, typename CategoryPtr> void operator()(Schema *s, CategoryPtr &c)
		{
			c->dbCreateRelations();
		}
	};
	///////////////////////////
	template <class S>
	struct SchemaBase<S>::enumOper_createInheritances
	{
		template <typename Schema, typename CategoryPtr> void operator()(Schema *s, CategoryPtr &c)
		{
			c->dbCreateInheritance();
		}
	};

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	void SchemaBase<S>::init()
	{
		S* s = (S*)this;
		s->enumCategories(enumOper_init());
	}


	//////////////////////////////////////////////////////////////////////////
	template <class S>
	SchemaBase<S>::SchemaBase(Model *model, const char *id, const char *name)
		: _model(model)
		, _id(id)
		, _name(name)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	SchemaBase<S>::~SchemaBase()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	pgc::Connection SchemaBase<S>::con()
	{
		return _model->con();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	const std::string &SchemaBase<S>::id()
	{
		return _id;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	const std::string &SchemaBase<S>::name()
	{
		return _name;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	std::string SchemaBase<S>::db_name()
	{
		return "\""+_name+"_"+_id+"\"";
	}


	//////////////////////////////////////////////////////////////////////////
	template <class S>
	void SchemaBase<S>::dbCreate()
	{
		S* s = (S*)this;

		con().once("CREATE SCHEMA "+db_name()).exec().throwIfError();
		con().once("CREATE SEQUENCE "+db_name()+".\"idGen\"").exec().throwIfError();

		//таблицы, поля первичных ключей
		s->enumCategories(enumOper_createTable());

		//поля данных
		s->enumCategories(enumOper_createFields());

		//индексы
		s->enumCategories(enumOper_createIndices());

		//поля вторичных ключей
		s->enumCategories(enumOper_createRelations());

		//наследование таблиц
		s->enumCategories(enumOper_createInheritances());
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	void SchemaBase<S>::dbDrop()
	{
		con().once("DROP SCHEMA "+db_name()+" CASCADE").exec().throwIfError();
	}

}
#endif
