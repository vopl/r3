#ifndef _R3_SERVER_SESSION_HPP_
#define _R3_SERVER_SESSION_HPP_

#include "net/channel.hpp"

namespace r3
{
	//////////////////////////////////////////////////////////////////////////
	namespace server
	{
		class Session
		{
			std::string		_sid;

			boost::posix_time::ptime			_timeCreate;
			boost::posix_time::ptime			_timeAccess;
			boost::posix_time::ptime			_timeFinish;
			boost::posix_time::time_duration	_timeout;

		public:

			Session(std::string sid);
			~Session();

			const std::string &sid() const;
			void addChannel(net::ChannelPtr channel);

			void touch();
			void close();
		};
		typedef boost::shared_ptr<Session> SessionPtr;
	}
}
#endif
