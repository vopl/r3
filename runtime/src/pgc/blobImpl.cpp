#include "blobImpl.hpp"
#include "connectionImpl.hpp"
#include <libpq/libpq-fs.h>

namespace pgc
{

	BlobImpl::BlobImpl()
		: _oid(InvalidOid)
		, _fd(-1)
	{

	}
	BlobImpl::BlobImpl(ConnectionImplPtr con)
		: _con(con)
		, _oid(InvalidOid)
		, _fd(-1)
	{

	}

	BlobImpl::~BlobImpl()
	{
		close();
	}

	bool BlobImpl::unlink()
	{
		close();

		if(InvalidOid != _oid)
		{
			if(!_con) return false;
			bool res = 1 == lo_unlink(_con->pgcon(), _oid);
			_oid = InvalidOid;
			return res;
		}
		return true;
	}

	bool BlobImpl::close()
	{
		if(_fd >= 0)
		{
			if(!_con) return false;
			lo_close(_con->pgcon(), _fd);
		}
		return true;
	}

	bool BlobImpl::ensureOpen()
	{
		if(_fd < 0)
		{
			if(!_con) return false;
			if(InvalidOid == _oid)
			{
				_oid = lo_creat(_con->pgcon(), INV_READ|INV_WRITE);
				if(InvalidOid == _oid)
				{
					return false;
				}
			}

			_fd = lo_open(_con->pgcon(), _oid, INV_READ|INV_WRITE);
			if(0 > _fd)
			{
				return false;
			}
			return true;
		}

		return false;
	}

	bool BlobImpl::read(char *buf, size_t len)
	{
		if(!ensureOpen())
		{
			return false;
		}

		return 0 >= lo_read(_con->pgcon(), _fd, buf, len);
	}
	bool BlobImpl::write(const char *buf, size_t len)
	{
		if(!ensureOpen())
		{
			return false;
		}

		return 0 >= lo_write(_con->pgcon(), _fd, buf, len);
	}

	bool BlobImpl::seek(int offset, EBlobSeekMethod whence)
	{
		if(!ensureOpen())
		{
			return false;
		}

		return 0 >= lo_lseek(_con->pgcon(), _fd, offset, whence);
	}
	int BlobImpl::tell()
	{
		if(!ensureOpen())
		{
			return false;
		}

		return lo_tell(_con->pgcon(), _fd);
	}
	bool BlobImpl::truncate(size_t len)
	{
		if(!ensureOpen())
		{
			return false;
		}

		return 0 >= lo_truncate(_con->pgcon(), _fd, len);
	}

	bool BlobImpl::import(const char *filename)
	{
		unlink();

		if(!_con) return false;
		_oid = lo_import(_con->pgcon(), filename);

		return InvalidOid != _oid;
	}
	bool BlobImpl::export_(const char *filename)
	{
		if(!_con) return false;
		return 1 ==  lo_export(_con->pgcon(), _oid, filename);
	}

	Oid BlobImpl::oid()
	{
		return _oid;
	}

	Oid BlobImpl::oid(Oid oid)
	{
		if(_oid != oid)
		{
			unlink();
			_oid = oid;
		}

		return _oid;
	}

	void BlobImpl::con(ConnectionImplPtr con)
	{
		_con = con;
	}


}
