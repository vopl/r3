//
// Copyright (C) 2004-2008 Maciej Sobczak, Stephen Hutton
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#include "StdAfx.h"

#define SOCI_POSTGRESQL_SOURCE
#include "soci-postgresql.h"
#include "common.h"
#include <libpq/libpq-fs.h> // libpq
#include "rawSimpleTypes/utils.hpp"

#ifdef SOCI_POSTGRESQL_NOPARAMS
#define SOCI_POSTGRESQL_NOBINDBYNAME
#endif // SOCI_POSTGRESQL_NOPARAMS

#ifdef _MSC_VER
#pragma warning(disable:4355 4996)
#define snprintf _snprintf
#endif

using namespace soci;
using namespace soci::details;
using namespace soci::details::postgresql;


void postgresql_vector_use_type_backend::bind_by_pos(int & position,
        void * data, exchange_type type)
{
    data_ = data;
    type_ = type;
    position_ = position++;
}

void postgresql_vector_use_type_backend::bind_by_name(
    std::string const & name, void * data, exchange_type type)
{
    data_ = data;
    type_ = type;
    name_ = name;
}

void postgresql_vector_use_type_backend::pre_use(indicator const * ind)
{
    std::size_t const vsize = size();
    for (size_t i = 0; i != vsize; ++i)
    {
		Oid		typ=0;		//type oid
		int		len=0;		//length of data in bytes
		int		fmt=0;		//text=0 or binary=1
		char	*val=NULL;	//data

        // the data in vector can be either i_ok or i_null
        if (ind != NULL && ind[i] == i_null)
        {
            val = NULL;
        }
        else
        {
            // allocate and fill the buffer with text-formatted client data
            switch (type_)
            {

				//////////////////////////////////////////////////////////////////////////
			case x2_String:
				{
					std::vector<SFString> * pv = static_cast<std::vector<SFString> *>(data_);
					std::vector<SFString> & v = *pv;

					typ = 1043;//varchar
					len = v[i].size();
					fmt = 1;
					val = new char[len];
					memmove(val, v[i].data(), len);
				}
				break;


				//////////////////////////////////////////////////////////////////////////
			case x2_Bits8:
				{
					std::vector<SFBits8> * pv = static_cast<std::vector<SFBits8> *>(data_);
					std::vector<SFBits8> & v = *pv;

					typ = 1562;//varbit
					len = 8;
					fmt = 1;
					val = new char[len/8];
					rst::bitset2bin(v[i], val, len);
				}
				break;


				//////////////////////////////////////////////////////////////////////////
			case x2_Bits16:
				{
					std::vector<SFBits16> * pv = static_cast<std::vector<SFBits16> *>(data_);
					std::vector<SFBits16> & v = *pv;

					typ = 1562;//varbit
					len = 16;
					fmt = 1;
					val = new char[len/8];
					rst::bitset2bin(v[i], val, len);
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Bits32:
				{
					std::vector<SFBits32> * pv = static_cast<std::vector<SFBits32> *>(data_);
					std::vector<SFBits32> & v = *pv;

					typ = 1562;//varbit
					len = 32;
					fmt = 1;

					val = new char[len/8];
					rst::bitset2bin(v[i], val, len);
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Bits64:
				{
					std::vector<SFBits64> * pv = static_cast<std::vector<SFBits64> *>(data_);
					std::vector<SFBits64> & v = *pv;

					typ = 1562;//varbit
					len = 64;
					fmt = 1;

					val = new char[len/8];
					rst::bitset2bin(v[i], val, len);
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Bits128:
				{
					std::vector<SFBits128> * pv = static_cast<std::vector<SFBits128> *>(data_);
					std::vector<SFBits128> & v = *pv;

					typ = 1562;//varbit
					len = 128;
					fmt = 1;

					val = new char[len/8];
					rst::bitset2bin(v[i], val, len);
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Bits256:
				{
					std::vector<SFBits256> * pv = static_cast<std::vector<SFBits256> *>(data_);
					std::vector<SFBits256> & v = *pv;

					typ = 1562;//varbit
					len = 256;
					fmt = 1;

					val = new char[len/8];
					rst::bitset2bin(v[i], val, len);
				}
				break;


				//////////////////////////////////////////////////////////////////////////
			case x2_Bytea:
				{
					std::vector<SFBytea> * pv = static_cast<std::vector<SFBytea> *>(data_);
					std::vector<SFBytea> & v = *pv;

					typ = 17;//bytea
					len = v.size();
					fmt = 1;

					val = new char[len];
					std::copy(v[i].begin(), v[i].end(), val);
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Bool:
				{
					std::vector<SFBool> * pv = static_cast<std::vector<SFBool> *>(data_);
					std::vector<SFBool> & v = *pv;

					typ = 16;//bool
					len = 1;
					fmt = 1;

					val = new char[1];
					*val = v[i];
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Real32:
				{
					std::vector<SFReal32> * pv = static_cast<std::vector<SFReal32> *>(data_);
					std::vector<SFReal32> & v = *pv;

					typ = 700;//float4
					len = 4;
					fmt = 1;

					val = new char[4];
					memcpy((char *)&v[i], val, 4);
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Real64:
				{
					std::vector<SFReal64> * pv = static_cast<std::vector<SFReal64> *>(data_);
					std::vector<SFReal64> & v = *pv;

					typ = 701;//float8
					len = 8;
					fmt = 1;

					val = new char[8];
					memcpy((char *)&v[i], val, 8);
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Int8:
				{
					std::vector<SFInt8> * pv = static_cast<std::vector<SFInt8> *>(data_);
					std::vector<SFInt8> & v = *pv;

					typ = 21;//int2
					len = 2;
					fmt = 1;

					val = new char[2];
					val[0] = v[i];
					val[1] = v[i]>=0?0:0xff;
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Int16:
				{
					std::vector<SFInt16> * pv = static_cast<std::vector<SFInt16> *>(data_);
					std::vector<SFInt16> & v = *pv;

					typ = 21;//int2
					len = 2;
					fmt = 1;

					val = new char[2];
					*(SFInt16 *)val = v[i];
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Int32:
				{
					std::vector<SFInt32> * pv = static_cast<std::vector<SFInt32> *>(data_);
					std::vector<SFInt32> & v = *pv;

					typ = 23;//int4
					len = 4;
					fmt = 1;

					val = new char[4];
					*(SFInt32 *)val = v[i];
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Int64:
				{
					std::vector<SFInt64> * pv = static_cast<std::vector<SFInt64> *>(data_);
					std::vector<SFInt64> & v = *pv;

					typ = 20;//int8
					len = 8;
					fmt = 1;

					val = new char[8];
					*(SFInt64 *)val = v[i];
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Uint8:
				{
					std::vector<SFUint8> * pv = static_cast<std::vector<SFUint8> *>(data_);
					std::vector<SFUint8> & v = *pv;

					typ = 21;//int2
					len = 2;
					fmt = 1;

					val = new char[2];
					val[0] = v[i];
					val[1] = 0;
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Uint16:
				{
					std::vector<SFUint16> * pv = static_cast<std::vector<SFUint16> *>(data_);
					std::vector<SFUint16> & v = *pv;

					typ = 23;//int4
					len = 4;
					fmt = 1;

					val = new char[4];
					*(SFInt32 *)val = (SFInt32)(SFUint32)v[i];
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Uint32:
				{
					std::vector<SFUint32> * pv = static_cast<std::vector<SFUint32> *>(data_);
					std::vector<SFUint32> & v = *pv;

					typ = 20;//int8
					len = 8;
					fmt = 1;

					val = new char[8];
					*(SFInt64 *)val = (SFInt64)(SFUint64)v[i];
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Uint64:
				{
					std::vector<SFUint64> * pv = static_cast<std::vector<SFUint64> *>(data_);
					std::vector<SFUint64> & v = *pv;

					if(v[i] & 0x8000000000000000)
					{
						typ = 0;//auto text
						len = 0;
						fmt = 0;
						val = new char[22];
						sprintf(val, "%%") лонг лонг в строку
						memmove(val, v[i].data(), len);

					}
					else
					{
						typ = 20;//int8
						len = 8;
						fmt = 1;

						val = new char[8];
						*(SFInt64 *)val = v[i];
					}
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Date:
				{
					std::vector<SFDate> * pv = static_cast<std::vector<SFDate> *>(data_);
					std::vector<SFDate> & v = *pv;

					typ = 1082;//date
					len = 4;
					fmt = 1;

					val = new char[4];

					BOOST_STATIC_ASSERT(sizeof(v[i].julian_day())==4);
					*(boost::uint32_t *)val = v[i].julian_day();
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Time:
				{
					std::vector<SFTime> * pv = static_cast<std::vector<SFTime> *>(data_);
					std::vector<SFTime> & v = *pv;

					typ = 1083;//time
					len = 8;
					fmt = 1;

					val = new char[8];

					BOOST_STATIC_ASSERT(sizeof(double)==8);
					*(double *)val = 
						double(v[i].total_seconds()) + 
						double(v[i].fractional_seconds())/v[i].ticks_per_second();
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Timestamp:
				{
					std::vector<SFTimestamp> * pv = static_cast<std::vector<SFTimestamp> *>(data_);
					std::vector<SFTimestamp> & v = *pv;

					typ = 1114;//timestamp
					len = 8;
					fmt = 1;

					val = new char[8];

					BOOST_STATIC_ASSERT(sizeof(double)==8);

					const SFDate &d = v[i].date();
					const SFTime &t = v[i].time_of_day();

					*(double *)val = 
						double(d.julian_day()*(24*60*60) + t.total_seconds()) + 
						double(t.fractional_seconds())/t.ticks_per_second();
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Interval:
				{
					std::vector<SFInterval> * pv = static_cast<std::vector<SFInterval> *>(data_);
					std::vector<SFInterval> & v = *pv;

					typ = 1186;//interval
					len = 16;
					fmt = 1;

					val = new char[16];

					const boost::posix_time::ptime::date_duration_type &d = v[i].iDate;
					const SFTime &t = v[i].iTime;

					boost::uint64_t days = d.days();
					boost::uint64_t months = days / 30;
					days -= months*30;

					*(double *)val = 
						double(days*(24*60*60) + t.total_seconds()) + 
						double(t.fractional_seconds())/t.ticks_per_second();

					*(boost::uint64_t*)(val+8) = months;
				}
				break;

				//////////////////////////////////////////////////////////////////////////
			case x2_Money:
				{
					std::vector<SFMoney> * pv = static_cast<std::vector<SFMoney> *>(data_);
					std::vector<SFMoney> & v = *pv;

					typ = 790;//money
					len = 8;
					fmt = 1;

					val = new char[8];

					*(boost::uint64_t*)(val) = v[i]._value;
				}
				break;

            default:
                throw soci_error(
                    "Use vector element used with non-supported type.");
            }
        }

		assert(!"вместе с val провести еще typ, len, fmt");
        buffers_.push_back(val);
    }

    if (position_ > 0)
    {
        // binding by position
        statement_.useByPosBuffers_[position_] = &buffers_[0];
    }
    else
    {
        // binding by name
        statement_.useByNameBuffers_[name_] = &buffers_[0];
    }
}

std::size_t postgresql_vector_use_type_backend::size()
{
    std::size_t sz = 0; // dummy initialization to please the compiler
    switch (type_)
    {



#define RST_ENTRY(i,t,n) case x2_##n: sz = get_vector_size<SF##n>(data_);
#include "rawSimpleTypes/list.h"

    default:
        throw soci_error("Use vector element used with non-supported type.");
    }

    return sz;
}

void postgresql_vector_use_type_backend::clean_up()
{
    std::size_t const bsize = buffers_.size();
    for (std::size_t i = 0; i != bsize; ++i)
    {
        delete [] buffers_[i];
    }
}
