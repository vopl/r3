#include <boost/serialization/export.hpp>

#include "utils/serialization/polymorphic_binary_portable_iarchive.hpp"
#include "utils/serialization/polymorphic_binary_portable_oarchive.hpp"


#include "utils/serialization/collection_size_type.hpp"
#include <boost/serialization/string.hpp>
#include <boost/serialization/deque.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/set.hpp>
#include <boost/serialization/bitset.hpp>
#include <boost/date_time/gregorian/greg_serialize.hpp>
#include <boost/date_time/posix_time/time_serialize.hpp>


//////////////////////////////////////////////////////////////////////////
//std::tm
BOOST_SERIALIZATION_SPLIT_FREE(std::tm)
namespace boost 
{
	namespace serialization 
	{
		//////////////////////////////////////////////////////////////////////////
		template<class Archive>
		void save(Archive & ar, const std::tm &x, const unsigned int version)
		{
			ar & x.tm_hour;
			ar & x.tm_sec;
			ar & x.tm_min;
			ar & x.tm_hour;
			ar & x.tm_mday;
			ar & x.tm_mon;
			ar & x.tm_year;
			ar & x.tm_wday;
			ar & x.tm_yday;
			ar & x.tm_isdst;
		}

		//////////////////////////////////////////////////////////////////////////
		template<class Archive>
		void load(Archive & ar, std::tm & x, const unsigned int version)
		{
			ar & x.tm_hour;
			ar & x.tm_sec;
			ar & x.tm_min;
			ar & x.tm_hour;
			ar & x.tm_mday;
			ar & x.tm_mon;
			ar & x.tm_year;
			ar & x.tm_wday;
			ar & x.tm_yday;
			ar & x.tm_isdst;
		}


	} // namespace serialization
} // namespace boost







//////////////////////////////////////////////////////////////////////////
//utils::DateTimeDuration 
namespace boost 
{
	namespace serialization 
	{
		//////////////////////////////////////////////////////////////////////////
		template<class Archive>
		void serialize(Archive & ar, utils::DateTimeDuration &x, const unsigned int version)
		{
			ar & x._dd;
			ar & x._td;
		}
	} // namespace serialization
} // namespace boost

