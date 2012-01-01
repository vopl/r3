#ifdef _WIN32
#	define _WIN32_WINNT 0x0501
#endif

#define LOG_NAME clientqt
#include "log/client.hpp"

#include <QtGui>
#include <QtCore>

#include <string>
#include <iostream>
#include <deque>
#include <set>

#include <boost/shared_array.hpp>
#include <boost/date_time/gregorian_calendar.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/cstdint.hpp>

#include <boost/enable_shared_from_this.hpp>

#include <boost/foreach.hpp>

#include <boost/thread.hpp>
#include <vector>

