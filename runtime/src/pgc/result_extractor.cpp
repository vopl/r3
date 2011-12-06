#include "pch.h"
#include "result.hpp"
#include "pgDataType.h"
#include "utils/fixEndian.hpp"
#include "utils/ntoa.hpp"
#include "utils/aton.hpp"
#include "utils/julian.h"


namespace pgc
{
	using namespace utils;

	//////////////////////////////////////////////////////////////////////////
	bool Result::extractor_int2			(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (bigEndian(*(boost::int16_t *)valDb))

		switch(typCpp)
		{
// 		case Variant::Type2Enum<char *>::et:
// 			_ntoa(VAL, *(char **)valCpp);
// 			return true;
		case Variant::Type2Enum<std::string>::et:
			{
				char buf[32];
				*(std::string*)valCpp = _ntoa(VAL, buf);
			}
			return true;
		case Variant::Type2Enum<bool>::et:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case Variant::Type2Enum<float>::et:
			*(float *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<double>::et:
			*(double *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::int8_t>::et:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int16_t>::et:
			*(boost::int16_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::int32_t>::et:
			*(boost::int32_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::int64_t>::et:
			*(boost::int64_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::uint8_t>::et:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint16_t>::et:
			*(boost::uint16_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::uint32_t>::et:
			*(boost::uint32_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::uint64_t>::et:
			*(boost::uint64_t *)valCpp = VAL;
			return true;
		}
#undef VAL

		//assert(!"unsupported cpp type for int2");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::extractor_int4			(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (bigEndian(*(boost::int32_t *)valDb))

		switch(typCpp)
		{
// 		case Variant::Type2Enum<char *>::et:
// 			_ntoa(VAL, *(char **)valCpp);
// 			return true;
		case Variant::Type2Enum<std::string>::et:
			{
				char buf[32];
				*(std::string*)valCpp = _ntoa(VAL, buf);
			}
			return true;
		case Variant::Type2Enum<bool>::et:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case Variant::Type2Enum<float>::et:
			*(float *)valCpp = (float)VAL;
			return true;
		case Variant::Type2Enum<double>::et:
			*(double *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::int8_t>::et:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int16_t>::et:
			*(boost::int16_t *)valCpp = (boost::int16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int32_t>::et:
			*(boost::int32_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::int64_t>::et:
			*(boost::int64_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::uint8_t>::et:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint16_t>::et:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint32_t>::et:
			*(boost::uint32_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::uint64_t>::et:
			*(boost::uint64_t *)valCpp = VAL;
			return true;
		}
#undef VAL

		//assert(!"unsupported cpp type for int4");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::extractor_int8			(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (bigEndian(*(boost::int64_t *)valDb))

		switch(typCpp)
		{
// 		case Variant::Type2Enum<char *>::et:
// 			_ntoa(VAL, *(char **)valCpp);
// 			return true;
		case Variant::Type2Enum<std::string>::et:
			{
				char buf[32];
				*(std::string*)valCpp = _ntoa(VAL, buf);
			}
			return true;
		case Variant::Type2Enum<bool>::et:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case Variant::Type2Enum<float>::et:
			*(float *)valCpp = (float)VAL;
			return true;
		case Variant::Type2Enum<double>::et:
			*(double *)valCpp = (double)VAL;
			return true;
		case Variant::Type2Enum<boost::int8_t>::et:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int16_t>::et:
			*(boost::int16_t *)valCpp = (boost::int16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int32_t>::et:
			*(boost::int32_t *)valCpp = (boost::int32_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int64_t>::et:
			*(boost::int64_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::uint8_t>::et:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint16_t>::et:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint32_t>::et:
			*(boost::uint32_t *)valCpp = (boost::uint32_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint64_t>::et:
			*(boost::uint64_t *)valCpp = VAL;
			return true;
		}
#undef VAL

		//assert(!"unsupported cpp type for int8");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::extractor_numeric		(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

		/*
			план такой

			получить доступ к бинарному представлению нумерика

			сформировать текстовый буфер достаточной длины чтобы в него складывать значение в текстовом виде
			при этом если заказана строка из cpp то взять ее

			если была заказана не строка то сконвертировать
		*/

		int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
		std::vector<unsigned char> buf(lenDb);
		memcpy(&buf.front(), valDb, lenDb);
		PG_NumericData &v = *(PG_NumericData *)&buf.front();

		v.ndigits = bigEndian(v.ndigits);
		v.weight = bigEndian(v.weight);
		//v.sign = bigEndian(v.sign);
		v.dscale = bigEndian(v.dscale);


		std::vector<char> strBuf;
		char *str = NULL;

		switch(typCpp)
		{
// 		case Variant::Type2Enum<char *>::et:
// 			str = *(char **)valCpp;
// 			break;
		case Variant::Type2Enum<std::string>::et:
			{
				std::string &cppStr = *(std::string*)valCpp;
				cppStr.resize(10+v.ndigits*5);
				str = const_cast<char *>(cppStr.data());
			}
			break;
		default:
			{
				strBuf.resize(10+v.ndigits*5);
				str = &strBuf[0];
			}
		}


		size_t strPos = 0;
		if(v.sign)
		{
			str[strPos++] = '-';
		}

		for(int idx(0); idx<v.ndigits; idx++)
		{
			v.NumericDigits[idx] = bigEndian(v.NumericDigits[idx]);
			char numStrPart[8];
			size_t numStrPartPos=7;
			numStrPart[numStrPartPos--] = 0;
			while(v.NumericDigits[idx])
			{
				numStrPart[numStrPartPos--] = char('0'+v.NumericDigits[idx]%10);
				v.NumericDigits[idx] /= 10;
			}

			memcpy(str+strPos, numStrPart+numStrPartPos+1, 7-numStrPartPos-1);
			strPos += 7-numStrPartPos-1;

			if(v.weight>=0)
			{
				if(!v.weight)
				{
					str[strPos++] = '.';
				}
				v.weight--;
			}
		}

		while('0' == str[--strPos]);
		str[++strPos] = 0;


		//////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		switch(typCpp)
		{
// 		case Variant::Type2Enum<char *>::et:
// 			//уже все готово
// 			return true;
		case Variant::Type2Enum<std::string>::et:
			{
				std::string &strCpp = *(std::string*)valCpp;
				strCpp.resize(strlen(strCpp.c_str()));
			}
			return true;
		case Variant::Type2Enum<bool>::et:
			*(bool *)valCpp = _atoc(str)?true:false;
			return true;
		case Variant::Type2Enum<float>::et:
			if(1 != sscanf(str, "%f", (float *)valCpp))
			{
				*(float *)valCpp = 0;
			}
			return true;
		case Variant::Type2Enum<double>::et:
			if(1 != sscanf(str, "%lf", (double *)valCpp))
			{
				*(double *)valCpp = 0;
			}
			return true;
		case Variant::Type2Enum<boost::int8_t>::et:
			_aton(str, *(boost::int8_t *)valCpp);
			return true;
		case Variant::Type2Enum<boost::int16_t>::et:
			_aton(str, *(boost::int16_t *)valCpp);
			return true;
		case Variant::Type2Enum<boost::int32_t>::et:
			_aton(str, *(boost::int32_t *)valCpp);
			return true;
		case Variant::Type2Enum<boost::int64_t>::et:
			_aton(str, *(boost::int64_t *)valCpp);
			return true;
		case Variant::Type2Enum<boost::uint8_t>::et:
			_atoun(str, *(boost::uint8_t *)valCpp);
			return true;
		case Variant::Type2Enum<boost::uint16_t>::et:
			_atoun(str, *(boost::uint16_t *)valCpp);
			return true;
		case Variant::Type2Enum<boost::uint32_t>::et:
			_atoun(str, *(boost::uint32_t *)valCpp);
			return true;
		case Variant::Type2Enum<boost::uint64_t>::et:
			_atoun(str, *(boost::uint64_t *)valCpp);
			return true;
		}


		//assert(!"unsupported cpp type for numeric");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::extractor_float4		(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (bigEndian(*(float *)valDb))

		switch(typCpp)
		{
// 		case Variant::Type2Enum<char *>::et:
// 			sprintf(*(char **)valCpp, "%.7g", (double)VAL);
// 			return true;
		case Variant::Type2Enum<std::string>::et:
			{
				char buf[32];
				sprintf(buf, "%.7g", (double)VAL);
				*(std::string*)valCpp = buf;
			}
			return true;
		case Variant::Type2Enum<bool>::et:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case Variant::Type2Enum<float>::et:
			*(float *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<double>::et:
			*(double *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::int8_t>::et:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int16_t>::et:
			*(boost::int16_t *)valCpp = (boost::int16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int32_t>::et:
			*(boost::int32_t *)valCpp = (boost::int32_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int64_t>::et:
			*(boost::int64_t *)valCpp = (boost::int64_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint8_t>::et:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint16_t>::et:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint32_t>::et:
			*(boost::uint32_t *)valCpp = (boost::uint32_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint64_t>::et:
			*(boost::uint64_t *)valCpp = (boost::uint64_t)VAL;
			return true;
		}
#undef VAL

		//assert(!"unsupported cpp type for float4");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::extractor_float8		(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (bigEndian(*(double *)valDb))

		switch(typCpp)
		{
// 		case Variant::Type2Enum<char *>::et:
// 			sprintf(*(char **)valCpp, "%.7g", VAL);
// 			return true;
		case Variant::Type2Enum<std::string>::et:
			{
				char buf[32];
				sprintf(buf, "%.7g", VAL);
				*(std::string*)valCpp = buf;
			}
			return true;
		case Variant::Type2Enum<bool>::et:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case Variant::Type2Enum<float>::et:
			*(float *)valCpp = (float)VAL;
			return true;
		case Variant::Type2Enum<double>::et:
			*(double *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::int8_t>::et:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int16_t>::et:
			*(boost::int16_t *)valCpp = (boost::int16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int32_t>::et:
			*(boost::int32_t *)valCpp = (boost::int32_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int64_t>::et:
			*(boost::int64_t *)valCpp = (boost::int64_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint8_t>::et:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint16_t>::et:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint32_t>::et:
			*(boost::uint32_t *)valCpp = (boost::uint32_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint64_t>::et:
			*(boost::uint64_t *)valCpp = (boost::uint64_t)VAL;
			return true;
		}
#undef VAL

		//assert(!"unsupported cpp type for float8");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::extractor_money		(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (bigEndian(*(boost::int64_t *)valDb))

		switch(typCpp)
		{
// 		case Variant::Type2Enum<char *>::et:
// 			_ntoa(VAL, *(char **)valCpp);
// 			return true;
		case Variant::Type2Enum<std::string>::et:
			{
				char buf[32];
				*(std::string*)valCpp = _ntoa(VAL, buf);
			}
			return true;
		case Variant::Type2Enum<bool>::et:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case Variant::Type2Enum<float>::et:
			*(float *)valCpp = (float)VAL;
			return true;
		case Variant::Type2Enum<double>::et:
			*(double *)valCpp = (double)VAL;
			return true;
		case Variant::Type2Enum<boost::int8_t>::et:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int16_t>::et:
			*(boost::int16_t *)valCpp = (boost::int16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int32_t>::et:
			*(boost::int32_t *)valCpp = (boost::int32_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int64_t>::et:
			*(boost::int64_t *)valCpp = (boost::int64_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint8_t>::et:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint16_t>::et:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint32_t>::et:
			*(boost::uint32_t *)valCpp = (boost::uint32_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint64_t>::et:
			*(boost::uint64_t *)valCpp = (boost::uint64_t)VAL;
			return true;
// 		case Variant::Type2Enum<Money>::et:
// 			((Money *)valCpp)->_value = VAL;
// 			return true;
		}
#undef VAL

		//assert(!"unsupported cpp type for money");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::extractor_varchar		(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

		//////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		switch(typCpp)
		{
// 		case Variant::Type2Enum<char *>::et:
// 			{
// 				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
// 				memcpy(*(char **)valCpp, valDb, lenDb);
// 				(*(char **)valCpp)[lenDb] = 0;
// 			}
// 			return true;
		case Variant::Type2Enum<std::string>::et:
			{
				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
				std::string &strCpp = *(std::string*)valCpp;
				strCpp.assign(valDb, valDb+lenDb);
			}
			return true;
		case Variant::Type2Enum<bool>::et:
			*(bool *)valCpp = _atoc(valDb)?true:false;
			return true;
		case Variant::Type2Enum<float>::et:
			if(1 != sscanf(valDb, "%f", (float *)valCpp))
			{
				*(float *)valCpp = 0;
			}
			return true;
		case Variant::Type2Enum<double>::et:
			if(1 != sscanf(valDb, "%lf", (double *)valCpp))
			{
				*(double *)valCpp = 0;
			}
			return true;
		case Variant::Type2Enum<boost::int8_t>::et:
			_aton(valDb, *(boost::int8_t *)valCpp);
			return true;
		case Variant::Type2Enum<boost::int16_t>::et:
			_aton(valDb, *(boost::int16_t *)valCpp);
			return true;
		case Variant::Type2Enum<boost::int32_t>::et:
			_aton(valDb, *(boost::int32_t *)valCpp);
			return true;
		case Variant::Type2Enum<boost::int64_t>::et:
			_aton(valDb, *(boost::int64_t *)valCpp);
			return true;
		case Variant::Type2Enum<boost::uint8_t>::et:
			_atoun(valDb, *(boost::uint8_t *)valCpp);
			return true;
		case Variant::Type2Enum<boost::uint16_t>::et:
			_atoun(valDb, *(boost::uint16_t *)valCpp);
			return true;
		case Variant::Type2Enum<boost::uint32_t>::et:
			_atoun(valDb, *(boost::uint32_t *)valCpp);
			return true;
		case Variant::Type2Enum<boost::uint64_t>::et:
			_atoun(valDb, *(boost::uint64_t *)valCpp);
			return true;
		case Variant::Type2Enum<std::vector<unsigned char> >::et:
			{
				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
				(*(std::vector<unsigned char> *)valCpp).assign((unsigned char *)valDb, (unsigned char*)valDb+lenDb);
			}
			return true;
		}


		//assert(!"unsupported cpp type for varchar");
		return false;
	}

	namespace impl
	{
		template <size_t N>
		void bytea2Bitset(std::bitset<N> &bs, int bitsDb, const char *valDb)
		{
			if(bitsDb > (int)bs.size())
			{
				bitsDb = (int)bs.size();
			}

			for(int i(0); i<bitsDb/8; i++)
			{
				bs.set(i*8+0, (valDb[i] & 0x01)?true:false);
				bs.set(i*8+1, (valDb[i] & 0x02)?true:false);
				bs.set(i*8+2, (valDb[i] & 0x04)?true:false);
				bs.set(i*8+3, (valDb[i] & 0x08)?true:false);
				bs.set(i*8+4, (valDb[i] & 0x10)?true:false);
				bs.set(i*8+5, (valDb[i] & 0x20)?true:false);
				bs.set(i*8+6, (valDb[i] & 0x40)?true:false);
				bs.set(i*8+7, (valDb[i] & 0x80)?true:false);
			}

			if(bitsDb%8)
			{
				for(int i(0); i<bitsDb%8; i++)
				{
					bs.set(bitsDb/8*8+i, (valDb[bitsDb/8] & (0x01<<i))?true:false);
				}

				bitsDb = bitsDb/8*8 + 1;
			}

			for(size_t i(bitsDb); i<bs.size(); i++)
			{
				bs.reset(i);
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::extractor_bytea		(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

		//////////////////////////////////////////////////////////////////////////
		switch(typCpp)
		{
// 		case Variant::Type2Enum<char *>::et:
// 			{
// 				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
// 				size_t lenCpp=0;
// 
// 				unsigned char *esc = PQescapeByteaConn(_con->pgcon(), (const unsigned char *)valDb, lenDb, &lenCpp);
// 				if(!esc)
// 				{
// 					return false;
// 				}
// 
// 				memcpy(*(char **)valCpp, esc, lenCpp);
// 				PQfreemem(esc);
// 				(*(char **)valCpp)[lenCpp] = 0;
// 			}
// 			return true;
		case Variant::Type2Enum<std::string>::et:
			{
				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
				std::string &strCpp = *(std::string*)valCpp;
				strCpp.assign(valDb, valDb+lenDb);
			}
			return true;
		case Variant::Type2Enum<bool>::et:
			{
				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
				(*(bool*)valCpp) = lenDb?true:false;
			}
			return true;
		case Variant::Type2Enum<std::bitset<8> >::et:
			{
				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
				impl::bytea2Bitset(*(std::bitset<8>*)valCpp, lenDb*8, valDb);
			}
			return true;
		case Variant::Type2Enum<std::bitset<16> >::et:
			{
				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
				impl::bytea2Bitset(*(std::bitset<16>*)valCpp, lenDb*8, valDb);
			}
			return true;
		case Variant::Type2Enum<std::bitset<32> >::et:
			{
				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
				impl::bytea2Bitset(*(std::bitset<32>*)valCpp, lenDb*8, valDb);
			}
			return true;
		case Variant::Type2Enum<std::bitset<64> >::et:
			{
				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
				impl::bytea2Bitset(*(std::bitset<64>*)valCpp, lenDb*8, valDb);
			}
			return true;
		case Variant::Type2Enum<std::bitset<128> >::et:
			{
				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
				impl::bytea2Bitset(*(std::bitset<128>*)valCpp, lenDb*8, valDb);
			}
			return true;
		case Variant::Type2Enum<std::bitset<256> >::et:
			{
				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
				impl::bytea2Bitset(*(std::bitset<256>*)valCpp, lenDb*8, valDb);
			}
			return true;
		case Variant::Type2Enum<std::bitset<512> >::et:
			{
				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
				impl::bytea2Bitset(*(std::bitset<512>*)valCpp, lenDb*8, valDb);
			}
			return true;
		case Variant::Type2Enum<std::vector<unsigned char> >::et:
			{
				int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
				(*(std::vector<unsigned char> *)valCpp).assign((unsigned char *)valDb, (unsigned char *)valDb+lenDb);
			}
			return true;
		}


		//assert(!"unsupported cpp type for bytea");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::extractor_timestamp	(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

		boost::uint64_t VAL;
		if(_con->integerDatetimes())
		{
			VAL = bigEndian(*(boost::uint64_t *)valDb);
		}
		else
		{
			double v = bigEndian(*(double *)valDb);
			VAL = (boost::int64_t)v;
			v -= VAL;
			VAL *= 1000000;
			VAL += (boost::uint64_t)(v*1000000 + 0.5);
		}


		switch(typCpp)
		{
// 		case Variant::Type2Enum<char *>::et:
		case Variant::Type2Enum<std::string>::et:
		case Variant::Type2Enum<std::tm>::et:
			{
				boost::int64_t time, date;
				time = VAL;
				TMODULO(time, date, USECS_PER_DAY);

				if(time < 0)
				{
					time += USECS_PER_DAY;
					date -= 1;
				}

				/* add offset to go from J2000 back to standard Julian date */
				date += POSTGRES_EPOCH_JDATE;

				switch(typCpp)
				{
// 				case Variant::Type2Enum<char *>::et:
// 					{
// 						int year, month, day, hour, min, sec, fsec;
// 						j2date((int) date, &year, &month, &day);
// 						dt2time(time, &hour, &min, &sec, &fsec);
// 
// 						if(fsec)
// 						{
// 							int digs = 6;
// 							while(!(fsec%10))
// 							{
// 								digs--;
// 								fsec /= 10;
// 							}
// 							sprintf(*(char **)valCpp, "%04d-%02d-%02d %02d:%02d:%02d.%0*d", 
// 								year, month, day,
// 								hour, min, sec,
// 								digs, fsec);
// 						}
// 						else
// 						{
// 							sprintf(*(char **)valCpp, "%04d-%02d-%02d %02d:%02d:%02d", 
// 								year, month, day,
// 								hour, min, sec);
// 						}
// 					}
// 					break;
				case Variant::Type2Enum<std::string>::et:
					{
						int year, month, day, hour, min, sec, fsec;
						j2date((int) date, &year, &month, &day);
						dt2time(time, &hour, &min, &sec, &fsec);

						char buf[128];
						if(fsec)
						{
							int digs = 6;
							while(!(fsec%10))
							{
								digs--;
								fsec /= 10;
							}
							sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d.%0*d", 
								year, month, day,
								hour, min, sec,
								digs, fsec);
						}
						else
						{
							sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d", 
								year, month, day,
								hour, min, sec);
						}
						(*(std::string*)valCpp) = buf;
					}
					break;
				case Variant::Type2Enum<std::tm>::et:
					{
						std::tm &stm = *(std::tm *)valCpp;
						memset(&stm, 0, sizeof(std::tm));
						int fsec;
						
						j2date((int) date, &stm.tm_year, &stm.tm_mon, &stm.tm_mday);
						dt2time(time, &stm.tm_hour, &stm.tm_min, &stm.tm_sec, &fsec);

						stm.tm_year -= 1900;
						stm.tm_mon -= 1;
						stm.tm_isdst = -1;
					}
					break;
				}
			}
			return true;
		case Variant::Type2Enum<float>::et:
			*(float *)valCpp = (float)VAL;
			return true;
		case Variant::Type2Enum<double>::et:
			*(double *)valCpp = (double)VAL;
			return true;
		case Variant::Type2Enum<boost::int8_t>::et:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int16_t>::et:
			*(boost::int16_t *)valCpp = (boost::int16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int32_t>::et:
			*(boost::int32_t *)valCpp = (boost::int32_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int64_t>::et:
			*(boost::int64_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::uint8_t>::et:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint16_t>::et:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint32_t>::et:
			*(boost::uint32_t *)valCpp = (boost::uint32_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint64_t>::et:
			*(boost::uint64_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::gregorian::date>::et:
			{
				boost::int64_t time, date;
				time = VAL;
				TMODULO(time, date, USECS_PER_DAY);

				if(time < 0)
				{
					time += USECS_PER_DAY;
					date -= 1;
				}

				/* add offset to go from J2000 back to standard Julian date */
				date += POSTGRES_EPOCH_JDATE;

				int year, month, day;
				j2date((int) date, &year, &month, &day);

				*(boost::gregorian::date*)valCpp = boost::gregorian::date(year, month, day);
			}
			return true;
		case Variant::Type2Enum<boost::posix_time::time_duration>::et:
			{
				boost::int64_t time, date;
				time = VAL;
				TMODULO(time, date, USECS_PER_DAY);

				if(time < 0)
				{
					time += USECS_PER_DAY;
					//date -= 1;
				}

				int hour, min, sec, fsec;
				dt2time(time, &hour, &min, &sec, &fsec);

				boost::int64_t fsecl = (boost::int64_t)fsec * USECS_PER_SEC / boost::posix_time::time_duration::ticks_per_second();

				*(boost::posix_time::time_duration*)valCpp = 
					boost::posix_time::time_duration(hour, min, sec, fsecl);
			}
			return true;
		case Variant::Type2Enum<boost::posix_time::ptime>::et:
			{
				boost::int64_t time, date;
				time = VAL;
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

				*(boost::posix_time::ptime*)valCpp = 
					boost::posix_time::ptime(
						boost::gregorian::date(year, month, day),
						boost::posix_time::time_duration(hour, min, sec, fsecl)
					);

				
			}
			return true;
		}


		//assert(!"unsupported cpp type for timestamp");
		return false;
	}



	//////////////////////////////////////////////////////////////////////////
	bool Result::extractor_interval		(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}


		unsigned char buf[sizeof(PG_Interval)];
		memcpy(buf, valDb, sizeof(PG_Interval));
		PG_Interval &v = *(PG_Interval *)buf;

		//v.time = bigEndian(v.time);
		v.day = bigEndian(v.day);
		v.month = bigEndian(v.month);


		if(_con->integerDatetimes())
		{
			v.time = bigEndian(v.time);
		}
		else
		{
			double dv = bigEndian(*(double *)&v.time);
			v.time = (boost::int64_t)dv;
			dv -= v.time;
			v.time *= 1000000;
			v.time += (boost::uint64_t)(dv*1000000 + 0.5);
		}
		//v.time += USECS_PER_DAY*(v.day + v.month*DAYS_PER_MONTH);

#define VAL (v.time)


		switch(typCpp)
		{
// 		case Variant::Type2Enum<char *>::et:
// 			{
// 				int hour, min, sec, fsec;
// 				dt2time(v.time, &hour, &min, &sec, &fsec);
// 
// 				if(fsec)
// 				{
// 					int digs = 6;
// 					while(!(fsec%10))
// 					{
// 						digs--;
// 						fsec /= 10;
// 					}
// 					sprintf(*(char **)valCpp, "%d month %d day %02d:%02d:%02d.%0*d", 
// 						v.month, v.day,
// 						hour, min, sec,
// 						digs, fsec);
// 				}
// 				else
// 				{
// 					sprintf(*(char **)valCpp, "%d month %d day %02d:%02d:%02d", 
// 						v.month, v.day,
// 						hour, min, sec);
// 				}
// 			}
// 			return true;
		case Variant::Type2Enum<std::string>::et:
			{
				int hour, min, sec, fsec;
				dt2time(v.time, &hour, &min, &sec, &fsec);

				char buf[128];

				if(fsec)
				{
					int digs = 6;
					while(!(fsec%10))
					{
						digs--;
						fsec /= 10;
					}
					sprintf(buf, "%d month %d day %02d:%02d:%02d.%0*d", 
						v.month, v.day,
						hour, min, sec,
						digs, fsec);
				}
				else
				{
					sprintf(buf, "%d month %d day %02d:%02d:%02d", 
						v.month, v.day,
						hour, min, sec);
				}

				*(std::string*)valCpp = buf;
			}
			return true;
		case Variant::Type2Enum<bool>::et:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case Variant::Type2Enum<float>::et:
			*(float *)valCpp = (float)(((double)(VAL + USECS_PER_DAY*(v.day + v.month*DAYS_PER_MONTH)))/1000000);
			return true;
		case Variant::Type2Enum<double>::et:
			*(double *)valCpp = (((double)(VAL + USECS_PER_DAY*(v.day + v.month*DAYS_PER_MONTH)))/1000000);
			return true;
		case Variant::Type2Enum<boost::int8_t>::et:
			*(boost::int8_t *)valCpp = (boost::int8_t)(VAL + USECS_PER_DAY*(v.day + v.month*DAYS_PER_MONTH));
			return true;
		case Variant::Type2Enum<boost::int16_t>::et:
			*(boost::int16_t *)valCpp = (boost::int16_t)(VAL + USECS_PER_DAY*(v.day + v.month*DAYS_PER_MONTH));
			return true;
		case Variant::Type2Enum<boost::int32_t>::et:
			*(boost::int32_t *)valCpp = (boost::int32_t)(VAL + USECS_PER_DAY*(v.day + v.month*DAYS_PER_MONTH));
			return true;
		case Variant::Type2Enum<boost::int64_t>::et:
			*(boost::int64_t *)valCpp = (VAL + USECS_PER_DAY*(v.day + v.month*DAYS_PER_MONTH));
			return true;
		case Variant::Type2Enum<boost::uint8_t>::et:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)(VAL + USECS_PER_DAY*(v.day + v.month*DAYS_PER_MONTH));
			return true;
		case Variant::Type2Enum<boost::uint16_t>::et:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)(VAL + USECS_PER_DAY*(v.day + v.month*DAYS_PER_MONTH));
			return true;
		case Variant::Type2Enum<boost::uint32_t>::et:
			*(boost::uint32_t *)valCpp = (boost::uint32_t)(VAL + USECS_PER_DAY*(v.day + v.month*DAYS_PER_MONTH));
			return true;
		case Variant::Type2Enum<boost::uint64_t>::et:
			*(boost::uint64_t *)valCpp = (VAL + USECS_PER_DAY*(v.day + v.month*DAYS_PER_MONTH));
			return true;
		case Variant::Type2Enum<boost::posix_time::time_duration>::et:
			{
				int hour, min, sec, fsec;
				dt2time(v.time, &hour, &min, &sec, &fsec);

				boost::int64_t fsecl = (boost::int64_t)fsec * USECS_PER_SEC / boost::posix_time::time_duration::ticks_per_second();

				*(boost::posix_time::time_duration*)valCpp = 
					boost::posix_time::time_duration(hour, min, sec, fsecl);
			}
			return true;
		case Variant::Type2Enum<boost::gregorian::date_duration>::et:
			{
				*(boost::gregorian::date_duration*)valCpp = 
					boost::gregorian::date_duration(v.day + v.month*DAYS_PER_MONTH);
			}
			return true;
		case Variant::Type2Enum<DateTimeDuration>::et:
			{
				DateTimeDuration &dtd = *(DateTimeDuration *)valCpp;

				dtd._dd = boost::gregorian::date_duration(v.day + v.month*DAYS_PER_MONTH);

				int hour, min, sec, fsec;
				dt2time(v.time, &hour, &min, &sec, &fsec);

				boost::int64_t fsecl = (boost::int64_t)fsec * USECS_PER_SEC / boost::posix_time::time_duration::ticks_per_second();
				dtd._td = boost::posix_time::time_duration(hour, min, sec, fsecl);
			}
			return true;
		}
#undef VAL

		//assert(!"unsupported cpp type for interval");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::extractor_date			(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (bigEndian(*(boost::int32_t *)valDb) + POSTGRES_EPOCH_JDATE)

		switch(typCpp)
		{
// 		case Variant::Type2Enum<char *>::et:
// 			{
// 				int year, month, day;
// 				j2date(VAL, &year, &month, &day);
// 
// 				sprintf(*(char **)valCpp, "%04d-%02d-%02d", 
// 					year, month, day);
// 			}
// 			return true;
		case Variant::Type2Enum<std::string>::et:
			{
				int year, month, day;
				j2date(VAL, &year, &month, &day);

				char buf[128];
				sprintf(buf, "%04d-%02d-%02d", 
					year, month, day);
				*(std::string*)valCpp = buf;
			}
			return true;
		case Variant::Type2Enum<float>::et:
			*(float *)valCpp = (float)VAL;
			return true;
		case Variant::Type2Enum<double>::et:
			*(double *)valCpp = (double)VAL;
			return true;
		case Variant::Type2Enum<boost::int8_t>::et:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int16_t>::et:
			*(boost::int16_t *)valCpp = (boost::int16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int32_t>::et:
			*(boost::int32_t *)valCpp = (boost::int32_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int64_t>::et:
			*(boost::int64_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::uint8_t>::et:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint16_t>::et:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint32_t>::et:
			*(boost::uint32_t *)valCpp = (boost::uint32_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint64_t>::et:
			*(boost::uint64_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<std::tm>::et:
			{
				std::tm &stm = *(std::tm *)valCpp;
				memset(&stm, 0, sizeof(std::tm));

				j2date(VAL, &stm.tm_year, &stm.tm_mon, &stm.tm_mday);

				stm.tm_year -= 1900;
				stm.tm_mon -= 1;
				stm.tm_isdst = -1;
			}
			return true;
		case Variant::Type2Enum<boost::gregorian::date>::et:
			{
				int year, month, day;
				j2date(VAL, &year, &month, &day);

				*(boost::gregorian::date*)valCpp = boost::gregorian::date(year, month, day);
			}
			return true;
		case Variant::Type2Enum<boost::posix_time::ptime>::et:
			{
				int year, month, day;
				j2date(VAL, &year, &month, &day);

				*(boost::posix_time::ptime*)valCpp = 
					boost::posix_time::ptime(
						boost::gregorian::date(year, month, day));


			}
			return true;

		}
#undef VAL

		//assert(!"unsupported cpp type for date");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::extractor_time			(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

		boost::uint64_t VAL;
		if(_con->integerDatetimes())
		{
			VAL = bigEndian(*(boost::uint64_t *)valDb);
		}
		else
		{
			double v = bigEndian(*(double *)valDb);
			VAL = (boost::int64_t)v;
			v -= VAL;
			VAL *= 1000000;
			VAL += (boost::uint64_t)(v*1000000 + 0.5);
		}

		switch(typCpp)
		{
// 		case Variant::Type2Enum<char *>::et:
// 			{
// 				int hour, min, sec, fsec;
// 				dt2time(VAL, &hour, &min, &sec, &fsec);
// 
// 				if(fsec)
// 				{
// 					int digs = 6;
// 					while(!(fsec%10))
// 					{
// 						digs--;
// 						fsec /= 10;
// 					}
// 					sprintf(*(char **)valCpp, "%02d:%02d:%02d.%0*d", 
// 						hour, min, sec,
// 						digs, fsec);
// 				}
// 				else
// 				{
// 					sprintf(*(char **)valCpp, "%02d:%02d:%02d", 
// 						hour, min, sec);
// 				}
// 			}
// 			return true;
		case Variant::Type2Enum<std::string>::et:
			{
				int hour, min, sec, fsec;
				dt2time(VAL, &hour, &min, &sec, &fsec);

				char buf[128];

				if(fsec)
				{
					int digs = 6;
					while(!(fsec%10))
					{
						digs--;
						fsec /= 10;
					}
					sprintf(buf, "%02d:%02d:%02d.%0*d", 
						hour, min, sec,
						digs, fsec);
				}
				else
				{
					sprintf(buf, "%02d:%02d:%02d", 
						hour, min, sec);
				}

				*(std::string*)valCpp = buf;
			}
			return true;
		case Variant::Type2Enum<bool>::et:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case Variant::Type2Enum<float>::et:
			*(float *)valCpp = (float)VAL;
			return true;
		case Variant::Type2Enum<double>::et:
			*(double *)valCpp = (double)VAL;
			return true;
		case Variant::Type2Enum<boost::int8_t>::et:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int16_t>::et:
			*(boost::int16_t *)valCpp = (boost::int16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int32_t>::et:
			*(boost::int32_t *)valCpp = (boost::int32_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int64_t>::et:
			*(boost::int64_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::uint8_t>::et:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint16_t>::et:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint32_t>::et:
			*(boost::uint32_t *)valCpp = (boost::uint32_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint64_t>::et:
			*(boost::uint64_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<std::tm>::et:
			{
				std::tm &stm = *(std::tm *)valCpp;
				memset(&stm, 0, sizeof(std::tm));

				int fsec;
				dt2time(VAL, &stm.tm_hour, &stm.tm_min, &stm.tm_sec, &fsec);

				stm.tm_isdst = -1;
			}
			return true;
		case Variant::Type2Enum<boost::posix_time::time_duration>::et:
			{
				int hour, min, sec, fsec;
				dt2time(VAL, &hour, &min, &sec, &fsec);

				boost::int64_t fsecl = (boost::int64_t)fsec * USECS_PER_SEC / boost::posix_time::time_duration::ticks_per_second();

				*(boost::posix_time::time_duration*)valCpp = 
					boost::posix_time::time_duration(hour, min, sec, fsecl);
			}
			return true;
		case Variant::Type2Enum<DateTimeDuration>::et:
			{
				int hour, min, sec, fsec;
				dt2time(VAL, &hour, &min, &sec, &fsec);

				boost::int64_t fsecl = (boost::int64_t)fsec * USECS_PER_SEC / boost::posix_time::time_duration::ticks_per_second();

				DateTimeDuration &dtd = *(DateTimeDuration*)valCpp;
				dtd._td = 
					boost::posix_time::time_duration(hour, min, sec, fsecl);
				dtd._dd = boost::gregorian::date_duration();
			}
			return true;
		}


		//assert(!"unsupported cpp type for time");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::extractor_bool			(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (*(boost::int8_t *)valDb)

		switch(typCpp)
		{
// 		case Variant::Type2Enum<char *>::et:
// 			(*(char **)valCpp)[0] = VAL?'1':'0';
// 			(*(char **)valCpp)[1] = 0;
// 			return true;
		case Variant::Type2Enum<std::string>::et:
			{
				(*(std::string*)valCpp) = VAL?"1":"0";
			}
			return true;
		case Variant::Type2Enum<bool>::et:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case Variant::Type2Enum<float>::et:
			*(float *)valCpp = VAL?1.0f:0.0f;
			return true;
		case Variant::Type2Enum<double>::et:
			*(double *)valCpp = VAL?1:0;
			return true;
		case Variant::Type2Enum<boost::int8_t>::et:
			*(boost::int8_t *)valCpp = VAL?1:0;
			return true;
		case Variant::Type2Enum<boost::int16_t>::et:
			*(boost::int16_t *)valCpp = VAL?1:0;
			return true;
		case Variant::Type2Enum<boost::int32_t>::et:
			*(boost::int32_t *)valCpp = VAL?1:0;
			return true;
		case Variant::Type2Enum<boost::int64_t>::et:
			*(boost::int64_t *)valCpp = VAL?1:0;
			return true;
		case Variant::Type2Enum<boost::uint8_t>::et:
			*(boost::uint8_t *)valCpp = VAL?1:0;
			return true;
		case Variant::Type2Enum<boost::uint16_t>::et:
			*(boost::uint16_t *)valCpp = VAL?1:0;
			return true;
		case Variant::Type2Enum<boost::uint32_t>::et:
			*(boost::uint32_t *)valCpp = VAL?1:0;
			return true;
		case Variant::Type2Enum<boost::uint64_t>::et:
			*(boost::uint64_t *)valCpp = VAL?1:0;
			return true;
		}
#undef VAL

		//assert(!"unsupported cpp type for bool");
		return false;
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
	bool Result::extractor_varbit		(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

		int lenDb = PQgetlength(_pgr, rowIdx, colIdx);
		std::vector<unsigned char> buf(lenDb);
		memcpy(&buf.front(), valDb, lenDb);
		PG_VarBit &v = *(PG_VarBit *)&buf.front();

		v.amount = bigEndian(v.amount);

		switch(typCpp)
		{
// 		case Variant::Type2Enum<char *>::et:
// 			{
// 				char *strCpp = (*(char **)valCpp);
// 
// 				for(size_t i(0); i<v.amount; i++)
// 				{
// 					if((v.bits[i/8] << i%8) & 0x80)
// 					{
// 						strCpp[i] = '1';
// 					}
// 					else
// 					{
// 						strCpp[i] = '0';
// 					}
// 				}
// 				strCpp[v.amount] = 0;
// 			}
// 			return true;
		case Variant::Type2Enum<std::string>::et:
			{
				std::string &strCpp = (*(std::string*)valCpp);

				strCpp.resize(v.amount);
				for(size_t i(0); i<v.amount; i++)
				{
					if((v.bits[i/8] << i%8) & 0x80)
					{
						strCpp[i] = '1';
					}
					else
					{
						strCpp[i] = '0';
					}
				}
			}
			return true;
		case Variant::Type2Enum<bool>::et:
			{
				if(!v.amount)
				{
					*(bool *)valCpp = false;
					return true;
				}
				else
				{
					*(bool *)valCpp = (v.bits[0] & 0x80)?true:false;
					return true;
				}
			}
			return true;
		case Variant::Type2Enum<float>::et:
			impl::bits2POD(*(float *)valCpp, v.amount, v.bits);
			return true;
		case Variant::Type2Enum<double>::et:
			impl::bits2POD(*(double *)valCpp, v.amount, v.bits);
			return true;
		case Variant::Type2Enum<boost::int8_t>::et:
			impl::bits2POD(*(boost::int8_t *)valCpp, v.amount, v.bits);
			return true;
		case Variant::Type2Enum<boost::int16_t>::et:
			impl::bits2POD(*(boost::int16_t *)valCpp, v.amount, v.bits);
			return true;
		case Variant::Type2Enum<boost::int32_t>::et:
			impl::bits2POD(*(boost::int32_t *)valCpp, v.amount, v.bits);
			return true;
		case Variant::Type2Enum<boost::int64_t>::et:
			impl::bits2POD(*(boost::int64_t *)valCpp, v.amount, v.bits);
			return true;
		case Variant::Type2Enum<boost::uint8_t>::et:
			impl::bits2POD(*(boost::uint8_t *)valCpp, v.amount, v.bits);
			return true;
		case Variant::Type2Enum<boost::uint16_t>::et:
			impl::bits2POD(*(boost::uint16_t *)valCpp, v.amount, v.bits);
			return true;
		case Variant::Type2Enum<boost::uint32_t>::et:
			impl::bits2POD(*(boost::uint32_t *)valCpp, v.amount, v.bits);
			return true;
		case Variant::Type2Enum<boost::uint64_t>::et:
			impl::bits2POD(*(boost::uint64_t *)valCpp, v.amount, v.bits);
			return true;
		case Variant::Type2Enum<std::bitset<8> >::et:
			{
				impl::bits2Bitset(*(std::bitset<8>*)valCpp, v.amount, v.bits);
			}
			return true;
		case Variant::Type2Enum<std::bitset<16> >::et:
			{
				impl::bits2Bitset(*(std::bitset<16>*)valCpp, v.amount, v.bits);
			}
			return true;
		case Variant::Type2Enum<std::bitset<32> >::et:
			{
				impl::bits2Bitset(*(std::bitset<32>*)valCpp, v.amount, v.bits);
			}
			return true;
		case Variant::Type2Enum<std::bitset<64> >::et:
			{
				impl::bits2Bitset(*(std::bitset<64>*)valCpp, v.amount, v.bits);
			}
			return true;
		case Variant::Type2Enum<std::bitset<128> >::et:
			{
				impl::bits2Bitset(*(std::bitset<128>*)valCpp, v.amount, v.bits);
			}
			return true;
		case Variant::Type2Enum<std::bitset<256> >::et:
			{
				impl::bits2Bitset(*(std::bitset<256>*)valCpp, v.amount, v.bits);
			}
			return true;
		case Variant::Type2Enum<std::bitset<512> >::et:
			{
				impl::bits2Bitset(*(std::bitset<512>*)valCpp, v.amount, v.bits);
			}
			return true;
		case Variant::Type2Enum<std::vector<unsigned char> >::et:
			{
				std::vector<unsigned char> &vec = (*(std::vector<unsigned char> *)valCpp);
				vec.assign((unsigned char *)v.bits, (unsigned char *)v.bits + ((v.amount%8)?(v.amount/8+1):(v.amount/8)));

				//reverse
				for(size_t i(0); i<vec.size(); i++)
				{
					vec[i] = (unsigned char)(((vec[i] * 0x0802LU & 0x22110LU) | (vec[i] * 0x8020LU & 0x88440LU)) * 0x10101LU >> 16);
				}
			}
			return true;
		}

		//assert(!"unsupported cpp type for varbit");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::extractor_oid			(int colIdx, int rowIdx, Variant::EType typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgr, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (bigEndian(*(boost::uint32_t *)valDb))

		switch(typCpp)
		{
// 		case Variant::Type2Enum<char *>::et:
// 			_ntoa(VAL, *(char **)valCpp);
// 			return true;
		case Variant::Type2Enum<std::string>::et:
			{
				char buf[32];
				*(std::string*)valCpp = _ntoa(VAL, buf);
			}
			return true;
		case Variant::Type2Enum<bool>::et:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case Variant::Type2Enum<float>::et:
			*(float *)valCpp = (float)VAL;
			return true;
		case Variant::Type2Enum<double>::et:
			*(double *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::int8_t>::et:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int16_t>::et:
			*(boost::int16_t *)valCpp = (boost::int16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::int32_t>::et:
			*(boost::int32_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::int64_t>::et:
			*(boost::int64_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::uint8_t>::et:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint16_t>::et:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)VAL;
			return true;
		case Variant::Type2Enum<boost::uint32_t>::et:
			*(boost::uint32_t *)valCpp = VAL;
			return true;
		case Variant::Type2Enum<boost::uint64_t>::et:
			*(boost::uint64_t *)valCpp = VAL;
			return true;

// 		case Variant::Type2Enum<Blob>::et:
// 			{
// 				Blob &bl = *(Blob *)valCpp;
// 				bl._impl->oid(VAL);
// 				bl._impl->con(_con);
// 			}
// 			return true;
		}
#undef VAL

		//assert(!"unsupported cpp type for oid");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::extractor_null			(int /*rowIdx*/, int /*colIdx*/, Variant::EType /*typCpp*/, void * /*valCpp*/)
	{
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
}
