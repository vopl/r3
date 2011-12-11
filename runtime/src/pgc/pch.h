#define LOG_NAME pgc
#include "log/client.hpp"

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/function.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <boost/uuid/random_generator.hpp>

#include <boost/random/random_device.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>

#include <set>
#include <deque>
#include <iostream>

#include <libpq-fe.h>
