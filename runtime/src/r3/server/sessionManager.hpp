#ifndef _R3_SERVER_SESSIONMANAGER_HPP_
#define _R3_SERVER_SESSIONMANAGER_HPP_

#include "r3/logic/server/connection.hpp"
#include <boost/random.hpp>

namespace r3
{
	namespace server
	{
		class SessionManager
		{
					
			typedef r3::logic::server::Connection::Session Session;
			typedef r3::logic::server::Connection::Session_ptr Session_ptr;

			boost::mutex _mtx;
			typedef std::map<ContextId, Session_ptr> TMSessions;
			TMSessions _mGettedSessions;
			TMSessions _mUngettedSessions;

		private:
			boost::mt19937 _sidEng;
			boost::variate_generator<boost::mt19937&, boost::uniform_int<boost::int32_t> > _sidGen;

		public:
			SessionManager();
			~SessionManager();

			void reset();

			Session_ptr get(ContextId sid=0);
			void unget(Session_ptr s, bool destroy);
		};
	}
}

#endif

