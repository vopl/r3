#ifndef _PGC_FROMDB2CPP_HPP_
#define _PGC_FROMDB2CPP_HPP_

#include "cppType.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(char *&valCpp, Oid typDb, int lenDb, const char *valDb)
	{
// 		switch(typDb)
// 		{
// 
// 		}
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(std::string &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(bool &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(boost::int8_t &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(boost::int16_t &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(boost::int32_t &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(boost::int64_t &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(boost::uint8_t &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(boost::uint16_t &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(boost::uint32_t &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(boost::uint64_t &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(std::tm &valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool fromDb2Cpp(int typCpp, void *valCpp, Oid typDb, int lenDb, const char *valDb)
	{
		switch(typCpp)
		{
		case CppDataType<char *>::cdt_index:
			return fromDb2Cpp(*(char **)valCpp, typDb, lenDb, valDb);

		case CppDataType<std::string>::cdt_index:
			return fromDb2Cpp(*(std::string *)valCpp, typDb, lenDb, valDb);

		case CppDataType<bool>::cdt_index:
			return fromDb2Cpp(*(bool *)valCpp, typDb, lenDb, valDb);

		case CppDataType<boost::int8_t>::cdt_index:
			return fromDb2Cpp(*(boost::int8_t *)valCpp, typDb, lenDb, valDb);

		case CppDataType<boost::int16_t>::cdt_index:
			return fromDb2Cpp(*(boost::int16_t *)valCpp, typDb, lenDb, valDb);

		case CppDataType<boost::int32_t>::cdt_index:
			return fromDb2Cpp(*(boost::int32_t *)valCpp, typDb, lenDb, valDb);

		case CppDataType<boost::int64_t>::cdt_index:
			return fromDb2Cpp(*(boost::int64_t *)valCpp, typDb, lenDb, valDb);

		case CppDataType<boost::uint8_t>::cdt_index:
			return fromDb2Cpp(*(boost::uint8_t *)valCpp, typDb, lenDb, valDb);

		case CppDataType<boost::uint16_t>::cdt_index:
			return fromDb2Cpp(*(boost::uint16_t *)valCpp, typDb, lenDb, valDb);

		case CppDataType<boost::uint32_t>::cdt_index:
			return fromDb2Cpp(*(boost::uint32_t *)valCpp, typDb, lenDb, valDb);

		case CppDataType<boost::uint64_t>::cdt_index:
			return fromDb2Cpp(*(boost::uint64_t *)valCpp, typDb, lenDb, valDb);

		case CppDataType<std::tm>::cdt_index:
			return fromDb2Cpp(*(std::tm *)valCpp, typDb, lenDb, valDb);

		default:
			assert(!"unsupported cpp type");
		}
		return false;
	}
}
#endif
