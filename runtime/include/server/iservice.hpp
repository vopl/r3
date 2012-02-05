#ifndef _SERVER_ISERVICE_HPP_
#define _SERVER_ISERVICE_HPP_

#include "server/isession.hpp"
#include "server/inodeManager.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	struct IService
	{
		virtual ~IService(){}

		virtual void onSessionAdd(ISessionPtr session) =0;
		virtual void onSessionDel(ISessionPtr session) =0;
	};
	typedef boost::shared_ptr<IService> IServicePtr;
}
#endif
