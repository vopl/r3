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
	public:
		SchemaBase(const char *id);
		~SchemaBase();

		void dbCon(pgc::Connection con);
		void dbCreate();
		void dbDrop();
	};

	//////////////////////////////////////////////////////////////////////////
	namespace impl
	{
		///////////////////////////
		template <class S, class Tag> struct dbCreate_Operator;

		///////////////////////////
		typedef struct {} tag_Init;
		template <class S> struct dbCreate_Operator<S, tag_Init>
		{
			S *_schema;
			dbCreate_Operator(S *schema) : _schema(schema){}
			template <typename Category> void operator()(Category *stub)
			{
				_schema->getCategory<Category>()->init(_schema);
			}
		};

		///////////////////////////
		typedef struct {} tag_CreateTable;
		template <class S> struct dbCreate_Operator<S, tag_CreateTable>
		{
			S *_schema;
			dbCreate_Operator(S *schema) : _schema(schema){}
			template <typename Category> void operator()(Category *stub)
			{
				_schema->getCategory<Category>()->dbCreateTable();
			}
		};

		///////////////////////////
		typedef struct {} tag_CreateFields;
		template <class S> struct dbCreate_Operator<S, tag_CreateFields>
		{
			S *_schema;
			dbCreate_Operator(S *schema) : _schema(schema){}
			template <typename Category> void operator()(Category *stub)
			{
				_schema->getCategory<Category>()->dbCreateFields();
			}
		};

		///////////////////////////
		typedef struct {} tag_CreateIndices;
		template <class S> struct dbCreate_Operator<S, tag_CreateIndices>
		{
			S *_schema;
			dbCreate_Operator(S *schema) : _schema(schema){}
			template <typename Category> void operator()(Category *stub)
			{
				_schema->getCategory<Category>()->dbCreateIndices();
			}
		};

		///////////////////////////
		typedef struct {} tag_CreateForeignFields;
		template <class S> struct dbCreate_Operator<S, tag_CreateForeignFields>
		{
			S *_schema;
			dbCreate_Operator(S *schema) : _schema(schema){}
			template <typename Category> void operator()(Category *stub)
			{
				_schema->getCategory<Category>()->dbCreateForeignFields();
			}
		};

		///////////////////////////
		typedef struct {} tag_CreateCrosses;
		template <class S> struct dbCreate_Operator<S, tag_CreateCrosses>
		{
			S *_schema;
			dbCreate_Operator(S *schema) : _schema(schema){}
			template <typename Category> void operator()(Category *stub)
			{
				_schema->getCategory<Category>()->dbCreateCrosses();
			}
		};

		///////////////////////////
		typedef struct {} tag_CreateForeignConstraints;
		template <class S> struct dbCreate_Operator<S, tag_CreateForeignConstraints>
		{
			S *_schema;
			dbCreate_Operator(S *schema) : _schema(schema){}
			template <typename Category> void operator()(Category *stub)
			{
				_schema->getCategory<Category>()->dbCreateForeignConstraints();
			}
		};

		///////////////////////////
		typedef struct {} tag_CreateViews;
		template <class S> struct dbCreate_Operator<S, tag_CreateViews>
		{
			S *_schema;
			dbCreate_Operator(S *schema) : _schema(schema){}
			template <typename Category> void operator()(Category *stub)
			{
				_schema->getCategory<Category>()->dbCreateViews();
			}
		};

	}

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	SchemaBase<S>::SchemaBase(const char *id)
		: _id(id)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	SchemaBase<S>::~SchemaBase()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	void SchemaBase<S>::dbCon(pgc::Connection con)
	{
		_con = con;

		typedef typename bmpl::transform
			<
				typename Schema::TVCategoryTypes,
				boost::add_pointer<bmpl::_1>
			>::type CategoryPointerTypes;

		bmpl::for_each<CategoryPointerTypes>(impl::dbCreate_Operator<S, impl::tag_Init>((S*)this));
	}


	//////////////////////////////////////////////////////////////////////////
	template <class S>
	void SchemaBase<S>::dbCreate()
	{
		typedef typename bmpl::transform
			<
				typename Schema::TVCategoryTypes,
				boost::add_pointer<bmpl::_1>
			>::type CategoryPointerTypes;

		//таблицы, поля первичных ключей
		bmpl::for_each<CategoryPointerTypes>(impl::dbCreate_Operator<S, impl::tag_CreateTable>((S*)this));

		//поля данных
		bmpl::for_each<CategoryPointerTypes>(impl::dbCreate_Operator<S, impl::tag_CreateFields>((S*)this));

		//индексы
		bmpl::for_each<CategoryPointerTypes>(impl::dbCreate_Operator<S, impl::tag_CreateIndices>((S*)this));

		//поля вторичных ключей
		bmpl::for_each<CategoryPointerTypes>(impl::dbCreate_Operator<S, impl::tag_CreateForeignFields>((S*)this));

		//таблицы кроссов
		bmpl::for_each<CategoryPointerTypes>(impl::dbCreate_Operator<S, impl::tag_CreateCrosses>((S*)this));

		//ограничения по связям
		bmpl::for_each<CategoryPointerTypes>(impl::dbCreate_Operator<S, impl::tag_CreateForeignConstraints>((S*)this));

		//виды
		bmpl::for_each<CategoryPointerTypes>(impl::dbCreate_Operator<S, impl::tag_CreateViews>((S*)this));
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	void SchemaBase<S>::dbDrop()
	{
		_con.once("DROP SCHEMA $1").exec("r3_"+_id).throwIfError();
	}

}
#endif
