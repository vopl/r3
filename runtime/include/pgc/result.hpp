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

		bool fetchHelper(int rowIdx, int colIdx, int typIdx, void *data);
		bool fetchHelper(int rowIdx, const char *colName, int typIdx, void *data);

	public:
		~Result();

		EExecStatus status();
		Result &throwIfError();

		int rows();
		template <class T> Result &fetch(int rowIdx, int colIdx, T &v);
		template <class T> Result &fetch(int rowIdx, const char *colName, T &v);

		bool isNull(int rowIdx, int colIdx);
		bool isNull(int rowIdx, const char *colName);
	};
	typedef boost::shared_ptr<Result> ResultPtr;

	//////////////////////////////////////////////////////////////////////////
	template <class T> Result &Result::fetch(int rowIdx, int colIdx, T &v)
	{
		fetchHelper(rowIdx, colIdx, CppDataType<T>::cdt_index, &v);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class T> Result &Result::fetch(int rowIdx, const char *colName, T &v)
	{
		fetchHelper(rowIdx, colName, CppDataType<T>::cdt_index, &v);
		return *this;
	}

}
#endif
