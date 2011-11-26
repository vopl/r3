#ifndef _PGS_IMPL_RESULT_HPP_
#define _PGS_IMPL_RESULT_HPP_

#include "../pgc/resultImpl.hpp"
#include "fieldImpl.hpp"
#include "categoryImpl.hpp"

namespace pgs
{
	class StatementImpl;
	typedef boost::shared_ptr<StatementImpl> StatementImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class ResultImpl
		: public pgc::ResultImpl
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
