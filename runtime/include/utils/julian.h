#ifndef _UTILS_JULIANUTILS_H_
#define _UTILS_JULIANUTILS_H_

namespace utils
{
	//////////////////////////////////////////////////////////////////////////
	int
		inline date2j(int y, int m, int d)
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
	}	/* date2j() */

	void
		inline j2date(int jd, int *year, int *month, int *day)
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
	}	/* j2date() */

	static const boost::uint32_t UDAYS_PER_MONTH =	30;
	static const boost::uint32_t USECS_PER_YEAR	 =(36525 * 864);

	static const boost::uint64_t USECS_PER_DAY	=86400000000LL;
	static const boost::uint64_t USECS_PER_HOUR	=3600000000LL;
	static const boost::uint64_t USECS_PER_MINUTE =60000000LL;
	static const boost::uint64_t USECS_PER_SEC	=1000000LL;

	static const boost::int64_t POSTGRES_EPOCH_JDATE =2451545LL; /* == date2j(2000, 1, 1) */


	template <class T1, class T2, class T3>
	void TMODULO(T1 &t, T2 &q, const T3 &u)
	{
		do
		{
			(q) = ((t) / (u));
			if ((q) != 0) (t) -= ((q) * (u));
		} while(0);
	}

	void
		inline dt2time(boost::int64_t jd, int *hour, int *min, int *sec, int *fsec)
	{
		boost::int64_t		time;

		time = jd;
		*hour = (int)(time / USECS_PER_HOUR);
		time -= (*hour) * USECS_PER_HOUR;
		*min = (int)(time / USECS_PER_MINUTE);
		time -= (*min) * USECS_PER_MINUTE;
		*sec = (int)(time / USECS_PER_SEC);
		*fsec = (int)(time - (*sec * USECS_PER_SEC));
	}	/* dt2time() */

}

#endif
