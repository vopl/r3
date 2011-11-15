#ifndef _PGS_IMPL_RESULT_HPP_
#define _PGS_IMPL_RESULT_HPP_

#include "../pgc/resultImpl.hpp"
#include "fieldImpl.hpp"
#include "categoryImpl.hpp"

namespace pgs
{
	class StatementImpl;
	typedef boost::shared_ptr<StatementImpl> StatementImpl_ptr;

	//////////////////////////////////////////////////////////////////////////
	class ResultImpl
		: public pgc::ResultImpl
	{
		pgs::StatementImpl_ptr _stm;

	public:
		ResultImpl(const StatementImpl_ptr &stm, PGresult *pgres);

		bool fldIndex(size_t &res, const FieldImpl_ptr &fld);
		bool fldIndices(std::deque<size_t> &res, const CategoryImpl_ptr &cat);

	};
	typedef boost::shared_ptr<ResultImpl> ResultImpl_ptr;
}

#endif
