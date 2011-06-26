#include "stdafx.h"
#include "sessionManager.hpp"

namespace r3
{
	namespace server
	{
		//////////////////////////////////////////////////////////////////////////
		SessionManager::SessionManager()
			: _sidEng()
			, _sidGen(
				_sidEng, 
				boost::uniform_int<boost::int32_t>(
					std::numeric_limits<boost::int32_t>::min(), 
					std::numeric_limits<boost::int32_t>::max()))
		{
			time_t t;
			_sidEng.seed((boost::uint32_t)time(&t));
		}

		//////////////////////////////////////////////////////////////////////////
		SessionManager::~SessionManager()
		{

		}

		//////////////////////////////////////////////////////////////////////////
		void SessionManager::reset()
		{
			boost::mutex::scoped_lock l(_mtx);
			_mUngettedSessions.clear();
			_mGettedSessions.clear();
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
					_mGettedSessions.insert(std::make_pair(sid, res));
					return res;
				}
			}

			do 
			{
				sid = _sidGen();
			} while(	!sid ||
						_mUngettedSessions.end()!=_mUngettedSessions.find(sid) ||
						_mGettedSessions.end()!=_mGettedSessions.find(sid));

			Session_ptr res = Session_ptr(new Session(sid));
			_mGettedSessions.insert(std::make_pair(sid, res));
			return res;
		}
		
		//////////////////////////////////////////////////////////////////////////
		void SessionManager::unget(Session_ptr s, bool destroy)
		{
			boost::mutex::scoped_lock l(_mtx);

			TMSessions::iterator iter = _mGettedSessions.find(s->sid());
			if(_mGettedSessions.end() != iter)
			{
				Session_ptr res = iter->second;
				_mGettedSessions.erase(iter);
			}

			if(destroy)
			{
				return;
			}

			_mUngettedSessions[s->sid()] = s;
		}
	}
}