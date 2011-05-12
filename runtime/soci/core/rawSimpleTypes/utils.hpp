#ifndef _rawSimpleTypes_utils_hpp_
#define _rawSimpleTypes_utils_hpp_


namespace rst
{
	template < template <size_t> class Bitset, size_t N>
	void bitset2bin(const Bitset<N> &bs, char *outbuf, size_t outbits)
	{
		(void)bs;
		(void)outbuf;
		(void)outbits;

		assert(!"NEED IMPLEMENT");
	}
}

#endif
