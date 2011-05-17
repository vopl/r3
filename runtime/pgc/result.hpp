#ifndef _PGC_RESULT_HPP_
#define _PGC_RESULT_HPP_

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

		bool fetchHelper(size_t rowIdx, size_t colIdx, int typIdx, void *data);
		bool fetchHelper(size_t rowIdx, const char *colName, int typIdx, void *data);

	public:
		~Result();

		EExecStatus status();
		Result &throwIfError();

		size_t rows();
		template <class T> Result &fetch(size_t rowIdx, size_t colIdx, T &v);
		template <class T> Result &fetch(size_t rowIdx, const char *colName, T &v);

		bool isNull(size_t rowIdx, size_t colIdx);
		bool isNull(size_t rowIdx, const char *colName);
	};

	//////////////////////////////////////////////////////////////////////////
	template <class T> Result &Result::fetch(size_t rowIdx, size_t colIdx, T &v)
	{
		fetchHelper(rowIdx, colIdx, CppDataType<T>::cdt_index, &v);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class T> Result &Result::fetch(size_t rowIdx, const char *colName, T &v)
	{
		fetchHelper(rowIdx, colName, CppDataType<T>::cdt_index, &v);
		return *this;
	}

}
#endif
