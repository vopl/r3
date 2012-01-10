#ifndef _PGS_DATAIMPL_HPP_
#define _PGS_DATAIMPL_HPP_

#include "fieldImpl.hpp"
#include "categoryImpl.hpp"
#include "pgc/dataImpl.hpp"

namespace pgs
{
	class StatementImpl;
	typedef boost::shared_ptr<StatementImpl> StatementImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class DataImpl
		: pgc::DataImpl
	{
		typedef std::map<std::string, size_t>	TMName2idx;
		TMName2idx _fetchName2idx;
		ClusterImplPtr _cluster;


	public:
		DataImpl(	PGresult *pgres, 
					bool integerDatetime,
					ClusterImplPtr cluster,
					const TMName2idx &fetchName2idx);

		bool fldIndex(size_t &res, const std::string &name);
		bool fldIndex(size_t &res, const FieldImplPtr &fld);
		bool fldIndices(std::deque<size_t> &res, const CategoryImplPtr &cat);

	};
	typedef boost::shared_ptr<DataImpl> DataImplPtr;
}

#endif
