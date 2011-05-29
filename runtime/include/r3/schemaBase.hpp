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
		typedef S Schema;

		Model *_model;
		std::string _id;
		std::string _name;

	protected:
		void init();
	public:
		SchemaBase(Model *model, const char *id, const char *name);
		~SchemaBase();

		pgc::Connection con();

		const std::string &id();
		const std::string &name();

		std::string db_name();

		void dbCreate();
		void dbDrop();
	};

	//////////////////////////////////////////////////////////////////////////
	namespace impl
	{
		///////////////////////////
		struct enumOper_init
		{
			template <typename Schema, typename CategoryPtr> void operator()(Schema *s, CategoryPtr &c)
			{
				c.reset(new typename CategoryPtr::element_type(s));
			}
		};

		///////////////////////////
		struct enumOper_createTable
		{
			template <typename Schema, typename CategoryPtr> void operator()(Schema *s, CategoryPtr &c)
			{
				c->dbCreateTable();
			}
		};
		///////////////////////////
		struct enumOper_createFields
		{
			template <typename Schema, typename CategoryPtr> void operator()(Schema *s, CategoryPtr &c)
			{
				c->dbCreateFields();
			}
		};
		///////////////////////////
		struct enumOper_createIndices
		{
			template <typename Schema, typename CategoryPtr> void operator()(Schema *s, CategoryPtr &c)
			{
				c->dbCreateIndices();
			}
		};
		///////////////////////////
		struct enumOper_createRelations
		{
			template <typename Schema, typename CategoryPtr> void operator()(Schema *s, CategoryPtr &c)
			{
				c->dbCreateRelations();
			}
		};
		///////////////////////////
		struct enumOper_createInheritances
		{
			template <typename Schema, typename CategoryPtr> void operator()(Schema *s, CategoryPtr &c)
			{
				c->dbCreateInheritance();
			}
		};

	}

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	void SchemaBase<S>::init()
	{
		S* s = (S*)this;
		s->enumCategories(impl::enumOper_init());
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

		//таблицы, поля первичных ключей
		s->enumCategories(impl::enumOper_createTable());

		//поля данных
		s->enumCategories(impl::enumOper_createFields());

		//индексы
		s->enumCategories(impl::enumOper_createIndices());

		//поля вторичных ключей
		s->enumCategories(impl::enumOper_createRelations());

		//наследование таблиц
		s->enumCategories(impl::enumOper_createInheritances());
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	void SchemaBase<S>::dbDrop()
	{
		con().once("DROP SCHEMA "+db_name()+" CASCADE").exec().throwIfError();
	}

}
#endif
