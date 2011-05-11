#ifndef _SOCI_PCH_H_
#define _SOCI_PCH_H_

//warning C4127: conditional expression is constant
#pragma warning (disable: 4127)
#include <boost/cstdint.hpp>
#include <boost/date_time/gregorian_calendar.hpp>
#include <boost/date_time/gregorian/conversion.hpp>
#include <boost/date_time/gregorian/gregorian_types.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/include/at.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/sequence/intrinsic/size.hpp>
#include <boost/fusion/support/is_sequence.hpp>
#include <boost/optional.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/version.hpp>

// #include "boost-fusion.h"
// #include "boost-gregorian-date.h"
// #include "boost-optional.h"
// #include "boost-tuple.h"





#include <bitset>
#include <map>
#include <vector>

#include <cassert>
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <exception>
#include <iterator>
#include <limits>

#include <memory>

#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <utility>

#endif
