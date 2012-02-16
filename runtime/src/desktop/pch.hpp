#ifndef _DESKTOP_PCH_HPP_
#define _DESKTOP_PCH_HPP_

#ifdef _WIN32
#	define _WIN32_WINNT 0x0501
#endif

#define LOG_NAME desktop
#include "log/client.hpp"

#include <QtCore>
#include <QtScript>

#include <string>
#include <vector>
#include <deque>
#include <set>
#include <iostream>



#include <boost/uuid/uuid.hpp>
#include <boost/uuid/nil_generator.hpp>
#include <boost/uuid/random_generator.hpp>

#include <boost/enable_shared_from_this.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/foreach.hpp>

#include <boost/shared_array.hpp>
#include <boost/date_time/gregorian_calendar.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/cstdint.hpp>

#include "utils/variant.hpp"

#endif
