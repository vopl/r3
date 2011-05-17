#ifndef _PGC_FROMDB2CPP_HPP_
#define _PGC_FROMDB2CPP_HPP_

#include "cppType.hpp"
#include <pgtypes_numeric.h>
#include <vector>
#include <strstream>

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	template <class T>
	inline T &revert(T &v)
	{
		unsigned char *data = (unsigned char *)&v;
		int len = sizeof(T);
		size_t len_2 = len/2;
		for(size_t i=0; i<len_2; i++)
		{	
			size_t i2 = len - i - 1;
			unsigned char b = data[i];
			data[i] = data[i2];
			data[i2] = b;
		}
		return v;
	}

	//////////////////////////////////////////////////////////////////////////
	namespace impl
	{
		template <int maxDecs, typename integral>
		char *_ntoa(integral num, char *res)
		{
			if(num)
			{
				bool negative = num<0;
				int pos=maxDecs;

				res[pos] = 0;

				if(negative)
				{
					while(num)
					{
						res[--pos] = (char)('0' - (num % 10));
						num /= 10;
					}
					res[--pos] = '-';
				}
				else
				{
					while(num)
					{
						res[--pos] = (char)('0' + (num % 10));
						num /= 10;
					}
				}
				if(pos)
				{
					memmove(res, res+pos, maxDecs-pos+1);
				}
				return res;
			}
			res[0] = '0';
			res[1] = 0;
			return res;
		}
		template <int maxDecs, typename integral>
		char *_untoa(integral num, char *res)
		{
			if(num)
			{
				int pos=maxDecs;
				res[pos] = 0;

				while(num)
				{
					res[--pos] = (char)('0' + (num % 10));
					num /= 10;
				}
				if(pos)
				{
					memmove(res, res+pos, maxDecs-pos+1);
				}
				return res;
			}
			res[0] = '0';
			res[1] = 0;
			return res;
		}

		inline
			char *_ntoa(long long num, char *res)
		{
			return impl::_ntoa<24>(num, res);
		}
		inline
			char *_ntoa(unsigned long long num, char *res)
		{
			return impl::_untoa<25>(num, res);
		}
		inline
			char *_ntoa(long num, char *res)
		{
			return impl::_ntoa<12>(num, res);
		}
		inline
			char *_ntoa(unsigned long num, char *res)
		{
			return impl::_untoa<13>(num, res);
		}
		inline
			char *_ntoa(int num, char *res)
		{
			return impl::_ntoa<12>(num, res);
		}
		inline
			char *_ntoa(unsigned int num, char *res)
		{
			return impl::_untoa<13>(num, res);
		}
		inline
			char *_ntoa(short num, char *res)
		{
			return impl::_ntoa<6>(num, res);
		}
		inline
			char *_ntoa(unsigned short num, char *res)
		{
			return impl::_untoa<7>(num, res);
		}
		inline
			char *_ntoa(char num, char *res)
		{
			return impl::_ntoa<3>(num, res);
		}
		inline
			char *_ntoa(unsigned char num, char *res)
		{
			return impl::_untoa<4>(num, res);
		}

	}




	//////////////////////////////////////////////////////////////////////////
