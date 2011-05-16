#ifndef _PRE_USE_HELPER_HPP_
#define _PRE_USE_HELPER_HPP_

#include "rawSimpleTypes/utils.hpp"

namespace soci
{
	namespace
	{
// 		template<class T, bool forVector>
// 		struct VTDeductor
// 		{
// 			T &operator()(void *data, size_t vidx)
// 			{
// 				SOCI_VECTOR_TYPE<T> * pv = static_cast<SOCI_VECTOR_TYPE<T> *>(data);
// 				return pv->operator[](vidx);
// 			}
// 		};
// 
// 		//////////////////////////////////////////////////////////////////////////
// 		template<class T>
// 		struct VTDeductor<T, false>
// 		{
// 			T &operator()(void *data, size_t /*vidx*/)
// 			{
// 				T * pv = static_cast<T *>(data);
// 				return *pv;
// 			}
// 		};
	}

	//////////////////////////////////////////////////////////////////////////
	template <typename T> inline void fromInternal2Db(T &data, Oid &typ, int &len, int &fmt, char *&val)
	{
		BOOST_STATIC_ASSERT(false);
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromInternal2Db(SFString &data, Oid &typ, int &len, int &fmt, char *&val)
	{
		typ = 1043;//varchar
		len = data.size();
		fmt = 1;
		val = new char[len];
		memmove(val, data.data(), len);
	}

	//////////////////////////////////////////////////////////////////////////
	template <size_t N> void fromInternal2Db(std::bitset<N> &data, Oid &typ, int &len, int &fmt, char *&val)
	{
		BOOST_STATIC_ASSERT(!(N&0x7));

		typ = 1562;//varbit
		len = N;
		fmt = 1;
		val = new char[N/8];
		rst::bitset2bin(data, val, len);
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromInternal2Db(SFBytea &data, Oid &typ, int &len, int &fmt, char *&val)
	{
		typ = 17;//bytea
		len = data.size();
		fmt = 1;

		val = new char[len];
		std::copy(data.begin(), data.end(), val);
	}


	//////////////////////////////////////////////////////////////////////////
	inline void fromInternal2Db(SFBool &data, Oid &typ, int &len, int &fmt, char *&val)
	{
		typ = 16;//bool
		len = 1;
		fmt = 1;

		val = new char[1];
		*val = data;
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromInternal2Db(SFReal32 &data, Oid &typ, int &len, int &fmt, char *&val)
	{
		typ = 700;//float4
		len = 4;
		fmt = 1;

		val = new char[4];
		memcpy((char *)&data, val, 4);
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromInternal2Db(SFReal64 &data, Oid &typ, int &len, int &fmt, char *&val)
	{
		typ = 701;//float8
		len = 8;
		fmt = 1;

		val = new char[8];
		memcpy((char *)&data, val, 8);
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromInternal2Db(SFInt8 &data, Oid &typ, int &len, int &fmt, char *&val)
	{
		typ = 21;//int2
		len = 2;
		fmt = 1;

		val = new char[2];
		val[0] = data;
		val[1] = data>=0?0:0xff;
	}

	inline void fromInternal2Db(SFInt16 &data, Oid &typ, int &len, int &fmt, char *&val)
	{

		typ = 21;//int2
		len = 2;
		fmt = 1;

		val = new char[2];
		*(SFInt16 *)val = data;
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromInternal2Db(SFInt32 &data, Oid &typ, int &len, int &fmt, char *&val)
	{

		typ = 23;//int4
		len = 4;
		fmt = 1;

		val = new char[4];
		*(SFInt32 *)val = data;
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromInternal2Db(SFInt64 &data, Oid &typ, int &len, int &fmt, char *&val)
	{

		typ = 20;//int8
		len = 8;
		fmt = 1;

		val = new char[8];
		*(SFInt64 *)val = data;
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromInternal2Db(SFUint8 &data, Oid &typ, int &len, int &fmt, char *&val)
	{

		typ = 21;//int2
		len = 2;
		fmt = 1;

		val = new char[2];
		val[0] = data;
		val[1] = 0;
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromInternal2Db(SFUint16 &data, Oid &typ, int &len, int &fmt, char *&val)
	{

		typ = 23;//int4
		len = 4;
		fmt = 1;

		val = new char[4];
		*(SFInt32 *)val = (SFInt32)(SFUint32)data;
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromInternal2Db(SFUint32 &data, Oid &typ, int &len, int &fmt, char *&val)
	{

		typ = 20;//int8
		len = 8;
		fmt = 1;

		val = new char[8];
		*(SFInt64 *)val = (SFInt64)(SFUint64)data;
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromInternal2Db(SFUint64 &data, Oid &typ, int &len, int &fmt, char *&val)
	{

		if(((SFInt64)data)<0)
		{
			typ = 0;//auto text
			len = 0;
			fmt = 0;
			val = new char[22];
			sprintf(val, "%lld", data);
		}
		else
		{
			typ = 20;//int8
			len = 8;
			fmt = 1;

			val = new char[8];
			*(SFInt64 *)val = data;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromInternal2Db(SFDate &data, Oid &typ, int &len, int &fmt, char *&val)
	{

		typ = 1082;//date
		len = 4;
		fmt = 1;

		val = new char[4];

		BOOST_STATIC_ASSERT(sizeof(data.julian_day())==4);
		*(boost::uint32_t *)val = data.julian_day();
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromInternal2Db(SFTime &data, Oid &typ, int &len, int &fmt, char *&val)
	{

		typ = 1083;//time
		len = 8;
		fmt = 1;

		val = new char[8];

		BOOST_STATIC_ASSERT(sizeof(double)==8);
		*(double *)val = 
			double(data.total_seconds()) + 
			double(data.fractional_seconds())/data.ticks_per_second();
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromInternal2Db(SFTimestamp &data, Oid &typ, int &len, int &fmt, char *&val)
	{

		typ = 1114;//timestamp
		len = 8;
		fmt = 1;

		val = new char[8];

		BOOST_STATIC_ASSERT(sizeof(double)==8);

		const SFDate &d = data.date();
		const SFTime &t = data.time_of_day();

		*(double *)val = 
			double(d.julian_day()*(24*60*60) + t.total_seconds()) + 
			double(t.fractional_seconds())/t.ticks_per_second();
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromInternal2Db(SFInterval &data, Oid &typ, int &len, int &fmt, char *&val)
	{

		typ = 1186;//interval
		len = 16;
		fmt = 1;

		val = new char[16];

		const boost::posix_time::ptime::date_duration_type &d = data.iDate;
		const SFTime &t = data.iTime;

		boost::uint64_t days = d.days();
		boost::uint64_t months = days / 30;
		days -= months*30;

		*(double *)val = 
			double(days*(24*60*60) + t.total_seconds()) + 
			double(t.fractional_seconds())/t.ticks_per_second();

		*(boost::uint64_t*)(val+8) = months;
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromInternal2Db(SFMoney &data, Oid &typ, int &len, int &fmt, char *&val)
	{

		typ = 790;//money
		len = 8;
		fmt = 1;

		val = new char[8];

		*(boost::uint64_t*)(val) = data._value;
	}

}
#endif
