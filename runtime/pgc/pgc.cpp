// pgc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


/*
//////////////////////////////////////////////////////////////////////////
struct MyTuple2;
struct MyTuple3;
struct MyTuple1
{
	SFId				_id;

	SFString			_name;
	SFEnum<MyScramble1>	_position;
	SFSet<MyScramble2>	_skills;
	SFFile				_resume;

	SFInt32				_age;

	SFMany<MyTuple1, MyTuple2>	_prevWorks;
	SFOne<MyTuple1, MyTuple3>		_curWork;

};

//////////////////////////////////////////////////////////////////////////
class MyCategory1
{
	typedef MyTuple Tuple;
	typedef boost::shared_ptr<Tuple> TuplePtr;

	typedef std::deque<TuplePtr> TATuples;

public:

	TuplePtr recCreate();
	TuplePtr recSelect(SFId id);
	void recSave(TuplePtr r);
	void recDrop(TuplePtr r);


	//TATuples recSelect1(param1, param2);

};

//////////////////////////////////////////////////////////////////////////
template <class TSchema>
class SchemaBase
{
	typedef TSchema Schema;

public:
	void dbInit();
	void dbCheck();
	void dbDrop();

	Category1 getCategory1();
	Category2 getCategory2();
	...

};

*/

int _tmain(int argc, _TCHAR* argv[])
{
	{

		pgc::Connection con;
		pgc::EConnectionStatus s = con.open("dbname=test user=postgres password=postgres port=5432");


		std::string str;

		try
		{
			{
				con.once("BEGIN").exec();
				pgc::Blob bl(con);
				bl.import("c:/temp/httrack.exe");
				pgc::Blob bl2;

				pgc::Result res = con.prep("SELECT $1::oid").exec(bl);

				res.fetch(0,0,bl2);
				bl2.export_("c:/temp/httrack.exe.2");



				con.once("COMMIT").exec();
			}

			//////////////////////////////////////////////////////////////////////////

			std::vector<unsigned char> in;
			in.resize(4);
			in[0] = '\0';
			in[1] = '1';
			in[2] = '2';
			in[3] = '3';

			std::string out;


			pgc::Statement stmt = con.prep("SELECT $1::bytea, $2::bytea").bind(in,1).bind(in,2);

			pgc::Result res = stmt.exec(in, in).throwIfError();
			bool b = res.fetch(0,1,out);
			if(!b)throw std::exception("fetch failed");
			std::cout<<out<<std::endl;

			con.ping();
			res = stmt.exec(in, in).throwIfError();
			b = res.fetch(0,1,out);
			if(!b)throw std::exception("fetch failed");
			std::cout<<out<<std::endl;

			res = stmt.exec(in, in).throwIfError();
			b = res.fetch(0,1,out);
			if(!b)throw std::exception("fetch failed");
			std::cout<<out<<std::endl;

			res = stmt.exec(in, in).throwIfError();
			b = res.fetch(0,1,out);
			if(!b)throw std::exception("fetch failed");
			std::cout<<out<<std::endl;

		}
		catch (pgc::Exception &e)
		{
			std::cout<<e.what()<<", "<<e.errorMsg()<<", "<<e.errorCode()<<", "<<e.status()<<std::endl;
		}
		catch (std::exception &e)
		{
			std::cout<<e.what()<<std::endl;
		}

		con.close();
	}
	//_CrtDumpMemoryLeaks();

	return 0;
}

