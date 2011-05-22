#ifndef _PGC_BLOBIMPL_HPP_
#define _PGC_BLOBIMPL_HPP_

#include <boost/enable_shared_from_this.hpp>
#include <libpq-fe.h>
#include "pgc/blob.hpp"

namespace pgc
{
	class ConnectionImpl;
	typedef boost::shared_ptr<ConnectionImpl> ConnectionImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class BlobImpl
		: public boost::enable_shared_from_this<BlobImpl>
	{
		ConnectionImplPtr _con;

		Oid _oid;
		int	_fd;

	public:
		BlobImpl();
		BlobImpl(ConnectionImplPtr con);
		~BlobImpl();

		bool unlink();
		bool close();

		bool read(char *buf, size_t len);
		bool write(const char *buf, size_t len);

		bool seek(int offset, EBlobSeekMethod whence);
		int tell();
		bool truncate(size_t len);

		bool import(const char *filename);
		bool export_(const char *filename);

		Oid oid();
		Oid oid(Oid oid);
		void con(ConnectionImplPtr con);

	private:
		bool ensureOpen();

	};

	typedef boost::shared_ptr<BlobImpl> BlobImplPtr;
}
#endif
