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
		bool fetchNative(int typCpp, void *valCpp, size_t colIdx, size_t rowIdx);
		bool fetchNative(int typCpp, void *valCpp, const char *colName, size_t rowIdx);

	public:
		~Result();

		EExecStatus status();
		const char *errorMsg();
		const char *errorCode();
		Result &throwIfError();

		size_t cmdRows();
		size_t rows();
		template <class T> bool fetch(T &v, int colIdx=0, size_t rowIdx=0);
		template <class T> bool fetch(T &v, const char *colName, size_t rowIdx=0);

		boost::int32_t fetchInt32(int colIdx=0, size_t rowIdx=0);
		boost::int32_t fetchInt32(const char *colName, size_t rowIdx=0);

		boost::uint32_t fetchUInt32(int colIdx=0, size_t rowIdx=0);
		boost::uint32_t fetchUInt32(const char *colName, size_t rowIdx=0);

		std::string fetchString(int colIdx=0, size_t rowIdx=0);
		std::string fetchString(const char *colName, size_t rowIdx=0);

		bool isNull(int colIdx=0, size_t rowIdx=0);
		bool isNull(const char *colName, size_t rowIdx);
	};
	typedef boost::shared_ptr<Result> ResultPtr;

	//////////////////////////////////////////////////////////////////////////
	template <class T> bool Result::fetch(T &v, int colIdx, size_t rowIdx)
	{
		return fetchNative(CppDataType<T>::cdt_index, &v, colIdx, rowIdx);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class T> bool Result::fetch(T &v, const char *colName, size_t rowIdx)
	{
		return fetchNative(CppDataType<T>::cdt_index, &v, colName, rowIdx);
	}

}
#endif
