#ifndef _PGC_ICONNECTION_HPP_
#define _PGC_ICONNECTION_HPP_

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	struct IConnection
	{
		virtual ~IConnection(){}
	};
	typedef boost::shared_ptr<IConnection> IConnectionPtr;
}
#endif
