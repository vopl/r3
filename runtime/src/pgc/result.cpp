#include "pch.h"
#include "result.hpp"
#include <libpq-fe.h>
#include "utils/aton.hpp"
#include "utils/fixEndian.hpp"
#include "utils/julian.h"
#include "pgDataType.h"

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


// 	//////////////////////////////////////////////////////////////////////////
// 	void Result::initExtractors()
// 	{
// 		int cols = PQnfields(_pgr);
// 		_extractors.resize(cols);
// 
// 		for(int colIdx(0); colIdx<cols; colIdx++)
// 		{
// 			Oid typDb = PQftype(_pgr, colIdx);
// 
// 			switch(typDb)
// 			{
// 			case 21://int2
// 				_extractors[colIdx]._meth = &Result::extractor_int2;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<boost::int16_t>::et;
// 				break;
// 			case 23://int4
// 				_extractors[colIdx]._meth = &Result::extractor_int4;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<boost::int32_t>::et;
// 				break;
// 			case 20://int8
// 				_extractors[colIdx]._meth = &Result::extractor_int8;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<boost::int64_t>::et;
// 				break;
// 			case 1700://numeric
// 				_extractors[colIdx]._meth = &Result::extractor_numeric;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<std::string>::et;
// 				break;
// 			case 700://float4
// 				_extractors[colIdx]._meth = &Result::extractor_float4;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<float>::et;
// 				break;
// 			case 701://float8
// 				_extractors[colIdx]._meth = &Result::extractor_float8;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<double>::et;
// 				break;
// 			case 790://money
// 				_extractors[colIdx]._meth = &Result::extractor_money;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<boost::uint64_t>::et;
// 				break;
// 			case 1043://varchar
// 			case 1042://bpchar
// 			case 25://text
// 				_extractors[colIdx]._meth = &Result::extractor_varchar;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<std::string>::et;
// 				break;
// 			case 17://bytea
// 				_extractors[colIdx]._meth = &Result::extractor_bytea;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<std::string>::et;
// 				break;
// 			case 1114://timestamp
// 			case 1184://timestamptz
// 				_extractors[colIdx]._meth = &Result::extractor_timestamp;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<boost::posix_time::ptime>::et;
// 				break;
// 			case 1186://interval
// 				_extractors[colIdx]._meth = &Result::extractor_interval;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<boost::posix_time::time_duration>::et;
// 				break;
// 			case 1082://date
// 				_extractors[colIdx]._meth = &Result::extractor_date;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<boost::gregorian::date>::et;
// 				break;
// 			case 1083://time
// 			case 1266://timetz
// 				_extractors[colIdx]._meth = &Result::extractor_time;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<boost::posix_time::time_duration>::et;
// 				break;
// 			case 16://bool
// 				_extractors[colIdx]._meth = &Result::extractor_bool;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<bool>::et;
// 				break;
// 			case 1560://bit
// 			case 1562://varbit
// 				_extractors[colIdx]._meth = &Result::extractor_varbit;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<std::string>::et;
// 				break;
// 			case 26://oid
// 				_extractors[colIdx]._meth = &Result::extractor_oid;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<boost::uint32_t>::et;
// 				break;
// 			case 2950://uuid
// 				_extractors[colIdx]._meth = &Result::extractor_uuid;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<boost::uuids::uuid>::et;
// 				break;
// 			case 18://char
// 				_extractors[colIdx]._meth = &Result::extractor_char;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<char>::et;
// 				break;
// 			default:
// 				_extractors[colIdx]._meth = &Result::extractor_null;
// 				_extractors[colIdx]._favorType = Variant::Type2Enum<std::string>::et;
// 			}
// 		}
// 	}

	//////////////////////////////////////////////////////////////////////////
	Result::Result(PGresult *pgr, ConnectionImplPtr con)
		: _pgr(pgr)
		, _con(con)
	{
		assert(_pgr);
	}

	//////////////////////////////////////////////////////////////////////////
	Result::~Result()
	{
		PQclear(_pgr);
	}

	//////////////////////////////////////////////////////////////////////////
	EResultStatus Result::status()
	{
		switch(PQresultStatus(_pgr))
		{
		case PGRES_EMPTY_QUERY:
		case PGRES_COMMAND_OK:
			return ersCommandOk;
		case PGRES_TUPLES_OK:
			return ersTuplesOk;
		}
		return ersError;
	}

	//////////////////////////////////////////////////////////////////////////
	const char *Result::errorMsg()
	{
		const char *res = PQresultErrorMessage(_pgr);
		return res?res:"";
	}

	//////////////////////////////////////////////////////////////////////////
	const char *Result::errorCode()
	{
		const char *res = PQresultErrorField(_pgr, PG_DIAG_SQLSTATE);
		return res?res:"";
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Result::cmdRows()
	{
		return _atost(PQcmdTuples(_pgr));
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Result::rows()
	{
		return (size_t)PQntuples(_pgr);
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Result::cols()
	{
		return (size_t)PQnfields(_pgr);
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Result::colIdx(const char *colName)
	{
		return (size_t)PQfnumber(_pgr, colName);
	}

	//////////////////////////////////////////////////////////////////////////
	const char *Result::colName(size_t colIdx)
	{
		return PQfname(_pgr, (int)colIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::isNull(size_t colIdx, size_t rowIdx)
	{
		return PQgetisnull(_pgr, (int)rowIdx, (int)colIdx)?true:false;
	}

	//////////////////////////////////////////////////////////////////////////
	Variant::EType Result::colType(size_t colIdx)
	{
		if(colIdx >= (size_t)PQnfields(_pgr))
		{
			return Variant::etUnknown;
		}

		assert(1 == PQfformat(_pgr, colIdx));
		switch(PQftype(_pgr, colIdx))
		{
		case 21://int2
			return Variant::etInt16;
			break;
		case 23://int4
			return Variant::etInt32;
			break;
		case 20://int8
			return Variant::etInt64;
			break;
		case 1700://numeric
			return Variant::etString;
			break;
		case 700://float4
			return Variant::etFloat;
			break;
		case 701://float8
			return Variant::etDouble;
			break;
		case 790://money
			return Variant::etInt64;
			break;
		case 1043://varchar
		case 1042://bpchar
		case 25://text
			return Variant::etString;
			break;
		case 17://bytea
			return Variant::etVectorChar;
			break;
		case 1114://timestamp
		case 1184://timestamptz
			return Variant::etDatetime;
			break;
		case 1186://interval
			return Variant::etDateTimeDuration;
			break;
		case 1082://date
			return Variant::etDate;
			break;
		case 1083://time
		case 1266://timetz
			return Variant::etTimeDuration;
			break;
		case 16://bool
			return Variant::etBool;
			break;
		case 1560://bit
		case 1562://varbit
			return Variant::etBitset8;
			break;
		case 26://oid
			return Variant::etInt32;
			break;
		case 2950://uuid
			return Variant::etUuid;
			break;
		case 18://char
			return Variant::etChar;
			break;
		default:
			return Variant::etVoid;
		}
		return Variant::etVoid;
	}


	namespace impl
	{
		template <class T>
		void bits2POD(T &pod, boost::uint32_t amount, boost::uint8_t *bits)
		{
			boost::uint32_t tail = 0;
			if(sizeof(pod)*8 <= amount)
			{
				//1:1
				memcpy(&pod, bits, sizeof(pod));
			}
			else
			{
				//POD больше
				memcpy(&pod, bits, amount/8);

				switch(amount%8)
				{
				case 0:
					tail = sizeof(pod)-amount/8;
					break;
				case 1:
					tail = sizeof(pod)-amount/8 - 1;
					((char *)&pod)[amount/8] = bits[amount/8] & 0x80;
					break;
				case 2:
					tail = sizeof(pod)-amount/8 - 1;
					((char *)&pod)[amount/8] = bits[amount/8] & 0xc0;
					break;
				case 3:
					tail = sizeof(pod)-amount/8 - 1;
					((char *)&pod)[amount/8] = bits[amount/8] & 0xe0;
					break;
				case 4:
					tail = sizeof(pod)-amount/8 - 1;
					((char *)&pod)[amount/8] = bits[amount/8] & 0xf0;
					break;
				case 5:
					tail = sizeof(pod)-amount/8 - 1;
					((char *)&pod)[amount/8] = bits[amount/8] & 0xf8;
					break;
				case 6:
					tail = sizeof(pod)-amount/8 - 1;
					((char *)&pod)[amount/8] = bits[amount/8] & 0xfc;
					break;
				case 7:
					tail = sizeof(pod)-amount/8 - 1;
					((char *)&pod)[amount/8] = bits[amount/8] & 0xfe;
					break;
				}

				memset((char *)&pod + sizeof(pod)-tail, 0, tail);
			}

			//reverse
			unsigned char *buf = (unsigned char *)&pod;
			for(size_t i(0); i<sizeof(pod)-tail; i++)
			{
				buf[i] = (unsigned char)(((buf[i] * 0x0802LU & 0x22110LU) | (buf[i] * 0x8020LU & 0x88440LU)) * 0x10101LU >> 16);
			}
		}

		template <size_t N>
		void bits2Bitset(std::bitset<N> &bs, int bitsDb, boost::uint8_t *valDb)
		{
			if(bitsDb > (int)bs.size())
			{
				bitsDb = (int)bs.size();
			}

			for(int i(0); i<bitsDb/8; i++)
			{
				bs.set(i*8+0, (valDb[i] & 0x80)?true:false);
				bs.set(i*8+1, (valDb[i] & 0x40)?true:false);
				bs.set(i*8+2, (valDb[i] & 0x20)?true:false);
				bs.set(i*8+3, (valDb[i] & 0x10)?true:false);
				bs.set(i*8+4, (valDb[i] & 0x08)?true:false);
				bs.set(i*8+5, (valDb[i] & 0x04)?true:false);
				bs.set(i*8+6, (valDb[i] & 0x02)?true:false);
				bs.set(i*8+7, (valDb[i] & 0x01)?true:false);
			}

			for(int i(0); i<bitsDb%8; i++)
			{
				bs.set(bitsDb/8*8+i, (valDb[bitsDb/8] & (0x80>>i))?true:false);
			}

			for(size_t i(bitsDb); i<bs.size(); i++)
			{
				bs.reset(i);
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetch(Variant &v, size_t colIdx, size_t rowIdx)
	{
		if(colIdx >= (size_t)PQnfields(_pgr))
		{
			return false;
		}

		assert(1 == PQfformat(_pgr, colIdx));
		if(PQgetisnull(_pgr, (int)rowIdx, (int)colIdx))
		{
			v.forceType(colType(colIdx));
			v.setNull(true);
			return true;
		}
		Oid type = PQftype(_pgr, colIdx);
		switch(type)
		{
		case 21://int2
			v = bigEndian(*(boost::int16_t *)PQgetvalue(_pgr, rowIdx, colIdx));
			break;
		case 23://int4
			v = bigEndian(*(boost::int32_t *)PQgetvalue(_pgr, rowIdx, colIdx));
			break;
		case 20://int8
			v = bigEndian(*(boost::int64_t *)PQgetvalue(_pgr, rowIdx, colIdx));
			break;
		case 1700://numeric
			{
				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
				std::vector<unsigned char> buf(lenDb);
				memcpy(&buf.front(), PQgetvalue(_pgr, rowIdx, colIdx), lenDb);
				PG_NumericData &nd = *(PG_NumericData *)&buf.front();

				nd.ndigits = bigEndian(nd.ndigits);
				nd.weight = bigEndian(nd.weight);
				//v.sign = bigEndian(nd.sign);
				nd.dscale = bigEndian(nd.dscale);

				char str[4096];

				size_t strPos = 0;
				if(nd.sign)
				{
					str[strPos++] = '-';
				}

				for(int idx(0); idx<nd.ndigits; idx++)
				{
					nd.NumericDigits[idx] = bigEndian(nd.NumericDigits[idx]);
					char numStrPart[8];
					size_t numStrPartPos=7;
					numStrPart[numStrPartPos--] = 0;
					while(nd.NumericDigits[idx])
					{
						numStrPart[numStrPartPos--] = char('0'+nd.NumericDigits[idx]%10);
						nd.NumericDigits[idx] /= 10;
					}

					memcpy(str+strPos, numStrPart+numStrPartPos+1, 7-numStrPartPos-1);
					strPos += 7-numStrPartPos-1;

					if(nd.weight>=0)
					{
						if(!nd.weight)
						{
							str[strPos++] = '.';
						}
						nd.weight--;
					}
				}

				while('0' == str[--strPos]);
				++strPos;
				//str[++strPos] = 0;

				v.as<Variant::String>(true).assign(str, str+strPos);
			}
			break;
		case 700://float4
			v = bigEndian(*(float *)PQgetvalue(_pgr, rowIdx, colIdx));
			break;
		case 701://float8
			v = bigEndian(*(double *)PQgetvalue(_pgr, rowIdx, colIdx));
			break;
		case 790://money
			v = bigEndian(*(boost::int64_t *)PQgetvalue(_pgr, rowIdx, colIdx));
			break;
		case 705://unknown
		case 1043://varchar
		case 1042://bpchar
		case 25://text
			{
				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
				char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
				v.as<Variant::String>(true).assign(valDb, valDb+lenDb);
			}
			break;
		case 17://bytea
			{
				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
				char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
				v.as<Variant::VectorChar>(true).assign(valDb, valDb+lenDb);
			}
			break;
		case 1114://timestamp
		case 1184://timestamptz
			{
				boost::uint64_t time;
				if(_con->integerDatetimes())
				{
					time = bigEndian(*(boost::uint64_t *)PQgetvalue(_pgr, rowIdx, colIdx));
				}
				else
				{
					double v = bigEndian(*(double *)PQgetvalue(_pgr, rowIdx, colIdx));
					time = (boost::int64_t)v;
					v -= time;
					time *= 1000000;
					time += (boost::uint64_t)(v*1000000 + 0.5);
				}

				boost::int64_t date;
				TMODULO(time, date, USECS_PER_DAY);

				if(time < 0)
				{
					time += USECS_PER_DAY;
					date -= 1;
				}

				/* add offset to go from J2000 back to standard Julian date */
				date += POSTGRES_EPOCH_JDATE;

				int year, month, day, hour, min, sec, fsec;
				j2date((int) date, &year, &month, &day);
				dt2time(time, &hour, &min, &sec, &fsec);

				boost::int64_t fsecl = (boost::int64_t)fsec * USECS_PER_SEC / boost::posix_time::time_duration::ticks_per_second();

				v = 
					boost::posix_time::ptime(
						boost::gregorian::date(year, month, day),
						boost::posix_time::time_duration(hour, min, sec, fsecl)
					);

			}
			break;
		case 1186://interval
			{
				unsigned char buf[sizeof(PG_Interval)];
				memcpy(buf, PQgetvalue(_pgr, rowIdx, colIdx), sizeof(PG_Interval));
				PG_Interval &i = *(PG_Interval *)buf;

				//v.time = bigEndian(v.time);
				i.day = bigEndian(i.day);
				i.month = bigEndian(i.month);


				if(_con->integerDatetimes())
				{
					i.time = bigEndian(i.time);
				}
				else
				{
					double dv = bigEndian(*(double *)&i.time);
					i.time = (boost::int64_t)dv;
					dv -= i.time;
					i.time *= 1000000;
					i.time += (boost::uint64_t)(dv*1000000 + 0.5);
				}

				DateTimeDuration &dtd = v.as<Variant::DateTimeDuration>(true);

				dtd._dd = boost::gregorian::date_duration(i.day + i.month*DAYS_PER_MONTH);

				int hour, min, sec, fsec;
				dt2time(i.time, &hour, &min, &sec, &fsec);

				boost::int64_t fsecl = (boost::int64_t)fsec * USECS_PER_SEC / boost::posix_time::time_duration::ticks_per_second();
				dtd._td = boost::posix_time::time_duration(hour, min, sec, fsecl);
			}
			break;
		case 1082://date
			{
				boost::int32_t jd = bigEndian(*(boost::int32_t *)PQgetvalue(_pgr, rowIdx, colIdx)) + POSTGRES_EPOCH_JDATE;
				int year, month, day;
				j2date(jd, &year, &month, &day);

				v = boost::gregorian::date(year, month, day);
			}
			break;
		case 1083://time
		case 1266://timetz
			{
				boost::uint64_t time;
				if(_con->integerDatetimes())
				{
					time = bigEndian(*(boost::uint64_t *)PQgetvalue(_pgr, rowIdx, colIdx));
				}
				else
				{
					double v = bigEndian(*(double *)PQgetvalue(_pgr, rowIdx, colIdx));
					time = (boost::int64_t)v;
					v -= time;
					time *= 1000000;
					time += (boost::uint64_t)(v*1000000 + 0.5);
				}

				int hour, min, sec, fsec;
				dt2time(time, &hour, &min, &sec, &fsec);

				boost::int64_t fsecl = (boost::int64_t)fsec * USECS_PER_SEC / boost::posix_time::time_duration::ticks_per_second();

				v = 
					boost::posix_time::time_duration(hour, min, sec, fsecl);

			}
			break;
		case 16://bool
			v = (*(boost::int8_t *)PQgetvalue(_pgr, rowIdx, colIdx))?true:false;
			break;
		case 1560://bit
		case 1562://varbit
			{

				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
				std::vector<unsigned char> buf(lenDb);
				memcpy(&buf.front(), PQgetvalue(_pgr, rowIdx, colIdx), lenDb);
				PG_VarBit &vb = *(PG_VarBit *)&buf.front();

				boost::uint32_t amount = bigEndian(vb.amount);

				if(amount <= 8)
				{
					impl::bits2Bitset(v.as<Variant::Bitset8>(true), amount, vb.bits);
				}
				else if(amount <= 16)
				{
					impl::bits2Bitset(v.as<Variant::Bitset16>(true), amount, vb.bits);
				}
				else if(amount <= 32)
				{
					impl::bits2Bitset(v.as<Variant::Bitset32>(true), amount, vb.bits);
				}
				else if(amount <= 64)
				{
					impl::bits2Bitset(v.as<Variant::Bitset64>(true), amount, vb.bits);
				}
				else if(amount <= 128)
				{
					impl::bits2Bitset(v.as<Variant::Bitset128>(true), amount, vb.bits);
				}
				else if(amount <= 256)
				{
					impl::bits2Bitset(v.as<Variant::Bitset256>(true), amount, vb.bits);
				}
				else
				{
					impl::bits2Bitset(v.as<Variant::Bitset512>(true), amount, vb.bits);
				}
			}
			break;
		case 26://oid
			v = bigEndian(*(boost::uint32_t *)PQgetvalue(_pgr, rowIdx, colIdx));
			break;
		case 2950://uuid
			{
				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
				boost::uuids::uuid &u = v.as<Variant::Uuid>(true);
				if(lenDb > (int)u.size())
				{
					lenDb = u.size();
				}
				char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
				std::copy((char *)valDb, (char *)valDb+lenDb, u.begin());

			}
			break;
		case 18://char
			v = *(char *)PQgetvalue(_pgr, rowIdx, colIdx);
			break;
		default:
			v.setNull<Variant::Void>();
			break;
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowList(Variant &v, size_t rowIdx)
	{
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
		return fetchRowMap_(v.as<Variant::MapStringVariant>(true), rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowsList(Variant &v, size_t rowBeginIdx, size_t rowEndIdx)
	{
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
		return fetchRowMap_(v.as<Variant::MapStringVariant>(true), colIndices, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowsList(Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx, size_t rowEndIdx)
	{
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
