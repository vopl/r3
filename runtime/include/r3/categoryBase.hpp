#ifndef _R3_CATEGORYBASE_HPP_
#define _R3_CATEGORYBASE_HPP_

#include "r3/relations/relation.hpp"
#include "utils/ntoa.hpp"

namespace r3
{
	template <class S, class C, class T>
	class CategoryBase
	{
	public:
		enum EIndexMethod
		{
			im_tree,
			im_hash,
		};

		enum ERelationSide
		{
			rs_src,
			rs_dst,
		};

	public:
		typedef S Schema;
		typedef C Category;
		typedef T Tuple;
		typedef boost::shared_ptr<T> Tuple_ptr;

	public:
		pgc::Connection con();

		template <class tag>
		pgc::Statement stm(const std::string &key);
		pgc::Statement stm(const std::string &key);

		C *category();
		const std::string &name();
		std::string db_name();
		std::string db_sname();

	public:
		void ins(Tuple &tup);
		void ins(Tuple_ptr tup);

		void upd(Tuple &tup);
		void upd(Tuple_ptr tup);

		void del(const fields::Id &id);
		void del(Tuple &tup);
		void del(Tuple_ptr tup);

		Tuple_ptr sel(const fields::Id &id);
		Tuple_ptr sel(Tuple_ptr tup);


	protected:
		CategoryBase(const char *name);
		~CategoryBase();

	private:
		struct enumOper_createField;
		struct enumOper_createIndex;
		struct enumOper_createRelation;
		struct enumOper_createInheritance;

	private:
		template <class S> friend class SchemaBase;
		void dbCreateTable();
		void dbCreateFields();
		void dbCreateIndices();
		void dbCreateRelations();
		void dbCreateInheritance();

	private:
		struct enumOper_tupleFillKey;
		std::string tupleFillKey(Tuple &tup);

		template <bool isIns> struct enumOper_tupleInsUpdSql;
		std::string tupleInsSql(Tuple &tup);
		std::string tupleUpdSql(Tuple &tup);

		struct enumOper_tupleSelSql;
		std::string tupleSelSql(Tuple &tup);

		struct enumOper_tupleInsUpdBind;
		void tupleInsBind(Tuple &tup, pgc::Statement &stm);
		void tupleUpdBind(Tuple &tup, pgc::Statement &stm);

		struct enumOper_tupleSelFetch;
		void tupleSelFetch(Tuple &tup, pgc::Result &res, size_t row);


