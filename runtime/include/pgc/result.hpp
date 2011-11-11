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
		bool fetchNative(int typCpp, void *valCpp, size_t rowIdx, size_t colIdx);
		bool fetchNative(int typCpp, void *valCpp, size_t rowIdx, const char *colName);

	public:
		~Result();

		EExecStatus status();
		const char *errorMsg();
		const char *errorCode();
		Result &throwIfError();

		size_t cmdRows();
		size_t rows();
		template <class T> bool fetch(T &v, size_t rowIdx=0, size_t colIdx=0);
		template <class T> bool fetch(T &v, size_t rowIdx, const char *colName);

		boost::int32_t fetchInt32(size_t rowIdx=0, size_t colIdx=0);
		boost::int32_t fetchInt32(size_t rowIdx, const char *colName);

		boost::uint32_t fetchUInt32(size_t rowIdx=0, size_t colIdx=0);
		boost::uint32_t fetchUInt32(size_t rowIdx, const char *colName);

		std::string fetchString(size_t rowIdx=0, size_t colIdx=0);
		std::string fetchString(size_t rowIdx, const char *colName);

		bool isNull(size_t rowIdx=0, size_t colIdx=0);
		bool isNull(size_t rowIdx, const char *colName);
	};
	typedef boost::shared_ptr<Result> ResultPtr;

	//////////////////////////////////////////////////////////////////////////
	template <class T> bool Result::fetch(T &v, size_t rowIdx, size_t colIdx)
	{
		return fetchNative(CppDataType<T>::cdt_index, &v, rowIdx, colIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class T> bool Result::fetch(T &v, size_t rowIdx, const char *colName)
	{
		return fetchNative(CppDataType<T>::cdt_index, &v, rowIdx, colName);
	}

}
#endif
