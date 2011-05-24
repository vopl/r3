#ifndef _OUT_FILE_HPP_
#define _OUT_FILE_HPP_

#include <fstream>
#include <string>

namespace out
{
	//////////////////////////////////////////////////////////////////////////
	class File
		: public std::ofstream
	{
	public:
		File(const char *pathName)
			: std::ofstream(pathName)
		{
		}
		File(const std::string &pathName)
			: std::ofstream(pathName.c_str())
		{
		}
		~File()
		{

		}
	};
}
#endif
