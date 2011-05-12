#ifndef _rawSimpleTypes_types_hpp_
#define _rawSimpleTypes_types_hpp_


namespace rst
{
	//////////////////////////////////////////////////////////////////////////
	typedef std::deque<boost::uint8_t> Bytea;

	//////////////////////////////////////////////////////////////////////////
	typedef struct 
	{
		boost::uint64_t _value;//копеек
	} Money;
}

#endif
