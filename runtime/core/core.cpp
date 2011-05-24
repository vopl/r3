// core.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "r3/model/schema_common.hpp"
#include "pgc/connection.hpp"

/*
	создавалка схемы
	репликатор
	гуй
*/

//////////////////////////////////////////////////////////////////////////
// class Category1Record
// {
// public:
// 	Id id;
// 
// 	String name;
// 	Timestamp birth;
// 
// 	Enum<MyScanty1>	someEnum;
// 
// 	RefN<Category2>	someReferenceN;
// 	Ref1<Category3>	someReference1;
// };
// 
// //////////////////////////////////////////////////////////////////////////
// class CategoryRecords
// {
// public:
// 
// 
// 
// };
// 
// //////////////////////////////////////////////////////////////////////////
// class Node
// {
// public:
// 	//crud
// 
// 	void insert_Category1(Category1Record, Comment);
// 	void update_Category1(Category1Record, Comment);
// 	void delete_Category1(id, Comment);
// 
// 	Category1Records select_Category1("name='%s' AND label LIKE '%220%' AND age=%d", ...);
// 	/*
// 		where
// 		order by
// 		limit offset
// 	*/
// 
// 
// 
// 	void test()
// 	{
// 		select_Category1(Category1.Where().name()==)
// 		Category1
// 	}
// 
// 
// 
// };
// 
// 
// //////////////////////////////////////////////////////////////////////////
// class DBManager
// {
// public:
// 	void connect(const char *connectionString);
// 	void disconnect();
// 
// 	bool createNode(const char *nid);
// 	bool dropNode(const char *nid);
// 
// 	Node getNode(const char *nid);
// };

// struct MyTuple
// {
// 	boost::int64_t			id;
// 	r3::fields::Date		birth;
// 	//r3::fields::Enum<Sex>	sex;
// 	r3::fields::Int64		year;
// 
// };
// 
// //////////////////////////////////////////////////////////////////////////
// class MyCategory1
// {
// 	typedef MyTuple Tuple;
// 	typedef boost::shared_ptr<Tuple> TuplePtr;
// 
// 	typedef std::deque<TuplePtr> TATuples;
// 
// 	pgc::Connection _con;
// 	pgc::Statement _selectById;
// 	pgc::Statement _insert;
// 	pgc::Statement _update;
// 	pgc::Statement _lastid;
// 
// public:
// 	MyCategory1(pgc::Connection con, const char *schema=NULL)
// 		: _con(con)
// 	{
// 		_selectById = _con.prep("SELECT id,birth,year FROM tratata WHERE id=$1");
// 		_insert = _con.prep("INSERT INTO tratata (birth,year) VALUES ($1,$2)");
// 		_update = _con.prep("UPDATE INTO tratata SET birth=$2,year=$3 WHERE id=$1");
// 		_lastid = _con.prep("SELECT lastval('tratata_id_seq'::regclass)");
// 	}
// 
// 	TuplePtr recSelect(boost::int64_t id)
// 	{
// 		pgc::Result res = _selectById.exec(id);
// 		if(!res.rows())
// 		{
// 			return TuplePtr();
// 		}
// 
// 		TuplePtr tupl(new Tuple);
// 
// 		res.fetch(0, 0, tupl->id);
// 		res.fetch(0, 1, tupl->birth.value());
// 		res.fetch(0, 2, tupl->year.value());
// 		return tupl;
// 	}
// 	void recSave(TuplePtr r)
// 	{
// 		pgc::Result res;
// 		if(r->id)
// 		{
// 			res = _update.exec(r->id, r->birth.value(), r->year.value());
// 		}
// 		else
// 		{
// 			res = _insert.exec(r->birth.value(), r->year.value());
// 			_lastid.exec().fetch(0,0,r->id);
// 		}
// 	}
// 	void recDrop(TuplePtr r)
// 	{
// 		//аналогично
// 	}
// 
// 
// 	//TATuples recSelect1(param1, param2);
// 
// };

int _tmain(int argc, _TCHAR* argv[])
{

// 	std::cout<<sizeof(r3::fields::Date)<<std::endl;
// 	std::cout<<sizeof(r3::fields::Int64)<<std::endl;

	r3::model::Schema_common_ptr s(new r3::model::Schema_common("myId"));

	pgc::Connection con;
	con.open("dbname=test user=postgres password=postgres port=5432");
	s->attach(con);
	return 0;
}

