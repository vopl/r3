// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
#include <string>
#include <iostream>
#include <deque>

#include <boost/date_time/gregorian_calendar.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/cstdint.hpp>

#include <boost/type_traits.hpp>

#include <boost/mpl/vector.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/transform.hpp>
namespace bmpl = boost::mpl;

#include <boost/enable_shared_from_this.hpp>