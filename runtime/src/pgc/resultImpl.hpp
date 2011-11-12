#ifndef _PGC_RESULTIMPL_HPP_
#define _PGC_RESULTIMPL_HPP_

#include <boost/enable_shared_from_this.hpp>
#include <vector>
#include <libpq-fe.h>
#include "pgc/result.hpp"

namespace pgc
{
	class ConnectionImpl;
	typedef boost::shared_ptr<ConnectionImpl> ConnectionImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class ResultImpl
		: public boost::enable_shared_from_this<ResultImpl>
	{
		ConnectionImplPtr _con;
		PGresult *_pgres;

		typedef bool (ResultImpl::*MExtractor)(int rowIdx, int colIdx, int typCpp, void *valCpp);

		struct Extractor
		{
			MExtractor	_meth;
			int			_favorCppType;
		};

		typedef std::vector<Extractor> TVExtractors;
		TVExtractors _extractors;

		bool extractor_int2			(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool extractor_int4			(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool extractor_int8			(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool extractor_numeric		(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool extractor_float4		(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool extractor_float8		(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool extractor_money		(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool extractor_varchar		(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool extractor_bytea		(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool extractor_timestamp	(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool extractor_interval		(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool extractor_date			(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool extractor_time			(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool extractor_bool			(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool extractor_varbit		(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool extractor_oid			(int rowIdx, int colIdx, int typCpp, void *valCpp);
		bool extractor_null			(int rowIdx, int colIdx, int typCpp, void *valCpp);


	public:
		ResultImpl(ConnectionImplPtr con, PGresult *pgres);
		virtual ~ResultImpl();

		EExecStatus status();
		const char *errorMsg();
		const char *errorCode();

		size_t cmdRows();

		size_t rows();
		bool fetch(int typCpp, void *valCpp, size_t colIdx, size_t rowIdx);
		bool fetch(int typCpp, void *valCpp, const char *colName, size_t rowIdx);

		bool isNull(size_t colIdx, size_t rowIdx);
		bool isNull(const char *colName, size_t rowIdx);

	};

	typedef boost::shared_ptr<ResultImpl> ResultImplPtr;
}
#endif
