#ifndef _PGC_DATAIMPL_HPP_
#define _PGC_DATAIMPL_HPP_

#include <boost/enable_shared_from_this.hpp>
#include "connectionImpl.hpp"

namespace pgc
{
	using namespace boost;
	using namespace utils;

	class DataImpl
		: public enable_shared_from_this<DataImpl>
	{
		PGresult *_pgr;
		ConnectionHolderPtr _con;
	public:
		DataImpl(PGresult *pgr, ConnectionHolderPtr con);
		~DataImpl();

		EDataStatus status();
		const char *errorMsg();
		const char *errorCode();

		size_t cmdRows();

		size_t rows();
		size_t cols();

		size_t colIdx(const char *colName);
		const char *colName(size_t colIdx);

		bool isNull(size_t colIdx, size_t rowIdx);
		Variant::EType colType(size_t colIdx);

		bool fetch(Variant &v, size_t colIdx, size_t rowIdx);

		//////////////////////////////////////////////////////////////////////////
		bool fetchRowList(Variant &v, size_t rowIdx=0);
		bool fetchRowMap(Variant &v, size_t rowIdx=0);

		bool fetchRowsList(Variant &v, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);
		bool fetchRowsMap(Variant &v, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		//////////////////////////////////////////////////////////////////////////
		bool fetchRowList(Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx=0);
		bool fetchRowMap(Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx=0);

		bool fetchRowsList(Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);
		bool fetchRowsMap(Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		bool fetchColumn(Variant &v, size_t colIdx, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		//////////////////////////////////////////////////////////////////////////
		boost::int32_t fetchInt32(size_t colIdx, size_t rowIdx);
		boost::uint32_t fetchUInt32(size_t colIdx, size_t rowIdx);
		std::string fetchString(size_t colIdx, size_t rowIdx);

	private:
		//////////////////////////////////////////////////////////////////////////
		template <class SequenceVariant>
		bool fetchRowList_(SequenceVariant &v, size_t rowIdx=0);

		bool fetchRowMap_(utils::Variant::MapStringVariant &v, size_t rowIdx=0);

		template <class SequenceVariant>
		bool fetchRowsList_(SequenceVariant &v, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		template <class SequenceVariant>
		bool fetchRowsMap_(SequenceVariant &v, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		//////////////////////////////////////////////////////////////////////////
		template <class SequenceVariant>
		bool fetchRowList_(SequenceVariant &v, const std::deque<size_t> &colIndices, size_t rowIdx=0);

		bool fetchRowMap_(utils::Variant::MapStringVariant &v, const std::deque<size_t> &colIndices, size_t rowIdx=0);

		template <class SequenceVariant>
		bool fetchRowsList_(SequenceVariant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		template <class SequenceVariant>
		bool fetchRowsMap_(SequenceVariant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		template <class SequenceVariant>
		bool fetchColumn_(SequenceVariant &v, size_t colIdx, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

	};
}

#endif

