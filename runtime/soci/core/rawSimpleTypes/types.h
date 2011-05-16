#ifndef _rawSimpleTypes_types_hpp_
#define _rawSimpleTypes_types_hpp_


namespace rst
{
	//////////////////////////////////////////////////////////////////////////
	typedef std::vector<boost::uint8_t> Bytea;

	//////////////////////////////////////////////////////////////////////////
	typedef struct 
	{
		boost::uint64_t _value;//копеек
	} Money;

	//////////////////////////////////////////////////////////////////////////
	typedef struct
	{
		boost::posix_time::ptime::date_duration_type iDate; 
		boost::posix_time::ptime::time_duration_type iTime;
	} Interval;
}

#endif
