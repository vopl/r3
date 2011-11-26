/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// binary_iarchive.cpp:

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.
#include "pch.h"
#include <istream>

#define BOOST_ARCHIVE_SOURCE
#include "utils/serialization/binary_portable_iarchive.hpp"
#include <boost/archive/detail/archive_serializer_map.hpp>

#include <boost/archive/impl/archive_serializer_map.ipp>
#include <boost/archive/impl/basic_binary_iprimitive.ipp>
#include <boost/archive/impl/basic_binary_iarchive.ipp>




namespace boost
{ 
	namespace archive
{ 
	namespace detail
	{
		// explicitly instantiate for this type of stream
		template class archive_serializer_map<utils::serialization::naked_binary_portable_iarchive>;
		// explicitly instantiate for this type of stream
		template class archive_serializer_map<utils::serialization::binary_portable_iarchive>;
		}

		template class basic_binary_iprimitive<
			utils::serialization::naked_binary_portable_iarchive,
			std::istream::char_type, 
			std::istream::traits_type
		>;
		template class basic_binary_iarchive<utils::serialization::naked_binary_portable_iarchive> ;
		template class basic_binary_iprimitive<
			utils::serialization::binary_portable_iarchive,
			std::istream::char_type, 
			std::istream::traits_type
		>;
		template class boost::archive::basic_binary_iarchive<utils::serialization::binary_portable_iarchive> ;
	}
}

namespace utils
{
	namespace serialization
	{
		template class binary_portable_iarchive_impl<
			naked_binary_portable_iarchive, 
			std::istream::char_type, 
			std::istream::traits_type
		>;

		template class binary_portable_iarchive_impl<
			binary_portable_iarchive, 
			std::istream::char_type, 
			std::istream::traits_type
		>;

	} 
} 
