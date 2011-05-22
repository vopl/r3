#include "pgc/blob.hpp"
#include "blobImpl.hpp"

namespace pgc
{

	Blob::Blob(BlobImplPtr impl)
		: _impl(impl)
	{

	}

	Blob::Blob()
		: _impl(new BlobImpl)
	{

	}
	Blob::Blob(Connection con)
		: _impl(new BlobImpl(con._impl))
	{
	}



	bool Blob::unlink()
	{
		return _impl->unlink();
	}
	bool Blob::close()
	{
		return _impl->close();
	}

	bool Blob::read(char *buf, size_t len)
	{
		return _impl->read(buf, len);
	}
	bool Blob::write(const char *buf, size_t len)
	{
		return _impl->write(buf, len);
	}

	bool Blob::seek(int offset, EBlobSeekMethod whence)
	{
		return _impl->seek(offset, whence);
	}
	int Blob::tell()
	{
		return _impl->tell();
	}
	bool Blob::truncate(size_t len)
	{
		return _impl->truncate(len);
	}

	bool Blob::import(const char *filename)
	{
		return _impl->import(filename);
	}
	bool Blob::export_(const char *filename)
	{
		return _impl->export_(filename);
	}

}
