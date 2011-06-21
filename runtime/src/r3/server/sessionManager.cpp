#include "stdafx.h"
#include "sessionManager.hpp"

namespace r3
{
	namespace server
	{
		//////////////////////////////////////////////////////////////////////////
		SessionManager::SessionManager()
			: _sidGen(1000)
		{

		}

		//////////////////////////////////////////////////////////////////////////
		SessionManager::~SessionManager()
		{

		}
		
		//////////////////////////////////////////////////////////////////////////
		SessionManager::Session_ptr SessionManager::get(ContextId sid)
		{
			boost::mutex::scoped_lock l(_mtx);

			if(sid)
			{
				TMSessions::iterator iter = _mUngettedSessions.find(sid);
				if(_mUngettedSessions.end() != iter)
				{
					Session_ptr res = iter->second;
					_mUngettedSessions.erase(iter);
					return res;
				}
			}

			sid = _sidGen++;
			return Session_ptr(new Session(sid));
		}
		
		//////////////////////////////////////////////////////////////////////////
		void SessionManager::unget(Session_ptr s, bool destroy)
		{
			boost::mutex::scoped_lock l(_mtx);

			if(destroy)
			{
				return;
			}

			_mUngettedSessions[s->sid()] = s;
		}
	}
}