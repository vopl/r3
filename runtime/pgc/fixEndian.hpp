#ifndef _PGC_FIXENDIAN_H_
#define _PGC_FIXENDIAN_H_

namespace pgc
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		template <bool le>
		struct FixEndian
		{
			//////////////////////////////////////////////////////////////////////////
			template <class T>
			static T call(const T &v)
			{
				T res = v;
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
			template <>
			static boost::int16_t call<boost::int16_t>(const boost::int16_t &v)
			{
				unsigned char const *s = (unsigned char const *)&v;
				return 
					(boost::int16_t)s[0] << 8 | 
					(boost::int16_t)s[1];
			}
			template <>
			static boost::uint16_t call<boost::uint16_t>(const boost::uint16_t &v)
			{
				return (boost::uint16_t)call((const boost::int16_t &)v);
			}

			//////////////////////////////////////////////////////////////////////////
			template <>
			static boost::int32_t call<boost::int32_t>(const boost::int32_t &v)
			{
				unsigned char const *s = (unsigned char const *)&v;
				return 
					(boost::int32_t)s[0] << 24 | 
					(boost::int32_t)s[1] << 16 | 
					(boost::int32_t)s[2] << 8 | 
					(boost::int32_t)s[3];
			}
			template <>
			static boost::uint32_t call<boost::uint32_t>(const boost::uint32_t &v)
			{
				return (boost::uint32_t)call((const boost::int32_t &)v);
			}
			//////////////////////////////////////////////////////////////////////////
			template <>
			static boost::int64_t call<boost::int64_t>(const boost::int64_t &v)
			{

				unsigned char const *s = (unsigned char const *)&v;
				return 
					(boost::int64_t)s[0] << 56 | 
					(boost::int64_t)s[1] << 48 | 
					(boost::int64_t)s[2] << 40 | 
					(boost::int64_t)s[3] << 32 | 
					(boost::int64_t)s[4] << 24 | 
					(boost::int64_t)s[5] << 16 | 
					(boost::int64_t)s[6] << 8 | 
					(boost::int64_t)s[7];
			}
			template <>
			static boost::uint64_t call<boost::uint64_t>(const boost::uint64_t &v)
			{
				return (boost::uint64_t)call((const boost::int64_t &)v);
			}

			//////////////////////////////////////////////////////////////////////////
			template <>
			static float call<float>(const float &v)
			{
				unsigned char const *s = (unsigned char const *)&v;
				boost::int32_t bytes =
					(boost::int32_t)s[0] << 24 | 
					(boost::int32_t)s[1] << 16 | 
					(boost::int32_t)s[2] << 8 | 
					(boost::int32_t)s[3];

				return *(float *)&bytes;
			}

			//////////////////////////////////////////////////////////////////////////
			template <>
			static double call<double>(const double &v)
			{
				unsigned char const *s = (unsigned char const *)&v;
				boost::int64_t bytes =
					(boost::int64_t)s[0] << 56 | 
					(boost::int64_t)s[1] << 48 | 
					(boost::int64_t)s[2] << 40 | 
					(boost::int64_t)s[3] << 32 | 
					(boost::int64_t)s[4] << 24 | 
					(boost::int64_t)s[5] << 16 | 
					(boost::int64_t)s[6] << 8 | 
					(boost::int64_t)s[7];

				return *(double *)&bytes;
			}


		};

		template <>
		struct FixEndian<false>
		{
			template <class T>
			static T call(const T &v)
			{
				return v;
			}
		};
	}

	template <class T>
	inline T fixEndian(const T &v)
	{
		static const bool le = ((boost::uint8_t)((boost::uint16_t)1)) ? true : false;
		return impl::FixEndian<le>::call(v);
	}

}
#endif
