#include "resultImpl.hpp"
#include "connectionImpl.hpp"
#include "pgc/cppDataType.hpp"
#include "pgDataType.h"
#include "utils/fixEndian.hpp"
#include "utils/ntoa.hpp"
#include "utils/aton.hpp"
#include "utils/julian.h"

#include "pgc/blob.hpp"
#include "blobImpl.hpp"

#include <boost/static_assert.hpp>


namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	bool ResultImpl::extractor_int2			(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgres, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (utils::fixEndian(*(boost::int16_t *)valDb))

		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
// 			utils::_ntoa(VAL, *(char **)valCpp);
// 			return true;
		case CppDataType<std::string>::cdt_index:
			{
				char buf[32];
				*(std::string*)valCpp = utils::_ntoa(VAL, buf);
			}
			return true;
		case CppDataType<bool>::cdt_index:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case CppDataType<float>::cdt_index:
			*(float *)valCpp = VAL;
			return true;
		case CppDataType<double>::cdt_index:
			*(double *)valCpp = VAL;
			return true;
		case CppDataType<boost::int8_t>::cdt_index:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case CppDataType<boost::int16_t>::cdt_index:
			*(boost::int16_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::int32_t>::cdt_index:
			*(boost::int32_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::int64_t>::cdt_index:
			*(boost::int64_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::uint8_t>::cdt_index:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case CppDataType<boost::uint16_t>::cdt_index:
			*(boost::uint16_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::uint32_t>::cdt_index:
			*(boost::uint32_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::uint64_t>::cdt_index:
			*(boost::uint64_t *)valCpp = VAL;
			return true;
		}
#undef VAL

		//assert(!"unsupported cpp type for int2");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool ResultImpl::extractor_int4			(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgres, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (utils::fixEndian(*(boost::int32_t *)valDb))

		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
// 			utils::_ntoa(VAL, *(char **)valCpp);
// 			return true;
		case CppDataType<std::string>::cdt_index:
			{
				char buf[32];
				*(std::string*)valCpp = utils::_ntoa(VAL, buf);
			}
			return true;
		case CppDataType<bool>::cdt_index:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case CppDataType<float>::cdt_index:
			*(float *)valCpp = (float)VAL;
			return true;
		case CppDataType<double>::cdt_index:
			*(double *)valCpp = VAL;
			return true;
		case CppDataType<boost::int8_t>::cdt_index:
			*(boost::int8_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::int16_t>::cdt_index:
			*(boost::int16_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::int32_t>::cdt_index:
			*(boost::int32_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::int64_t>::cdt_index:
			*(boost::int64_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::uint8_t>::cdt_index:
			*(boost::uint8_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::uint16_t>::cdt_index:
			*(boost::uint16_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::uint32_t>::cdt_index:
			*(boost::uint32_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::uint64_t>::cdt_index:
			*(boost::uint64_t *)valCpp = VAL;
			return true;
		}
#undef VAL

		//assert(!"unsupported cpp type for int4");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool ResultImpl::extractor_int8			(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgres, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (utils::fixEndian(*(boost::int64_t *)valDb))

		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
// 			utils::_ntoa(VAL, *(char **)valCpp);
// 			return true;
		case CppDataType<std::string>::cdt_index:
			{
				char buf[32];
				*(std::string*)valCpp = utils::_ntoa(VAL, buf);
			}
			return true;
		case CppDataType<bool>::cdt_index:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case CppDataType<float>::cdt_index:
			*(float *)valCpp = (float)VAL;
			return true;
		case CppDataType<double>::cdt_index:
			*(double *)valCpp = (double)VAL;
			return true;
		case CppDataType<boost::int8_t>::cdt_index:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case CppDataType<boost::int16_t>::cdt_index:
			*(boost::int16_t *)valCpp = (boost::int16_t)VAL;
			return true;
		case CppDataType<boost::int32_t>::cdt_index:
			*(boost::int32_t *)valCpp = (boost::int32_t)VAL;
			return true;
		case CppDataType<boost::int64_t>::cdt_index:
			*(boost::int64_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::uint8_t>::cdt_index:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case CppDataType<boost::uint16_t>::cdt_index:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)VAL;
			return true;
		case CppDataType<boost::uint32_t>::cdt_index:
			*(boost::uint32_t *)valCpp = (boost::uint32_t)VAL;
			return true;
		case CppDataType<boost::uint64_t>::cdt_index:
			*(boost::uint64_t *)valCpp = VAL;
			return true;
		}
#undef VAL

		//assert(!"unsupported cpp type for int8");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool ResultImpl::extractor_numeric		(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgres, rowIdx, colIdx);
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

		int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
		std::vector<unsigned char> buf(lenDb);
		memcpy(&buf.front(), valDb, lenDb);
		PG_NumericData &v = *(PG_NumericData *)&buf.front();

		v.ndigits = utils::fixEndian(v.ndigits);
		v.weight = utils::fixEndian(v.weight);
		//v.sign = utils::fixEndian(v.sign);
		v.dscale = utils::fixEndian(v.dscale);


		std::vector<char> strBuf;
		char *str = NULL;

		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
// 			str = *(char **)valCpp;
// 			break;
		case CppDataType<std::string>::cdt_index:
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
			v.NumericDigits[idx] = utils::fixEndian(v.NumericDigits[idx]);
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
		BOOST_STATIC_ASSERT(1 == sizeof(char));
		BOOST_STATIC_ASSERT(2 == sizeof(short));
		BOOST_STATIC_ASSERT(4 == sizeof(int));
		BOOST_STATIC_ASSERT(8 == sizeof(long long));

		//////////////////////////////////////////////////////////////////////////
		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
// 			//уже все готово
// 			return true;
		case CppDataType<std::string>::cdt_index:
			{
				std::string &strCpp = *(std::string*)valCpp;
				strCpp.resize(strlen(strCpp.c_str()));
			}
			return true;
		case CppDataType<bool>::cdt_index:
			*(bool *)valCpp = utils::_atoc(str)?true:false;
			return true;
		case CppDataType<float>::cdt_index:
			if(1 != sscanf(str, "%f", (float *)valCpp))
			{
				*(float *)valCpp = 0;
			}
			return true;
		case CppDataType<double>::cdt_index:
			if(1 != sscanf(str, "%lf", (double *)valCpp))
			{
				*(double *)valCpp = 0;
			}
			return true;
		case CppDataType<boost::int8_t>::cdt_index:
			*(boost::int8_t *)valCpp = utils::_atoc(str);
			return true;
		case CppDataType<boost::int16_t>::cdt_index:
			*(boost::int16_t *)valCpp = utils::_atos(str);
			return true;
		case CppDataType<boost::int32_t>::cdt_index:
			*(boost::int32_t *)valCpp = utils::_atoi(str);
			return true;
		case CppDataType<boost::int64_t>::cdt_index:
			*(boost::int64_t *)valCpp = utils::_atoll(str);
			return true;
		case CppDataType<boost::uint8_t>::cdt_index:
			*(boost::uint8_t *)valCpp = utils::_atouc(str);
			return true;
		case CppDataType<boost::uint16_t>::cdt_index:
			*(boost::uint16_t *)valCpp = utils::_atous(str);
			return true;
		case CppDataType<boost::uint32_t>::cdt_index:
			*(boost::uint32_t *)valCpp = utils::_atoui(str);
			return true;
		case CppDataType<boost::uint64_t>::cdt_index:
			*(boost::uint64_t *)valCpp = utils::_atoul(str);
			return true;
		}


		//assert(!"unsupported cpp type for numeric");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool ResultImpl::extractor_float4		(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgres, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (utils::fixEndian(*(float *)valDb))

		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
// 			sprintf(*(char **)valCpp, "%.7g", (double)VAL);
// 			return true;
		case CppDataType<std::string>::cdt_index:
			{
				char buf[32];
				sprintf(buf, "%.7g", (double)VAL);
				*(std::string*)valCpp = buf;
			}
			return true;
		case CppDataType<bool>::cdt_index:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case CppDataType<float>::cdt_index:
			*(float *)valCpp = VAL;
			return true;
		case CppDataType<double>::cdt_index:
			*(double *)valCpp = VAL;
			return true;
		case CppDataType<boost::int8_t>::cdt_index:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case CppDataType<boost::int16_t>::cdt_index:
			*(boost::int16_t *)valCpp = (boost::int16_t)VAL;
			return true;
		case CppDataType<boost::int32_t>::cdt_index:
			*(boost::int32_t *)valCpp = (boost::int32_t)VAL;
			return true;
		case CppDataType<boost::int64_t>::cdt_index:
			*(boost::int64_t *)valCpp = (boost::int64_t)VAL;
			return true;
		case CppDataType<boost::uint8_t>::cdt_index:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case CppDataType<boost::uint16_t>::cdt_index:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)VAL;
			return true;
		case CppDataType<boost::uint32_t>::cdt_index:
			*(boost::uint32_t *)valCpp = (boost::uint32_t)VAL;
			return true;
		case CppDataType<boost::uint64_t>::cdt_index:
			*(boost::uint64_t *)valCpp = (boost::uint64_t)VAL;
			return true;
		}
#undef VAL

		//assert(!"unsupported cpp type for float4");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool ResultImpl::extractor_float8		(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgres, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (utils::fixEndian(*(double *)valDb))

		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
// 			sprintf(*(char **)valCpp, "%.7g", VAL);
// 			return true;
		case CppDataType<std::string>::cdt_index:
			{
				char buf[32];
				sprintf(buf, "%.7g", VAL);
				*(std::string*)valCpp = buf;
			}
			return true;
		case CppDataType<bool>::cdt_index:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case CppDataType<float>::cdt_index:
			*(float *)valCpp = (float)VAL;
			return true;
		case CppDataType<double>::cdt_index:
			*(double *)valCpp = VAL;
			return true;
		case CppDataType<boost::int8_t>::cdt_index:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case CppDataType<boost::int16_t>::cdt_index:
			*(boost::int16_t *)valCpp = (boost::int16_t)VAL;
			return true;
		case CppDataType<boost::int32_t>::cdt_index:
			*(boost::int32_t *)valCpp = (boost::int32_t)VAL;
			return true;
		case CppDataType<boost::int64_t>::cdt_index:
			*(boost::int64_t *)valCpp = (boost::int64_t)VAL;
			return true;
		case CppDataType<boost::uint8_t>::cdt_index:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case CppDataType<boost::uint16_t>::cdt_index:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)VAL;
			return true;
		case CppDataType<boost::uint32_t>::cdt_index:
			*(boost::uint32_t *)valCpp = (boost::uint32_t)VAL;
			return true;
		case CppDataType<boost::uint64_t>::cdt_index:
			*(boost::uint64_t *)valCpp = (boost::uint64_t)VAL;
			return true;
		}
#undef VAL

		//assert(!"unsupported cpp type for float8");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool ResultImpl::extractor_money		(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgres, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (utils::fixEndian(*(boost::int64_t *)valDb))

		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
// 			utils::_ntoa(VAL, *(char **)valCpp);
// 			return true;
		case CppDataType<std::string>::cdt_index:
			{
				char buf[32];
				*(std::string*)valCpp = utils::_ntoa(VAL, buf);
			}
			return true;
		case CppDataType<bool>::cdt_index:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case CppDataType<float>::cdt_index:
			*(float *)valCpp = (float)VAL;
			return true;
		case CppDataType<double>::cdt_index:
			*(double *)valCpp = (double)VAL;
			return true;
		case CppDataType<boost::int8_t>::cdt_index:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case CppDataType<boost::int16_t>::cdt_index:
			*(boost::int16_t *)valCpp = (boost::int16_t)VAL;
			return true;
		case CppDataType<boost::int32_t>::cdt_index:
			*(boost::int32_t *)valCpp = (boost::int32_t)VAL;
			return true;
		case CppDataType<boost::int64_t>::cdt_index:
			*(boost::int64_t *)valCpp = (boost::int64_t)VAL;
			return true;
		case CppDataType<boost::uint8_t>::cdt_index:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case CppDataType<boost::uint16_t>::cdt_index:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)VAL;
			return true;
		case CppDataType<boost::uint32_t>::cdt_index:
			*(boost::uint32_t *)valCpp = (boost::uint32_t)VAL;
			return true;
		case CppDataType<boost::uint64_t>::cdt_index:
			*(boost::uint64_t *)valCpp = (boost::uint64_t)VAL;
			return true;
		case CppDataType<Money>::cdt_index:
			((Money *)valCpp)->_value = VAL;
			return true;
		}
#undef VAL

		//assert(!"unsupported cpp type for money");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool ResultImpl::extractor_varchar		(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgres, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

		//////////////////////////////////////////////////////////////////////////
		BOOST_STATIC_ASSERT(1 == sizeof(char));
		BOOST_STATIC_ASSERT(2 == sizeof(short));
		BOOST_STATIC_ASSERT(4 == sizeof(int));
		BOOST_STATIC_ASSERT(8 == sizeof(long long));

		//////////////////////////////////////////////////////////////////////////
		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
// 			{
// 				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
// 				memcpy(*(char **)valCpp, valDb, lenDb);
// 				(*(char **)valCpp)[lenDb] = 0;
// 			}
// 			return true;
		case CppDataType<std::string>::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				std::string &strCpp = *(std::string*)valCpp;
				strCpp.assign(valDb, valDb+lenDb);
			}
			return true;
		case CppDataType<bool>::cdt_index:
			*(bool *)valCpp = utils::_atoc(valDb)?true:false;
			return true;
		case CppDataType<float>::cdt_index:
			if(1 != sscanf(valDb, "%f", (float *)valCpp))
			{
				*(float *)valCpp = 0;
			}
			return true;
		case CppDataType<double>::cdt_index:
			if(1 != sscanf(valDb, "%lf", (double *)valCpp))
			{
				*(double *)valCpp = 0;
			}
			return true;
		case CppDataType<boost::int8_t>::cdt_index:
			*(boost::int8_t *)valCpp = utils::_atoc(valDb);
			return true;
		case CppDataType<boost::int16_t>::cdt_index:
			*(boost::int16_t *)valCpp = utils::_atos(valDb);
			return true;
		case CppDataType<boost::int32_t>::cdt_index:
			*(boost::int32_t *)valCpp = utils::_atoi(valDb);
			return true;
		case CppDataType<boost::int64_t>::cdt_index:
			*(boost::int64_t *)valCpp = utils::_atoll(valDb);
			return true;
		case CppDataType<boost::uint8_t>::cdt_index:
			*(boost::uint8_t *)valCpp = utils::_atouc(valDb);
			return true;
		case CppDataType<boost::uint16_t>::cdt_index:
			*(boost::uint16_t *)valCpp = utils::_atous(valDb);
			return true;
		case CppDataType<boost::uint32_t>::cdt_index:
			*(boost::uint32_t *)valCpp = utils::_atoui(valDb);
			return true;
		case CppDataType<boost::uint64_t>::cdt_index:
			*(boost::uint64_t *)valCpp = utils::_atoul(valDb);
			return true;
		case CppDataType<std::vector<unsigned char> >::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
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
	bool ResultImpl::extractor_bytea		(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgres, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

		//////////////////////////////////////////////////////////////////////////
		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
// 			{
// 				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
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
		case CppDataType<std::string>::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				std::string &strCpp = *(std::string*)valCpp;
				strCpp.assign(valDb, valDb+lenDb);
			}
			return true;
		case CppDataType<bool>::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				(*(bool*)valCpp) = lenDb?true:false;
			}
			return true;
		case CppDataType<std::bitset<8> >::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				impl::bytea2Bitset(*(std::bitset<8>*)valCpp, lenDb*8, valDb);
			}
			return true;
		case CppDataType<std::bitset<16> >::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				impl::bytea2Bitset(*(std::bitset<16>*)valCpp, lenDb*8, valDb);
			}
			return true;
		case CppDataType<std::bitset<32> >::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				impl::bytea2Bitset(*(std::bitset<32>*)valCpp, lenDb*8, valDb);
			}
			return true;
		case CppDataType<std::bitset<64> >::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				impl::bytea2Bitset(*(std::bitset<64>*)valCpp, lenDb*8, valDb);
			}
			return true;
		case CppDataType<std::bitset<128> >::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				impl::bytea2Bitset(*(std::bitset<128>*)valCpp, lenDb*8, valDb);
			}
			return true;
		case CppDataType<std::bitset<256> >::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				impl::bytea2Bitset(*(std::bitset<256>*)valCpp, lenDb*8, valDb);
			}
			return true;
		case CppDataType<std::bitset<512> >::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				impl::bytea2Bitset(*(std::bitset<512>*)valCpp, lenDb*8, valDb);
			}
			return true;
		case CppDataType<std::vector<unsigned char> >::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				(*(std::vector<unsigned char> *)valCpp).assign((unsigned char *)valDb, (unsigned char *)valDb+lenDb);
			}
			return true;
		}


		//assert(!"unsupported cpp type for bytea");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool ResultImpl::extractor_timestamp	(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgres, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

		boost::uint64_t VAL;
		if(_con->integerDatetimes())
		{
			VAL = utils::fixEndian(*(boost::uint64_t *)valDb);
		}
		else
		{
			double v = utils::fixEndian(*(double *)valDb);
			VAL = (boost::int64_t)v;
			v -= VAL;
			VAL *= 1000000;
			VAL += (boost::uint64_t)(v*1000000 + 0.5);
		}


		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
		case CppDataType<std::string>::cdt_index:
		case CppDataType<std::tm>::cdt_index:
			{
				boost::int64_t time, date;
				time = VAL;
				utils::TMODULO(time, date, utils::USECS_PER_DAY);

				if(time < 0)
				{
					time += utils::USECS_PER_DAY;
					date -= 1;
				}

				/* add offset to go from J2000 back to standard Julian date */
				date += utils::POSTGRES_EPOCH_JDATE;

				switch(typCpp)
				{
// 				case CppDataType<char *>::cdt_index:
// 					{
// 						int year, month, day, hour, min, sec, fsec;
// 						utils::j2date((int) date, &year, &month, &day);
// 						utils::dt2time(time, &hour, &min, &sec, &fsec);
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
				case CppDataType<std::string>::cdt_index:
					{
						int year, month, day, hour, min, sec, fsec;
						utils::j2date((int) date, &year, &month, &day);
						utils::dt2time(time, &hour, &min, &sec, &fsec);

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
				case CppDataType<std::tm>::cdt_index:
					{
						std::tm &stm = *(std::tm *)valCpp;
						memset(&stm, 0, sizeof(std::tm));
						int fsec;
						
						utils::j2date((int) date, &stm.tm_year, &stm.tm_mon, &stm.tm_mday);
						utils::dt2time(time, &stm.tm_hour, &stm.tm_min, &stm.tm_sec, &fsec);

						stm.tm_year -= 1900;
						stm.tm_mon -= 1;
						stm.tm_isdst = -1;
					}
					break;
				}
			}
			return true;
		case CppDataType<float>::cdt_index:
			*(float *)valCpp = (float)VAL;
			return true;
		case CppDataType<double>::cdt_index:
			*(double *)valCpp = (double)VAL;
			return true;
		case CppDataType<boost::int8_t>::cdt_index:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case CppDataType<boost::int16_t>::cdt_index:
			*(boost::int16_t *)valCpp = (boost::int16_t)VAL;
			return true;
		case CppDataType<boost::int32_t>::cdt_index:
			*(boost::int32_t *)valCpp = (boost::int32_t)VAL;
			return true;
		case CppDataType<boost::int64_t>::cdt_index:
			*(boost::int64_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::uint8_t>::cdt_index:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case CppDataType<boost::uint16_t>::cdt_index:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)VAL;
			return true;
		case CppDataType<boost::uint32_t>::cdt_index:
			*(boost::uint32_t *)valCpp = (boost::uint32_t)VAL;
			return true;
		case CppDataType<boost::uint64_t>::cdt_index:
			*(boost::uint64_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::gregorian::date>::cdt_index:
			{
				boost::int64_t time, date;
				time = VAL;
				utils::TMODULO(time, date, utils::USECS_PER_DAY);

				if(time < 0)
				{
					time += utils::USECS_PER_DAY;
					date -= 1;
				}

				/* add offset to go from J2000 back to standard Julian date */
				date += utils::POSTGRES_EPOCH_JDATE;

				int year, month, day;
				utils::j2date((int) date, &year, &month, &day);

				*(boost::gregorian::date*)valCpp = boost::gregorian::date(year, month, day);
			}
			return true;
		case CppDataType<boost::posix_time::time_duration>::cdt_index:
			{
				boost::int64_t time, date;
				time = VAL;
				utils::TMODULO(time, date, utils::USECS_PER_DAY);

				if(time < 0)
				{
					time += utils::USECS_PER_DAY;
					//date -= 1;
				}

				int hour, min, sec, fsec;
				utils::dt2time(time, &hour, &min, &sec, &fsec);

				boost::int64_t fsecl = (boost::int64_t)fsec * utils::USECS_PER_SEC / boost::posix_time::time_duration::ticks_per_second();

				*(boost::posix_time::time_duration*)valCpp = 
					boost::posix_time::time_duration(hour, min, sec, fsecl);
			}
			return true;
		case CppDataType<boost::posix_time::ptime>::cdt_index:
			{
				boost::int64_t time, date;
				time = VAL;
				utils::TMODULO(time, date, utils::USECS_PER_DAY);

				if(time < 0)
				{
					time += utils::USECS_PER_DAY;
					date -= 1;
				}

				/* add offset to go from J2000 back to standard Julian date */
				date += utils::POSTGRES_EPOCH_JDATE;

				int year, month, day, hour, min, sec, fsec;
				utils::j2date((int) date, &year, &month, &day);
				utils::dt2time(time, &hour, &min, &sec, &fsec);

				boost::int64_t fsecl = (boost::int64_t)fsec * utils::USECS_PER_SEC / boost::posix_time::time_duration::ticks_per_second();

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
	bool ResultImpl::extractor_interval		(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgres, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}


		unsigned char buf[sizeof(PG_Interval)];
		memcpy(buf, valDb, sizeof(PG_Interval));
		PG_Interval &v = *(PG_Interval *)buf;

		//v.time = utils::fixEndian(v.time);
		v.day = utils::fixEndian(v.day);
		v.month = utils::fixEndian(v.month);


		if(_con->integerDatetimes())
		{
			v.time = utils::fixEndian(v.time);
		}
		else
		{
			double dv = utils::fixEndian(*(double *)&v.time);
			v.time = (boost::int64_t)dv;
			dv -= v.time;
			v.time *= 1000000;
			v.time += (boost::uint64_t)(dv*1000000 + 0.5);
		}
		//v.time += utils::USECS_PER_DAY*(v.day + v.month*utils::DAYS_PER_MONTH);

#define VAL (v.time)


		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
// 			{
// 				int hour, min, sec, fsec;
// 				utils::dt2time(v.time, &hour, &min, &sec, &fsec);
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
		case CppDataType<std::string>::cdt_index:
			{
				int hour, min, sec, fsec;
				utils::dt2time(v.time, &hour, &min, &sec, &fsec);

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
		case CppDataType<bool>::cdt_index:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case CppDataType<float>::cdt_index:
			*(float *)valCpp = (float)(((double)(VAL + utils::USECS_PER_DAY*(v.day + v.month*utils::DAYS_PER_MONTH)))/1000000);
			return true;
		case CppDataType<double>::cdt_index:
			*(double *)valCpp = (((double)(VAL + utils::USECS_PER_DAY*(v.day + v.month*utils::DAYS_PER_MONTH)))/1000000);
			return true;
		case CppDataType<boost::int8_t>::cdt_index:
			*(boost::int8_t *)valCpp = (boost::int8_t)(VAL + utils::USECS_PER_DAY*(v.day + v.month*utils::DAYS_PER_MONTH));
			return true;
		case CppDataType<boost::int16_t>::cdt_index:
			*(boost::int16_t *)valCpp = (boost::int16_t)(VAL + utils::USECS_PER_DAY*(v.day + v.month*utils::DAYS_PER_MONTH));
			return true;
		case CppDataType<boost::int32_t>::cdt_index:
			*(boost::int32_t *)valCpp = (boost::int32_t)(VAL + utils::USECS_PER_DAY*(v.day + v.month*utils::DAYS_PER_MONTH));
			return true;
		case CppDataType<boost::int64_t>::cdt_index:
			*(boost::int64_t *)valCpp = (VAL + utils::USECS_PER_DAY*(v.day + v.month*utils::DAYS_PER_MONTH));
			return true;
		case CppDataType<boost::uint8_t>::cdt_index:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)(VAL + utils::USECS_PER_DAY*(v.day + v.month*utils::DAYS_PER_MONTH));
			return true;
		case CppDataType<boost::uint16_t>::cdt_index:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)(VAL + utils::USECS_PER_DAY*(v.day + v.month*utils::DAYS_PER_MONTH));
			return true;
		case CppDataType<boost::uint32_t>::cdt_index:
			*(boost::uint32_t *)valCpp = (boost::uint32_t)(VAL + utils::USECS_PER_DAY*(v.day + v.month*utils::DAYS_PER_MONTH));
			return true;
		case CppDataType<boost::uint64_t>::cdt_index:
			*(boost::uint64_t *)valCpp = (VAL + utils::USECS_PER_DAY*(v.day + v.month*utils::DAYS_PER_MONTH));
			return true;
		case CppDataType<boost::posix_time::time_duration>::cdt_index:
			{
				int hour, min, sec, fsec;
				utils::dt2time(v.time, &hour, &min, &sec, &fsec);

				boost::int64_t fsecl = (boost::int64_t)fsec * utils::USECS_PER_SEC / boost::posix_time::time_duration::ticks_per_second();

				*(boost::posix_time::time_duration*)valCpp = 
					boost::posix_time::time_duration(hour, min, sec, fsecl);
			}
			return true;
		case CppDataType<boost::gregorian::date_duration>::cdt_index:
			{
				*(boost::gregorian::date_duration*)valCpp = 
					boost::gregorian::date_duration(v.day + v.month*utils::DAYS_PER_MONTH);
			}
			return true;
		case CppDataType<DateTimeDuration>::cdt_index:
			{
				DateTimeDuration &dtd = *(DateTimeDuration *)valCpp;

				dtd._dd = boost::gregorian::date_duration(v.day + v.month*utils::DAYS_PER_MONTH);

				int hour, min, sec, fsec;
				utils::dt2time(v.time, &hour, &min, &sec, &fsec);

				boost::int64_t fsecl = (boost::int64_t)fsec * utils::USECS_PER_SEC / boost::posix_time::time_duration::ticks_per_second();
				dtd._td = boost::posix_time::time_duration(hour, min, sec, fsecl);
			}
			return true;
		}
#undef VAL

		//assert(!"unsupported cpp type for interval");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool ResultImpl::extractor_date			(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgres, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (utils::fixEndian(*(boost::int32_t *)valDb) + utils::POSTGRES_EPOCH_JDATE)

		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
// 			{
// 				int year, month, day;
// 				utils::j2date(VAL, &year, &month, &day);
// 
// 				sprintf(*(char **)valCpp, "%04d-%02d-%02d", 
// 					year, month, day);
// 			}
// 			return true;
		case CppDataType<std::string>::cdt_index:
			{
				int year, month, day;
				utils::j2date(VAL, &year, &month, &day);

				char buf[128];
				sprintf(buf, "%04d-%02d-%02d", 
					year, month, day);
				*(std::string*)valCpp = buf;
			}
			return true;
		case CppDataType<float>::cdt_index:
			*(float *)valCpp = (float)VAL;
			return true;
		case CppDataType<double>::cdt_index:
			*(double *)valCpp = (double)VAL;
			return true;
		case CppDataType<boost::int8_t>::cdt_index:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case CppDataType<boost::int16_t>::cdt_index:
			*(boost::int16_t *)valCpp = (boost::int16_t)VAL;
			return true;
		case CppDataType<boost::int32_t>::cdt_index:
			*(boost::int32_t *)valCpp = (boost::int32_t)VAL;
			return true;
		case CppDataType<boost::int64_t>::cdt_index:
			*(boost::int64_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::uint8_t>::cdt_index:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case CppDataType<boost::uint16_t>::cdt_index:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)VAL;
			return true;
		case CppDataType<boost::uint32_t>::cdt_index:
			*(boost::uint32_t *)valCpp = (boost::uint32_t)VAL;
			return true;
		case CppDataType<boost::uint64_t>::cdt_index:
			*(boost::uint64_t *)valCpp = VAL;
			return true;
		case CppDataType<std::tm>::cdt_index:
			{
				std::tm &stm = *(std::tm *)valCpp;
				memset(&stm, 0, sizeof(std::tm));

				utils::j2date(VAL, &stm.tm_year, &stm.tm_mon, &stm.tm_mday);

				stm.tm_year -= 1900;
				stm.tm_mon -= 1;
				stm.tm_isdst = -1;
			}
			return true;
		case CppDataType<boost::gregorian::date>::cdt_index:
			{
				int year, month, day;
				utils::j2date(VAL, &year, &month, &day);

				*(boost::gregorian::date*)valCpp = boost::gregorian::date(year, month, day);
			}
			return true;
		case CppDataType<boost::posix_time::ptime>::cdt_index:
			{
				int year, month, day;
				utils::j2date(VAL, &year, &month, &day);

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
	bool ResultImpl::extractor_time			(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgres, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

		boost::uint64_t VAL;
		if(_con->integerDatetimes())
		{
			VAL = utils::fixEndian(*(boost::uint64_t *)valDb);
		}
		else
		{
			double v = utils::fixEndian(*(double *)valDb);
			VAL = (boost::int64_t)v;
			v -= VAL;
			VAL *= 1000000;
			VAL += (boost::uint64_t)(v*1000000 + 0.5);
		}

		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
// 			{
// 				int hour, min, sec, fsec;
// 				utils::dt2time(VAL, &hour, &min, &sec, &fsec);
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
		case CppDataType<std::string>::cdt_index:
			{
				int hour, min, sec, fsec;
				utils::dt2time(VAL, &hour, &min, &sec, &fsec);

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
		case CppDataType<bool>::cdt_index:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case CppDataType<float>::cdt_index:
			*(float *)valCpp = (float)VAL;
			return true;
		case CppDataType<double>::cdt_index:
			*(double *)valCpp = (double)VAL;
			return true;
		case CppDataType<boost::int8_t>::cdt_index:
			*(boost::int8_t *)valCpp = (boost::int8_t)VAL;
			return true;
		case CppDataType<boost::int16_t>::cdt_index:
			*(boost::int16_t *)valCpp = (boost::int16_t)VAL;
			return true;
		case CppDataType<boost::int32_t>::cdt_index:
			*(boost::int32_t *)valCpp = (boost::int32_t)VAL;
			return true;
		case CppDataType<boost::int64_t>::cdt_index:
			*(boost::int64_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::uint8_t>::cdt_index:
			*(boost::uint8_t *)valCpp = (boost::uint8_t)VAL;
			return true;
		case CppDataType<boost::uint16_t>::cdt_index:
			*(boost::uint16_t *)valCpp = (boost::uint16_t)VAL;
			return true;
		case CppDataType<boost::uint32_t>::cdt_index:
			*(boost::uint32_t *)valCpp = (boost::uint32_t)VAL;
			return true;
		case CppDataType<boost::uint64_t>::cdt_index:
			*(boost::uint64_t *)valCpp = VAL;
			return true;
		case CppDataType<std::tm>::cdt_index:
			{
				std::tm &stm = *(std::tm *)valCpp;
				memset(&stm, 0, sizeof(std::tm));

				int fsec;
				utils::dt2time(VAL, &stm.tm_hour, &stm.tm_min, &stm.tm_sec, &fsec);

				stm.tm_isdst = -1;
			}
			return true;
		case CppDataType<boost::posix_time::time_duration>::cdt_index:
			{
				int hour, min, sec, fsec;
				utils::dt2time(VAL, &hour, &min, &sec, &fsec);

				boost::int64_t fsecl = (boost::int64_t)fsec * utils::USECS_PER_SEC / boost::posix_time::time_duration::ticks_per_second();

				*(boost::posix_time::time_duration*)valCpp = 
					boost::posix_time::time_duration(hour, min, sec, fsecl);
			}
			return true;
		case CppDataType<DateTimeDuration>::cdt_index:
			{
				int hour, min, sec, fsec;
				utils::dt2time(VAL, &hour, &min, &sec, &fsec);

				boost::int64_t fsecl = (boost::int64_t)fsec * utils::USECS_PER_SEC / boost::posix_time::time_duration::ticks_per_second();

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
	bool ResultImpl::extractor_bool			(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgres, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (*(boost::int8_t *)valDb)

		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
// 			(*(char **)valCpp)[0] = VAL?'1':'0';
// 			(*(char **)valCpp)[1] = 0;
// 			return true;
		case CppDataType<std::string>::cdt_index:
			{
				(*(std::string*)valCpp) = VAL?"1":"0";
			}
			return true;
		case CppDataType<bool>::cdt_index:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case CppDataType<float>::cdt_index:
			*(float *)valCpp = VAL?1.0f:0.0f;
			return true;
		case CppDataType<double>::cdt_index:
			*(double *)valCpp = VAL?1:0;
			return true;
		case CppDataType<boost::int8_t>::cdt_index:
			*(boost::int8_t *)valCpp = VAL?1:0;
			return true;
		case CppDataType<boost::int16_t>::cdt_index:
			*(boost::int16_t *)valCpp = VAL?1:0;
			return true;
		case CppDataType<boost::int32_t>::cdt_index:
			*(boost::int32_t *)valCpp = VAL?1:0;
			return true;
		case CppDataType<boost::int64_t>::cdt_index:
			*(boost::int64_t *)valCpp = VAL?1:0;
			return true;
		case CppDataType<boost::uint8_t>::cdt_index:
			*(boost::uint8_t *)valCpp = VAL?1:0;
			return true;
		case CppDataType<boost::uint16_t>::cdt_index:
			*(boost::uint16_t *)valCpp = VAL?1:0;
			return true;
		case CppDataType<boost::uint32_t>::cdt_index:
			*(boost::uint32_t *)valCpp = VAL?1:0;
			return true;
		case CppDataType<boost::uint64_t>::cdt_index:
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
	bool ResultImpl::extractor_varbit		(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgres, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

		int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
		std::vector<unsigned char> buf(lenDb);
		memcpy(&buf.front(), valDb, lenDb);
		PG_VarBit &v = *(PG_VarBit *)&buf.front();

		v.amount = utils::fixEndian(v.amount);

		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
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
		case CppDataType<std::string>::cdt_index:
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
		case CppDataType<bool>::cdt_index:
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
		case CppDataType<float>::cdt_index:
			impl::bits2POD(*(float *)valCpp, v.amount, v.bits);
			return true;
		case CppDataType<double>::cdt_index:
			impl::bits2POD(*(double *)valCpp, v.amount, v.bits);
			return true;
		case CppDataType<boost::int8_t>::cdt_index:
			impl::bits2POD(*(boost::int8_t *)valCpp, v.amount, v.bits);
			return true;
		case CppDataType<boost::int16_t>::cdt_index:
			impl::bits2POD(*(boost::int16_t *)valCpp, v.amount, v.bits);
			return true;
		case CppDataType<boost::int32_t>::cdt_index:
			impl::bits2POD(*(boost::int32_t *)valCpp, v.amount, v.bits);
			return true;
		case CppDataType<boost::int64_t>::cdt_index:
			impl::bits2POD(*(boost::int64_t *)valCpp, v.amount, v.bits);
			return true;
		case CppDataType<boost::uint8_t>::cdt_index:
			impl::bits2POD(*(boost::uint8_t *)valCpp, v.amount, v.bits);
			return true;
		case CppDataType<boost::uint16_t>::cdt_index:
			impl::bits2POD(*(boost::uint16_t *)valCpp, v.amount, v.bits);
			return true;
		case CppDataType<boost::uint32_t>::cdt_index:
			impl::bits2POD(*(boost::uint32_t *)valCpp, v.amount, v.bits);
			return true;
		case CppDataType<boost::uint64_t>::cdt_index:
			impl::bits2POD(*(boost::uint64_t *)valCpp, v.amount, v.bits);
			return true;
		case CppDataType<std::bitset<8> >::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				impl::bits2Bitset(*(std::bitset<8>*)valCpp, v.amount, v.bits);
			}
			return true;
		case CppDataType<std::bitset<16> >::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				impl::bits2Bitset(*(std::bitset<16>*)valCpp, v.amount, v.bits);
			}
			return true;
		case CppDataType<std::bitset<32> >::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				impl::bits2Bitset(*(std::bitset<32>*)valCpp, v.amount, v.bits);
			}
			return true;
		case CppDataType<std::bitset<64> >::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				impl::bits2Bitset(*(std::bitset<64>*)valCpp, v.amount, v.bits);
			}
			return true;
		case CppDataType<std::bitset<128> >::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				impl::bits2Bitset(*(std::bitset<128>*)valCpp, v.amount, v.bits);
			}
			return true;
		case CppDataType<std::bitset<256> >::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				impl::bits2Bitset(*(std::bitset<256>*)valCpp, v.amount, v.bits);
			}
			return true;
		case CppDataType<std::bitset<512> >::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);
				impl::bits2Bitset(*(std::bitset<512>*)valCpp, v.amount, v.bits);
			}
			return true;
		case CppDataType<std::vector<unsigned char> >::cdt_index:
			{
				int lenDb = PQgetlength(_pgres, rowIdx, colIdx);

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
	bool ResultImpl::extractor_oid			(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		char *valDb = PQgetvalue(_pgres, rowIdx, colIdx);
		if(!valDb)
		{
			//null
			return false;
		}

#define VAL (utils::fixEndian(*(boost::uint32_t *)valDb))

		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
// 			utils::_ntoa(VAL, *(char **)valCpp);
// 			return true;
		case CppDataType<std::string>::cdt_index:
			{
				char buf[32];
				*(std::string*)valCpp = utils::_ntoa(VAL, buf);
			}
			return true;
		case CppDataType<bool>::cdt_index:
			*(bool *)valCpp = VAL?true:false;
			return true;
		case CppDataType<float>::cdt_index:
			*(float *)valCpp = (float)VAL;
			return true;
		case CppDataType<double>::cdt_index:
			*(double *)valCpp = VAL;
			return true;
		case CppDataType<boost::int8_t>::cdt_index:
			*(boost::int8_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::int16_t>::cdt_index:
			*(boost::int16_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::int32_t>::cdt_index:
			*(boost::int32_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::int64_t>::cdt_index:
			*(boost::int64_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::uint8_t>::cdt_index:
			*(boost::uint8_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::uint16_t>::cdt_index:
			*(boost::uint16_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::uint32_t>::cdt_index:
			*(boost::uint32_t *)valCpp = VAL;
			return true;
		case CppDataType<boost::uint64_t>::cdt_index:
			*(boost::uint64_t *)valCpp = VAL;
			return true;

		case CppDataType<Blob>::cdt_index:
			{
				Blob &bl = *(Blob *)valCpp;
				bl._impl->oid(VAL);
				bl._impl->con(_con);
			}
			return true;
		}
#undef VAL

		//assert(!"unsupported cpp type for oid");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool ResultImpl::extractor_null			(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
}
