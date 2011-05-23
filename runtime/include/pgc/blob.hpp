#ifndef _PGC_BLOB_HPP_
#define _PGC_BLOB_HPP_

#include "pgc/common.h"
#include "pgc/connection.hpp"

namespace pgc
{
	class BlobImpl;
	typedef boost::shared_ptr<BlobImpl> BlobImplPtr;

	enum EBlobSeekMethod
	{
		bsm_set=0,
		bsm_cur=1,
		bsm_end=2,
	};

	//////////////////////////////////////////////////////////////////////////
	class Blob
	{
		friend class StatementImpl;
		friend class ResultImpl;
		BlobImplPtr _impl;
	private:
		Blob(BlobImplPtr impl);

	public:
		Blob();
		Blob(Connection con);

		void con(Connection con);

		bool unlink();
		bool close();

		int read(char *buf, size_t len);
		int write(const char *buf, size_t len);

		int seek(int offset, EBlobSeekMethod whence = bsm_set);
		int tell();
		bool truncate(size_t len);

		bool import(const char *filename);
		bool export_(const char *filename);
	};

	typedef boost::shared_ptr<Blob> BlobPtr;

}
#endif