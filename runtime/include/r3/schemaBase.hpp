#ifndef _R3_SCHEMABASE_HPP_
#define _R3_SCHEMABASE_HPP_

#include "pgc/connection.hpp"

namespace r3
{
	//////////////////////////////////////////////////////////////////////////
	template <class S>
	class SchemaBase
		: public boost::enable_shared_from_this<S>
	{
		typedef S Schema;

		pgc::Connection _con;
		std::string _id;
		std::string _name;

	protected:
		void init();
	public:
		SchemaBase(const char *id, const char *name);
		~SchemaBase();

		pgc::Connection con();

		const std::string &id();
		const std::string &name();

		std::string db_name();

		void dbCon(pgc::Connection con);
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
		struct enumOper_createForeignFields
		{
			template <typename Schema, typename CategoryPtr> void operator()(Schema *s, CategoryPtr &c)
			{
				c->dbCreateForeignFields();
			}
		};
		///////////////////////////
		struct enumOper_createCrosses
		{
			template <typename Schema, typename CategoryPtr> void operator()(Schema *s, CategoryPtr &c)
			{
				c->dbCreateCrosses();
			}
		};
		///////////////////////////
		struct enumOper_createForeignConstraints
		{
			template <typename Schema, typename CategoryPtr> void operator()(Schema *s, CategoryPtr &c)
			{
				c->dbCreateForeignConstraints();
			}
		};
		///////////////////////////
		struct enumOper_createViews
		{
			template <typename Schema, typename CategoryPtr> void operator()(Schema *s, CategoryPtr &c)
			{
				c->dbCreateViews();
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
	SchemaBase<S>::SchemaBase(const char *id, const char *name)
		: _id(id)
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
		return _con;
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
		return "\""+_id+"_"+_name+"\"";
	}


	//////////////////////////////////////////////////////////////////////////
	template <class S>
	void SchemaBase<S>::dbCon(pgc::Connection con)
	{
		_con = con;
	}


	//////////////////////////////////////////////////////////////////////////
	template <class S>
	void SchemaBase<S>::dbCreate()
	{
		S* s = (S*)this;

		_con.once("CREATE SCHEMA "+db_name()).exec().throwIfError();

		//таблицы, поля первичных ключей
		s->enumCategories(impl::enumOper_createTable());

		//поля данных
		s->enumCategories(impl::enumOper_createFields());

		//индексы
		s->enumCategories(impl::enumOper_createIndices());

		//поля вторичных ключей
		s->enumCategories(impl::enumOper_createForeignFields());

		//таблицы кроссов
		s->enumCategories(impl::enumOper_createCrosses());

		//ограничения по связям
		s->enumCategories(impl::enumOper_createForeignConstraints());

		//виды
		s->enumCategories(impl::enumOper_createViews());
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	void SchemaBase<S>::dbDrop()
	{
		_con.once("DROP SCHEMA "+db_name()).exec().throwIfError();
	}

}
#endif
