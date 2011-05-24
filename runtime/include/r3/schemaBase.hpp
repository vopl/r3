#ifndef _R3_SCHEMABASE_HPP_
#define _R3_SCHEMABASE_HPP_

#include "pgc/connection.hpp"

namespace r3
{
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

		void attach(pgc::Connection con);
	};

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
	void SchemaBase<S>::attach(pgc::Connection con)
	{
		_con = con;
	}

}
#endif
