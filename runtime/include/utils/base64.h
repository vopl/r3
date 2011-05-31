#ifndef _UTILS_BASE64_HPP_
#define _UTILS_BASE64_HPP_

#include <string>

namespace utils
{
	std::string base64_encode(const char * bytes_to_encode, unsigned int in_len, size_t maxLineLen = (size_t)-1);
	std::string base64_encode(const unsigned char * bytes_to_encode, unsigned int in_len, size_t maxLineLen = (size_t)-1);
	std::string base64_encode(const std::string &s, size_t maxLineLen = (size_t)-1);
	std::string base64_decode(const std::string &s);
}

#endif
