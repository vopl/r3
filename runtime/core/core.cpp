// core.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "fields/Field.h"

#include "soci.h"
#include "../backends/postgresql/soci-postgresql.h"

/*
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

int _tmain(int argc, _TCHAR* argv[])
{
	soci::session sql(soci::postgresql, "dbname=test user=postgres password=postgres");

	SOCI_VECTOR_TYPE<std::string> str(220);
	const int in=0;
	//sql<<"SELECT txt FROM myt WHERE id>:one", soci::into(str), soci::use(in, "one");


	soci::statement st = (sql.prepare<<"SELECT 'asdf'::varchar", soci::into(str));
	st.execute(true);

	sql.close();

	/*
	connection con("dbname=test user=postgres password=postgres");

	con.once<<"SELECT txt FROM myt WHERE id>$1" & use(in);
	stmt s = con.prep;

	s.sql("SELECT txt FROM myt WHERE id>$1");
	s.bind(str);
	s.exec();

	while(s.hasRow())
	{
		s.fetch(str);
		//use str
	}

	*/



	return 0;
}

