#ifndef _SERVER_PCH_H_
#define _SERVER_PCH_H_

#define LOG_NAME server
#include "log/client.hpp"

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

#include "async/service.hpp"
using namespace async;

using namespace boost;
using namespace boost::system;

#endif
