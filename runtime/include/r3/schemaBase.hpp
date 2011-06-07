#ifndef _R3_SCHEMABASE_HPP_
#define _R3_SCHEMABASE_HPP_

#include "pgc/connection.hpp"
#include "r3/fields/field.h"

namespace r3
{
	//////////////////////////////////////////////////////////////////////////
	class Data;

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	class SchemaBase
		: public boost::enable_shared_from_this<S>
	{
	public:
		SchemaBase(Data *data, const char *id, const char *name);
		~SchemaBase();

		pgc::Connection con();

		template <class tag>
		pgc::Statement stm(const std::string &key);
		pgc::Statement stm(const std::string &key);

		const std::string &id();
		const std::string &name();
		std::string db_name();

	public:
		void dbCreate();
		void dbDrop();

		fields::Id idGen();

	public:


	private:
		struct enumOper_init;
		struct enumOper_createTable;
		struct enumOper_createFields;
		struct enumOper_createIndices;
		struct enumOper_createRelations;
		struct enumOper_createInheritances;

	private:
		Data *_data;
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
	SchemaBase<S>::SchemaBase(Data *data, const char *id, const char *name)
		: _data(data)
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
		return _data->con();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	template <class tag>
	pgc::Statement SchemaBase<S>::stm(const std::string &key)
	{
		return _data->stm<std::pair<S, tag> >(key);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	pgc::Statement SchemaBase<S>::stm(const std::string &key)
	{
		return _data->stm<S>(key);
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

		//�������, ���� ��������� ������
		s->enumCategories(enumOper_createTable());

		//���� ������
		s->enumCategories(enumOper_createFields());

		//�������
		s->enumCategories(enumOper_createIndices());

		//���� ��������� ������
		s->enumCategories(enumOper_createRelations());

		//������������ ������
		s->enumCategories(enumOper_createInheritances());
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S>
	void SchemaBase<S>::dbDrop()
	{
		con().once("DROP SCHEMA "+db_name()+" CASCADE").exec().throwIfError();
	}

	//////////////////////////////////////////////////////////////////////////
	namespace {
		struct SchemaBaseSecretType;
	}
	template <class S>
	fields::Id SchemaBase<S>::idGen()
	{
		pgc::Statement stm_ = stm<SchemaBaseSecretType>("idGen");
		if(stm_.empty())
		{
			stm_.sql("SELECT nextval('"+db_name()+".\"idGen\"'::regclass)");
		}

		fields::Id res;
		res.fvs(fields::fvs_set);
		stm_.exec().throwIfError().fetch(0,0,res.value());

		return res;

	}


}
#endif
