#include "StdAfx.h"
#include "session.hpp"

namespace r3
{
	namespace logic
	{
		namespace server
		{

			//////////////////////////////////////////////////////////////////////////
			Connection::Session::Session(ContextId sid)
				: r3::protocol::server::Connection::Session()
				, _sid(sid)
			{
			}

			//////////////////////////////////////////////////////////////////////////
			Connection::Session::~Session()
			{

			}

			//////////////////////////////////////////////////////////////////////////
			ContextId Connection::Session::sid()
			{
				return _sid;
			}

		}
	}
}
