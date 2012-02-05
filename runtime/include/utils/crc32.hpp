#ifndef _UTILS_CRC32_HPP_
#define _UTILS_CRC32_HPP_

#include <boost/cstdint.hpp>

namespace utils
{
	boost::uint32_t crc32(const void * buf, size_t len);

	struct CRC32_CTX
	{
		boost::uint32_t _state;
	};

	int CRC32_Init(CRC32_CTX *c);
	int CRC32_Update(CRC32_CTX *c, const void *data, size_t len);
	int CRC32_Final(unsigned char *md, CRC32_CTX *c);

}

#endif
