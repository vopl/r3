#ifndef _PRE_USE_HELPER_HPP_
#define _PRE_USE_HELPER_HPP_

#include "rawSimpleTypes/utils.hpp"

namespace soci
{
	namespace
	{
		template<class T, bool forVector>
		struct VTDeductor
		{
			T &operator()(void *data, size_t vidx)
			{
				std::vector<T> * pv = static_cast<std::vector<T> *>(data);
				return pv->operator[](vidx);
			}
		};

		//////////////////////////////////////////////////////////////////////////
		template<class T>
		struct VTDeductor<T, false>
		{
			T &operator()(void *data, size_t /*vidx*/)
			{
				T * pv = static_cast<T *>(data);
				return *pv;
			}
		};
	}
	//////////////////////////////////////////////////////////////////////////
	template<bool forVector>
	void pre_use_switch(details::exchange_type type, void *data, Oid &typ, int &len, int &fmt, char *&val, size_t vidx=0)
	{
        switch (type)
        {

			//////////////////////////////////////////////////////////////////////////
		case x2_String:
			{
				SFString &v = VTDeductor<SFString, forVector>()(data, vidx);

				typ = 1043;//varchar
				len = v.size();
				fmt = 1;
				val = new char[len];
				memmove(val, v.data(), len);
			}
			break;


			//////////////////////////////////////////////////////////////////////////
		case x2_Bits8:
			{
				SFBits8 &v = VTDeductor<SFBits8, forVector>()(data, vidx);

				typ = 1562;//varbit
				len = 8;
				fmt = 1;
				val = new char[len/8];
				rst::bitset2bin(v, val, len);
			}
			break;


			//////////////////////////////////////////////////////////////////////////
		case x2_Bits16:
			{
				SFBits16 &v = VTDeductor<SFBits16, forVector>()(data, vidx);

				typ = 1562;//varbit
				len = 16;
				fmt = 1;
				val = new char[len/8];
				rst::bitset2bin(v, val, len);
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Bits32:
			{
				SFBits32 &v = VTDeductor<SFBits32, forVector>()(data, vidx);

				typ = 1562;//varbit
				len = 32;
				fmt = 1;

				val = new char[len/8];
				rst::bitset2bin(v, val, len);
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Bits64:
			{
				SFBits64 &v = VTDeductor<SFBits64, forVector>()(data, vidx);

				typ = 1562;//varbit
				len = 64;
				fmt = 1;

				val = new char[len/8];
				rst::bitset2bin(v, val, len);
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Bits128:
			{
				SFBits128 &v = VTDeductor<SFBits128, forVector>()(data, vidx);

				typ = 1562;//varbit
				len = 128;
				fmt = 1;

				val = new char[len/8];
				rst::bitset2bin(v, val, len);
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Bits256:
			{
				SFBits256 &v = VTDeductor<SFBits256, forVector>()(data, vidx);

				typ = 1562;//varbit
				len = 256;
				fmt = 1;

				val = new char[len/8];
				rst::bitset2bin(v, val, len);
			}
			break;


			//////////////////////////////////////////////////////////////////////////
		case x2_Bytea:
			{
				SFBytea &v = VTDeductor<SFBytea, forVector>()(data, vidx);

				typ = 17;//bytea
				len = v.size();
				fmt = 1;

				val = new char[len];
				std::copy(v.begin(), v.end(), val);
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Bool:
			{
				assert(!"вектор бул!!!")
// 				SFBool &v = VTDeductor<SFBool, forVector>()(data, vidx);
// 
// 				typ = 16;//bool
// 				len = 1;
// 				fmt = 1;
// 
// 				val = new char[1];
// 				*val = v;
				;
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Real32:
			{
				SFReal32 &v = VTDeductor<SFReal32, forVector>()(data, vidx);

				typ = 700;//float4
				len = 4;
				fmt = 1;

				val = new char[4];
				memcpy((char *)&v, val, 4);
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Real64:
			{
				SFReal64 &v = VTDeductor<SFReal64, forVector>()(data, vidx);

				typ = 701;//float8
				len = 8;
				fmt = 1;

				val = new char[8];
				memcpy((char *)&v, val, 8);
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Int8:
			{
				SFInt8 &v = VTDeductor<SFInt8, forVector>()(data, vidx);

				typ = 21;//int2
				len = 2;
				fmt = 1;

				val = new char[2];
				val[0] = v;
				val[1] = v>=0?0:0xff;
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Int16:
			{
				SFInt16 &v = VTDeductor<SFInt16, forVector>()(data, vidx);

				typ = 21;//int2
				len = 2;
				fmt = 1;

				val = new char[2];
				*(SFInt16 *)val = v;
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Int32:
			{
				SFInt32 &v = VTDeductor<SFInt32, forVector>()(data, vidx);

				typ = 23;//int4
				len = 4;
				fmt = 1;

				val = new char[4];
				*(SFInt32 *)val = v;
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Int64:
			{
				SFInt64 &v = VTDeductor<SFInt64, forVector>()(data, vidx);

				typ = 20;//int8
				len = 8;
				fmt = 1;

				val = new char[8];
				*(SFInt64 *)val = v;
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Uint8:
			{
				SFUint8 &v = VTDeductor<SFUint8, forVector>()(data, vidx);

				typ = 21;//int2
				len = 2;
				fmt = 1;

				val = new char[2];
				val[0] = v;
				val[1] = 0;
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Uint16:
			{
				SFUint16 &v = VTDeductor<SFUint16, forVector>()(data, vidx);

				typ = 23;//int4
				len = 4;
				fmt = 1;

				val = new char[4];
				*(SFInt32 *)val = (SFInt32)(SFUint32)v;
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Uint32:
			{
				SFUint32 &v = VTDeductor<SFUint32, forVector>()(data, vidx);

				typ = 20;//int8
				len = 8;
				fmt = 1;

				val = new char[8];
				*(SFInt64 *)val = (SFInt64)(SFUint64)v;
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Uint64:
			{
				SFUint64 &v = VTDeductor<SFUint64, forVector>()(data, vidx);

				if(((SFInt64)v)<0)
				{
					typ = 0;//auto text
					len = 0;
					fmt = 0;
					val = new char[22];
					sprintf(val, "%lld", v);
				}
				else
				{
					typ = 20;//int8
					len = 8;
					fmt = 1;

					val = new char[8];
					*(SFInt64 *)val = v;
				}
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Date:
			{
				SFDate &v = VTDeductor<SFDate, forVector>()(data, vidx);

				typ = 1082;//date
				len = 4;
				fmt = 1;

				val = new char[4];

				BOOST_STATIC_ASSERT(sizeof(v.julian_day())==4);
				*(boost::uint32_t *)val = v.julian_day();
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Time:
			{
				SFTime &v = VTDeductor<SFTime, forVector>()(data, vidx);

				typ = 1083;//time
				len = 8;
				fmt = 1;

				val = new char[8];

				BOOST_STATIC_ASSERT(sizeof(double)==8);
				*(double *)val = 
					double(v.total_seconds()) + 
					double(v.fractional_seconds())/v.ticks_per_second();
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Timestamp:
			{
				SFTimestamp &v = VTDeductor<SFTimestamp, forVector>()(data, vidx);

				typ = 1114;//timestamp
				len = 8;
				fmt = 1;

				val = new char[8];

				BOOST_STATIC_ASSERT(sizeof(double)==8);

				const SFDate &d = v.date();
				const SFTime &t = v.time_of_day();

				*(double *)val = 
					double(d.julian_day()*(24*60*60) + t.total_seconds()) + 
					double(t.fractional_seconds())/t.ticks_per_second();
			}
			break;

			//////////////////////////////////////////////////////////////////////////
		case x2_Interval:
			{
				SFInterval &v = VTDeductor<SFInterval, forVector>()(data, vidx);

				typ = 1186;//interval
				len = 16;
				fmt = 1;

				val = new char[16];

				const boost::posix_time::ptime::date_duration_type &d = v.iDate;
				const SFTime &t = v.iTime;

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
				SFMoney &v = VTDeductor<SFMoney, forVector>()(data, vidx);

				typ = 790;//money
				len = 8;
				fmt = 1;

				val = new char[8];

				*(boost::uint64_t*)(val) = v._value;
			}
			break;

        default:
            throw soci_error(
                "Use vector element used with non-supported type.");
        }

	}
}
#endif
