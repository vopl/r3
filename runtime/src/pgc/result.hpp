#ifndef _PGC_RESULT_HPP_
#define _PGC_RESULT_HPP_

#include "pgc/iresult.hpp"
#include <boost/enable_shared_from_this.hpp>
#include "pgconnWrapper.hpp"

namespace pgc
{
	using namespace boost;
	using namespace utils;

	class Result
		: public IResult
		, public enable_shared_from_this<Result>
	{
		PGresult *_pgr;
		PGconnWrapperPtr _con;

		typedef bool (Result::*MExtractor)(int rowIdx, int colIdx, Variant::EType typCpp, void *valCpp);

		struct Extractor
		{
			MExtractor				_meth;
			Variant::EType	_favorType;
		};

		typedef std::vector<Extractor> TVExtractors;
		TVExtractors	_extractors;

		bool extractor_int2			(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp);
		bool extractor_int4			(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp);
		bool extractor_int8			(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp);
		bool extractor_numeric		(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp);
		bool extractor_float4		(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp);
		bool extractor_float8		(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp);
		bool extractor_money		(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp);
		bool extractor_varchar		(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp);
		bool extractor_bytea		(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp);
		bool extractor_timestamp	(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp);
		bool extractor_interval		(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp);
		bool extractor_date			(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp);
		bool extractor_time			(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp);
		bool extractor_bool			(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp);
		bool extractor_varbit		(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp);
		bool extractor_oid			(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp);
		bool extractor_null			(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp);

		void initExtractors();
	public:
		Result(PGresult *pgr, PGconnWrapperPtr con);
		~Result();

		virtual EExecStatus status();
		virtual const char *errorMsg();
		virtual const char *errorCode();

		virtual size_t cmdRows();

		virtual size_t rows();
		virtual size_t cols();

		virtual size_t colIdx(const char *colName);
		virtual const char *colName(size_t colIdx);

		virtual bool isNull(size_t colIdx, size_t rowIdx);
		virtual Variant::EType colType(size_t colIdx);

		virtual bool fetch(Variant &v, size_t colIdx, size_t rowIdx);

		//////////////////////////////////////////////////////////////////////////
		virtual bool fetchRowList(Variant &v, size_t rowIdx=0);
		virtual bool fetchRowMap(Variant &v, size_t rowIdx=0);

		virtual bool fetchRowsList(Variant &v, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);
		virtual bool fetchRowsMap(Variant &v, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		//////////////////////////////////////////////////////////////////////////
		virtual bool fetchRowList(Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx=0);
		virtual bool fetchRowMap(Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx=0);

		virtual bool fetchRowsList(Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);
		virtual bool fetchRowsMap(Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		virtual bool fetchColumn(Variant &v, size_t colIdx, size_t rowBeginIdx=0, size_t rowEndIdx=(size_t)-1);

		//////////////////////////////////////////////////////////////////////////
		virtual boost::int32_t fetchInt32(size_t colIdx, size_t rowIdx);
		virtual boost::uint32_t fetchUInt32(size_t colIdx, size_t rowIdx);
		virtual std::string fetchString(size_t colIdx, size_t rowIdx);

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

