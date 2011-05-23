#ifndef _PGC_RESULT_HPP_
#define _PGC_RESULT_HPP_

#include "pgc/common.h"

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

		bool fetchHelper(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool fetchHelper(int rowIdx, const char *colName, int typCpp, void *valCpp);

	public:
		Result();
		~Result();

		EExecStatus status();
		const char *errorMsg();
		const char *errorCode();
		Result &throwIfError();

		int rows();
		template <class T> bool fetch(int rowIdx, int colIdx, T &v);
		template <class T> bool fetch(int rowIdx, const char *colName, T &v);

		bool isNull(int rowIdx, int colIdx);
		bool isNull(int rowIdx, const char *colName);
	};
	typedef boost::shared_ptr<Result> ResultPtr;

	//////////////////////////////////////////////////////////////////////////
	template <class T> bool Result::fetch(int rowIdx, int colIdx, T &v)
	{
		return fetchHelper(rowIdx, colIdx, CppDataType<T>::cdt_index, &v);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class T> bool Result::fetch(int rowIdx, const char *colName, T &v)
	{
		return fetchHelper(rowIdx, colName, CppDataType<T>::cdt_index, &v);
	}

}
#endif
