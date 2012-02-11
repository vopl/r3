#ifndef _NET_PCH_H_
#define _NET_PCH_H_

#define LOG_NAME net
#include "log/client.hpp"

#include <iostream>
#include <deque>
#include <set>
#include <map>

#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/foreach.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>


using namespace boost;
using namespace boost::system;
using namespace boost::asio;

#endif
