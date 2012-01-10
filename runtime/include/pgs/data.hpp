#ifndef _PGS_DATA_HPP_
#define _PGS_DATA_HPP_

#include <boost/shared_ptr.hpp>
#include "pgs/category.hpp"
#include "pgs/field.hpp"
#include "pgc/data.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class DataImpl;
	typedef boost::shared_ptr<DataImpl> DataImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class PG_API Data
		: public pgc::Data
	{
	protected:
		typedef DataImplPtr ImplPtr;

		friend class Statement;
		Data(ImplPtr impl);

	protected:
		bool fldIndex(size_t &res, const Field &fld);
		bool fldIndices(std::deque<size_t> &res, const Category &cat);

	public:

		using pgc::Data::fetch;
		using pgc::Data::fetchRowList;
		using pgc::Data::fetchRowMap;
		using pgc::Data::fetchRowsList;
		using pgc::Data::fetchRowsMap;
		using pgc::Data::fetchColumn;

		bool fetchRowList(utils::Variant &v, const pgs::Category &cat, size_t rowIdx=0);
		bool fetchRowMap(utils::Variant &v, const pgs::Category &cat, size_t rowIdx=0);
		bool fetchRowsList(utils::Variant &v, const pgs::Category &cat, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);
		bool fetchRowsMap(utils::Variant &v, const pgs::Category &cat, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);




		bool fetch(utils::Variant &v, const pgs::Field &fld, size_t rowIdx=0);
		bool fetchColumn(utils::Variant &v, const pgs::Field &fld, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);
	};
}
#endif
