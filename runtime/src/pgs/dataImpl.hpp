#ifndef _PGS_RESULTIMPL_HPP_
#define _PGS_RESULTIMPL_HPP_

#include "fieldImpl.hpp"
#include "categoryImpl.hpp"

namespace pgs
{
	class StatementImpl;
	typedef boost::shared_ptr<StatementImpl> StatementImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class ResultImpl
	{
		pgs::StatementImplPtr _stm;

	public:
		ResultImpl(const StatementImplPtr &stm, PGresult *pgres);

		bool fldIndex(size_t &res, const FieldImplPtr &fld);
		bool fldIndices(std::deque<size_t> &res, const CategoryImplPtr &cat);

	};
	typedef boost::shared_ptr<ResultImpl> ResultImplPtr;
}

#endif
