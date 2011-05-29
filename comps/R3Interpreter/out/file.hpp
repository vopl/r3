#ifndef _OUT_FILE_HPP_
#define _OUT_FILE_HPP_

#include <fstream>
#include <string>
#include <boost/filesystem.hpp>

namespace out
{
	//////////////////////////////////////////////////////////////////////////
	class File
		: public std::ofstream
	{
		std::string _pathName;
	public:
		File(const char *pathName)
			: std::ofstream(pathName)
			, _pathName(pathName)
		{
		}
		File(const std::string &pathName)
			: std::ofstream(pathName.c_str())
			, _pathName(pathName)
		{
		}
		File(const boost::filesystem::path &pathName)
			: std::ofstream(pathName.string().c_str())
			, _pathName(pathName.string())
		{
		}
		~File()
		{

		}

		const char *pathName()
		{
			return _pathName.c_str();
		}
	};
}
#endif
