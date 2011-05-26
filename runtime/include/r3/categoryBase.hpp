#ifndef _R3_CATEGORYBASE_HPP_
#define _R3_CATEGORYBASE_HPP_

#include "r3/fields/Field.h"
#include "utils/ntoa.hpp"

namespace r3
{
	template <class C>
	class CategoryBase
	{
		typedef C Category;
		Category *category();

		std::string _name;

	public:
		enum EIndexMethod
		{
			im_tree,
			im_hash,
		};

	public:
		CategoryBase(const char *name);
		~CategoryBase();

		const std::string &name();
		std::string db_name();
		std::string db_sname();


		void dbCreateTable();
		void dbCreateFields();
		void dbCreateIndices();
		void dbCreateForeignFields();
		void dbCreateCrosses();
		void dbCreateForeignConstraints();
		void dbCreateViews();
	};










	//////////////////////////////////////////////////////////////////////////
	template <class C>
	typename CategoryBase<C>::Category *CategoryBase<C>::category()
	{
		return (Category*)this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class C>
	CategoryBase<C>::CategoryBase(const char *name)
		: _name(name)
	{
	}

	template <class C>
	CategoryBase<C>::~CategoryBase()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class C>
	const std::string &CategoryBase<C>::name()
	{
		return _name;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class C>
	std::string CategoryBase<C>::db_name()
	{
		return "\""+_name+"\"";
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	std::string CategoryBase<C>::db_sname()
	{
		return category()->schema()->db_name()+"."+db_name();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateTable()
	{
		if(!C::isAbstract)
		{
			pgc::Connection con = category()->schema()->con();
			con.once("CREATE TABLE "+db_sname()+"(id int8 PRIMARY KEY)").exec().throwIfError();
		}
	}
	
	namespace impl
	{
		struct enumOper_createField
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
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_size\" INT4").exec().throwIfError();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_blob\" OID").exec().throwIfError();
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

				if(amount <= std::numeric_limits<boost::int16_t>::max())
				{
					con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT2").exec().throwIfError();
				}
				else if(amount <= std::numeric_limits<boost::int32_t>::max())
				{
					con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT4").exec().throwIfError();
				}
				else if(amount <= std::numeric_limits<boost::int64_t>::max())
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
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_size\" INT4").exec().throwIfError();
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

				static const size_t amount = r3::fields::Set<Domain>::amount;
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
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_size\" INT4").exec().throwIfError();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_blob\" OID").exec().throwIfError();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_width\" INT4").exec().throwIfError();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_height\" INT4").exec().throwIfError();
			}

			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(Category *c, CategoryBaseOrSelf *bos, void *stub, const char *fname)
			{
				//assert(!"������ ����");
				throw std::exception("����������� ��� ���� ��� ���������� ������� � �������");
			}
		};

		
		
		
		
		
		
		
		
		
		//////////////////////////////////////////////////////////////////////////
		struct enumOper_createIndex
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

			template <typename F>
			std::string sql2(F *stub, const char *fname)
			{
				std::string res = "\"_";
				res += fname;
				res += "_\"";
				return res;
			}

			template <>
			std::string sql2(r3::fields::Audio *stub, const char *fname)
			{
				std::string res = "\"_";
				res += fname;
				res += "_name\"";
				return res;
			}
			template <>
			std::string sql2(r3::fields::Image *stub, const char *fname)
			{
				std::string res = "\"_";
				res += fname;
				res += "_name\"";
				return res;
			}
			template <>
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
	}
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateFields()
	{
		if(!C::isAbstract)
		{
			//����������� ��� ������� � ����, ������� ��� ���� � �������� �� � �������
			((C*)this)->enumFieldsFromBasesAndSelf(impl::enumOper_createField());
		}
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateIndices()
	{
		if(!C::isAbstract)
		{
			//����������� ��� ������� � ����, ������� ��� ������� � �������� �� � �������
			((C*)this)->enumIndicesFromBasesAndSelf(impl::enumOper_createIndex());
		}
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateForeignFields()
	{
		if(!C::isAbstract)
		{
			//����������� ��� ������� � ����, ������� ��� ������� � �������� �� � �������
			//((C*)this)->enumRelationsFromBasesAndSelf(impl::enumOper_createForeignField());
		}
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateCrosses()
	{
		//assert(0);
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateForeignConstraints()
	{
		//assert(0);
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateViews()
	{
		//assert(0);
	}

}

#endif
