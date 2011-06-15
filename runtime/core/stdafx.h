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
#include <set>

#include <boost/shared_array.hpp>
#include <boost/date_time/gregorian_calendar.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/cstdint.hpp>

#include <boost/enable_shared_from_this.hpp>

#include <boost/foreach.hpp>

#include <boost/thread.hpp>
#include <vector>

#include <boost/serialization/export.hpp>
#include "utils/serialization/polymorphic_binary_portable_iarchive.hpp"
#include "utils/serialization/polymorphic_binary_portable_oarchive.hpp"
