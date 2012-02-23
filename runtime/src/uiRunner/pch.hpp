#ifndef _DESKTOP_PCH_HPP_
#define _DESKTOP_PCH_HPP_

#ifdef _WIN32
#	define _WIN32_WINNT 0x0501
#endif

#define LOG_NAME desktop
#include "log/client.hpp"

#include <QtCore>
#include <QtScript>
#include <QtScriptTools>
#include <QScriptable>

#include <QtCore/QObject>
#include <QtCore/QVariant>
#include <QtCore/QUuid>

#include <QPointer>

#include "utils/variant.hpp"

#include <boost/bind.hpp>
#include <boost/date_time/gregorian_calendar.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time/posix_time/posix_time_duration.hpp>

#endif