	private:
		std::string _name;
	};









	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	pgc::Connection CategoryBase<S,C,T>::con()
	{
		return category()->schema()->con();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	template <class tag>
	pgc::Statement CategoryBase<S,C,T>::stm(const std::string &key)
	{
		return category()->schema()->stm<std::pair<C, tag> >(key);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	pgc::Statement CategoryBase<S,C,T>::stm(const std::string &key)
	{
		return category()->schema()->stm<C>(key);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	typename C *CategoryBase<S,C,T>::category()
	{
		return (C*)this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	CategoryBase<S,C,T>::CategoryBase(const char *name)
		: _name(name)
	{
	}

	template <class S, class C, class T>
	CategoryBase<S,C,T>::~CategoryBase()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	const std::string &CategoryBase<S,C,T>::name()
	{
		return _name;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	std::string CategoryBase<S,C,T>::db_name()
	{
		return "\""+_name+"\"";
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	std::string CategoryBase<S,C,T>::db_sname()
	{
		return category()->schema()->db_name()+"."+db_name();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	void CategoryBase<S,C,T>::dbCreateTable()
	{
		pgc::Connection con = category()->schema()->con();
		con.once("CREATE TABLE "+db_sname()+"(id INT8 PRIMARY KEY DEFAULT nextval('"+category()->schema()->db_name()+".\"idGen\"'::regclass))").exec().throwIfError();
	}

	template <class S, class C, class T>
	struct CategoryBase<S,C,T>::enumOper_createField
	{
		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Audio *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_name\" VARCHAR").exec().throwIfError();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_ext\" VARCHAR").exec().throwIfError();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_blob\" OID").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Binary *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" BYTEA").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Bool *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" BOOL").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Date *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" DATE").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::DateTimeInterval *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INTERVAL").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename Domain> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Enum<Domain> *stub,
			const char *fname)
		{
			static const size_t amount = r3::fields::Enum<Domain>::amount;

			pgc::Connection con = c->schema()->con();

			if(amount <= (size_t)std::numeric_limits<boost::int16_t>::max())
			{
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT2").exec().throwIfError();
			}
			else if(amount <= (size_t)std::numeric_limits<boost::int32_t>::max())
			{
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT4").exec().throwIfError();
			}
			else if(amount <= (size_t)std::numeric_limits<boost::int64_t>::max())
			{
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT8").exec().throwIfError();
			}
			else
			{
				throw("enum domain too long");
			}
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Image *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_name\" VARCHAR").exec().throwIfError();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_ext\" VARCHAR").exec().throwIfError();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_blob\" OID").exec().throwIfError();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_width\" INT4").exec().throwIfError();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_height\" INT4").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Int16 *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT2").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Int32 *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT4").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Int64 *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT8").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Int8 *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT2").exec().throwIfError();
		}


		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Money *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" MONEY").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Real32 *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" FLOAT4").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Real64 *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" FLOAT8").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename Domain> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Set<Domain> *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();

			static const size_t amount = r3::fields::Set<Domain>::bits4SetAmount;
			char buf[64];
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" BIT("+utils::_ntoa(amount, buf)+")").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::String *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" VARCHAR").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Time *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" TIME WITHOUT TIME ZONE").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Timestamp *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" TIMESTAMP WITHOUT TIME ZONE").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Video *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_name\" VARCHAR").exec().throwIfError();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_ext\" VARCHAR").exec().throwIfError();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_blob\" OID").exec().throwIfError();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_width\" INT4").exec().throwIfError();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_height\" INT4").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::File *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_name\" VARCHAR").exec().throwIfError();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_ext\" VARCHAR").exec().throwIfError();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_blob\" OID").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(Category *c, CategoryBaseOrSelf *bos, void *stub, const char *fname)
		{
			//assert(!"������ ����");
			throw std::exception("����������� ��� ���� ��� ���������� ������� � �������");
		}
	};










	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	struct CategoryBase<S,C,T>::enumOper_createIndex
	{

		template <typename Category, typename CategoryBaseOrSelf>
		std::string sql1(
			Category *c,
			CategoryBaseOrSelf *bos,
			const char *idxName,
			typename Category::EIndexMethod idxMethod)
		{
			std::string res = "CREATE INDEX \"_idx_";
			res += c->name();
			res += "_";
			res += idxName;
			res += "\" ON ";
			res += c->db_sname();
			res += " USING ";

			switch(idxMethod)
			{
			case Category::im_tree:
				res += "btree";
				break;
			case Category::im_hash:
				res += "hash";
				break;
			default:
				assert(!"unknown index method");
				res += "btree";
				break;
			}

			return res;
		}

		std::string sql2(void *stub, const char *fname)
		{
			std::string res = "\"_";
			res += fname;
			res += "_\"";
			return res;
		}

		std::string sql2(r3::fields::Audio *stub, const char *fname)
		{
			std::string res = "\"_";
			res += fname;
			res += "_name\"";
			return res;
		}

		std::string sql2(r3::fields::Image *stub, const char *fname)
		{
			std::string res = "\"_";
			res += fname;
			res += "_name\"";
			return res;
		}

		std::string sql2(r3::fields::Video *stub, const char *fname)
		{
			std::string res = "\"_";
			res += fname;
			res += "_name\"";
			return res;
		}


		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename F0, typename F1, typename F2, typename F3> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			const char *idxName,
			typename Category::EIndexMethod idxMethod,
			F0 *stub0,
			const char *fname0,
			F1 *stub1,
			const char *fname1,
			F2 *stub2,
			const char *fname2,
			F3 *stub3,
			const char *fname3)
		{
			pgc::Connection con = c->schema()->con();
			con.once(
				sql1(c,bos, idxName, idxMethod)+" ("+
				sql2(stub0, fname0)+", "+
				sql2(stub1, fname1)+", "+
				sql2(stub2, fname2)+", "+
				sql2(stub3, fname3)+")").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename F0, typename F1, typename F2> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			const char *idxName,
			typename Category::EIndexMethod idxMethod,
			F0 *stub0,
			const char *fname0,
			F1 *stub1,
			const char *fname1,
			F2 *stub2,
			const char *fname2)
		{
			pgc::Connection con = c->schema()->con();
			con.once(
				sql1(c,bos, idxName, idxMethod)+" ("+
				sql2(stub0, fname0)+", "+
				sql2(stub1, fname1)+", "+
				sql2(stub2, fname2)+")").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename F0, typename F1> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			const char *idxName,
			typename Category::EIndexMethod idxMethod,
			F0 *stub0,
			const char *fname0,
			F1 *stub1,
			const char *fname1)
		{
			pgc::Connection con = c->schema()->con();
			con.once(
				sql1(c,bos, idxName, idxMethod)+" ("+
				sql2(stub0, fname0)+", "+
				sql2(stub1, fname1)+")").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename F0> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			const char *idxName,
			typename Category::EIndexMethod idxMethod,
			F0 *stub0,
			const char *fname0)
		{
			pgc::Connection con = c->schema()->con();
			con.once(
				sql1(c,bos, idxName, idxMethod)+" ("+
				sql2(stub0, fname0)+")").exec().throwIfError();
		}
	};

	template <class S, class C, class T>
	struct CategoryBase<S,C,T>::enumOper_createRelation
	{
		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename CategoryAlien>
		void operator()(
			Category *c, CategoryBaseOrSelf *bos, CategoryAlien *ca,
			r3::relations::Relation2one<typename CategoryAlien::Tuple> *stubOwn,	const char *nameOwn,
			r3::relations::Relation2one<typename CategoryBaseOrSelf::Tuple> *stubAlien, const char *nameAlien,
			typename Category::ERelationSide ers)
		{
			if(Category::rs_src == ers)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_rel_"+nameOwn+"_"+ca->name()+"_id_\" INT8").exec().throwIfError();
			}
			//
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename CategoryAlien>
		void operator()(
			Category *c, CategoryBaseOrSelf *bos, CategoryAlien *ca,
			r3::relations::Relation2one<typename CategoryAlien::Tuple> *stubOwn,	const char *nameOwn,
			r3::relations::Relation2n<typename CategoryBaseOrSelf::Tuple> *stubAlien, const char *nameAlien,
			typename Category::ERelationSide ers)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_rel_"+nameOwn+"_"+ca->name()+"_id_\" INT8").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename CategoryAlien>
		void operator()(
			Category *c, CategoryBaseOrSelf *bos, CategoryAlien *ca,
			r3::relations::Relation2n<typename CategoryAlien::Tuple> *stubOwn,	const char *nameOwn,
			r3::relations::Relation2one<typename CategoryBaseOrSelf::Tuple> *stubAlien, const char *nameAlien,
			typename Category::ERelationSide ers)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename CategoryAlien>
		void operator()(
			Category *c, CategoryBaseOrSelf *bos, CategoryAlien *ca,
			r3::relations::Relation2n<typename CategoryAlien::Tuple> *stubOwn,	const char *nameOwn,
			r3::relations::Relation2n<typename CategoryBaseOrSelf::Tuple> *stubAlien, const char *nameAlien,
			typename Category::ERelationSide ers)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryAlien>
		void operator()(
			Category *c, Category *bos, CategoryAlien *ca,
			r3::relations::Relation2n<typename CategoryAlien::Tuple> *stubOwn,	const char *nameOwn,
			r3::relations::Relation2n<typename Category::Tuple> *stubAlien, const char *nameAlien,
			typename Category::ERelationSide ers)
		{
			if(Category::rs_src == ers)
			{
				pgc::Connection con = c->schema()->con();

				std::string tableName = "\""+c->schema()->name()+"_"+c->schema()->id()+"\".\"_refcross_"+nameOwn+"_"+ca->name()+"_"+nameAlien+"_"+c->name()+"_\"";
				con.once(
					"CREATE TABLE "+tableName+"("+
					"\"_rel_"+nameOwn+"_"+ca->name()+"_id_\" INT8,"
					"\"_rel_"+nameAlien+"_"+c->name()+"_id_\" INT8"
					")").exec().throwIfError();
			}
		}
	};


	template <class S, class C, class T>
	struct CategoryBase<S,C,T>::enumOper_createInheritance
	{
		template <typename Category, typename CategoryBase>
		void operator()(Category *c, CategoryBase *bc)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" INHERIT "+bc->db_sname()).exec().throwIfError();
		}

	};

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	void CategoryBase<S,C,T>::dbCreateFields()
	{
		//����������� ��� ������� � ����, ������� ��� ���� � �������� �� � �������
		C::Tuple tup;
		((C*)this)->enumFieldsFromBasesAndSelf(enumOper_createField(), tup);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	void CategoryBase<S,C,T>::dbCreateIndices()
	{
		//����������� ��� ������� � ����, ������� ��� ������� � �������� �� � �������
		((C*)this)->enumIndicesFromBasesAndSelf(enumOper_createIndex());
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	void CategoryBase<S,C,T>::dbCreateRelations()
	{
		C::Tuple tup;
		((C*)this)->enumRelationsFromBasesAndSelf(enumOper_createRelation(), tup);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	void CategoryBase<S,C,T>::dbCreateInheritance()
	{
		((C*)this)->enumBasesFirst(enumOper_createInheritance());
	}








	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	void CategoryBase<S, C, T>::ins(Tuple &tup)
	{
		tup.id = ((C*)this)->schema()->idGen();

		pgc::Statement stm_ = stm(tupleFillKey(tup) + "_ins_tuple");

		if(stm_.empty())
		{
			stm_.sql(tupleInsSql(tup));
		}

 		tupleInsBind(tup, stm_);
 		stm_.exec().throwIfError();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	void CategoryBase<S, C, T>::ins(Tuple_ptr tup)
	{
		return ins(*tup);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	void CategoryBase<S, C, T>::upd(Tuple &tup)
	{
		pgc::Statement stm_ = stm(tupleFillKey(tup) + "_upd_tuple");

		if(stm_.empty())
		{
			stm_.sql(tupleUpdSql(tup));
		}

		tupleUpdBind(tup, stm_);
		stm_.exec().throwIfError();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	void CategoryBase<S, C, T>::upd(Tuple_ptr tup)
	{
		return upd(*tup);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	void CategoryBase<S, C, T>::del(const fields::Id &id)
	{
		pgc::Statement stm_ = stm("del_id");

		if(stm_.empty())
		{
			stm_.sql("DELETE FROM " + db_sname() + " WHERE id=$1");
		}

		stm_.bind(id.value());
		stm_.exec().throwIfError();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	void CategoryBase<S, C, T>::del(Tuple &tup)
	{
		del(tup.id);
		tup.id.value() = 0;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	void CategoryBase<S, C, T>::del(Tuple_ptr tup)
	{
		del(tup->id);
		tup->id.value() = 0;
	}



	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	typename CategoryBase<S, C, T>::Tuple_ptr CategoryBase<S, C, T>::sel(const fields::Id &id)
	{
		Tuple_ptr res(new Tuple);
		res->id = id;
		return sel(res);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	typename CategoryBase<S, C, T>::Tuple_ptr CategoryBase<S, C, T>::sel(Tuple_ptr tup)
	{
		pgc::Statement stm_ = stm("sel_id");

		if(stm_.empty())
		{
			stm_.sql(tupleSelSql(*tup));
		}

		stm_.bind(tup->id.value(), 1);
		pgc::Result res = stm_.exec().throwIfError();

		if(!res.rows())
		{
			return Tuple_ptr();
		}
		tupleSelFetch(*tup, res, 0);
		return tup;
	}




	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	struct CategoryBase<S,C,T>::enumOper_tupleFillKey
	{
		static const size_t _bufSize = T::_fieldsAmount/8 + (T::_fieldsAmount % 8 ? 1 : 0);
		unsigned char _buf[_bufSize];
		size_t idx;

		enumOper_tupleFillKey()
			: idx(0)
		{
			memset(_buf, 0, _bufSize);
		}

		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Field *fld,
			const char *fname)
		{
			assert(idx < T::_fieldsAmount);
			if(fld->fvs() != fields::fvs_notset)
			{
				_buf[idx/8] |= 1 << (idx%8);
			}
			idx++;
		}

		unsigned char toHex(unsigned char c)
		{
			if(c >= 10) 
				return c-10+'a';
			return c + '0';
		}

		std::string mkRes()
		{
			assert(idx == T::_fieldsAmount);

			std::string res;
			res.resize(_bufSize*2);
			for(size_t i(0); i<_bufSize; i++)
			{
				res[i*2+0] = toHex(_buf[i]/16);
				res[i*2+1] = toHex(_buf[i]%16);
			}

			return res;
		}
	};

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	std::string CategoryBase<S,C,T>::tupleFillKey(T &tup)
	{
		enumOper_tupleFillKey oper;
		((C*)this)->enumFieldsFromBasesAndSelf(oper, tup);

		return oper.mkRes();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	template <bool isIns>
	struct CategoryBase<S,C,T>::enumOper_tupleInsUpdSql
	{
		std::string fields;
		std::string values;
		size_t idx;

		enumOper_tupleInsUpdSql()
			: idx(0)
		{
		}

		void pushOne(const char *fname, const char *suffix = NULL)
		{
			if(idx)
			{
				fields += ",";
				values += ",";
			}

			idx++;

			fields += "\"_";
			fields += fname;
			fields += "_";
			if(suffix)
			{
				fields += suffix;
			}
			fields += "\"";

			char buf[32];
			if(isIns)
			{
				values += "$";
				values += utils::_ntoa(idx+1, buf);
			}
			else
			{
				fields += "=$";
				fields += utils::_ntoa(idx+1, buf);
			}
		}

		//file
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::File *fld,
			const char *fname)
		{
			if(fld->fvs() != fields::fvs_notset)
			{
				pushOne(fname, "name");
				pushOne(fname, "ext");
				pushOne(fname, "blob");
			}
		}

		//image
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Image *fld,
			const char *fname)
		{
			if(fld->fvs() != fields::fvs_notset)
			{
				pushOne(fname, "name");
				pushOne(fname, "ext");
				pushOne(fname, "blob");
				pushOne(fname, "width");
				pushOne(fname, "height");
			}
		}

		//video
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Video *fld,
			const char *fname)
		{
			if(fld->fvs() != fields::fvs_notset)
			{
				pushOne(fname, "name");
				pushOne(fname, "ext");
				pushOne(fname, "blob");
				pushOne(fname, "width");
				pushOne(fname, "height");
			}
		}

		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Field *fld,
			const char *fname)
		{
			if(fld->fvs() != fields::fvs_notset)
			{
				pushOne(fname);
			}
		}
	};

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	std::string CategoryBase<S,C,T>::tupleInsSql(T &tup)
	{
		enumOper_tupleInsUpdSql<true> oper;
		((C*)this)->enumFieldsFromBasesAndSelf(oper, tup);

		if(oper.fields.empty())
		{
			return "INSERT INTO "+((C*)this)->db_sname()+" (id) VALUES ($1)";
		}
		return "INSERT INTO "+((C*)this)->db_sname()+" (id,"+oper.fields+") VALUES ($1,"+oper.values+")";
	}


	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	struct CategoryBase<S,C,T>::enumOper_tupleInsUpdBind
	{
		pgc::Statement &stm;
		size_t idx;

		enumOper_tupleInsUpdBind(pgc::Statement &stm)
			: idx(0)
			, stm(stm)
		{
		}

		template <typename F> void bind(F *fld, bool isNull)
		{
			idx++;
			if(isNull)	stm.bind((F::TValue *)NULL, idx+1);
			else		stm.bind(fld->value(), idx+1);
		}

		void bind(r3::fields::File *fld, bool isNull)
		{
			idx++;
			if(isNull)	stm.bind((r3::fields::File::TName *)NULL, idx+1);
			else		stm.bind(fld->name(), idx+1);


			idx++;
			if(isNull)	stm.bind((r3::fields::File::TExt *)NULL, idx+1);
			else		stm.bind(fld->ext(), idx+1);

			idx++;
			if(isNull)	stm.bind((r3::fields::File::TBlob *)NULL, idx+1);
			else		stm.bind(fld->blob(), idx+1);
		}
		void bind(r3::fields::Audio *fld, bool isNull)
		{
			bind((r3::fields::File *)fld, isNull);
		}

		void bind(r3::fields::Image *fld, bool isNull)
		{
			bind((r3::fields::File *)fld, isNull);

			idx++;
			if(isNull)	stm.bind((r3::fields::Image::TWidth *)NULL, idx+1);
			else		stm.bind(fld->width(), idx+1);

			idx++;
			if(isNull)	stm.bind((r3::fields::Image::THeight *)NULL, idx+1);
			else		stm.bind(fld->height(), idx+1);
		}

		void bind(r3::fields::Video *fld, bool isNull)
		{
			bind((r3::fields::File *)fld, isNull);

			idx++;
			if(isNull)	stm.bind((r3::fields::Video::TWidth *)NULL, idx+1);
			else		stm.bind(fld->width(), idx+1);

			idx++;
			if(isNull)	stm.bind((r3::fields::Video::THeight *)NULL, idx+1);
			else		stm.bind(fld->height(), idx+1);
		}

		template <typename Category, typename CategoryBaseOrSelf, typename F> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			F *fld,
			const char *fname)
		{
			if(fld->fvs() != fields::fvs_notset)
			{
				bind(fld, fld->fvs() == fields::fvs_null);
			}
		}
	};

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	void CategoryBase<S,C,T>::tupleInsBind(T &tup, pgc::Statement &stm)
	{
		stm.bind(tup.id.value(), 1);
		enumOper_tupleInsUpdBind oper(stm);
		((C*)this)->enumFieldsFromBasesAndSelf(oper, tup);
	}










	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	std::string CategoryBase<S,C,T>::tupleUpdSql(T &tup)
	{
		enumOper_tupleInsUpdSql<false> oper;
		((C*)this)->enumFieldsFromBasesAndSelf(oper, tup);

		if(oper.fields.empty())
		{
			return "UPDATE "+((C*)this)->db_sname()+" SET id=id WHERE id=$1";
		}
		return "UPDATE "+((C*)this)->db_sname()+" SET "+oper.fields+" WHERE id=$1";
	}


	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	void CategoryBase<S,C,T>::tupleUpdBind(T &tup, pgc::Statement &stm)
	{
		//enumOper_tupleUpdBind oper(stm);
		enumOper_tupleInsUpdBind oper(stm);
		stm.bind(tup.id.value(), 1);
		((C*)this)->enumFieldsFromBasesAndSelf(oper, tup);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	struct CategoryBase<S,C,T>::enumOper_tupleSelSql
	{
		std::string fields;
		size_t idx;

		enumOper_tupleSelSql()
			: idx(0)
		{
		}

		void pushOne(const char *fname, const char *suffix = NULL)
		{
			if(idx)
			{
				fields += ",";
			}

			idx++;

			fields += "\"_";
			fields += fname;
			fields += "_";
			if(suffix)
			{
				fields += suffix;
			}
			fields += "\"";
		}

		//file
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::File *fld,
			const char *fname)
		{
			pushOne(fname, "name");
			pushOne(fname, "ext");
			pushOne(fname, "blob");
		}

		//image
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Image *fld,
			const char *fname)
		{
			pushOne(fname, "name");
			pushOne(fname, "ext");
			pushOne(fname, "blob");
			pushOne(fname, "width");
			pushOne(fname, "height");
		}

		//video
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Video *fld,
			const char *fname)
		{
			pushOne(fname, "name");
			pushOne(fname, "ext");
			pushOne(fname, "blob");
			pushOne(fname, "width");
			pushOne(fname, "height");
		}

		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::Field *fld,
			const char *fname)
		{
			pushOne(fname);
		}
	};

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	std::string CategoryBase<S,C,T>::tupleSelSql(Tuple &tup)
	{
		enumOper_tupleSelSql oper;
		((C*)this)->enumFieldsFromBasesAndSelf(oper, tup);

		return "SELECT tableoid,id,"+oper.fields+" FROM "+((C*)this)->db_sname()+" WHERE id=$1";
	}

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	struct CategoryBase<S,C,T>::enumOper_tupleSelFetch
	{
		pgc::Result &res;
		size_t row;
		size_t idx;
		enumOper_tupleSelFetch(pgc::Result &res, size_t row)
			: res(res)
			, row(row)
			, idx(1)
		{
		}

		template <typename F> void fetch(F *fld)
		{
			idx++;
			if(res.isNull(row, idx))
			{
				fld->fvs(fields::fvs_null);
			}
			else
			{
				fld->fvs(fields::fvs_set);
				res.fetch(row, idx, fld->value());
			}
		}

		void fetch(r3::fields::File *fld)
		{
			if(res.isNull(row, idx+1))
			{
				fld->fvs(fields::fvs_null);
			}
			else
			{
				fld->fvs(fields::fvs_set);
				res.fetch(row, idx+1, fld->name());
				res.fetch(row, idx+2, fld->ext());
				res.fetch(row, idx+3, fld->blob());
			}
			idx += 3;
		}

		void fetch(r3::fields::Audio *fld)
		{
			fetch((r3::fields::File *)fld);
		}

		void fetch(r3::fields::Image *fld)
		{
			fetch((r3::fields::File *)fld);

			if(fld->fvs() == fields::fvs_null)
			{
			}
			else
			{
				res.fetch(row, idx+1, fld->width());
				res.fetch(row, idx+2, fld->height());
			}
			idx += 2;
		}

		void fetch(r3::fields::Video *fld)
		{
			fetch((r3::fields::File *)fld);

			if(fld->fvs() == fields::fvs_null)
			{
			}
			else
			{
				res.fetch(row, idx+1, fld->width());
				res.fetch(row, idx+2, fld->height());
			}
			idx += 2;
		}

		template <typename Category, typename CategoryBaseOrSelf, typename F> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			F *fld,
			const char *fname)
		{
			fetch(fld);
		}

	};

	//////////////////////////////////////////////////////////////////////////
	template <class S, class C, class T>
	void CategoryBase<S,C,T>::tupleSelFetch(Tuple &tup, pgc::Result &res, size_t row)
	{
		res.fetch(row, 0, tup.tableoid);

		res.fetch(row, 1, tup.id.value());
		tup.id.fvs(fields::fvs_set);

		enumOper_tupleSelFetch oper(res, row);
		((C*)this)->enumFieldsFromBasesAndSelf(oper, tup);
	}

}

#endif
