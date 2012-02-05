#ifndef _PGC_CONNECTIONIMPL_HPP_
#define _PGC_CONNECTIONIMPL_HPP_

#include "connectionHolder.hpp"


namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	class ConnectionImpl
		: public enable_shared_from_this<ConnectionImpl>
	{
	public:
		ConnectionHolderPtr _holder;

	public:
		ConnectionImpl(ConnectionHolderPtr holder);
		~ConnectionImpl();


	};
	typedef shared_ptr<ConnectionImpl> ConnectionImplPtr;
}
#endif
