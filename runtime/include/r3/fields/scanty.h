#ifndef _R3_FIELDS_SCANTY_H
#define _R3_FIELDS_SCANTY_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
    template <size_t bits>
    struct ScantyIntegralHelper
    {
        typedef void Integral;
    };

    template <>
    struct ScantyIntegralHelper<8>
    {
        typedef boost::int8_t type;
    };

    template <>
    struct ScantyIntegralHelper<16>
    {
        typedef boost::int16_t type;
    };

    template <>
    struct ScantyIntegralHelper<32>
    {
        typedef boost::int32_t type;
    };

    template <>
    struct ScantyIntegralHelper<64>
    {
        typedef boost::int64_t type;
    };

	//*******************************************************************
	//   C  L  A  S  S   Scanty
	//*******************************************************************

	template <class Domain>
	class Scanty
		: public Field
	{
	public:
		static const size_t amount = Domain::amount;

		static const size_t bits4SetAmount =
			amount<=8?8:
			amount<=16?16:
			amount<=32?32:
			amount<=64?64:
			amount<=128?128:
			amount<=256?256:512;

		static const size_t bits4EnumAmount =
			amount<=(1ULL<<8)?8:
			amount<=(1ULL<<16)?16:
			amount<=(1ULL<<32)?32:64;

		typedef typename ScantyIntegralHelper<bits4EnumAmount>::type Integral;

	public:
	}; // class


}}  // namespace


#endif
