#ifndef _PGS_RESULT_HPP_
#define _PGS_RESULT_HPP_

#include <boost/shared_ptr.hpp>
#include "pgs/category.hpp"
#include "pgs/field.hpp"
#include "pgc/result.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class ResultImpl;
	typedef boost::shared_ptr<ResultImpl> ResultImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class PG_API Result
		: public pgc::Result
	{
	protected:
		typedef ResultImplPtr ImplPtr;

		friend class Statement;
		Result(ImplPtr impl);

	protected:
		bool fldIndex(size_t &res, const Field &fld);
		bool fldIndices(std::deque<size_t> &res, const Category &cat);

	public:

		using pgc::Result::fetch;
		using pgc::Result::fetchRowList;
		using pgc::Result::fetchRowMap;
		using pgc::Result::fetchRowsList;
		using pgc::Result::fetchRowsMap;
		using pgc::Result::fetchColumn;

		bool fetchRowList(utils::Variant &v, const pgs::Category &cat, size_t rowIdx=0);
		bool fetchRowMap(utils::Variant &v, const pgs::Category &cat, size_t rowIdx=0);
		bool fetchRowsList(utils::Variant &v, const pgs::Category &cat, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);
		bool fetchRowsMap(utils::Variant &v, const pgs::Category &cat, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);




		bool fetch(utils::Variant &v, const pgs::Field &fld, size_t rowIdx=0);
		bool fetchColumn(utils::Variant &v, const pgs::Field &fld, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);
	};
}
#endif
