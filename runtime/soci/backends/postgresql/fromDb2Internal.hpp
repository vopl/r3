#ifndef _PRE_USE_HELPER_HPP_
#define _PRE_USE_HELPER_HPP_

//#include "rawSimpleTypes/utils.hpp"

namespace soci
{

	//////////////////////////////////////////////////////////////////////////
	template <typename T> inline void fromDb2Internal(T &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFString &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		switch(ftype)
		{
		case 1043:
			data.assign(val, len);
			break;
		default:
			assert(!"not impl");
		}
	}

	//////////////////////////////////////////////////////////////////////////
	template <size_t N> inline void fromDb2Internal(std::bitset<N>  &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFBytea &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFBool &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFReal32 &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFReal64 &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFInt8 &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFInt16 &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFInt32 &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFInt64 &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFUint8 &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFUint16 &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFUint32 &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFUint64 &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFDate &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFTime &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFTimestamp &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFInterval &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	inline void fromDb2Internal(SFMoney &data, int fformat, Oid ftype, int fsize, int fmod, const char *val, int len)
	{
		(void)data; (void)fformat; (void)ftype; (void)fsize; (void)fmod; (void)val; (void)len;
		assert(!"not impl");
	}

}

#endif
