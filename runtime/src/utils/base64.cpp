/* 
base64.cpp and base64.h

Copyright (C) 2004-2008 Rene Nyffenegger

This source code is provided 'as-is', without any express or implied
warranty. In no event will the author be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this source code must not be misrepresented; you must not
claim that you wrote the original source code. If you use this source code
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original source code.

3. This notice may not be removed or altered from any source distribution.

Rene Nyffenegger rene.nyffenegger@adp-gmbh.ch

*/
#include "pch.h"
#include "utils/base64.h"
#include <iostream>

namespace utils
{
	namespace impl
	{
		static const std::string base64_chars = 
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz"
			"0123456789+/";

		std::string mkbase64_charsrev(const std::string &base64_chars)
		{
			std::string res(256, '\0');

			for(size_t i(0); i<base64_chars.size(); i++)
			{
				res[base64_chars[i]] = (unsigned char)i;
			}

			return res;
		}
		static const std::string base64_charsrev = mkbase64_charsrev(base64_chars);

		static inline bool is_base64(unsigned char c)
		{
			return ((c>='A' && c<='Z' || c>='a' && c<='z' || c>='0' && c<='9') || (c == '+') || (c == '/'));
		}
	}

	std::string base64_encode(const char * bytes_to_encode, size_t in_len, size_t maxLineLen)
	{
		return base64_encode((const unsigned char *) bytes_to_encode, in_len, maxLineLen);
	}

	std::string base64_encode(const unsigned char * bytes_to_encode, size_t in_len, size_t maxLineLen)
	{
		std::string ret;
		size_t i = 0;
		size_t j = 0;
		unsigned char char_array_3[3];
		unsigned char char_array_4[4];

		size_t lineLen = 0;

		while (in_len--)
		{
			char_array_3[i++] = *(bytes_to_encode++);
			if (i == 3)
			{
				char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
				char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
				char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
				char_array_4[3] = char_array_3[2] & 0x3f;

				for(i = 0; (i <4) ; i++)
				{
					if(lineLen >= maxLineLen)
					{
						lineLen = 0;
						ret += "\r\n";
					}
					lineLen++;
					ret += impl::base64_chars[char_array_4[i]];
				}
				i = 0;
			}
		}

		if (i)
		{
			for(j = i; j < 3; j++)
			{
				char_array_3[j] = '\0';
			}

			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
			char_array_4[3] = char_array_3[2] & 0x3f;

			for (j = 0; (j < i + 1); j++)
			{
				if(lineLen >= maxLineLen)
				{
					lineLen = 0;
					ret += "\r\n";
				}
				lineLen++;

				ret += impl::base64_chars[char_array_4[j]];
			}

			while((i++ < 3))
			{
				if(lineLen >= maxLineLen)
				{
					lineLen = 0;
					ret += "\r\n";
				}
				lineLen++;
				ret += '=';
			}

		}

		return ret;

	}
	std::string base64_encode(const std::string &s, size_t maxLineLen)
	{
		return base64_encode((const unsigned char *)s.data(), s.size(), maxLineLen);
	}

	std::string base64_decode(const std::string &encoded_string)
	{
		size_t in_len = encoded_string.size();
		size_t i = 0;
		size_t j = 0;
		size_t in_ = 0;
		unsigned char char_array_4[4], char_array_3[3];
		std::string ret;

		while (in_len-- && ( encoded_string[in_] != '=') && impl::is_base64(encoded_string[in_]))
		{
			char_array_4[i++] = encoded_string[in_]; in_++;
			if (i ==4)
			{
				for (i = 0; i <4; i++)
				{
					char_array_4[i] = impl::base64_charsrev[char_array_4[i]];
				}

				char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
				char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
				char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

				for (i = 0; (i < 3); i++)
				{
					ret += char_array_3[i];
				}
				i = 0;
			}
		}

		if (i) {
			for (j = i; j <4; j++)
			{
				char_array_4[j] = 0;
			}

			for (j = 0; j <4; j++)
			{
				char_array_4[j] = impl::base64_charsrev[char_array_4[j]];
			}

			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

			for (j = 0; (j < i - 1); j++)
			{
				ret += char_array_3[j];
			}
		}

		return ret;
	}
}
