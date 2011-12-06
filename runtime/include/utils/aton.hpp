#ifndef _UTILS_ATON_HPP_
#define _UTILS_ATON_HPP_

//////////////////////////////////////////////////////////////////////////
namespace utils
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		template <typename integral>
		void _aton(const char *a, integral &num)
		{
			num = 0;
			bool negative = false;

			if(a[0] == '-')
			{
				negative = true;
				a++;
			}

			while(*a && (*a>='0' && *a<='9'))
			{
				num *= 10;
				num += *a - '0';
				a++;
			}
			if(negative)
			{
				num = -num;
			}
		}
		template <typename integral>
		void _atoun(const char *a, integral &num)
		{
			num = 0;
			while(*a && (*a>='0' && *a<='9'))
			{
				num *= 10;
				num += *a - '0';
				a++;
			}
		}
	}



	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	inline signed char _atoc(const char *a)
	{
		signed char res;
		impl::_aton(a, res);
		return res;
	}
	inline unsigned char _atouc(const char *a)
	{
		unsigned char res;
		impl::_atoun(a, res);
		return res;
	}
	inline short _atos(const char *a)
	{
		short res;
		impl::_aton(a, res);
		return res;
	}
	inline unsigned short _atous(const char *a)
	{
		unsigned short res;
		impl::_atoun(a, res);
		return res;
	}
	inline int _atoi(const char *a)
	{
		int res;
		impl::_aton(a, res);
		return res;
	}
	inline unsigned int _atoui(const char *a)
	{
		unsigned int res;
		impl::_atoun(a, res);
		return res;
	}
	inline long _atol(const char *a)
	{
		long res;
		impl::_aton(a, res);
		return res;
	}
	inline unsigned long _atoul(const char *a)
	{
		unsigned long res;
		impl::_atoun(a, res);
		return res;
	}
	inline long long _atoll(const char *a)
	{
		long long res;
		impl::_aton(a, res);
		return res;
	}
	inline unsigned long long _atoull(const char *a)
	{
		unsigned long long res;
		impl::_atoun(a, res);
		return res;
	}
	inline size_t _atost(const char *a)
	{
		size_t res;
		impl::_atoun(a, res);
		return res;
	}

}

#endif