#define TMODULO(t,q,u) \
	do { \
	(q) = (((t) < 0) ? ceil((t) / (u)): floor((t) / (u))); \
	if ((q) != 0) (t) -= int((q) * (u) + 0.5); \
	} while(0)

	typedef double TTimestamp;
	enum
	{
		SECS_PER_YEAR	= 36525 * 864,	/* avoid floating-point computation */
		SECS_PER_DAY	= 86400,
		SECS_PER_HOUR	= 3600,
		SECS_PER_MINUTE = 60,
		MINS_PER_HOUR	= 60,
	};

	int date2j(int y, int m, int d);
	void j2date(int jd, int *year, int *month, int *day);

	double time2j(const int hour, const int min, const int sec, const int fsec);
	void j2time(double t, int *hour, int *min, int *sec, int *fsec);



	//////////////////////////////////////////////////////////////////////////
	inline int date2j(int y, int m, int d)
	{
		int			julian;
		int			century;

		if (m > 2)
		{
			m += 1;
			y += 4800;
		}
		else
		{
			m += 13;
			y += 4799;
		}

		century = y / 100;
		julian = y * 365 - 32167;
		julian += y / 4 - century + century / 4;
		julian += 7834 * m / 256 + d;

		return julian;
	}


	inline void j2date(int jd, int *year, int *month, int *day)
	{
		unsigned int julian;
		unsigned int quad;
		unsigned int extra;
		int			y;

		julian = jd;
		julian += 32044;
		quad = julian / 146097;
		extra = (julian - quad * 146097) * 4 + 3;
		julian += 60 + quad * 3 + extra / 146097;
		quad = julian / 1461;
		julian -= quad * 1461;
		y = julian * 4 / 1461;
		julian = ((y != 0) ? (julian + 305) % 365 : (julian + 306) % 366) + 123;
		y += quad * 4;
		*year = y - 4800;
		quad = julian * 2141 / 65536;
		*day = julian - 7834 * quad / 256;
		*month = (quad + 10) % 12 + 1;

		return;
	}


	//////////////////////////////////////////////////////////////////////////
	inline double time2j(const int hour, const int min, const int sec, const int fsec)
	{
		double d=0;
		int i = fsec;
		while(i)
		{
			d += i%10;
			d /= 10;
			i /= 10;
		}
		return (((((double)hour * MINS_PER_HOUR) + min) * SECS_PER_MINUTE) + sec) + d;
	}

	inline void j2time(double t, int *hour, int *min, int *sec, int *fsec)
	{
		*hour = (int)(t / SECS_PER_HOUR);
		t -= (*hour) * SECS_PER_HOUR;
		*min = (int)(t / SECS_PER_MINUTE);
		t -= (*min) * SECS_PER_MINUTE;
		*sec = (int)(t);
		t -= *sec;
		*fsec = 0;
		while(t)
		{
			*fsec *= 10;
			t *= 10;
			int d = (int)t;
			*fsec += d;
			t -= d;
		}

	}



	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(char *&valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		switch(typDb)
		{
		case 21://int2
			{
				boost::int16_t v = *(boost::int16_t *)valDb;
				impl::_ntoa(revert(v), valCpp);
			}
			break;
		case 23://int4
			{
				boost::int32_t v = *(boost::int32_t *)valDb;
				impl::_ntoa(revert(v), valCpp);
			}
			break;
		case 20://int8
			{
				boost::int64_t v = *(boost::int64_t *)valDb;
				impl::_ntoa(revert(v), valCpp);
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

				revert(v.ndigits);
				revert(v.weight);
				revert(v.sign);
				revert(v.dscale);

				size_t valCppPos = 0;
				if(v.sign)
				{
					valCpp[valCppPos++] = '-';
				}

				for(int idx(0); idx<v.ndigits; idx++)
				{
					revert(v.NumericDigits[idx]);
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
				revert(v);
				sprintf(valCpp,"%.7g",(double)v);
			}
			break;
		case 701://float8
			{
				double v = *(double *)valDb;
				revert(v);
				sprintf(valCpp,"%.16g",v);
			}
			break;
		case 790://money
			{
				boost::uint64_t v = *(boost::uint64_t *)valDb;
				impl::_ntoa(revert(v), valCpp);
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
				valCpp[lenCpp] = 0;
			}
			break;
		case 1114://timestamp
			{

				double v = *(double *)valDb;
				revert(v);

				double		date;
				double		time;

				time = v;
				TMODULO(time, date, (double) SECS_PER_DAY);

				if (time < 0)
				{
					time += SECS_PER_DAY;
					date -= 1;
				}

				/* add offset to go from J2000 back to standard Julian date */
				date += 2451545;

				/* Julian day routine does not work for negative Julian days */
				int year, month, day, hour, min, sec, fsec;
				j2date((int) date, &year, &month, &day);
				j2time(time, &hour, &min, &sec, &fsec);

				int k=220;


			}
			break;


		default:
			assert(!"unsupported db type");
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
