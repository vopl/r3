#ifndef _PGC_RESULT_HPP_
#define _PGC_RESULT_HPP_

#include "pgc/common.h"
#include "pgc/cppDataType.hpp"

namespace pgc
{
	class ResultImpl;
	typedef boost::shared_ptr<ResultImpl> ResultImplPtr;

	enum EExecStatus
	{
		ees_commandOk,
		ees_tuplesOk,
		ees_error,
	};

	//////////////////////////////////////////////////////////////////////////
	class Result
	{
		ResultImplPtr _impl;
	protected:
		friend class Statement;
		Result(ResultImplPtr impl);

	public:
		bool fetchNative(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool fetchNative(int rowIdx, const char *colName, int typCpp, void *valCpp);

	public:
		Result();
		~Result();

		EExecStatus status();
		const char *errorMsg();
		const char *errorCode();
		Result &throwIfError();

		size_t cmdRows();
		int rows();
		template <class T> bool fetch(int rowIdx, int colIdx, T &v);
		template <class T> bool fetch(int rowIdx, const char *colName, T &v);

		boost::int32_t fetchInt32(int rowIdx, int colIdx);
		boost::int32_t fetchInt32(int rowIdx, const char *colName);

		boost::uint32_t fetchUInt32(int rowIdx, int colIdx);
		boost::uint32_t fetchUInt32(int rowIdx, const char *colName);

		std::string fetchString(int rowIdx, int colIdx);
		std::string fetchString(int rowIdx, const char *colName);

		bool isNull(int rowIdx, int colIdx);
		bool isNull(int rowIdx, const char *colName);
	};
	typedef boost::shared_ptr<Result> ResultPtr;

	//////////////////////////////////////////////////////////////////////////
	template <class T> bool Result::fetch(int rowIdx, int colIdx, T &v)
	{
		return fetchNative(rowIdx, colIdx, CppDataType<T>::cdt_index, &v);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class T> bool Result::fetch(int rowIdx, const char *colName, T &v)
	{
		return fetchNative(rowIdx, colName, CppDataType<T>::cdt_index, &v);
	}

}
#endif
