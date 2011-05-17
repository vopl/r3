#ifndef _PGC_FROMDB2CPP_HPP_
#define _PGC_FROMDB2CPP_HPP_

#include "pgc/cppType.hpp"
#include <pgtypes_numeric.h>
#include <vector>
#include <strstream>
#include "utils/julian.h"
#include "utils/ntoa.hpp"
#include "utils/fixEndian.hpp"

namespace pgc
{
	using namespace utils;

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(char *&valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		switch(typDb)
		{
		case 21://int2
			{
				boost::int16_t v = *(boost::int16_t *)valDb;
				_ntoa(fixEndian(v), valCpp);
			}
			break;
		case 23://int4
			{
				boost::int32_t v = *(boost::int32_t *)valDb;
				_ntoa(fixEndian(v), valCpp);
			}
			break;
		case 20://int8
			{
				boost::int64_t v = *(boost::int64_t *)valDb;
				_ntoa(fixEndian(v), valCpp);
			}
			break;
		case 1700://numeric
			{
				typedef struct NumericData
				{
					short ndigits;
					short weight;
					short sign;
					short dscale;
					short NumericDigits[1];
				} NumericData;

				std::vector<unsigned char> buf(lenDb);
				memcpy(&buf.front(), valDb, lenDb);
				NumericData &v = *(NumericData *)&buf.front();

				v.ndigits = fixEndian(v.ndigits);
				v.weight = fixEndian(v.weight);
				v.sign = fixEndian(v.sign);
				v.dscale = fixEndian(v.dscale);

				size_t valCppPos = 0;
				if(v.sign)
				{
					valCpp[valCppPos++] = '-';
				}

				for(int idx(0); idx<v.ndigits; idx++)
				{
					v.NumericDigits[idx] = fixEndian(v.NumericDigits[idx]);
					char numStrPart[8];
					size_t numStrPartPos=7;
					numStrPart[numStrPartPos--] = 0;
					while(v.NumericDigits[idx])
					{
						numStrPart[numStrPartPos--] = char('0'+v.NumericDigits[idx]%10);
						v.NumericDigits[idx] /= 10;
					}

					memcpy(valCpp+valCppPos, numStrPart+numStrPartPos+1, 7-numStrPartPos-1);
					valCppPos += 7-numStrPartPos-1;

					if(v.weight>=0)
					{
						if(!v.weight)
						{
							valCpp[valCppPos++] = '.';
						}
						v.weight--;
					}
				}

				while('0' == valCpp[--valCppPos]);
				valCpp[++valCppPos] = 0;
			}
			break;

		case 700://float4
			{
				float v = *(float *)valDb;
				v = fixEndian(v);
				sprintf(valCpp,"%.7g",(double)v);
			}
			break;
		case 701://float8
			{
				double v = *(double *)valDb;
				v = fixEndian(v);
				sprintf(valCpp,"%.16g",v);
			}
			break;
		case 790://money
			{
				boost::uint64_t v = *(boost::uint64_t *)valDb;
				_ntoa(fixEndian(v), valCpp);
			}
			break;
		case 1043://varchar
			{
				memcpy(valCpp, valDb, lenDb);
				valCpp[lenDb] = 0;
			}
			break;
		case 1042://bpchar
			{
				memcpy(valCpp, valDb, lenDb);
				valCpp[lenDb] = 0;
			}
			break;
		case 25://text
			{
				memcpy(valCpp, valDb, lenDb);
				valCpp[lenDb] = 0;
			}
			break;
		case 17://bytea
			{
				size_t lenCpp=0;
				unsigned char *esc = PQescapeBytea((const unsigned char *)valDb, lenDb, &lenCpp);
				memcpy(valCpp, esc, lenCpp);
				PQfreemem(esc);
				valCpp[lenCpp] = 0;
			}
			break;
		case 1114://timestamp
		case 1184://timestamptz
			{
				boost::int64_t		date, time;
				time = *(boost::int64_t *)valDb;
				time = fixEndian(time);

				TMODULO(time, date, USECS_PER_DAY);

				if(time < 0)
				{
					time += USECS_PER_DAY;
					date -= 1;
				}

				/* add offset to go from J2000 back to standard Julian date */
				date += date2j(2000, 1, 1);

				if(date < 0 || date > INT_MAX)
				{
					return false;
				}

				/* Julian day routine does not work for negative Julian days */
				int year, month, day, hour, min, sec, fsec;
				j2date((int) date, &year, &month, &day);
				dt2time(time, &hour, &min, &sec, &fsec);

				sprintf(valCpp, "%04d-%02d-%02d %02d:%02d:%02d", 
					year, month, day,
					hour, min, sec);
			}
			break;
		case 1186://interval
			{
				typedef struct Interval
				{
					boost::uint64_t time;
					boost::uint32_t day;
					boost::uint32_t month;
				} Interval;

				std::vector<unsigned char> buf(lenDb);
				memcpy(&buf.front(), valDb, lenDb);
				Interval &v = *(Interval *)&buf.front();

				v.time = fixEndian(v.time);
				v.day = fixEndian(v.day);
				v.month = fixEndian(v.month);

				int hour, min, sec, fsec;
				dt2time(v.time, &hour, &min, &sec, &fsec);

				sprintf(valCpp, "%d month %d day %02d:%02d:%02d", 
					v.month, v.day,
					hour, min, sec);
			}
			break;
		case 1082://date
			{
				boost::int32_t v = *(boost::int32_t *)valDb;
				v = fixEndian(v);

				v += date2j(2000, 1, 1);

				int year, month, day;
				j2date(v, &year, &month, &day);

				sprintf(valCpp, "%04d-%02d-%02d", 
					year, month, day);

			}
			break;
		case 1083://time
		case 1266://timetz
			{
				boost::int64_t		time;
				time = *(boost::int64_t *)valDb;
				time = fixEndian(time);

				/* Julian day routine does not work for negative Julian days */
				int hour, min, sec, fsec;
				dt2time(time, &hour, &min, &sec, &fsec);

				sprintf(valCpp, "%02d:%02d:%02d", 
					hour, min, sec);
			}
			break;
		case 16://bool
			{
				char v = *(char *)valDb;
				if(v)
				{
					strcpy(valCpp, "true");
				}
				else
				{
					strcpy(valCpp, "false");
				}
			}
			break;
		case 1560://bit
		case 1562://varbit
			{
				typedef struct VarBit
				{
					boost::uint32_t amount;
					boost::int8_t bits[1];
				} VarBit;

				std::vector<unsigned char> buf(lenDb);
				memcpy(&buf.front(), valDb, lenDb);
				VarBit &v = *(VarBit *)&buf.front();

				v.amount = fixEndian(v.amount);
				for(size_t i(0); i<v.amount; i++)
				{
					if((v.bits[i/8] << i%8) & 0x80)
					{
						valCpp[i] = '1';
					}
					else
					{
						valCpp[i] = '0';
					}
				}
				valCpp[v.amount] = 0;
			}
			break;

		case 26://oid
			{
				boost::uint32_t v = *(boost::uint32_t *)valDb;
				_ntoa(fixEndian(v), valCpp);
			}
			break;



		default:
// 			size_t lenCpp=0;
// 			unsigned char *esc = PQescapeBytea((const unsigned char *)valDb, lenDb, &lenCpp);
// 			memcpy(valCpp, esc, lenCpp);
// 			valCpp[lenCpp] = 0;

//			assert(!"unsupported db type");
			valCpp[0] = 0;
			return false;

		}

		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(std::string &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(bool &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(boost::int8_t &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(boost::int16_t &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(boost::int32_t &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(boost::int64_t &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(boost::uint8_t &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(boost::uint16_t &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(boost::uint32_t &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(boost::uint64_t &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(std::tm &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(int typCpp, void *valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		switch(typCpp)
		{
		case CppDataType<char *>::cdt_index:
			return fromDb2Cpp(*(char **)valCpp, typDb, lenDb, valDb);

		case CppDataType<std::string>::cdt_index:
			return fromDb2Cpp(*(std::string *)valCpp, typDb, lenDb, valDb);

		case CppDataType<bool>::cdt_index:
			return fromDb2Cpp(*(bool *)valCpp, typDb, lenDb, valDb);

		case CppDataType<boost::int8_t>::cdt_index:
			return fromDb2Cpp(*(boost::int8_t *)valCpp, typDb, lenDb, valDb);

		case CppDataType<boost::int16_t>::cdt_index:
			return fromDb2Cpp(*(boost::int16_t *)valCpp, typDb, lenDb, valDb);

		case CppDataType<boost::int32_t>::cdt_index:
			return fromDb2Cpp(*(boost::int32_t *)valCpp, typDb, lenDb, valDb);

		case CppDataType<boost::int64_t>::cdt_index:
			return fromDb2Cpp(*(boost::int64_t *)valCpp, typDb, lenDb, valDb);

		case CppDataType<boost::uint8_t>::cdt_index:
			return fromDb2Cpp(*(boost::uint8_t *)valCpp, typDb, lenDb, valDb);

		case CppDataType<boost::uint16_t>::cdt_index:
			return fromDb2Cpp(*(boost::uint16_t *)valCpp, typDb, lenDb, valDb);

		case CppDataType<boost::uint32_t>::cdt_index:
			return fromDb2Cpp(*(boost::uint32_t *)valCpp, typDb, lenDb, valDb);

		case CppDataType<boost::uint64_t>::cdt_index:
			return fromDb2Cpp(*(boost::uint64_t *)valCpp, typDb, lenDb, valDb);

		case CppDataType<std::tm>::cdt_index:
			return fromDb2Cpp(*(std::tm *)valCpp, typDb, lenDb, valDb);

		default:
			assert(!"unsupported cpp type");
		}
		return false;
	}
}
#endif
