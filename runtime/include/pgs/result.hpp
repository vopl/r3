#ifndef _PGS_RESULT_HPP_
#define _PGS_RESULT_HPP_

#include <boost/shared_ptr.hpp>
#include "pgc/connection.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	namespace impl
	{
		class Result;
		typedef boost::shared_ptr<Result> Result_ptr;
	}

	//////////////////////////////////////////////////////////////////////////
	class Result
	{
	protected:
		typedef impl::Result_ptr Impl_ptr;
		Impl_ptr _impl;

		bool fetchNative(size_t rowIdx, size_t colIdx, int typCpp, void *valCpp);
		bool fetchNative(size_t rowIdx, const std::string &colName, int typCpp, void *valCpp);

	public:
		Result(const Impl_ptr &impl);

		pgc::EExecStatus status();

		size_t cmdRows();
		size_t rows();
		template <class T> bool fetch(size_t rowIdx, size_t colIdx, T &v);
		template <class T> bool fetch(size_t rowIdx, const std::string &colName, T &v);

		bool isNull(size_t rowIdx, size_t colIdx);
		bool isNull(size_t rowIdx, const std::string &colName);

	};

	//////////////////////////////////////////////////////////////////////////
	template <class T> bool Result::fetch(size_t rowIdx, size_t colIdx, T &v)
	{
		return fetchNative(rowIdx, colIdx, CppDataType<T>::cdt_index, &v);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class T> bool Result::fetch(size_t rowIdx, const std::string &colName, T &v)
	{
		return fetchNative(rowIdx, colName, CppDataType<T>::cdt_index, &v);
	}

}
#endif
