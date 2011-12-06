#include "pch.h"
#include "result.hpp"
#include <libpq-fe.h>
#include "utils/aton.hpp"

namespace pgc
{
	using namespace utils;



	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchRowList_(SequenceVariant &v, size_t rowIdx)
	{
		size_t columns = this->cols();
		v.resize(columns);

		SequenceVariant::iterator iter = v.begin();
		for(size_t colIdx(0); colIdx<columns; colIdx++)
		{
			utils::Variant &rv = *iter;
			if(!fetch(rv, colIdx, rowIdx))
			{
				return false;
			}
			iter++;
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowMap_(utils::Variant::MapStringVariant &v, size_t rowIdx)
	{
		size_t columns = Result::cols();
		v.clear();

		for(size_t colIdx(0); colIdx<columns; colIdx++)
		{
			if(!fetch(v[colName(colIdx)], colIdx, rowIdx))
			{
				return false;
			}
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchRowsList_(SequenceVariant &v, size_t rowBeginIdx, size_t rowEndIdx)
	{
		size_t rows = this->rows();
		if(rowEndIdx > rows) 
		{
			rowEndIdx = rows;
		}

		if(rowBeginIdx>=rowEndIdx)
		{
			v.clear();
			return true;
		}

		v.resize(rowEndIdx - rowBeginIdx);
		SequenceVariant::iterator iter = v.begin();
		for(size_t rowIdx(rowBeginIdx); rowIdx<rowEndIdx; rowIdx++)
		{
			utils::Variant &rv = *iter;
			if(!fetchRowList_(rv.as<SequenceVariant>(true), rowIdx))
			{
				return false;
			}
			iter++;
		}
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchRowsMap_(SequenceVariant &v, size_t rowBeginIdx, size_t rowEndIdx)
	{
		size_t rows = this->rows();
		if(rowEndIdx > rows)
		{
			rowEndIdx = rows;
		}

		if(rowBeginIdx>=rowEndIdx)
		{
			v.clear();
			return true;
		}

		v.resize(rowEndIdx - rowBeginIdx);
		SequenceVariant::iterator iter = v.begin();
		for(size_t rowIdx(rowBeginIdx); rowIdx<rowEndIdx; rowIdx++)
		{
			utils::Variant &rv = *iter;
			if(!fetchRowMap_(rv.as<utils::Variant::MapStringVariant>(true), rowIdx))
			{
				return false;
			}
			iter++;
		}
		return true;
	}












	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchRowList_(SequenceVariant &v, const std::deque<size_t> &colIndices, size_t rowIdx)
	{
		size_t columns = colIndices.size();
		v.resize(columns);

		SequenceVariant::iterator iter = v.begin();
		for(size_t colIdx(0); colIdx<columns; colIdx++)
		{
			assert(colIndices[colIdx] < Result::cols());
			utils::Variant &rv = *iter;
			if(!fetch(rv, colIndices[colIdx], rowIdx))
			{
				return false;
			}
			iter++;
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowMap_(utils::Variant::MapStringVariant &v, const std::deque<size_t> &colIndices, size_t rowIdx)
	{
		size_t columns = colIndices.size();
		v.clear();

		for(size_t colIdx(0); colIdx<columns; colIdx++)
		{
			assert(colIndices[colIdx] < Result::cols());
			if(!fetch(v[colName(colIndices[colIdx])], colIndices[colIdx], rowIdx))
			{
				return false;
			}
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchRowsList_(SequenceVariant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx, size_t rowEndIdx)
	{
		size_t rows = this->rows();
		if(rowEndIdx > rows) 
		{
			rowEndIdx = rows;
		}

		if(rowBeginIdx>=rowEndIdx)
		{
			v.clear();
			return true;
		}

		v.resize(rowEndIdx - rowBeginIdx);
		SequenceVariant::iterator iter = v.begin();
		for(size_t rowIdx(rowBeginIdx); rowIdx<rowEndIdx; rowIdx++)
		{
			utils::Variant &rv = *iter;
			if(!fetchRowList_(rv.as<SequenceVariant>(true), colIndices, rowIdx))
			{
				return false;
			}
			iter++;
		}
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchRowsMap_(SequenceVariant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx, size_t rowEndIdx)
	{
		size_t rows = this->rows();
		if(rowEndIdx > rows)
		{
			rowEndIdx = rows;
		}

		if(rowBeginIdx>=rowEndIdx)
		{
			v.clear();
			return true;
		}

		v.resize(rowEndIdx - rowBeginIdx);
		SequenceVariant::iterator iter = v.begin();
		for(size_t rowIdx(rowBeginIdx); rowIdx<rowEndIdx; rowIdx++)
		{
			utils::Variant &rv = *iter;
			if(!fetchRowMap_(rv.as<utils::Variant::MapStringVariant>(true), colIndices, rowIdx))
			{
				return false;
			}
			iter++;
		}
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class SequenceVariant>
	bool Result::fetchColumn_(SequenceVariant &v, size_t colIdx, size_t rowBeginIdx, size_t rowEndIdx)
	{
		size_t rows = this->rows();
		if(rowEndIdx > rows)
		{
			rowEndIdx = rows;
		}

		if(rowBeginIdx>=rowEndIdx)
		{
			v.clear();
			return true;
		}

		v.resize(rowEndIdx - rowBeginIdx);
		SequenceVariant::iterator iter = v.begin();
		for(size_t rowIdx(rowBeginIdx); rowIdx<rowEndIdx; rowIdx++)
		{
			utils::Variant &rv = *iter;
			if(!fetch(rv, colIdx, rowIdx))
			{
				return false;
			}
			iter++;
		}
		return true;
	}


	//////////////////////////////////////////////////////////////////////////
	void Result::initExtractors()
	{
		if(_pgr)
		{
			int cols = PQnfields(_pgr);
			_extractors.resize(cols);

			for(int colIdx(0); colIdx<cols; colIdx++)
			{
				Oid typDb = PQftype(_pgr, colIdx);

				switch(typDb)
				{
				case 21://int2
					_extractors[colIdx]._meth = &Result::extractor_int2;
					_extractors[colIdx]._favorType = Variant::Type2Enum<boost::int16_t>::et;
					break;
				case 23://int4
					_extractors[colIdx]._meth = &Result::extractor_int4;
					_extractors[colIdx]._favorType = Variant::Type2Enum<boost::int32_t>::et;
					break;
				case 20://int8
					_extractors[colIdx]._meth = &Result::extractor_int8;
					_extractors[colIdx]._favorType = Variant::Type2Enum<boost::int64_t>::et;
					break;
				case 1700://numeric
					_extractors[colIdx]._meth = &Result::extractor_numeric;
					_extractors[colIdx]._favorType = Variant::Type2Enum<std::string>::et;
					break;
				case 700://float4
					_extractors[colIdx]._meth = &Result::extractor_float4;
					_extractors[colIdx]._favorType = Variant::Type2Enum<float>::et;
					break;
				case 701://float8
					_extractors[colIdx]._meth = &Result::extractor_float8;
					_extractors[colIdx]._favorType = Variant::Type2Enum<double>::et;
					break;
				case 790://money
					_extractors[colIdx]._meth = &Result::extractor_money;
					_extractors[colIdx]._favorType = Variant::Type2Enum<boost::uint64_t>::et;
					break;
				case 1043://varchar
				case 1042://bpchar
				case 25://text
					_extractors[colIdx]._meth = &Result::extractor_varchar;
					_extractors[colIdx]._favorType = Variant::Type2Enum<std::string>::et;
					break;
				case 17://bytea
					_extractors[colIdx]._meth = &Result::extractor_bytea;
					_extractors[colIdx]._favorType = Variant::Type2Enum<std::string>::et;
					break;
				case 1114://timestamp
				case 1184://timestamptz
					_extractors[colIdx]._meth = &Result::extractor_timestamp;
					_extractors[colIdx]._favorType = Variant::Type2Enum<boost::posix_time::ptime>::et;
					break;
				case 1186://interval
					_extractors[colIdx]._meth = &Result::extractor_interval;
					_extractors[colIdx]._favorType = Variant::Type2Enum<boost::posix_time::time_duration>::et;
					break;
				case 1082://date
					_extractors[colIdx]._meth = &Result::extractor_date;
					_extractors[colIdx]._favorType = Variant::Type2Enum<boost::gregorian::date>::et;
					break;
				case 1083://time
				case 1266://timetz
					_extractors[colIdx]._meth = &Result::extractor_time;
					_extractors[colIdx]._favorType = Variant::Type2Enum<boost::posix_time::time_duration>::et;
					break;
				case 16://bool
					_extractors[colIdx]._meth = &Result::extractor_bool;
					_extractors[colIdx]._favorType = Variant::Type2Enum<bool>::et;
					break;
				case 1560://bit
				case 1562://varbit
					_extractors[colIdx]._meth = &Result::extractor_varbit;
					_extractors[colIdx]._favorType = Variant::Type2Enum<std::string>::et;
					break;
				case 26://oid
					_extractors[colIdx]._meth = &Result::extractor_oid;
					_extractors[colIdx]._favorType = Variant::Type2Enum<boost::uint32_t>::et;
					break;
				default:
					_extractors[colIdx]._meth = &Result::extractor_null;
					_extractors[colIdx]._favorType = Variant::Type2Enum<std::string>::et;
				}
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	Result::Result(PGresult *pgr, PGconnWrapperPtr con)
		: _pgr(pgr)
		, _con(con)
	{
		initExtractors();
	}

	//////////////////////////////////////////////////////////////////////////
	Result::~Result()
	{
		PQclear(_pgr);
	}

	//////////////////////////////////////////////////////////////////////////
	EExecStatus Result::status()
	{
		if(_pgr)
		{
			switch(PQresultStatus(_pgr))
			{
			case PGRES_EMPTY_QUERY:
			case PGRES_COMMAND_OK:
				return eesCommandOk;
			case PGRES_TUPLES_OK:
				return eesTuplesOk;
			}
		}
		return eesError;
	}

	//////////////////////////////////////////////////////////////////////////
	const char *Result::errorMsg()
	{
		if(_pgr)
		{
			const char *res = PQresultErrorMessage(_pgr);
			return res?res:"";
		}
		return "null result";
	}

	//////////////////////////////////////////////////////////////////////////
	const char *Result::errorCode()
	{
		if(_pgr)
		{
			const char *res = PQresultErrorField(_pgr, PG_DIAG_SQLSTATE);
			return res?res:"";
		}
		return "null result";
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Result::cmdRows()
	{
		if(_pgr)
		{
			return _atost(PQcmdTuples(_pgr));
		}
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Result::rows()
	{
		if(_pgr)
		{
			return (size_t)PQntuples(_pgr);
		}
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Result::cols()
	{
		if(_pgr)
		{
			return (size_t)PQnfields(_pgr);
		}
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Result::colIdx(const char *colName)
	{
		if(_pgr)
		{
			return (size_t)PQfnumber(_pgr, colName);
		}
		return (size_t)-1;
	}

	//////////////////////////////////////////////////////////////////////////
	const char *Result::colName(size_t colIdx)
	{
		if(_pgr)
		{
			return PQfname(_pgr, (int)colIdx);
		}
		return NULL;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::isNull(size_t colIdx, size_t rowIdx)
	{
		if(_pgr)
		{
			return PQgetisnull(_pgr, (int)rowIdx, (int)colIdx)?true:false;
		}
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	Variant::EType Result::colType(size_t colIdx)
	{
		if(!_pgr)
		{
			return Variant::etUnknown;
		}

		if(colIdx >= (int)_extractors.size())
		{
			return Variant::etUnknown;
		}

		assert(1 == PQfformat(_pgr, colIdx));
		return _extractors[colIdx]._favorType;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetch(Variant &v, size_t colIdx, size_t rowIdx)
	{
		if(!_pgr)
		{
			return false;
		}

		if(colIdx >= (int)_extractors.size())
		{
			return false;
		}

		assert(1 == PQfformat(_pgr, colIdx));

		switch(v.type())
		{
		case Variant::etUnknown:
		case Variant::etVoid:
			v.forceType(_extractors[colIdx]._favorType);
			break;
		}
		if(PQgetisnull(_pgr, (int)rowIdx, (int)colIdx))
		{
			v.setNull();
			return true;
		}
		v.setNull(false);
		return (this->*_extractors[colIdx]._meth)(colIdx, rowIdx, v.type(), v.data());
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowList(Variant &v, size_t rowIdx)
	{
		if(!_pgr)
		{
			return false;
		}

		switch(v.type())
		{
		case Variant::etDequeVariant:
			return fetchRowList_(v.as<Variant::DequeVariant>(), rowIdx);
		case Variant::etListVariant:
			return fetchRowList_(v.as<Variant::ListVariant>(), rowIdx);
		case Variant::etVectorVariant:
			return fetchRowList_(v.as<Variant::VectorVariant>(), rowIdx);
		}
		return fetchRowList_(v.as<Variant::DequeVariant>(true), rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowMap(Variant &v, size_t rowIdx)
	{
		if(!_pgr)
		{
			return false;
		}

		return fetchRowMap_(v.as<Variant::MapStringVariant>(true), rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowsList(Variant &v, size_t rowBeginIdx, size_t rowEndIdx)
	{
		if(!_pgr)
		{
			return false;
		}

		switch(v.type())
		{
		case Variant::etDequeVariant:
			return fetchRowsList_(v.as<Variant::DequeVariant>(), rowBeginIdx, rowEndIdx);
		case Variant::etListVariant:
			return fetchRowsList_(v.as<Variant::ListVariant>(), rowBeginIdx, rowEndIdx);
		case Variant::etVectorVariant:
			return fetchRowsList_(v.as<Variant::VectorVariant>(), rowBeginIdx, rowEndIdx);
		}
		return fetchRowsList_(v.as<Variant::DequeVariant>(true), rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowsMap(Variant &v, size_t rowBeginIdx, size_t rowEndIdx)
	{
		if(!_pgr)
		{
			return false;
		}

		switch(v.type())
		{
		case Variant::etDequeVariant:
			return fetchRowsMap_(v.as<Variant::DequeVariant>(), rowBeginIdx, rowEndIdx);
		case Variant::etListVariant:
			return fetchRowsMap_(v.as<Variant::ListVariant>(), rowBeginIdx, rowEndIdx);
		case Variant::etVectorVariant:
			return fetchRowsMap_(v.as<Variant::VectorVariant>(), rowBeginIdx, rowEndIdx);
		}
		return fetchRowsMap_(v.as<Variant::DequeVariant>(true), rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowList(Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx)
	{
		if(!_pgr)
		{
			return false;
		}

		switch(v.type())
		{
		case Variant::etDequeVariant:
			return fetchRowList_(v.as<Variant::DequeVariant>(), colIndices, rowIdx);
		case Variant::etListVariant:
			return fetchRowList_(v.as<Variant::ListVariant>(), colIndices, rowIdx);
		case Variant::etVectorVariant:
			return fetchRowList_(v.as<Variant::VectorVariant>(), colIndices, rowIdx);
		}
		return fetchRowList_(v.as<Variant::DequeVariant>(true), colIndices, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowMap(Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx)
	{
		if(!_pgr)
		{
			return false;
		}

		return fetchRowMap_(v.as<Variant::MapStringVariant>(true), colIndices, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowsList(Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx, size_t rowEndIdx)
	{
		if(!_pgr)
		{
			return false;
		}

		switch(v.type())
		{
		case Variant::etDequeVariant:
			return fetchRowsList_(v.as<Variant::DequeVariant>(), colIndices, rowBeginIdx, rowEndIdx);
		case Variant::etListVariant:
			return fetchRowsList_(v.as<Variant::ListVariant>(), colIndices, rowBeginIdx, rowEndIdx);
		case Variant::etVectorVariant:
			return fetchRowsList_(v.as<Variant::VectorVariant>(), colIndices, rowBeginIdx, rowEndIdx);
		}
		return fetchRowsList_(v.as<Variant::DequeVariant>(true), colIndices, rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowsMap(Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx, size_t rowEndIdx)
	{
		if(!_pgr)
		{
			return false;
		}

		switch(v.type())
		{
		case Variant::etDequeVariant:
			return fetchRowsMap_(v.as<Variant::DequeVariant>(), colIndices, rowBeginIdx, rowEndIdx);
		case Variant::etListVariant:
			return fetchRowsMap_(v.as<Variant::ListVariant>(), colIndices, rowBeginIdx, rowEndIdx);
		case Variant::etVectorVariant:
			return fetchRowsMap_(v.as<Variant::VectorVariant>(), colIndices, rowBeginIdx, rowEndIdx);
		}
		return fetchRowsMap_(v.as<Variant::DequeVariant>(true), colIndices, rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchColumn(Variant &v, size_t colIdx, size_t rowBeginIdx, size_t rowEndIdx)
	{
		if(!_pgr)
		{
			return false;
		}

		switch(v.type())
		{
		case Variant::etDequeVariant:
			return fetchColumn_(v.as<Variant::DequeVariant>(), rowBeginIdx, rowEndIdx);
		case Variant::etListVariant:
			return fetchColumn_(v.as<Variant::ListVariant>(), rowBeginIdx, rowEndIdx);
		case Variant::etVectorVariant:
			return fetchColumn_(v.as<Variant::VectorVariant>(), rowBeginIdx, rowEndIdx);
		}
		return fetchColumn_(v.as<Variant::DequeVariant>(true), rowBeginIdx, rowEndIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	boost::int32_t Result::fetchInt32(size_t colIdx, size_t rowIdx)
	{
		Variant v;
		v.as<boost::int32_t>(true);
		if(!fetch(v, colIdx, rowIdx))
		{
			return 0;
		}
		return v.as<boost::int32_t>();
	}

	//////////////////////////////////////////////////////////////////////////
	boost::uint32_t Result::fetchUInt32(size_t colIdx, size_t rowIdx)
	{
		Variant v;
		v.as<boost::uint32_t>(true);
		if(!fetch(v, colIdx, rowIdx))
		{
			return 0;
		}
		return v.as<boost::uint32_t>();
	}

	//////////////////////////////////////////////////////////////////////////
	std::string Result::fetchString(size_t colIdx, size_t rowIdx)
	{
		Variant v;
		v.as<std::string>(true);
		if(!fetch(v, colIdx, rowIdx))
		{
			return 0;
		}
		return v.as<std::string>();
	}

}
